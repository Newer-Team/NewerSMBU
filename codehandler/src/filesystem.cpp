
#include "cafe.h"
#include "globals.h"
#include "socketstuff.h"

u32 strlen(const char *str) {
	u32 len = 0;
	while (*str != 0) {
		str++;
		len++;
	}
	return len;
}

bool compare(const char * s1, const char * s2, u8 length) {
	for (int i = 0; i < length; i++) {
		if (*(s1 + i) != *(s2 + i)) {
			return false;
		}
	}
	return true;
}

bool isServerFile(const char * path) {
	u32 pathLength = strlen(path);
	char * fileList = globals.fileList;
	u32 count = *(u32 *)fileList; fileList += 4;
	for (int i = 0; i < count; i++) {
		u8 fplength = *fileList; fileList += 1;
		if (fplength == pathLength) {
			if (compare(fileList, path, fplength)) {
				return true;
			};
		}
		fileList += fplength;
	}
	return false;
}

bool getStat(FSClient *client, FSCmdBlock *block,
			const char *path, FSStat *returnedStat,
			FSRetFlag errHandling)
{
	returnedStat->flag = 0;
	return !isServerFile(path);
}

void checkFileHandle() {
	if (globals.file != 0) {
		globals.SOSend(globals.fd, "\xFF", 1, 0);
		OSDynLoad_ModuleHandle coreinit;
		OSDynLoad_Acquire("coreinit.rpl", &coreinit);
		
		OSFatal_t OSFatal;
		OSDynLoad_FindExport(coreinit, 0, "OSFatal", &OSFatal);
		OSFatal("Blarg");
	}
}

bool getStatFile(FSClient *client, FSCmdBlock *block,
				 FSFileHandle fileHandle, FSStat *returnedStat,
				 FSRetFlag errHandling) {
	if (globals.file == fileHandle) {
		int fd = globals.fd;
		globals.SOSend(fd, "\x08", 1, 0);		
		globals.SOSend(fd, &fileHandle, 4, 0);
		
		globals.SORecv(fd, &returnedStat->size, 4, 0);
		return 0;
	}
	return 1;
}

bool setPosFile(FSClient *client, FSCmdBlock *block,
				FSFileHandle fileHandle, FSFilePosition fpos,
				FSRetFlag errHandling) {
	if (fileHandle != globals.file) {
		return 1;
	}

	int fd = globals.fd;
	globals.SOSend(fd, "\x09", 1, 0);
	globals.SOSend(fd, &fileHandle, 4, 0);
	globals.SOSend(fd, &fpos, 4, 0);
	return 0;
}

bool openSave(FSClient *client, FSCmdBlock *block,
			  u8 accountSlotNo, const char *path,
			  const char *mode,
			  FSFileHandle *fileHandle,
			  FSRetFlag errHandling)
{
	checkFileHandle();
	
	int fd = globals.fd;
	globals.SOSend(fd, "\x06", 1, 0);
	
	u32 length = strlen(path);
	globals.SOSend(fd, &length, 4, 0);
	globals.SOSend(fd, path, length, 0);
	globals.SOSend(fd, mode, 1, 0);
	
	u32 handle;
	globals.SORecv(fd, &handle, 4, 0);

	if (handle != 0) {
		globals.file = handle;
		*fileHandle = handle;
		return 0;
	}
	return 1;
}

bool openFile(FSClient *client, FSCmdBlock *block,
				  const char *path, const char *mode,
				  FSFileHandle *fileHandle,
				  FSRetFlag errHandling)
{
	if (!isServerFile(path)) {
		return 1;
	}

	checkFileHandle();

	int fd = globals.fd;
	globals.SOSend(fd, "\x02", 1, 0);
	
	u32 length = strlen(path);
	globals.SOSend(fd, &length, 4, 0);
	globals.SOSend(fd, path, length, 0);
	
	u32 handle;
	globals.SORecv(fd, &handle, 4, 0);
	
	globals.file = handle;
	*fileHandle = handle;
	return 0;
}

int readFile(FSClient *client, FSCmdBlock *block,
				  char *dest, FSSize size, FSCount count,
				  FSFileHandle fileHandle, FSFlag flag,
				  FSRetFlag errHandling)
{
	if (fileHandle != globals.file) {
		return -1;
	}
	
	int fd = globals.fd;
	globals.SOSend(fd, "\x03", 1, 0);
	globals.SOSend(fd, &fileHandle, 4, 0);
	globals.SOSend(fd, &size, 4, 0);
	globals.SOSend(fd, &count, 4, 0);

	u32 filesize;
	u32 elementsRead;
	globals.SORecv(fd, &elementsRead, 4, 0);
	globals.SORecv(fd, &filesize, 4, 0);
	receiveFile(dest, filesize);
	
	return elementsRead;
}

bool writeFile(FSClient *client, FSCmdBlock *block,
			   char *source, FSSize size, FSCount count,
			   FSFileHandle fileHandle, FSFlag flag,
			   FSRetFlag errHandling)
{
	if (fileHandle != globals.file) {
		return 1;
	}
	
	int fd = globals.fd;
	u32 length = size * count;
	globals.SOSend(fd, "\x04", 1, 0);
	globals.SOSend(fd, &fileHandle, 4, 0);
	globals.SOSend(fd, &length, 4, 0);
	
	sendFile(source, length);

	return 0;
}

bool closeFile(FSClient *client, FSCmdBlock *block,
			   FSFileHandle fileHandle,
			   FSRetFlag errHandling)
{
	if (fileHandle != globals.file) {
		return 1;
	}
	
	int fd = globals.fd;
	globals.SOSend(fd, "\x05", 1, 0);
	globals.SOSend(fd, &fileHandle, 4, 0);
	globals.file = 0;
	return 0;
}
