
#pragma once

#include "states.h"
#include "enums.h"

class MovementHandler {
	public:
		Vec3 position;
		Vec3 _C;
		Vec3 _18;
		Vec3 _24;
		u8 _30[8];
		u32 _38;
		u8 _3C[20];
		u32 zRotation;
		u8 _54[12];
		u8 _60[8];
		u8 _68[8];
		u32 _70;
		u32 _74;
		u32 _78;
		u32 _7C;
		u32 _80;
		u8 _84[0x1C];
		u32 _A0;
		u32 _A4;
		u32 _A8;
		u8 _AC[24];
		u8 _C4[12];
		u32 _D0;
		StateMgrBase<MovementHandler> state;
	
		MovementHandler();
	
		u32 getMaskForMovementType(MovementType type);
		void linkToMovementController(Vec3 *actorPos, u32 typeMask, u8 movementId);
		void execute();
};
