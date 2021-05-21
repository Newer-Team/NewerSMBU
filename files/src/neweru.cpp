
#include <stdio.h>
#include "game.h"
#include "neweru.h"
#include "../codehandler/src/globals.h"

ActorFiles::ActorFiles(Actors actorId, u8 count, const sead::String files[]) {
	fileCounts[actorId] = count;
	fileLists[actorId] = files;
}

void copyTilesInLocation(Location *loc, float x, float y, u8 layer, bool destroy) {
	u8 rows = (loc->w >> 4) + 1;
	u8 cols = (loc->h >> 4) + 1;
	
	for (int row = 0; row < rows; row++) {
		for (int column = 0; column < cols; column++) {
			u16 *dst = TileMgr::instance->getTilePointer(x + row * 16, -y + column * 16, layer, 0);
			if (destroy) {
				*dst = 0xFFFF;
			}
			else {
				u16 *src = TileMgr::instance->getTilePointer(loc->x + row * 16, loc->y + column * 16, 0, 0);
				*dst = *src;
			}
		}
	}
}

int snprintf(char *buffer, u32 length, const char *string, ...) {
	va_list args;
	va_start(args, string);
	int ret = vsnprintf(buffer, length, string, args);
	va_end(args);
	return ret;
}

void sendall(const char *buffer, u32 length) {
	u32 bytes = 0;
	while (bytes < length) {
		u32 num = globals.SOSend(globals.fd, buffer, length - bytes, 0);
		buffer += num;
		bytes += num;
	}
}

void DEBUG(const char *message) {
	globals.SOSend(globals.fd, "\x07", 1, 0);
	u32 length = __ghs_strlen(message);
	globals.SOSend(globals.fd, &length, 4, 0);
	globals.SOSend(globals.fd, message, length, 0);
}

void DEBUG_FMT(const char *message, ...) {
	/*The internet says to use vsnprintf(NULL, 0, fmt, args)
	to get the buffer length. However, vsnprintf seems to
	corrupt the va_list, and even va_copy doesn't fix it.*/
	va_list args;
	va_start(args, message);
	char buffer[0x1000];
	vsnprintf(buffer, 0x1000, message, args);
	DEBUG(buffer);
	va_end(args);
}

void DEBUG_FILE(const char *filename, const char *buffer, u32 length) {
	globals.SOSend(globals.fd, "\x0B", 1, 0);
	
	u32 fnlength = __ghs_strlen(filename);
	globals.SOSend(globals.fd, &fnlength, 4, 0);
	globals.SOSend(globals.fd, &length, 4, 0);
	globals.SOSend(globals.fd, filename, fnlength, 0);
	sendall(buffer, length);
}
