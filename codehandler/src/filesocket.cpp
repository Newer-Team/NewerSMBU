
#include "globals.h"

void receiveFile(char * dest, u32 filesize) {
	u32 bytes = 0;
	while (bytes < filesize) {
		u32 num = globals.SORecv(globals.fd, dest, filesize - bytes, 0);
		bytes += num;
		dest += num;
	}
}

void sendFile(char * source, u32 filesize) {
	u32 bytes = 0;
	while (bytes < filesize) {
		u32 num = globals.SOSend(globals.fd, source, filesize - bytes, 0);
		bytes += num;
		source += num;
	}
}
