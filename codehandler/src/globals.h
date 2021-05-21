
#include "cafe.h"

struct global_vars {
	u32 initialized;
	
	FSFileHandle file;
	
	int fd;
	SOInit_t SOInit;
	SOSocket_t SOSocket;
	SOConnect_t SOConnect;
	SOSend_t SOSend;
	SORecv_t SORecv;
	SOClose_t SOClose;
	SOFinish_t SOFinish;
	__os_snprintf_t __os_snprintf;
	
	char * fileList;
	char * ctorList;
	
	char * crashMessage;
	OSContext *crashContext;
	u32 crashAddr;
};

extern global_vars globals;
