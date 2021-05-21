
#pragma once

#include "types.h"
#include "zlib.h"

class FFLiBufferAllocator {
	public:
	void *buffer;
	u32 size;
};

class FFLiAllocatorInterface {
	public:
	virtual ~FFLiAllocatorInterface() = 0;
	virtual void Allocate(u32) = 0;
	virtual void vf1C() = 0; //deleted;
	virtual void Free(void *) = 0;
};

class FFLiBufferAllocatorForZlib : public FFLiAllocatorInterface {
	public:
	FFLiBufferAllocator allocator;
	
	FFLiBufferAllocatorForZlib(void *buffer, u32 size);
	
	~FFLiBufferAllocatorForZlib();
	void Allocate(u32);
	void vf1C();
	void Free(void *);
};

class FFLiZlibAllocator {
	public:
	FFLiAllocatorInterface *interface;
	
	FFLiZlibAllocator(FFLiAllocatorInterface *);
};

class FFLiZlibInterface {
	public:
	virtual ~FFLiZlibInterface() = 0;
	virtual void Process(void **, u32 *, const void **, u32 *, int) = 0;
	virtual void vf1C() = 0; //deleted
	virtual void vf24() = 0; //deleted
};

class FFLiZlibInflator : public FFLiZlibInterface {
	public:
	FFLiZlibAllocator allocator;
	z_stream stream;
	u32 _40;
	
	FFLiZlibInflator(FFLiAllocatorInterface *, int windowBits);
	
	~FFLiZlibInflator();
	void Process(void **, u32 *, const void **, u32 *, int);
	void vf1C();
	void vf24();
};
