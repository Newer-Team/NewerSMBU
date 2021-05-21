
#include "cafe.h"

#include "Code.h"

#define INSTALL_ADDR  0x011DD000
#define MAIN_JMP_ADDR 0x0101C56C

#define FSOpenFile 0x0106F9C4
#define FSCloseFile 0x0106FAD0
#define FSReadFile 0x0106FB50
#define FSWriteFile 0x0106FC70
#define FSSetPosFile 0x0106FF78
#define FSGetStatFile 0x0106FFE8
#define FSGetStat 0x01070810

#define KERN_SYSCALL_TBL_GAME 0xFFE85070
#define KERN_SYSCALL_TBL_MENU 0xFFEAAA60
#define KERN_CODE_READ 0xFFF023D4
#define KERN_CODE_WRITE 0xFFF023F4
#define KERN_ADDRESS_TBL 0xFFEAB7A0

void memcpy(void* dst, const void* src, u32 size) {
	for (u32 i = 0; i < size; i++) {
		*((u8 *)dst + i) = *((const u8 *)src + i);
	}
}

u32 doB(u32 dst, u32 src) {
	u32 instr = (dst - src);
	instr &= 0x03FFFFFC;
	instr |= 0x48000000;
	return instr;
}

u32 doBL(u32 dst, u32 src) {
	u32 instr = (dst - src);
	instr &= 0x03FFFFFC;
	instr |= 0x48000001;
	return instr;
}

void insertBranchL(u32 addr, u32 target, DCFlushRange_t DCFlushRange, ICInvalidateRange_t ICInvalidateRange) {
	u32 *loc = (u32 *)(0xA0000000 + addr);
	*loc = doBL(target, addr);
	DCFlushRange((u32 *)((u32)loc & ~0x1F), 0x20);
	ICInvalidateRange((u32 *)((u32)loc & ~0x1F), 0x20);
}

void insertBranch(u32 addr, u32 target, DCFlushRange_t DCFlushRange, ICInvalidateRange_t ICInvalidateRange) {
	u32 *loc = (u32 *)(0xA0000000 + addr);
	*loc = doB(target, addr);
	DCFlushRange((u32 *)((u32)loc & ~0x1F), 0x20);
	ICInvalidateRange((u32 *)((u32)loc & ~0x1F), 0x20);
}

void kern_write(u32 addr, u32 value) {
	asm(
		"stwu 1, -0x20(1)\n"
		"mflr 0\n"
		"stw 0, 0x24(1)\n"
		"stw 29, 0x14(1)\n"
		"stw 30, 0x18(1)\n"
		"stw 31, 0x1C(1)\n"
		"mr 31, 1\n"
		"stw 3, 8(31)\n"
		"stw 4, 0xC(31)\n"
		"lwz 30, 8(31)\n"
		"lwz 29, 0xC(31)\n"
		"li 3, 1\n"
		"li 4, 0\n"
		"mr 5, 29\n"
		"li 6, 0\n"
		"li 7, 0\n"
		"lis 8, 1\n"
		"mr 9, 30\n"
		"mr 29, 1\n"
		"li 0, 0x3500\n"
		"sc\n"
		"nop\n"
		"mr 1, 29\n"
		"addi 11, 31, 0x20\n"
		"lwz 0, 4(11)\n"
		"mtlr 0\n"
		"lwz 29, -0xC(11)\n"
		"lwz 30, -8(11)\n"
		"lwz 31, -4(11)\n"
		"mr 1, 11\n"
	);
}

void ShowScreenMessage(char *message) {
	OSDynLoad_ModuleHandle coreinit;
	OSDynLoad_ModuleHandle vpad;
	OSDynLoad_Acquire("coreinit.rpl", &coreinit);
	OSDynLoad_Acquire("vpad.rpl", &vpad);
	
	_Exit_t _Exit;
	OSScreenInit_t OSScreenInit;
	OSScreenGetBufferSizeEx_t OSScreenGetBufferSizeEx;
	OSScreenSetBufferEx_t OSScreenSetBufferEx;
	OSScreenEnableEx_t OSScreenEnableEx;
	OSScreenClearBufferEx_t OSScreenClearBufferEx;
	OSScreenPutFontEx_t OSScreenPutFontEx;
	OSScreenFlipBuffersEx_t OSScreenFlipBuffersEx;
	OSDynLoad_FindExport(coreinit, 0, "_Exit", &_Exit);
	OSDynLoad_FindExport(coreinit, 0, "OSScreenInit", &OSScreenInit);
	OSDynLoad_FindExport(coreinit, 0, "OSScreenGetBufferSizeEx", &OSScreenGetBufferSizeEx);
	OSDynLoad_FindExport(coreinit, 0, "OSScreenSetBufferEx", &OSScreenSetBufferEx);
	OSDynLoad_FindExport(coreinit, 0, "OSScreenEnableEx", &OSScreenEnableEx);
	OSDynLoad_FindExport(coreinit, 0, "OSScreenClearBufferEx", &OSScreenClearBufferEx);
	OSDynLoad_FindExport(coreinit, 0, "OSScreenPutFontEx", &OSScreenPutFontEx);
	OSDynLoad_FindExport(coreinit, 0, "OSScreenFlipBuffersEx", &OSScreenFlipBuffersEx);
	
	VPADRead_t VPADRead;
	OSDynLoad_FindExport(vpad, 0, "VPADRead", &VPADRead);

	OSScreenInit();
	u32 bufsize = OSScreenGetBufferSizeEx(0);
	OSScreenSetBufferEx(0, (void *)0xF4000000);
	OSScreenSetBufferEx(1, (void *)0xF4000000 + bufsize);
	OSScreenEnableEx(0, 1);
	OSScreenEnableEx(1, 1);
	OSScreenClearBufferEx(0, 0);
	OSScreenClearBufferEx(1, 0);
	OSScreenPutFontEx(0, 0, 0, message);
	OSScreenPutFontEx(1, 0, 0, message);
	OSScreenFlipBuffersEx(0);
	OSScreenFlipBuffersEx(1);
	
	OSDynLoad_ModuleHandle sysapp;
	OSDynLoad_Acquire("sysapp.rpl", &sysapp);
	SYSLaunchMenu_t SYSLaunchMenu;
	OSDynLoad_FindExport(sysapp, 0, "SYSLaunchMenu", &SYSLaunchMenu);
	
	VPADStatus gamepadData;
	s32 gamepadError;
	while (true) {
		VPADRead(0, &gamepadData, 1, &gamepadError);
		
		if (gamepadData.trig & VPAD_BUTTON_HOME) {
			//SYSLaunchMenu();
			_Exit();
		}
	}
}

void _main() {
	OSDynLoad_ModuleHandle coreinit;
	OSDynLoad_Acquire("coreinit.rpl", &coreinit);
	
	DCFlushRange_t DCFlushRange;
	ICInvalidateRange_t ICInvalidateRange;
	OSEffectiveToPhysical_t OSEffectiveToPhysical;
	OSFatal_t OSFatal;
	_Exit_t _Exit;
	OSDynLoad_FindExport(coreinit, 0, "DCFlushRange", &DCFlushRange);
	OSDynLoad_FindExport(coreinit, 0, "ICInvalidateRange", &ICInvalidateRange);
	OSDynLoad_FindExport(coreinit, 0, "OSEffectiveToPhysical", &OSEffectiveToPhysical);
	OSDynLoad_FindExport(coreinit, 0, "OSFatal", &OSFatal);
	OSDynLoad_FindExport(coreinit, 0, "_Exit", &_Exit);
	
	if (OSEffectiveToPhysical((void*)0xA0000000) == 0) {
		ShowScreenMessage("You didn't execute the kernel exploit.\nPress the home button to exit.");
	}

	u32 codehandlerLoc = 0xA0000000 + INSTALL_ADDR;	
	memcpy((void *)codehandlerLoc, Code_bin, Code_bin_len);
	DCFlushRange((const void *)codehandlerLoc, Code_bin_len);
	ICInvalidateRange((const void *)codehandlerLoc, Code_bin_len);
		
	insertBranchL(MAIN_JMP_ADDR, INSTALL_ADDR, DCFlushRange, ICInvalidateRange);
	insertBranch(FSOpenFile + 0x28, INSTALL_ADDR + 4, DCFlushRange, ICInvalidateRange);
	insertBranch(FSReadFile + 0x30, INSTALL_ADDR + 8, DCFlushRange, ICInvalidateRange);
	insertBranch(FSWriteFile + 0x30, INSTALL_ADDR + 0xC, DCFlushRange, ICInvalidateRange);
	insertBranch(FSCloseFile + 0x2C, INSTALL_ADDR + 0x10, DCFlushRange, ICInvalidateRange);
	insertBranch(FSGetStat + 0x24, INSTALL_ADDR + 0x14, DCFlushRange, ICInvalidateRange);
	insertBranch(FSGetStatFile + 0x24, INSTALL_ADDR + 0x18, DCFlushRange, ICInvalidateRange);
	insertBranch(FSSetPosFile + 0x24, INSTALL_ADDR + 0x1C, DCFlushRange, ICInvalidateRange);
	
	kern_write(KERN_SYSCALL_TBL_GAME + 0x34 * 4, KERN_CODE_READ);
	kern_write(KERN_SYSCALL_TBL_GAME + 0x35 * 4, KERN_CODE_WRITE);
	kern_write(KERN_SYSCALL_TBL_MENU + 0x34 * 4, KERN_CODE_READ);
	kern_write(KERN_SYSCALL_TBL_MENU + 0x35 * 4, KERN_CODE_WRITE);
	
	kern_write(KERN_ADDRESS_TBL + 0x48, 0x80000000);
	kern_write(KERN_ADDRESS_TBL + 0x4C, 0x28305800);
	
	_Exit();
}
