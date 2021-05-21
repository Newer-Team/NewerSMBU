
#include "game.h"

class NewerBgRenderer : public BgRenderer {
	public:
	agl::ShaderProgram *revealShader;
	
	agl::TextureData mainLayerTextureData;
	agl::RenderTargetColor mainLayerTargetColor;
	agl::RenderBuffer mainLayerRenderBuffer;
	
	agl::TextureData revealMaskTextureData;
	agl::RenderTargetColor revealMaskTargetColor;
	agl::RenderBuffer revealMaskRenderBuffer;
	
	BgMaskList revealMasks;
	
	bool usingRevealMasks;
	
	NewerBgRenderer();
	~NewerBgRenderer();
	
	static void initShaders(agl::ShaderProgramArchive *, sead::Heap *);

	void init(sead::Heap *heap);
	void initMainLayerFrameBuffer(agl::lyr::RenderInfo *renderInfo);
	void renderMainLayer(agl::lyr::RenderInfo *renderInfo);
	
	void initRevealMaskFrameBuffer(agl::lyr::RenderInfo *);
	void drawRevealMasks(agl::lyr::RenderInfo *);
	void drawTilesWithRevealMasks(agl::lyr::RenderInfo *);
	void revealMaskRenderStep(agl::lyr::RenderInfo *);
	
	void freeLayerMaskTexData();
};
