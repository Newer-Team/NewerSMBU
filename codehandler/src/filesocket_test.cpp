
#include "globals.h"

#define MSG_DONTWAIT 0x20

void receiveFile(char * dest, u32 filesize) {
	OSDynLoad_ModuleHandle nsysnet;
	OSDynLoad_Acquire("nsysnet.rpl", &nsysnet);
	
	SOLastError_t SOLastError;
	OSDynLoad_FindExport(nsysnet, 0, "socketlasterr", &SOLastError);
	
	globals.SOSend(globals.fd, "\x07", 1, 0);
	globals.SOSend(globals.fd, "\x00\x00\x00\x0A", 4, 0);
	char buffer2[10];
	globals.__os_snprintf(buffer2, 10, "%i", filesize);
	globals.SOSend(globals.fd, buffer2, 10, 0);
	
	u32 bytes = 0;
	while (bytes < filesize) {
		u32 blarg;
		if ((filesize - bytes) < 0x400) {
			blarg = filesize - bytes;
		} else {
			blarg = 0x400;
		}
		globals.SOSend(globals.fd, "\x07", 1, 0);
		globals.SOSend(globals.fd, "\x00\x00\x00\x0A", 4, 0);
		char buffer3[10];
		globals.__os_snprintf(buffer3, 10, "%i", blarg);
		globals.SOSend(globals.fd, buffer3, 10, 0);
		
		u32 num = globals.SORecv(globals.fd, dest, blarg, MSG_DONTWAIT);
		
		globals.SOSend(globals.fd, "\x07", 1, 0);
		globals.SOSend(globals.fd, "\x00\x00\x00\x0A", 4, 0);
		char buffer4[10];
		globals.__os_snprintf(buffer4, 10, "%i", num);
		globals.SOSend(globals.fd, buffer4, 10, 0);
		
		if (num == 0xFFFFFFFF) {
			globals.SOSend(globals.fd, "\x07", 1, 0);
			globals.SOSend(globals.fd, "\x00\x00\x00\x09", 4, 0);
			char buffer[9];
			globals.__os_snprintf(buffer, 9, "%x", SOLastError());
			globals.SOSend(globals.fd, buffer, 9, 0);
		} else {
			bytes += num;
			dest += num;
		}
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
