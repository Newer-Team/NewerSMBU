
#include "types.h"

enum GX2SurfaceDim {};
enum GX2SurfaceFormat {};
enum GX2AAMode {};
enum GX2SurfaceUse {};
enum GX2TileMode {};

struct GX2Surface {
	GX2SurfaceDim dim;
	u32 width;
	u32 height;
	u32 depth;
	u32 numMips;
	GX2SurfaceFormat format;
	GX2AAMode aa;
	GX2SurfaceUse use;
	u32 imageSize;
	void *imagePtr;
	u32 mipSize;
	void *mipPtr;
	GX2TileMode tileMode;
	u32 swizzle;
	u32 alignment;
	u32 pitch;
	u32 mipOffset[13];
};

struct GX2ColorBuffer {
	GX2Surface surface;
	u8 _0x74[0x9C - 0x74];
};

struct GX2DepthBuffer {
	GX2Surface surface;
	u8 _74[0xAC - 0x74];
};
