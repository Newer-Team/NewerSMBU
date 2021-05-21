
#pragma once

class MaskTexture {
	public:
	enum Shape {
		cave = 0,
		cave_small = 1,
		dark = 2,
		deep_sea = 3,
		flashlightA = 4,
		flashlightB = 5,
		DRC_block = 6,
		DRC_touch = 7
	};

	virtual bool init(sead::Heap *heap, Shape shape) = 0;
	virtual bool update() = 0;
	virtual bool draw() = 0;
};

class LightMask : public MaskTexture {
	public:
	float size;
	u32 _8;
	Vec3 position;
	u32 *_18;
	u32 _1C;
	Shape shape;
	u32 _24;
	
	LightMask();
	
	bool init(sead::Heap *heap, Shape shape);
	bool update();
	bool draw();
};

class LayerMask : public MaskTexture {
	public:
	Vec3 position;
	float size;
	void *_14;
	void *_18;
	
	bool init(sead::Heap *heap, Shape shape);
	bool update();
	bool draw();
};

class ModelObj {
	/* Incomplete */
	public:
	virtual void vf0C();
	virtual void vf14();
	virtual void vf1C();
	virtual void vf24();
	virtual void vf2C();
	virtual void vf34();
	virtual void vf3C();
	virtual void vf44();
	virtual void vf4C();
	virtual void vf54();
	virtual void vf5C();
	virtual void vf64();
	virtual void vf6C();
	virtual void vf74();
	virtual void setMatrix(Mtx *);
	virtual void vf84();
	virtual void setScale(Vec3 *);
	/* ........ */
};

class ResArchive {
	/* Incomplete */
	public:
	ModelObj * getModel(sead::String filename, u32, u32, u32, u32, u32, bool, sead::Heap *heap);
};

class Animation {
	public:
	float startFrame;
	float endFrame;
	float _8;
	float _C;
	float frame;
	float speed;
	u32 flags;

	void setRepeat(bool);
	void update();
};

class ModelAnimation : public Animation {
	public:
	void update();
	
	virtual void Calc() = 0;
};

class SkeletalAnim : public ModelAnimation {
	public:
	nw::g3d::SkeletalAnimObj animObj;
	u8 _58[0x40];
	
	void Calc();

	void play(ResArchive * archive, sead::String * filename);
};

template <class T>
struct AnimationList {
	u32 count;
	T **anims;
};

class Model {
	public:
	ModelObj *obj;
	ResArchive *archive;
	AnimationList<SkeletalAnim> sklAnims;
	AnimationList<ModelAnimation> texAnims;
	AnimationList<ModelAnimation> shuAnims;
	AnimationList<ModelAnimation> visAnims;
	AnimationList<ModelAnimation> shaAnims;
	
	Model(ModelObj * model, u32 sklAnimCount, u32 texAnimCount, u32 shuAnimCount, u32 visAnimCount, u32 shaAnimCount);
	void init(ResArchive * archive, sead::PtrArrayImpl<ResArchive> *archives, sead::Heap *heap);
	void update(); //updates animations
};

struct Model2Thing {
	float _0;
	float _4;
	float _8;
	float _C;
	u8 _10;
	u8 _11;
	u8 _12;
	u8 _13;
};

class Model2 : public Model {
	public:
	Model2Thing _30;
	u32 _44;
	
	Model2(ModelObj * model, u32, u32, u32, u32, u32);
	void init(ResArchive * archive, sead::PtrArrayImpl<ResArchive> *archives, sead::Heap *heap);
	void update();
};

class CharacterModel : public sead::IDisposer {
	public:
		ResArchive *texArchive;
		ResArchive *animArchive;
		Model *model;
		u32 animTypeId;
		u32 _20;
		u32 _24;
		u32 _28;
		Mtx matrix1;
		Mtx matrix2;
		Vec3 _8C;
		Vec3 _98;
		u32 _A4;
		u32 _A8;
		u32 _AC;
		u32 _B0;
		float _B4;
		float _B8;
		float _BC;
		float _C0;
		u32 _C4[3];
		u32 _D0;
		u32 _D4;
		u32 _D8;
		u32 _DC;
		u32 _E0;
		u32 _E4;
		u32 _E8;
		u32 _EC;
		
		CharacterModel(sead::String *texture, sead::String *anim);
};

class YoshiModel : public CharacterModel {
	public:
};

class CharacterModelHandler {
	public:
	CharacterModel *model;
	u32 _4;
	
	virtual void vf0C(); //nullsub
};

class YoshiModelHandler : public CharacterModelHandler {
	public:
	YoshiModel *yoshiModel;
};

class PlatformModel {
	public:
		ResArchive *archive;
		Model *models[3];
		Model *models2[30];
		Vec3 position;
		Vec3 _94;
		Vec3 _A0;
		Vec3 _AC;
		Vec3 _B8;
		Vec3i rotation;
		float fwidth;
		float fwidth2;
		float _D8;
		u32 width;
		u32 type;
		float scale;
		u8 _E8;
		u8 _E9;
		u8 _EA;
		u8 _EB;
				
		void init();
		void update(Vec3 *pos, float width);
		void draw();
			
		inline PlatformModel() {		
			scale = 1.0;		
		}		
};

class Drawer {
	public:
		static Drawer *instance;
		void drawModel(Model * model);
		void drawTile(u32 tileNumber, Vec3 *pos, u32 *zrot, Vec3 *scale);
};

class FrameBufferInstance {
	public:
	agl::TextureData *textureData;
	u32 format;
	u32 width;
	u32 height;
	agl::RenderBuffer *renderBuffer;
	agl::RenderTargetColor *targetColor;
	Rect rect;
	void *resTexData;
	u32 referenceCount;
	u32 _30;
	u32 _34;
};

class FrameBufferKeeper : public sead::IDisposer {
	public:
	enum BufferType {
		All3D,
		DRCMode,
		Effect,
		Pause,
		PauseDRC
	};
	FrameBufferInstance buffers[5];
	sead::GraphicsContext graphicsContext;
	agl::utl::DebugTexturePage debugPage;
	
	static FrameBufferKeeper *instance;
	
	void switchBuffer(BufferType which, agl::lyr::RenderInfo *renderInfo, bool gaussian);
};

class MaskTexData {
	public:
	static agl::TextureData *loadTexture(MaskTexture::Shape shape, agl::TextureData *texdata);
};

struct MaskInfo {
	Vec2 position;
	float transparency;
	Vec2 texcoords;
};

class BgMaskList {
	public:
	u8 _0[0x510C];
	
	BgMaskList();
	void init(sead::Heap *heap);
	void draw(void *, void *);
	void add(MaskInfo *, MaskInfo *, MaskInfo *, MaskInfo *, agl::TextureData *texture, u32);
	
	virtual ~BgMaskList();
};

class BgRenderer : public sead::IDisposer {
	public:
	u8 _10[0x6300 - 0x10];
	agl::ShaderProgramArchive *shaderArchive;
	u8 _6304[0x65F4 - 0x6304];
	agl::ShaderProgram *layerMaskShader;
	u8 _65F8[0x6944 - 0x65F8];
	agl::TextureData *frontLayerTextureData;
	agl::RenderTargetColor frontLayerTextureTargetColor;
	agl::TextureData *layerBufferTextureData;
	agl::RenderTargetColor layerBufferTargetColor;
	agl::TextureData *layerDepthTextureData;
	agl::RenderTargetDepth layerRenderTargetDepth;
	agl::RenderBuffer frontLayerRenderBuffer;
	u8 _6DA8[0x73AC - 0x6DA8];
	agl::TextureData *maskTextureData;
	agl::RenderTargetColor maskTargetColor;
	agl::RenderBuffer maskRenderBuffer;
	u8 _7554[0x797C - 0x7554];
	sead::Color4f darknessCircleColor;
	u8 _798C[0x88DC - 0x798C];
	BgMaskList layerMasks;
	BgMaskList lightMasks;
	
	static BgRenderer *instance;
	
	static void initShaders(agl::ShaderProgramArchive *archive, sead::Heap *heap);
	
	static agl::TextureData *allocTexture(sead::String *name, agl::utl::DynamicTextureAllocator::AllocateType allocType);
	static agl::TextureData *allocDepthTexture(sead::String *name, void **hiZPtr);
	static void freeTexture(agl::TextureData **);
	
	BgRenderer();
	
	void init(sead::Heap *heap);
	void drawLayerMasks(agl::lyr::RenderInfo *renderInfo);
	void drawTilesWithMasks(agl::lyr::RenderInfo *renderInfo);
	void renderTileLayer(sead::Viewport *, sead::OrthoProjection *, u32 layer);
	
	void initMainLayerFrameBuffer(agl::lyr::RenderInfo *renderInfo);
	void initMainLayerContext(agl::lyr::RenderInfo *renderInfo);
	void initSpotlightMaskFrameBuffer(agl::lyr::RenderInfo *);
	
	~BgRenderer();
};

struct TileAnimation {
	u8 playing;
	u8 reverse;
	u32 *frameDelays;
	u32 frameCount;
	u32 frame;
	u32 delayTimer;
};

class BgTexMgr : public sead::IDisposer {
	public:
	u32 _10;
	agl::TextureData tilesetTextures[4];
	u32 usedTilesetSlots;
	u32 _288;
	agl::TextureData normalMaps[4];
	agl::RenderTargetColor textureRenderTargetColor;
	agl::RenderBuffer textureRenderBuffer;
	agl::RenderTargetColor normalRenderTargetColor;
	agl::RenderBuffer normalRenderBuffer;
	sead::OrthoProjection projection;
	sead::OrthoCamera camera;
	agl::TextureData animationTextures[6];
	TileAnimation tileAnimations[9];
	u32 _DA4;
	agl::utl::DebugTexturePage debugTexturePage;
	u8 _F84;
	
	static void loadTexture(agl::TextureData *, sead::String *tilesetName, sead::String *texFilename);
	void loadTilesets(u8 area);
	void update();
	void renderAnimation(u32 tile, u32 animIndex, u32 animTexIndex, s32 tileCount);
};

class CourseDarknessMgr : public sead::IDisposer {
	public:
	static CourseDarknessMgr *instance;
	u32 visibility;
	//...
};
