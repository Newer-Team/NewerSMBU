
#pragma once

extern "C" {

	#define ZLIB_VERSION "1.2.5"

	#define Z_FINISH 4

	typedef unsigned char Byte;
	typedef unsigned int uInt;
	typedef unsigned long uLong;

	typedef void *(*alloc_func)(void *opaque, uInt items, uInt size);
	typedef void  (* free_func)(void *opaque, void *address);

	struct internal_state;

	struct z_stream {
		Byte *next_in;
		uInt avail_in;
		uLong total_in;
		
		Byte *next_out;
		uInt avail_out;
		uLong total_out;
		
		char *msg;
		internal_state *state;
		
		alloc_func zalloc;
		free_func zfree;
		void *opaque;
		
		int data_type;
		uLong adler;
		uLong reserved;
	};

	int inflateInit_(z_stream *strm, const char *version, int stream_size);
	int inflateInit2_(z_stream *strm, int windowBits, const char *version, int stream_size);
	int inflate(z_stream *strm, int flush);
	int inflateEnd(z_stream *strm);

	#define inflateInit(strm) inflateInit_((strm), ZLIB_VERSION, sizeof(z_stream))
	#define inflateInit2(strm, windowBits) inflateInit2_((strm), (windowBits), ZLIB_VERSION, sizeof(z_stream))
	
}