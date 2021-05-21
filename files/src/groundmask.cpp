
#include "neweru.h"
#include "groundmask.h"
#include "specialevent.h"

/***
*
* NewerBgRenderer:
*	Renders layer 1 tiles with reveal masks
*
***/

NewerBgRenderer::NewerBgRenderer() : 
	BgRenderer(),
	mainLayerRenderBuffer(&(Vec2){1280, 720}, 0, 0, 1280, 720),
	revealMaskRenderBuffer(&(Vec2){1280, 720}, 0, 0, 1280, 720) {}
	
NewerBgRenderer::~NewerBgRenderer() {
	if (mainLayerTextureData.surface.imagePtr) delete mainLayerTextureData.surface.imagePtr;
	if (revealMaskTextureData.surface.imagePtr) delete revealMaskTextureData.surface.imagePtr;
}

void NewerBgRenderer::initShaders(agl::ShaderProgramArchive *archive, sead::Heap *heap) {
	BgRenderer::initShaders(archive, heap);
	
	sead::String programName = "reveal_mask_program";
	int programIndex = archive->searchShaderProgramIndex(&programName);
	agl::ShaderProgram *revealShader = &archive->programs.list[programIndex];
	
	sead::String uniformNames[] = {"projection[0]", "circle_color"};
	revealShader->createUniformBlock(2, heap);
	revealShader->setUniformBlockName(0, &uniformNames[0]);
	revealShader->setUniformBlockName(1, &uniformNames[1]);
	
	sead::String samplerNames[] = {"texture_layer0", "texture_mask"};
	revealShader->createSamplerBlock(2, heap);
	revealShader->setSamplerBlockName(0, &samplerNames[0]);
	revealShader->setSamplerBlockName(1, &samplerNames[1]);
}

void NewerBgRenderer::init(sead::Heap *heap) {
	BgRenderer::init(heap);
	revealMasks.init(heap);
	
	//Initialize shader program
	sead::String programName = "reveal_mask_program";
	int programIndex = shaderArchive->searchShaderProgramIndex(&programName);
	revealShader = &shaderArchive->programs.list[programIndex];
	
	//Initialize texture data
	mainLayerTextureData.initialize((agl::TextureType)1, (agl::TextureFormat)0x1D, 1280, 720, 1, 1, (agl::MultiSampleType)0);
	mainLayerTextureData.surface.imagePtr = operator new(mainLayerTextureData.surface.imageSize, 0, mainLayerTextureData.surface.alignment);
	
	revealMaskTextureData.initialize((agl::TextureType)1, (agl::TextureFormat)0x1D, 1280, 720, 1, 1, (agl::MultiSampleType)0);
	revealMaskTextureData.surface.imagePtr = operator new(revealMaskTextureData.surface.imageSize, 0, revealMaskTextureData.surface.alignment);
}

void NewerBgRenderer::initMainLayerFrameBuffer(agl::lyr::RenderInfo *renderInfo) {
	//Apply it to a render target
	mainLayerTargetColor.applyTextureData(&mainLayerTextureData);
	
	//Apply the render target to a render buffer and bind it
	//Everything will be drawn onto the layer 1 texture data now
	mainLayerRenderBuffer.targetColors[0] = &mainLayerTargetColor;
	mainLayerRenderBuffer.frameBuffer.bind();
	
	sead::GraphicsContextMRT context;
	context.blendEnableMask &= ~3;
	context.targetChannelMasks = 0xFF;
	context.apply();
	
	sead::Color4f clearColor = {0, 0, 0, 0};
	mainLayerRenderBuffer.clear(0, 1, &clearColor, 0, 1.0);
}

void NewerBgRenderer::renderMainLayer(agl::lyr::RenderInfo *renderInfo) {
	sead::OrthoProjection *proj = (sead::OrthoProjection *)renderInfo->projection;
	sead::OrthoProjection projection(proj->nearOrFar, proj->farOrNear, -proj->top,
									 -proj->bottom, proj->left, proj->right);
	
	sead::GraphicsContextMRT context;
	context.blendEnableMask &= ~3;
	context.alphaTestEnable = true;
	context.ref = 0.0625;
	context.depthEnable = true;
	context.depthWriteEnable = true;
	context.targetChannelMasks = 0xFF;
	context.alphaFunc = 6;
	context.apply();
	
	mainLayerRenderBuffer.frameBuffer.bind();
	
	//Since our own frame buffer is bound, tiles will
	//be drawn onto a texture instead of the screen
	renderTileLayer(renderInfo->viewport, &projection, 0);
	
	mainLayerTargetColor.invalidateGPUCache();
	mainLayerTextureData.invalidateGPUCache();
	
	context.targetChannelMasks &= ~0xF0;
	context.apply();
	
	//The original function does this, so we have to do it as well
	//because the game would crash when it tries to reallocate them
	freeTexture(&layerDepthTextureData);
	freeTexture(&layerBufferTextureData);
}

void NewerBgRenderer::initRevealMaskFrameBuffer(agl::lyr::RenderInfo *renderInfo) {
	//The mask textures should be drawn on this texture
	//Attach it to a render buffer and bind it
	revealMaskTargetColor.applyTextureData(&revealMaskTextureData);
	
	revealMaskRenderBuffer.targetColors[0] = &revealMaskTargetColor;
	revealMaskRenderBuffer.frameBuffer.bind();
	
	sead::GraphicsContext context;
	context.blendEnable = true;
	context.depthWriteEnable = false;
	context.depthEnable = false;
	context.apply();
	
	sead::Color4f clearColor = {0, 0, 0, 0};
	if (!isRevealMode()) clearColor.red = 1; //Masks use the "red" component as transparency
	revealMaskRenderBuffer.clear(0, 1, &clearColor, 0, 1.0);
}

void NewerBgRenderer::drawRevealMasks(agl::lyr::RenderInfo *renderInfo) {
	sead::GraphicsContext context;
	context.blendEnable = true;
	context.depthEnable = false;
	context.depthWriteEnable = false;
	context.apply();
	
	//Now actually render the mask textures onto our texture
	void *matrix = renderInfo->projection->getDeviceProjectionMatrix();
	revealMasks.draw(renderInfo->_14, matrix);
	
	revealMaskTargetColor.invalidateGPUCache();
	revealMaskTextureData.invalidateGPUCache();
	
	//Bind the original frame buffer, we're
	//going to draw to screen now.
	renderInfo->frameBuffer->bind();
}

void NewerBgRenderer::drawTilesWithRevealMasks(agl::lyr::RenderInfo *renderInfo) {
	//Using the function that renders layer 0 tiles with spotlight masks here
	//Replace texture data and shader with our own
	agl::TextureData *origMaskTextureData = maskTextureData;
	agl::TextureData *origLayerTextureData = frontLayerTextureData;
	agl::ShaderProgram *origShaderProgram = layerMaskShader;
	
	usingRevealMasks = true;
	maskTextureData = &revealMaskTextureData;
	frontLayerTextureData = &mainLayerTextureData;
	layerMaskShader = revealShader;
	drawTilesWithMasks(renderInfo);
	usingRevealMasks = false;
	
	//Restore original textures and shader.
	maskTextureData = origMaskTextureData;
	frontLayerTextureData = origLayerTextureData;
	layerMaskShader = origShaderProgram;
}

void NewerBgRenderer::revealMaskRenderStep(agl::lyr::RenderInfo *renderInfo) {
	//Stuff the whole reveal mask code into a single render step
	initRevealMaskFrameBuffer(renderInfo);
	drawRevealMasks(renderInfo);
	drawTilesWithRevealMasks(renderInfo);
	
	//I patched a branch to initSpotlightMaskFrameBuffer
	initSpotlightMaskFrameBuffer(renderInfo);
}

void NewerBgRenderer::freeLayerMaskTexData() {
	if (!usingRevealMasks) {
		freeTexture(&maskTextureData);
		freeTexture(&frontLayerTextureData);
	}
}
