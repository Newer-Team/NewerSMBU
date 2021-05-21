
#include "cafe.h"
#include "nn.h"
#include "globals.h"
#include "socketstuff.h"
#include "exceptionhandlers.h"
 
extern char SAVEOpenFile;
extern int (* const entry_point)(int argc, char *argv[]);
 
#define main (*entry_point)

void Patch(char *buffer) {
    u16 count = *(u16 *)buffer; buffer += 2;
    for (u16 i = 0; i < count; i++) {
        u16 bytes = *(u16 *)buffer; buffer += 2;
        u32 addr = *(u32 *)buffer; buffer += 4;
        for (u16 j = 0; j < bytes; j++) {
            *((u8 *)addr) = *(u8 *)buffer;
            buffer += 1;
            addr += 1;
        }
    }
}

void memcpy(char *dst, char *src, u32 length) {
	for (u32 i = 0; i < length; i++) {
		*dst++ = *src++;
	}
}

#define Acquire(module) \
	OSDynLoad_ModuleHandle module; \
	OSDynLoad_Acquire(#module ".rpl", &module);
	
#define Import(module, function) \
	function ##_t function; \
	OSDynLoad_FindExport(module, 0, #function, &function);
	
#define Import2(module, function, name) \
	name ##_t name; \
	OSDynLoad_FindExport(module, 0, #function, &name);
 
int _main(int argc, char *argv[]) {
	Acquire(coreinit)
	Acquire(nsysnet)
	
	Import(coreinit, OSAllocFromSystem)
	Import(coreinit, OSFatal)
	Import(coreinit, OSFreeToSystem)
	Import(coreinit, OSSetExceptionCallback)
	Import(coreinit, __os_snprintf)
	
	Import2(nsysnet, socket_lib_init, SOInit)
	Import2(nsysnet, socket, SOSocket)
	Import2(nsysnet, connect, SOConnect)
	Import2(nsysnet, recv, SORecv)
	Import2(nsysnet, send, SOSend)
	Import2(nsysnet, socketclose, SOClose)
	Import2(nsysnet, socket_lib_finish, SOFinish)
	
	globals.__os_snprintf = __os_snprintf;
	globals.SOInit = SOInit;
	globals.SOSocket = SOSocket;
	globals.SOConnect = SOConnect;;
	globals.SORecv = SORecv;
	globals.SOSend = SOSend;
	globals.SOClose = SOClose;
	globals.SOFinish = SOFinish;
     
    OSSetExceptionCallback(OS_EXCEPTION_DSI, &DSIHandler);
    OSSetExceptionCallback(OS_EXCEPTION_ISI, &ISIHandler);
    OSSetExceptionCallback(OS_EXCEPTION_PROGRAM, &ProgramHandler);
	
	SOInit();
	int fd = SOSocket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	struct sockaddr serverAddr;
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = 2557;
	//serverAddr.sin_addr = (192 << 24) | (168 << 16) | (178 << 8) | 188; //Kinnay
	serverAddr.sin_addr = (10 << 24) | 89; //newluigidev
	SOConnect(fd, &serverAddr, 16);
	globals.fd = fd;
	
	SOSend(fd, "\x01", 1, 0);
	
	u32 length;
	SOSend(fd, "\x80", 1, 0);
	SORecv(fd, &length, 4, 0);
	receiveFile((char *)DATA_ADDR, length);
	Patch((char *)DATA_ADDR);
	
	SOSend(fd, "\x81", 1, 0);
	SORecv(fd, &length, 4, 0);
	receiveFile((char *)DATA_ADDR, length);
	memcpy((char *)(0xA0000000 + CODE_ADDR), (char *)DATA_ADDR, length);
	
	SOSend(fd, "\x82", 1, 0);
	SORecv(fd, &length, 4, 0);
	receiveFile((char *)DATA_ADDR, length);

	SOSend(fd, "\x83", 1, 0);
	SORecv(fd, &length, 4, 0);
	receiveFile((char *)(DATA_ADDR + 0x10000), length);
	globals.fileList = (char *)(DATA_ADDR + 0x10000);
	
	SOSend(fd, "\x84", 1, 0);
	SORecv(fd, &length, 4, 0);
	receiveFile((char *)(DATA_ADDR + 0x20000), length);
	globals.ctorList = (char *)(DATA_ADDR + 0x20000);
 
    *(u32 *)(0xA0000000 + &SAVEOpenFile + 0x1C) = 0x3D80011D; //lis r12, (0x011DD020)@h
    *(u32 *)(0xA0000000 + &SAVEOpenFile + 0x20) = 0x618CD020; //ori r12, r12, (0x011DD020)@l
    *(u32 *)(0xA0000000 + &SAVEOpenFile + 0x24) = 0x7D8903A6; //mtctr r12
    *(u32 *)(0xA0000000 + &SAVEOpenFile + 0x28) = 0x4E800420; //bctr

    globals.file = 0;
    globals.initialized = 0x1357;
     
    return main(argc, argv);
}