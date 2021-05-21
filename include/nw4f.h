
#pragma once

#include "cafe.h"
#include "common.h"

namespace sead {
	
	struct Color4f {
		float red;
		float green;
		float blue;
		float alpha;
	};
	
	struct ListNode {
		ListNode *previous;
		ListNode *next;
	};
	
	struct ListImpl {
		ListNode root;
		u32 count;
		u32 nodeOffset;
	};
	
	template <class T>
	struct PtrArrayImpl {
		u32 count;
		u32 size;
		T **ptrs;
	};
	
	class IDisposer {
		public:
		void * heap;
		ListNode disposerListNode;
		
		virtual ~IDisposer();
	};
	
	//There are actually multiple classes representing strings,
	//with templates and inline functions. This class is a heavily
	//simplified version of those string classes. Hence the more
	//general name "String".
	class String {
		public:
		const char * str;
		String(const char * string) {
			str = string;
		}
		
		virtual void vf0C(); //Destructor
		virtual void vf14();
	};
	
	class Random {
		public:
		u32 getU32();
	};
	
	class GlobalRandom : public Random {
		public:
		static GlobalRandom *instance;
	};
	
	class CriticalSection : public IDisposer {
		public:
		OSMutex mutex;
	};
	
	class TreeNode {
		public:
		u32 _0;
		u32 _4;
		u32 _8;
		u32 _C;
	};
	
	//Not the official name, obviously
	class TreeNodeThing : public TreeNode {
		public:
		void *self; //Not sure what this is supposed to be
	};
	
	//This may inherit more than one class, actually
	class MethodTreeNode : public TreeNodeThing {
		public:
		String name;
		IDisposer disposer;
		u8 function[0x10]; //PTMF struct
		CriticalSection *criticalSection;
		u32 _40;
		u32 _44;
		u32 _48;
		u32 _4C;
		
		virtual void vf0C();
		virtual void vf14();
		virtual ~MethodTreeNode();
	};
	
	class Heap : public IDisposer {
		public:
		String name;
		u32 addr;
		u32 size;
		Heap *parent;
		ListImpl children;
		u32 _34;
		u32 _38;
		ListImpl disposers;
		u32 direction;
		CriticalSection mutex;
		u32 flags;
		
		~Heap();
		virtual void vf14() = 0; //deleted;
		virtual void vf1C() = 0; //deleted;
		virtual void destroy() = 0;
		virtual u32 adjust() = 0;
		virtual void *tryAlloc(u32 size, int alignment) = 0;
		virtual void free(void *ptr) = 0;
		virtual u32 resizeFront(void *, u32) = 0;
		virtual u32 resizeBack(void *, u32) = 0;
		virtual void freeAll() = 0;
		virtual void *getStartAddress() = 0;
		virtual void *getEndAddress() = 0;
		virtual void vf6C() = 0; //deleted
		virtual u32 getFreeSize() = 0;
		virtual u32 getMaxAllocatableSize(int alignment) = 0;
		virtual bool isInclude(void *) = 0;
		virtual bool isFreeable() = 0;
		virtual void vf94() = 0; //deleted
		virtual void vf9C() = 0; //deleted
		virtual void vfA4() = 0; //deleted
		virtual void vfAC() = 0; //deleted
	};
	
	class ExpHeap : public Heap {
		public:
		u32 _90;
		ListImpl freeBlocks;
		ListImpl usedBlocks;
	
		~ExpHeap();
		void vf14();
		void vf1C();
		void destroy();
		u32 adjust();
		void *tryAlloc(u32 size, int alignment);
		void free(void *ptr);
		u32 resizeFront(void *, u32);
		u32 resizeBack(void *, u32);
		void freeAll();
		void *getStartAddress();
		void *getEndAddress();
		void vf6C();
		u32 getFreeSize();
		u32 getMaxAllocatableSize(int alignment);
		bool isInclude(void *);
		bool isFreeable();
		void vf94();
		void vf9C();
		void vfA4();
		void vfAC();
		virtual void vfB4(); //deleted
		virtual void vfBC(); //deleted
	};
	
	class HeapMgr : public IDisposer {
		public:
		static PtrArrayImpl<Heap> rootHeaps;
		static Heap *getCurrentHeap();
	};
	
	class Viewport {
		public:
		Rect rect;
		u32 _10;
		
		virtual void vf0C(); //deleted
	};
	
	class Projection {
		public:
		u8 _0;
		u8 _1;
		u8 _2;
		u8 _3;
		u8 _4[64];
		u8 _44[64];
		u32 _84;
		float _88;
		float _8C;
		
		void *getDeviceProjectionMatrix();
		
		virtual bool checkDerivedRuntimeTypeInfo(void *);
		virtual void vf14(); //deleted
		virtual ~Projection();
		//More virtual functions here
	};
	
	class TaskMgr;
	class TaskEvent;
	
	class TaskBase : public TreeNodeThing, IDisposer {
		public:
		String name;
		u32 _2C;
		u32 _30;
		u8 _34[0x10]; //Actually a structure of some kind
		u32 _44;
		u32 _48;
		u32 _4C;
		u32 _50;
		u32 _54;
		u32 _58;
		TaskMgr *taskMgr;
		u32 state;
		u32 _64;
		u32 _68;
		u32 _6C;
		
		bool checkDerivedRuntimeTypeInfo(void *);
		virtual void vf14(); //deleted
		virtual void pauseCalc(bool) = 0;
		virtual void pauseDraw(bool) = 0;
		virtual void vf2C() = 0; //deleted
		virtual void vf34() = 0; //deleted
		virtual void pauseCalcChild(); //deleted
		virtual void vf44(); //deleted
		virtual ~TaskBase();
		virtual void prepare();
		virtual void enterCommon();
		virtual void enter();
		virtual void exit();
		virtual void onEvent(TaskEvent *);
		virtual void attachCalcImpl() = 0;
		virtual void attachDrawImpl() = 0;
		virtual void detachCalcImpl() = 0;
		virtual void detachDrawImpl() = 0;
		virtual void vf9C() = 0; //deleted
		virtual MethodTreeNode *getMethodTreeNode(int) = 0;
		virtual void vfAC(); //deleted
	};
	
	class CalculateTask : public TaskBase {
		public:
		MethodTreeNode methodTreeNode;
		
		bool checkDerivedRuntimeTypeInfo(void *);
		void pauseCalc(bool);
		void pauseDraw(bool);
		void vf2C();
		void vf34();
		~CalculateTask();
		void attachCalcImpl();
		void attachDrawImpl();
		void detachCalcImpl();
		void detachDrawImpl();
		void vf9C();
		MethodTreeNode *getMethodTreeNode(int);
		virtual void calc();
	};
	
	class OrthoProjection : public Projection {
		public:
		float nearOrFar;
		float farOrNear;
		float top;
		float bottom;
		float left;
		float right;
		
		OrthoProjection(float, float, float top, float bottom, float left, float right);
		~OrthoProjection();
	};
	
	class Camera {
		Mtx matrix;
		
		virtual bool checkDerivedRuntimeTypeInfo(void *);
		virtual void vf14(); //deleted;
		virtual ~Camera();
		virtual void doUpdateMatrix(Mtx *matrix) = 0;
	};
	
	class LookAtCamera : public sead::Camera {
		u8 _34[0x58 - 0x34];
		
		bool checkDerivedRuntimeTypeInfo(void *);
		~LookAtCamera();
		void doUpdateMatrix(Mtx *matrix);
	};

	class OrthoCamera : public LookAtCamera {
		bool checkDerivedRuntimeTypeInfo(void *);
		~OrthoCamera();
	};
	
	class GraphicsContext {
		public:
		bool depthEnable;
		bool depthWriteEnable;
		u32 depthFunc;
		u32 cullRelated;
		
		bool blendEnable;
		u32 colorSrcBlend;
		u32 alphaSrcBlend;
		u32 colorDstBlend;
		u32 alphaDstBlend;
		u32 colorCombine;
		u32 alphaCombine;
		
		Color4f color;
		
		bool alphaTestEnable;
		u32 alphaFunc;
		float ref;
		
		u8 _44;
		u8 _45;
		u8 _46;
		u8 _47;
		
		bool stencilEnable;
		u32 stencilFunc;
		u32 writeMask;
		u32 preMask;
		u32 stencilFail;
		u32 stencilZFail;
		u32 stencilZPass;
		u32 polygonModeFront;
		u32 polygonModeBack;
		bool polyOffsetFrontEnable;
		bool polyOffsetBackEnable;
		bool polyLineOffsetEnable;
		
		GraphicsContext();
		
		void apply();
		
		virtual void vf0C(); //deleted
	};
	
	class GraphicsContextMRT {
		public:
		class BlendExpression {
			public:
			u32 colorSrcBlend;
			u32 alphaSrcBlend;
			u32 colorDstBlend;
			u32 alphaDstBlend;
			u32 colorCombine;
			u32 alphaCombine;
			
			BlendExpression();
		};
		
		bool depthEnable;
		bool depthWriteEnable;
		u32 depthFunc;
		
		u32 _8;
		u32 blendEnableMask;
		BlendExpression blendExpressions[8];
		
		Color4f color;
		bool alphaTestEnable;
		u32 alphaFunc;
		
		float ref;
		u32 targetChannelMasks;
		
		bool stencilEnable;
		u32 stencilFunc;
		u32 writeMask;
		u32 preMask;
		u32 stencilFail;
		u32 stencilZFail;
		u32 stencilZPass;
		
		u32 _10C;
		u32 _110;
		u32 _114;
		
		GraphicsContextMRT();
		
		void apply();
		
		virtual void vf0C(); //deleted
	};
	
	class DisplayBuffer;
	
	class FrameBuffer {
		public:
		float width;
		float height;
		Rect rect;
	
		void bind();
		
		virtual bool checkDerivedRuntimeTypeInfo(void *);
		virtual void vf14(); //deleted
		virtual void vf1C(); //deleted
		virtual void copyToDisplayBuffer(DisplayBuffer *);
		virtual void clear(u32 flags, Color4f *color, u32 stencilValue, float depthValue);
		virtual void vf34(); //nullptr
		virtual void bindImpl_();
	};
	
	class FileDevice {
		public:
		struct LoadArg {
			String filename;
			u32 _8;
			u32 _C;
			Heap *heap;
			u32 _14;
			u32 _18;
			u32 _1C;
			u32 _20;
			u8 _24;
		};
		
		void *tryLoad(LoadArg *);
	};
	class MainFileDevice : public FileDevice {};
	
	class FileDeviceMgr : public IDisposer {
		public:
		static FileDeviceMgr *instance;
		ListImpl mountedFileDevices;
		MainFileDevice *mainFileDevice;
		FSClient fsClient;
		
		//Not sure if this is an official name
		void *tryLoad(FileDevice::LoadArg *);
	};
	
	class SZSDecompressor {
		public:
		static int decomp(void *outPtr, u32 outSize, const void *inPtr, u32 inSize);
		static int getDecompSize(const void * inPtr);
	};
	
	class Resource {};
	class DirectResource : public Resource {};
	class ArchiveRes : public DirectResource {};
	class SharcArchiveRes : public ArchiveRes {};
}

namespace nw {
	
	namespace snd {
		
		namespace internal {
			
			namespace SoundArchiveFile {
				class StringBlockBody {
					public:
					char *GetString(u32 stringId);
				};
				
				class InfoBlockBody {};
			}
			
			class ExternalSoundPlayer {
				public:
				u32 _0;
				u32 _4;
				u32 _8;
				u32 _C;
			};
			
			class SoundArchiveFileReader {
				public:
				u8 header[0x38];
				SoundArchiveFile::StringBlockBody *stringBlock;
				SoundArchiveFile::InfoBlockBody *infoBlock;
				u32 _40;
			};
		}
		
		class SoundHandle;
		
		class SoundStartable {
			public:
			class StartInfo;
			
			virtual ~SoundStartable() = 0;
			virtual void detail_SetupSound(SoundHandle *, u32, bool, SoundStartable::StartInfo) = 0;
			virtual u32 detail_GetItemId(const char *) = 0;
		};
		
		class SoundActor : public SoundStartable {
			public:
			~SoundActor();
			void detail_SetupSound(SoundHandle *, u32, bool, SoundStartable::StartInfo);
			u32 detail_GetItemId(const char *);
			virtual u32 SetupSound(SoundHandle *, u32, SoundStartable::StartInfo, void *);
			virtual void vf2C(); //deleted
			
			u32 _4;
			internal::ExternalSoundPlayer externalSoundPlayers[4];
			float _48;
			float _4C;
			float _50;
			float _54;
			float _58;
			float _5C;
			u8 _60;
			u8 _61;
			u8 _62;
			u8 _63;
		};
		
		class SoundArchive {
			public:
			internal::SoundArchiveFileReader *fileReader;
			u8 _4[160];
			u32 _284;
			u32 fileBlockOffs;
			
			char *GetItemLabel(u32 itemId);
			
			virtual ~SoundArchive();
			virtual u32 detail_GetFileAddress(u32) = 0;
			virtual void vf1C() = 0; //deleted by subclasses
			virtual void FileAccessBegin();
			virtual void FileAccessEnd();
			virtual void *OpenStream(void *, int, u32, u32) = 0;
			virtual void *OpenExtStream(void *, int, const char *, void *, u32) = 0;
		};
		
		class FsSoundArchive : public SoundArchive {
			public:
			//data here
			
			~FsSoundArchive();
			u32 detail_GetFileAddress(u32);
			void FileAccessBegin();
			void FileAccessEnd();
			void *OpenStream(void *, int, u32, u32);
			void *OpenExtStream(void *, int, const char *, void *, u32);
		};
	}
	
	namespace g3d {
		
		class AnimFrameCtrl {
			public:
			float _0;
			float _4;
			float _8;
			float _C;
			void *_10;
			u32 _14;
		};
		
		class AnimObj {
			public:
			u32 _0;
			AnimFrameCtrl frameCtrl;
			u8 _1C[0x18];
			
			virtual ~AnimObj();
			virtual void ClearResult() = 0;
			virtual void Calc() = 0;
		};
		
		class SkeletalAnimObj : public AnimObj {
			void ClearResult();
			void Calc();
		};
	}
	
	namespace ut {		
		int snprintf(char *buffer, u32 length, const char *string, ...);
	}
}

//Not sure what this struct belongs to and what it's real name is
template <class T>
struct List {
	u32 count;
	T *list;
};

namespace agl {
	
	class DisplayList;
	
	namespace utl {
		
		class DebugTexturePage : public sead::IDisposer {
			public:
			u8 _10[0x1DC - 0x10];
		};
		
		class DynamicTextureAllocator {
			public:
			enum AllocateType {
				Type0,
				Type1,
				Type2
			};
		};
	}
	
	namespace lyr {
		
		enum DisplayType {};
		
		class DebugInfo {
			public:
			u8 _0[0x390];
		};
		
		class Layer : public sead::IDisposer {
			public:
			u32 _10;
			sead::Viewport viewPort1;
			sead::Viewport viewPort2;
			u32 _44;
			u32 _48;
			u32 _4C;
			u32 _50;
			u32 _54;
			u32 _58;
			u32 _5C;
			u32 _60;
			u32 _64;
			u32 _68;
			float _6C;
			float _70;
			float _74;
			float _78;
			float _7C;
			sead::ListNode node;
			u32 _88;
			DebugInfo debufInfo;
			
		};
		
		class RenderInfo {
			public:
			int step;
			DisplayType displayType;
			sead::FrameBuffer *frameBuffer;
			u32 _C;
			Layer *layer;
			void *_14;
			sead::Projection *projection;
			sead::Viewport *viewport;
			DisplayList *displayList;
			u32 _24;
		};
	}
	
	class DisplayList {
		public:
		u32 _0;
		u32 _4;
		u32 _8;
		
		DisplayList();
		virtual ~DisplayList();
	};
	
	class Shader {
		public:
		void *gx2struct;
		void *compileInfo;
		
		Shader();
		virtual void vf0C(); //deleted
		virtual int getShaderType() = 0;
		virtual void vf1C(); //deleted
		virtual void vf24(); //deleted
	};
	
	class VertexShader : public Shader { int getShaderType(); };
	class FragmentShader : public Shader { int getShaderType(); };
	class GeometryShader : public Shader { int getShaderType(); };
	
	class ShaderProgram {
		public:
		u8 flags;
		u8 _1;
		u16 _2;
		DisplayList displayList;
		List<void> _14;
		List<void> uniformBlocks;
		List<void> _24;
		List<void> samplerBlocks;
		VertexShader vertexShader;
		FragmentShader fragmentShader;
		GeometryShader geometryShader;
		u32 info;
		
		ShaderProgram();
		virtual ~ShaderProgram();
		
		void createUniformBlock(int count, sead::Heap *heap);
		void setUniformBlockName(int index, sead::String *name);
		
		//The following two function names are guesses, I couldn't find them in swkbd.rpl
		void createSamplerBlock(int count, sead::Heap *heap);
		void setSamplerBlockName(int index, sead::String *name);
	};
	
	class ShaderProgramArchive : public sead::IDisposer {
		public:
		void *resBinaryShaderArchive;
		u32 _14;
		List<ShaderProgram> programs;
		u32 _20;
		u32 _24;
		u16 _28;
		u16 _2A;
		u32 _2C;
		u32 _30;
		u32 _34;
		u32 _38;
		u32 _3C;
		u32 _40;
		u32 _44;
		u32 _48;
		
		int searchShaderProgramIndex(sead::String *name);
		
		ShaderProgramArchive();
		~ShaderProgramArchive();
	};
	
	enum TextureType {};
	enum TextureFormat {};
	enum MultiSampleType {};
	
	class TextureData {
		public:
		TextureFormat format;
		GX2Surface surface;
		u32 width;
		u32 height;
		u32 depth;
		u32 size;
		u32 compSel1;
		u32 compSel2;
		u32 compSel3;
		u32 compSel4;
		
		TextureData();
		
		void invalidateGPUCache();
		void initialize(TextureType, TextureFormat, u32 width, u32 height, u32 depth, u32 mipLevelNum, MultiSampleType);
		
		//Not an official name
		void loadGTX(void *data, u32);
		
		virtual void vf0C(); //deleted
	};
	
	class TextureSampler {
		public:
		void applyTextureData_(agl::TextureData *);
	};
	
	class RenderTargetColor {
		public:
		TextureData textureData;
		u32 _9C;
		u32 viewMip;
		u32 viewFirstSlice;
		u8 _A8;
		u8 _A9;
		u8 _AA;
		u8 _AB;
		u32 auxBufferSize;
		u32 auxBufferAlign;
		u32 _B4;
		GX2ColorBuffer colorBuffer;
		
		RenderTargetColor();
		
		void invalidateGPUCache();
		void applyTextureData(agl::TextureData *);
	};
	
	class RenderTargetDepth {
		public:
		TextureData textureData;
		u8 _9C;
		u32 _A0;
		u32 _A4;
		u32 _A8;
		u32 _AC;
		u32 _B0;
		GX2DepthBuffer depthBuffer;
		
		RenderTargetDepth();
		
		void invalidateGPUCache();
		void applyTextureData(agl::TextureData *);
	};
	
	class RenderBuffer : public sead::IDisposer {
		public:
		sead::FrameBuffer frameBuffer;
		RenderTargetColor *targetColors[8];
		RenderTargetDepth *targetDepth;
		
		RenderBuffer();
		RenderBuffer(Vec2 *size, float, float, float, float);
		
		void clear(u32, u32 flags, sead::Color4f *color, u32 stencilValue, float depthValue);
		
		virtual ~RenderBuffer();
	};
}
