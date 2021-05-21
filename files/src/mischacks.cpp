
#include "game.h"
#include "neweru.h"
#include "zlib.h"

void *allocZlib(void *opaque, uInt items, uInt size) {
	return ((sead::Heap *)opaque)->tryAlloc(items * size, 2);
}

void freeZlib(void *opaque, void *address) {
	((sead::Heap *)opaque)->free(address);
}

int decompZlib(Byte *outPtr, u32 outSize, Byte *inPtr, u32 inSize, sead::Heap *heap) {
	if (*(u32 *)inPtr != 0x5A6C6962) { //"Zlib"
		return sead::SZSDecompressor::decomp(outPtr, outSize, inPtr, inSize);
	}
	
	int decompSize = sead::SZSDecompressor::getDecompSize(inPtr);
	if (outSize < decompSize) return -2;
	
	z_stream stream;
	//I don't think this is the right way to clear it
	__gh_memclr32(&stream, 14);
	stream.opaque = heap;
	stream.zalloc = &allocZlib;
	stream.zfree = &freeZlib;
	inflateInit2(&stream, 15);
	
	stream.next_in = inPtr + 12;
	stream.avail_in = inSize - 12;
	stream.next_out = outPtr;
	stream.avail_out = outSize;
	inflate(&stream, Z_FINISH);
	
	inflateEnd(&stream);
	return decompSize;
}


float getWrappedYPos(float ypos) {
	//Reading the wrap flag can be done more efficiently
	//by adding another field to the AreaTask class
	LevelArea *area = Level::instance->getArea(LevelInfo::instance->area);
	AreaSettings *settings = (AreaSettings *)area->blockPtrs[LevelArea::AreaSettings];
	if (settings->flags & 2) {
		
		float top = AreaTask::instance->zoneRect.top;
		float bottom = AreaTask::instance->zoneRect.bottom - 32;
		float height = top - bottom;
		while (ypos > top) {
			ypos -= height;
		}
		while (ypos < bottom) {
			ypos += height;
		}
		
	}
	return ypos;
}

u16 getWrappedYPos(u16 ypos) {
	return -getWrappedYPos(-(float)ypos);
}

void doVerticalWrap(StageActor *actor) {
	float wrappedPos = getWrappedYPos(actor->position3.Y);
	float wrappedDiff = actor->position3.Y - wrappedPos;
	actor->position.Y = wrappedPos;
	if (wrappedDiff > 0.0001 || wrappedDiff < -0.0001) {
		//A wrap occurred
		actor->position2.Y += wrappedDiff;
	}
}
