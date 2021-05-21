
#pragma once

#include "types.h"
#include "common.h"
#include "gx2.h"

typedef void * OSDynLoad_ModuleHandle;

#define OSDynLoad_Acquire ((int (*)(char const *apBaseModuleName, OSDynLoad_ModuleHandle *apRetHandle))0x0102A3B4)
#define OSDynLoad_FindExport ((int (*)(OSDynLoad_ModuleHandle aModuleHandle, int aTypeIsData, char const *apExportName, void *appRetAddr))0x0102B828)

struct OSMutex;

struct OSThread {
	//....
};

struct OSThreadQueue {
	OSThread *head;
	OSThread *tail;
	void *parent_struct;
	u32 reserved;
};

struct OSMutexLink {
	OSMutex *next;
	OSMutex *prev;
};

struct OSMutex {
	u32 txtTag;
	char *name;
	u32 reserved;
	
	OSThreadQueue queue;
	OSThread *thread;
	s32 count;
	OSMutexLink link;
};

struct OSContext {
	char tag[8];
	
	u32 gpr[32];
	
	u32 cr;
	u32 lr;
	u32 ctr;
	u32 xer;
	
	u32 srr0;
	u32 srr1;
	
	u32 exception_specific0;
	u32 exception_specific1;
	
	//......
};

#define OS_EXCEPTION_DSI 2
#define OS_EXCEPTION_ISI 3
#define OS_EXCEPTION_PROGRAM 6
typedef u8 OSExceptionType;
typedef bool (*OSExceptionCallback)(OSContext *context);

typedef s64 OSTime;

#define MAX_SYSTEM_CORES 3

typedef struct OSSystemInfo
{
    u32     busClockSpeed;
    u32     coreClockSpeed;
    OSTime  timeBase;
    u32     L2Size[MAX_SYSTEM_CORES];
    u32     cpuFreqRatio;
} OSSystemInfo;

#define OS_BUS_CLOCK (OSGetSystemInfo()->busClockSpeed)
#define OS_TIMER_CLOCK (OS_BUS_CLOCK/4)
#define OSSecondsToTicks(sec) ((sec) * OS_TIMER_CLOCK)
#define OSSleepSeconds(sec) OSSleepTicks(OSSecondsToTicks((OSTime)sec))

typedef void  (*DCFlushRange_t)(const void* addr, u32 nBytes);
typedef void  (*DisassemblePPCRange_t)(void *start, void *end, void *printf_func, int *find_symbol_func, int flags);
typedef void  (*ICInvalidateRange_t)(const void* addr, u32 nBytes);
typedef int   (*IM_Close_t)(int fd);
typedef int   (*IM_Open_t)();
typedef int   (*IM_SetDeviceState_t)(int fd, void* mem, int state, int a, int b);
typedef void* (*OSAllocFromSystem_t)(u32 size, int align);
typedef void* (*OSEffectiveToPhysical_t)(const void* addr);
typedef void  (*OSFatal_t)(const char* msg);
typedef void  (*OSFreeToSystem_t)(void *ptr);
typedef OSSystemInfo * (*OSGetSystemInfo_t)();
typedef void  (*OSScreenClearBufferEx_t)(u8 screen, u32 color);
typedef void  (*OSScreenEnableEx_t)(u8 screen, bool enabled);
typedef void  (*OSScreenFlipBuffersEx_t)(u8 screen);
typedef u32   (*OSScreenGetBufferSizeEx_t)(u8 screen);
typedef void  (*OSScreenInit_t)();
typedef void  (*OSScreenPutFontEx_t)(u8 screen, u32 x, u32 y, char *text);
typedef void  (*OSScreenSetBufferEx_t)(u8 screen, void *ptr);
typedef void  (*OSSetExceptionCallback_t)(OSExceptionType type, OSExceptionCallback cb);
typedef void  (*OSSleepTicks_t)(OSTime ticks);
typedef void  (*_Exit_t)();
typedef int   (*__os_snprintf_t)(char *buffer, int size, char *fmt, ... );

typedef void (*OSYieldThread_t)();


#define FS_CLIENT_BUFFER_SIZE 5888
#define FS_CMD_BLOCK_SIZE 2688
#define FS_STAT_ATTRIBUTES_SIZE 48

typedef struct {
	u8 buffer[FS_CLIENT_BUFFER_SIZE];
} FSClient;

typedef struct {
	u8 buffer[FS_CMD_BLOCK_SIZE];
} FSCmdBlock;

typedef s32 FSStatus;
typedef s32 FSFileHandle;
typedef u32 FSSize;
typedef u64 FSBSize;
typedef u32 FSCount;
typedef u32 FSFlag;
typedef u32 FSRetFlag;
typedef u32 FSMode;
typedef u32 FSFilePosition;
typedef u64 FSTime;
typedef u32 FSUserId;
typedef u32 FSGroupId;

typedef struct {
	FSFlag flag;
	FSMode permission;
	FSUserId owner_id;
	FSGroupId group_id;
	FSSize size;
	FSSize alloc_size;
	FSBSize quota_size;
	u32 ent_id;
	FSTime ctime;
	FSTime mtime;
	u8 attributes[FS_STAT_ATTRIBUTES_SIZE];
} FSStat;

typedef void     (*FSInit_t)();
typedef FSStatus (*FSAddClient_t)(FSClient *client, FSRetFlag errHandling);
typedef FSStatus (*FSInitCmdBlock_t)(FSCmdBlock *block);
typedef FSStatus (*FSReadFile_t)(FSClient *client, FSCmdBlock *block, void *dest, FSSize size, FSCount count, FSFileHandle fileHandle, FSFlag flag, FSRetFlag errHandling);
typedef FSStatus (*FSCloseFile_t)(FSClient *client, FSCmdBlock *block, FSFileHandle fileHandle, FSRetFlag errHandling);


typedef struct SysStandardArgsIn
{
	const char * cp_Anchor;
	u32 anchorSize;
} SysStandardArgsIn;

typedef enum SysSettingsJumpTo
{
	SYS_SETTINGS_JUMP_TO_TOP = 0,
	SYS_SETTINGS_JUMP_TO_INTERNET,
	SYS_SETTINGS_JUMP_TO_DATA_MANAGE,
	SYS_SETTINGS_JUMP_TO_TV_REMOTE,
	SYS_SETTINGS_JUMP_TO_DATE_TIME,
	SYS_SETTINGS_JUMP_TO_COUNTRY,
	SYS_SETTINGS_JUMP_TO_UPDATE
} SysSettingsJumpTo;

typedef struct SysSettingsArgsIn
{
	SysStandardArgsIn stdIn;
	SysSettingsJumpTo jumpTo;
} SysSettingsArgsIn;

typedef u64 (*SYSGetCallerTitleId_t)();
typedef s32 (*SYSLaunchMenu_t)();
typedef s32 (*SYSLaunchSettings_t)(const SysSettingsArgsIn *cp_Args);
typedef s32 (*SYSRelaunchTitle_t)(u32 argc, char *pa_Argv[]);


#define AF_INET 2
#define SOCK_STREAM 1
#define IPPROTO_TCP 6

#define SOL_SOCKET -1
#define SO_NBIO 0x1014

struct sockaddr {
	unsigned short sin_family;
	unsigned short sin_port;
	unsigned long sin_addr;
	char sin_zero[8];
};

typedef int socklen_t;

typedef int (*SOInit_t)();
typedef int (*SOSocket_t)(int family, int type, int proto);
typedef int (*SOSetSockOpt_t)(int s, int level, int optname, void *optval, socklen_t optlen);
typedef int (*SOConnect_t)(int fd, struct sockaddr *addr, int addrlen);
typedef int (*SORecv_t)(int fd, void *buffer, int len, int flags);
typedef int (*SOSend_t)(int fd, const void *buffer, int len, int flags);
typedef int (*SOClose_t)(int fd);
typedef int (*SOFinish_t)();
typedef int (*SOLastError_t)();


#define VPAD_BUTTON_HOME 0x2

typedef struct VPADDir {
    Vec3 X;
    Vec3 Y;
    Vec3 Z;
} VPADDir;

typedef struct {
	u16 x;
	u16 y;
	u16 touch;
	u16 validity;
} VPADTPData;

typedef struct VPADStatus {
	u32 hold;
	u32 trig;
	u32 release;
	
	Vec2 lStick;
	Vec2 rStick;
	
	Vec3 acc;
	float accValue;
	float accSpeed;
	Vec2 accVertical;
	
	Vec3 gyro;
	Vec3 angle;
	
	s8 vpadErr;
	
	VPADTPData tpData;
	VPADTPData tpFilteredData1;
	VPADTPData tpFilteredData2;
	
	VPADDir dir;
	
	bool headphoneStatus ;
	
	Vec3 magnet;
	
	u8 slideVolume;
	u8 batteryLevel;
	u8 micStatus;
	u8 slideVolumeCalibrated;
	u8 __paddings__[7];
} VPADStatus;

typedef s32 (*VPADRead_t)(s32 chan, VPADStatus samplingBufs[], u32 length, s32* err);
