
#include "cafe.h"
#include "globals.h"

bool isValidStackPtr(u32 sp) {
	return 0x10000000 <= sp && sp < 0x12000000;
}

void ReportCrash(const char *message, OSContext *context) {
	u32 sp = context->gpr[1];
	
	char buffer[1000];
	int length = globals.__os_snprintf(buffer, 1000,
		"\n%s\n"
		"Please report the info below to http://rhcafe.us.to/ in detail\n"
		"r0 :%08X r1 :%08X r2 :%08X r3 :%08X r4 :%08X\n"
		"r5 :%08X r6 :%08X r7 :%08X r8 :%08X r9 :%08X\n"
		"r10:%08X r11:%08X r12:%08X r13:%08X r14:%08X\n"
		"r15:%08X r16:%08X r17:%08X r18:%08X r19:%08X\n"
		"r20:%08X r21:%08X r22:%08X r23:%08X r24:%08X\n"
		"r25:%08X r26:%08X r27:%08X r28:%08X r29:%08X\n"
		"r30:%08X r31:%08X\n"
		"CR :%08X LR :%08X CTR:%08X XER:%08X\n"
		"SSR0:%08X SRR1:%08X EX0:%08X EX1:%08X\n"
		"Press the home button to exit",
		message,
		context->gpr[0],
		context->gpr[1],
		context->gpr[2],
		context->gpr[3],
		context->gpr[4],
		context->gpr[5],
		context->gpr[6],
		context->gpr[7],
		context->gpr[8],
		context->gpr[9],
		context->gpr[10],
		context->gpr[11],
		context->gpr[12],
		context->gpr[13],
		context->gpr[14],
		context->gpr[15],
		context->gpr[16],
		context->gpr[17],
		context->gpr[18],
		context->gpr[19],
		context->gpr[20],
		context->gpr[21],
		context->gpr[22],
		context->gpr[23],
		context->gpr[24],
		context->gpr[25],
		context->gpr[26],
		context->gpr[27],
		context->gpr[28],
		context->gpr[29],
		context->gpr[30],
		context->gpr[31],
		context->cr,
		context->lr,
		context->ctr,
		context->xer,
		context->srr0,
		context->srr1,
		context->exception_specific0,
		context->exception_specific1
	);

	globals.SOSend(globals.fd, "\x0A", 1, 0);
	globals.SOSend(globals.fd, &length, 4, 0);
	globals.SOSend(globals.fd, buffer, length, 0);

	u32 stacktrace[30];
	u32 frameCount = 0;
	if (isValidStackPtr(sp)) {
		for (int i = 0; i < 30; i++) {
			sp = *(u32 *)sp;
			if (!isValidStackPtr(sp)) break;
			u32 lr = *(u32 *)(sp + 4);
			stacktrace[i] = lr;
			frameCount++;
		}
	}
	
	globals.SOSend(globals.fd, &frameCount, 4, 0);
	globals.SOSend(globals.fd, stacktrace, frameCount * 4, 0);
}

void HandleCrash() {
	globals.crashContext->srr0 = globals.crashAddr;
	ReportCrash(globals.crashMessage, globals.crashContext);
	
	OSDynLoad_ModuleHandle sysapp;
	OSDynLoad_ModuleHandle vpad;
	OSDynLoad_Acquire("sysapp.rpl", &sysapp);
	OSDynLoad_Acquire("vpad.rpl", &vpad);
	
	SYSLaunchMenu_t SYSLaunchMenu;
	OSDynLoad_FindExport(sysapp, 0, "SYSLaunchMenu", &SYSLaunchMenu);
	
	VPADRead_t VPADRead;
	OSDynLoad_FindExport(vpad, 0, "VPADRead", &VPADRead);
	
	OSDynLoad_ModuleHandle coreinit;
	OSDynLoad_Acquire("coreinit.rpl", &coreinit);
	OSSleepTicks_t OSSleepTicks;
	OSGetSystemInfo_t OSGetSystemInfo;
	OSDynLoad_FindExport(coreinit, 0, "OSSleepTicks", &OSSleepTicks);
	OSDynLoad_FindExport(coreinit, 0, "OSGetSystemInfo", &OSGetSystemInfo);
	
	VPADStatus gamepadData;
	s32 gamepadError;
	while (true) {
		VPADRead(0, &gamepadData, 1, &gamepadError);
		
		if (gamepadData.trig & VPAD_BUTTON_HOME) {
			SYSLaunchMenu();
			OSSleepSeconds(1);
		}
	}
}

bool DSIHandler(OSContext *context) {
	globals.crashMessage = "A DSI exception occurred!";
	globals.crashContext = context;
	globals.crashAddr = context->srr0;
	context->srr0 = (u32) &HandleCrash;
	return 1;
}

bool ISIHandler(OSContext *context) {
	globals.crashMessage = "An ISI exception occurred!";
	globals.crashContext = context;
	globals.crashAddr = context->srr0;
	context->srr0 = (u32) &HandleCrash;
	return 1;
}

bool ProgramHandler(OSContext *context) {
	globals.crashMessage = "A program exception occurred!";
	globals.crashContext = context;
	globals.crashAddr = context->srr0;
	context->srr0 = (u32) &HandleCrash;
	return 1;
}
