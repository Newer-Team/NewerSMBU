
#pragma once

#include "common.h"
#include "enums.h"
#include "effects.h"

class EffectHandler;

class EffectData {
	Mtx mtx;
	u8 _30;
	u8 _31;
	u8 _32;
	u8 _33;
	u32 _34;
	u32 _38;
	void *param;
};

struct EffectHandlerStruct {
	u32 _0;
	u32 _4;
	EffectHandler *handler;
	u32 _C;
};

class EffectHandler : public sead::IDisposer {
	public:
	EffectData effectData;
	EffectHandlerStruct struc;
	u32 effectId;
	u8 _64;
	
	EffectHandler();
	bool update(Effects effect, Mtx *mtx, bool);
	bool update(Effects effect, Vec3 *pos, Vec3i *rot, Vec3 *scale);
};
