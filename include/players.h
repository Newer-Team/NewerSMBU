
#pragma once

#include "actorbases.h"
#include "effectclasses.h"
#include "effects.h"
#include "enums.h"
#include "sounds.h"
#include "graphics.h"
#include "nw4f.h"

class ItemBase;

template <u32 count>
class PlayerBaseList {
	public:
	u32 * pointerToField10;
	u32 countOfField10;
	u32 _8;
	u32 _C;
	u32 _10[count];
};

class UsedByPlayerBase {
	public:
	u32 _0;
	u32 _4;
	u32 _8;
	u32 _C;
	PlayerBaseList<10> _10;
	PlayerBaseList<10> _48;
	u32 _80;
	u32 _84;
	u8 _88;
	u8 _89;
	u8 _8A;
	u8 _8B;
	u32 _8C;
	u32 _90;
};

class UsedByPlayerBase2 {
	u8 _0[8];
	Vec3 _8;
	u8 _14;
	u8 _15;
	u8 _16;
	u8 _17;
};

class UsedByPlayerBase3 {
	u8 _0[0x30];
	u32 _30;
	u32 _34;
	u32 _38;
	u32 _3C;
};

struct PlayerGravityData {
	float groundPound;
	float thresholds[5];
	float fallStrengths[6];
	float jumpStrengths[6];
};

class PlayerBase : public StageActor {
	public:
		u32 _27C;
		u32 modelRelated;
		Vec3 _284;
		u32 _290;
		u32 _294;
		Vec3 playerPos;
		u32 _2A4;
		UsedByPlayerBase _2A8;
		MovingSoundActor soundActor;
		u32 _458;
		u32 _45C;
		u8 _460;
		u8 _461;
		u8 _462;
		u8 _463;
		PlayerLookTarget lookTarget;
		u8 _490[0x24];
		float _4B4;
		u32 _4B8;
		Vec3 _4BC;
		Vec3 _4C8;
		u32 _4D4;
		u32 _4D8;
		u32 _4DC;
		u32 _4E0;
		float _4E4;
		u8 _4E8;
		u8 _4E9;
		u8 _4EA;
		u8 _4EB;
		Vec3 _4EC;
		u8 _4F8;
		u8 _4F9;
		u8 _4FA;
		u8 _4FB;
		u32 nybble10;
		u32 powerup;
		u32 _504;
		PlayerPhysics physics;
		u8 _1AA8[0xC];
		u8 _1AB4[0xC];
		u8 _1AC0[0xC];
		u8 _1ACC[0xC];
		u8 _1AD8[0xC];
		u8 _1AE4[0x28];
		float _1B0C;
		float _1B10;
		u32 _1B14;
		u32 _1B18;
		u32 _1B1C;
		u32 _1B20;
		u32 _1B24;
		Vec3 _1B28;
		u32 terrainType;
		u32 _1B38;
		float _1B3C;
		float _1B40;
		u32 _1B44;
		u32 _1B48;
		Vec3 _1B4C;
		u32 _1B58;
		float _1B5C;
		Vec2 _1B60;
		Vec2 _1B68;
		float _1B70;
		float _1B74;
		u8 _1B78;
		u8 _1B79;
		u8 _1B7A;
		u8 _1B7B;
		u32 _1B7C;
		PlayerBaseList<2> _1B80;
		u32 _1B98;
		u32 _1B9C;
		u32 _1BA0;
		float _1BA4;
		float _1BA8;
		float _1BAC;
		float _1BB0;
		u32 _1BB4;
		Collider _1BB8;
		Collider _1CE0;
		Collider _1E08;
		Collider _1F30;
		void *_2058; //vtable of some kind
		u32 _205C;
		u32 _2060;
		u32 _2064;
		u32 _2068;
		u32 _206C;
		u32 _2070;
		float _2074;
		float _2078;
		float _207C;
		float _2080;
		u8 _2084;
		u8 _2085;
		u8 _2086;
		u8 _2087;
		u32 _2088;
		u32 _208C;
		u32 _2090;
		u32 _2094;
		float _2098;
		u32 _209C;
		u32 _20A0;
		u8 _20A4[8];
		u8 _20AC[8];
		StateMgrBase<PlayerBase> state1;
		u32 _20D8;
		u32 _20DC;
		u32 _20E0;
		u32 _20E4;
		u32 _20E8;
		u32 _20EC;
		u32 _20F0;
		u32 _20F4;
		u32 _20F8;
		u32 _20FC;
		u8 _2100[8];
		u8 _2108[8];
		Vec3 playerPos2;
		u8 _211C;
		u8 _211D;
		u8 _211E;
		u8 _211F;
		float _2120;
		float _2124;
		u32 _2128;
		u32 _212C;
		float _2130;
		u32 _2134;
		u32 _2138;
		u8 _213C[0xC];
		u32 _2148;
		u32 _214C;
		u32 _2150;
		u8 _2154[0xC];
		u8 _2160[0xC];
		u8 _216C[8];
		u32 _2174;
		float _2178;
		float _217C;
		u32 _2180;
		u32 _2184;
		u32 _2188;
		u8 _218C;
		u8 _218D;
		u8 _218E;
		u8 _218F;
		float _2190;
		u32 _2194;
		u8 _2198;
		u8 _2199;
		u8 _219A;
		u8 _219B;
		StateMgrBase<PlayerBase> state2;
		u32 _21C0;
		u32 _21C4;
		u32 _21C8;
		u32 _21CC;
		u32 _21D0;
		u32 yoshiActorId;
		u32 _21D8;
		u32 _21DC;
		u32 _21E0;
		u32 _21E4;
		u32 _21E8;
		u32 _21EC;
		Vec2 _21F0;
		float _21F8;
		u8 _21FC[0xC];
		u8 _2208[0xC];
		u32 _2214;
		float _2218;
		u32 _221C;
		u32 _2220;
		u32 _2224;
		u32 _2228;
		EffectHandler _222C;
		EffectHandler _2294;
		EffectHandler _22FC;
		EffectHandler _2364;
		EffectHandler _23CC;
		u8 _2434[0x30];
		u8 _2464[0x10];
		u8 _2474[0xC];
		UsedByPlayerBase2 _2480;
		EffectHandler _2498;
		EffectHandler _2500;
		u8 _2568[0x30];
		u8 _2598[0x10];
		u8 _25A8[0x30];
		u8 _25D8[0x10];
		u32 _25E8;
		u8 _25EC;
		u8 _25ED;
		u8 _25EE;
		u8 _25EF;
		u32 _25F0;
		EffectHandler _25F4;
		u32 _265C;
		u32 _2660;
		UsedByPlayerBase3 _2664[3];
		StateMgrBase<PlayerBase> state3;
		u32 _2748;
		u8 _274C;
		u8 _274D;
		u8 _274E;
		u8 _274F;

		bool usedByGoalPole();

		PlayerBase(ActorBuildInfo *);

		bool checkDerivedRuntimeTypeInfo(void *);
		~PlayerBase();
		int onCreate();
		int beforeExecute();
		int onExecute();
		void afterExecute(int);
		int beforeDraw();
	
		void setPlayerId(u8);
		Physics * getPhysics();
		void vfAC();
		u32 vfB4();
		void vfBC();
		void vfC4();
		void vfCC();
		void damageFromUnder();
		
		virtual void vf10C() = 0;
		virtual void vf114() = 0;
		virtual void vf11C() = 0;
		virtual void givePowerup(Powerup powerup, bool save);
		virtual void doGivePowerup(Powerup powerup, bool save) = 0;
		
		//New in NSLU
		virtual bool vf134();

		//Both NSMBU and NSLU
		virtual u32 getSizeForPowerup(Powerup powerup) = 0; //returns 0 (mini) / 1 (small) / 2 (big)
		virtual void vf144(Vec3 *) = 0;
		virtual void vf14C(Vec3 *, float *) = 0;
		virtual bool vf154();
		virtual float *vf15C() = 0; //returns floats for size
		virtual float vf164() = 0;
		virtual void vf16C() = 0;
		virtual void vf174() = 0;
		virtual void vf17C() = 0;
		virtual void initColliders(CollisionInfo *one, CollisionInfo *two);
		virtual void deleteColliders();
		virtual void resetColliders();
		virtual bool vf19C() = 0;
		virtual void vf1A4();
		virtual void vf1AC(u32, u32);
		virtual void vf1B4();
		virtual bool vf1BC(Vec3 *);
		virtual void vf1C4();
		virtual void vf1CC() = 0;
		virtual bool vf1D4(u32) = 0;
		virtual bool vf1DC() = 0;
		virtual void vf1E4(u32, u32);
		virtual void vf1EC();
		virtual void vf1F4();
		virtual void vf1FC(); //nullsub
		virtual void vf204(u32);
		virtual void vf20C();
		virtual void vf214();
		virtual void vf21C();
		virtual void vf224(); //nullsub
		virtual void vf22C(); //nullsub
		virtual void vf234(); //nullsub
		virtual void vf23C(); //nullsub
		virtual void vf244(); //nullsub
		virtual void vf24C();
		virtual void vf254(); //nullsub
		virtual void vf25C(); //nullsub
		virtual void vf264();
		virtual void vf26C();
		virtual void vf274(); //nullsub
		virtual void vf27C();
		virtual void vf284();
		virtual void vf28C(); //nullsub
		virtual void vf294(); //nullsub
		virtual void vf29C(); //nullsub
		virtual void vf2A4(); //nullsub
		//Probably state functions
		virtual void vf2AC();
		virtual void vf2B4();
		virtual void vf2BC();
		virtual void vf2C4();
		virtual void vf2CC();
		virtual void vf2D4();
		virtual void vf2DC();
		virtual void vf2E4();
		virtual void vf2EC();
		virtual void vf2F4();
		virtual void vf2FC();
		virtual void vf304();
		virtual void vf30C();
		virtual void vf314();
		virtual void vf31C();
		virtual void vf324();
		virtual void vf32C();
		virtual void vf334();
		virtual void vf33C();
		virtual void vf344();
		virtual void vf34C();
		virtual void vf354();
		virtual void vf35C();
		virtual void vf364();
		virtual void vf36C();
		virtual void vf374();
		virtual void vf37C();
		virtual void vf384();
		virtual void vf38C();
		virtual void vf394();
		virtual void vf39C();
		virtual void vf3A4();
		virtual void vf3AC();
		virtual void vf3B4();
		virtual void vf3BC();
		virtual void vf3C4();
		virtual void vf3CC();
		virtual void vf3D4();
		virtual void vf3DC();
		virtual void vf3E4();
		virtual void vf3EC();
		virtual void vf3F4();
		virtual void vf3FC();
		virtual void vf404();
		virtual void vf40C();
		virtual void vf414();
		virtual void vf41C();
		virtual void vf424();
		virtual void vf42C();
		virtual void vf434();
		virtual void vf43C();
		virtual void vf444();
		virtual void vf44C();
		virtual void vf454();
		virtual void vf45C();
		virtual void vf464();
		virtual void vf46C();
		virtual void vf474();
		virtual void vf47C();
		virtual void vf484();
		virtual void vf48C();
		virtual void vf494();
		virtual void vf49C();
		virtual void vf4A4();
		virtual void vf4AC();
		virtual void vf4B4();
		virtual void vf4BC(bool) = 0;
		virtual void vf4C4(u8); //sets flag
		virtual void vf4CC(u8); //clears flag
		virtual void vf4D4(); //clears all flags
		virtual bool vf4DC(); //is any flag set
		virtual bool vf4E4(u8); //gets flag
		virtual bool vf4EC();
		virtual u32 vf4F4();
		virtual bool vf4FC() = 0;
		virtual void vf504(u32, u32, float) = 0;
		virtual void vf50C(u32, u32, float) = 0;
		virtual bool vf514() = 0;
		virtual void vf51C(u32) = 0;
		virtual bool vf524(void *, u32); //deleted, but not deleted in subclasses?
		virtual void vf52C() = 0;
		virtual void vf534();
		virtual void vf53C() = 0;
		virtual void vf544() = 0;
		virtual void vf54C() = 0;
		virtual void vf554() = 0;
		virtual bool vf55C(u32) = 0;
		virtual void vf564() = 0;
		virtual bool vf56C() = 0;
		virtual bool vf574() = 0;
		virtual bool vf57C(u32);
		virtual float vf584() = 0;
		virtual void vf58C(Vec3 *) = 0;
		
		//New in NSLU
		virtual void vf594(bool);
		
		//Both NSMBU and NSLU
		virtual void vf59C() = 0;
		virtual void vf5A4() = 0;
		virtual void vf5AC() = 0;
		
		//Only NSLU, not sure what this is, it's a null pointer
		virtual void vf5B4();
		
		//Both NSMBU and NSLU
		virtual bool vf5BC() = 0;
		virtual bool vf5C4(bool, u8, u32, float, float) = 0;
		//More states
		virtual void vf5CC(); //nullsub
		virtual void vf5D4(); //nullsub
		virtual void vf5DC(); //nullsub
		virtual void vf5E4();
		virtual void vf5EC();
		virtual void vf5F4();
		virtual void beginState_Jump();
		virtual void executeState_Jump();
		virtual void endState_Jump();
		virtual void vf614();
		virtual void vf61C();
		virtual void vf624();
		virtual void vf62C();
		virtual void vf634();
		virtual void vf63C();
		virtual void vf644();
		virtual void vf64C();
		virtual void vf654();
		virtual void vf65C();
		virtual void vf664();
		virtual void vf66C();
		virtual void vf674();
		virtual void vf67C();
		virtual void vf684();
		virtual void vf68C();
		virtual void vf694();
		virtual void vf69C();
		virtual void vf6A4();
		virtual void vf6AC();
		virtual void vf6B4();
		virtual void vf6BC();
		virtual void vf6C4();
		virtual void vf6CC();
		virtual void vf6D4();
		virtual void vf6DC();
		virtual void vf6E4();
		virtual void vf6EC();
		virtual void vf6F4();
		virtual void vf6FC();
		virtual void vf704();
		virtual void vf70C();
		virtual void vf714();
		virtual void vf71C();
		virtual void vf724();
		virtual void vf72C();
		virtual void vf734();
		virtual void vf73C();
		virtual void vf744();
		virtual void vf74C();
		virtual void vf754();
		virtual void vf75C();
		virtual void vf764();
		virtual void vf76C();
		virtual void vf774();
		virtual u32 vf77C() = 0; //only pure in NSLU
		virtual void vf784(bool) = 0;
		virtual void vf78C(u32) = 0;
		virtual void vf794(bool) = 0;
		virtual u32 vf79C();
		virtual void vf7A4() = 0;
		virtual bool vf7AC() = 0;
		virtual bool vf7B4(u32) = 0;
		virtual void vf7BC() = 0;
		virtual void vf7C4() = 0;
		virtual void vf7CC() = 0;
		virtual bool vf7D4() = 0;
		virtual bool vf7DC();
		virtual bool vf7E4();
		virtual bool vf7EC() = 0;
		virtual bool vf7F4(Collider *, Collider *) = 0;
		virtual void vf7FC() = 0;
		virtual float vf804() = 0;
		virtual void vf80C();
		
		//New in NSLU
		virtual void vf814();
		
		//Both NSMBU and NSLU
		virtual void vf81C();
		virtual void vf824(u32); //rumbles
		virtual void vf82C(); //rumbles
		virtual u32 vf834();
		virtual u32 vf83C();
		virtual bool vf844(); //deleted, but not deleted in subclasses, returns whether carried player is mini
		virtual u32 vf84C();
		virtual void vf854() = 0;
		virtual void vf85C(float) = 0;
		virtual void vf864(float) = 0;
		virtual void vf86C() = 0;
		virtual u32 vf874();
		virtual PlayerGravityData *getGravityData();
		virtual void updateMaxFallSpeed();
		virtual void vf88C() = 0;
		virtual float getJumpSpeed() = 0;
		virtual float vf89C() = 0;
		virtual void playJumpSound(u8) = 0;
		virtual void vf8AC(bool) = 0;
		virtual bool vf8B4() = 0;
		virtual void vf8BC() = 0;
		virtual bool hurt(Collider *) = 0;
		//hitType: 0x13 is actor falls on head, 4/5 = actor ground pounds
		virtual bool hitByActor(StageActor *actor, u32 hitType) = 0;
		virtual bool vf8D4(u32, u32) = 0;
		virtual bool vf8DC(float, float, u32, Direction, u32) = 0;
		virtual bool vf8E4(void *) = 0;
		virtual bool vf8EC(void *, bool) = 0;
		virtual void vf8F4() = 0;
		virtual s8 vf8FC() = 0;
		virtual s8 vf904(u32) = 0;
		virtual void giveStar(u32, u32) = 0;
		virtual bool hasStar() = 0;
		virtual void vf91C() = 0;
		virtual void vf924(void *) = 0;
		virtual void vf92C();
		virtual Effects getGroundPoundEffectId() = 0;
		virtual Effects getGroundPoundEXEffectId() = 0;
		virtual Effects getGroundPoundNormalEffectId() = 0;
		virtual Effects getGroundPoundBlurEffectId() = 0;
		virtual Effects getSlipSmokeEffectId() = 0;
		virtual Effects getTurnBrakeEffectId() = 0;
		virtual Effects getTurnBrakeSmokeEffectId() = 0;
		virtual u32 vf96C() = 0;
		virtual Effects getDashSmokeEffectId() = 0;
		virtual Effects getLandingSmokeEffectId() = 0;
		virtual Effects getWaterSplashEffectId(bool) = 0;
		virtual Effects getWaterSplashSEffectId() = 0;
		virtual Effects getPoisonSplashEffectId(bool) = 0;
		virtual Effects getLavaSplashEffectId(bool) = 0;
		virtual Effects getLavaSplash2EffectId(bool) = 0;
		
		//New in NSLU
		virtual void vf9AC(bool);
		
		//Both NSMBU and NSLU
		virtual void vf9B4();
		virtual void vf9BC();
		virtual void vf9C4();
		virtual void vf9CC();
		virtual void vf9D4();
		virtual void vf9DC();
		virtual void vf9E4();
		virtual void vf9EC();
		virtual void vf9F4();
		virtual void vf9FC();
		virtual void vfA04();
		virtual void vfA0C();
		virtual void vfA14();
		virtual void vfA1C();
		virtual void vfA24();
		virtual void vfA2C() = 0;
		virtual void vfA34() = 0;
		virtual void vfA3C() = 0;
		virtual void vfA44() = 0;

		void playSound(char *name, bool unk);
		void groundPound();
		void playLandSound();
		
		void spawnGroundPoundBlurEffect();
		void doLandEffects();
		
};

class Player : public PlayerBase {
	// Incomplete
	public:
		u8 _2750[0x34D8-0x2750];
		
		bool checkDerivedRuntimeTypeInfo(void *);
		~Player();
		
		int onCreate();
		int beforeExecute();
		void afterExecute(int);
		int beforeDraw();
		int onDraw();
		int onDelete();
		
		void setPlayerId(u8);
		void vfAC();
		u32 vfB4();
		void vfBC();
		
		void vf10C();
		void vf114();
		void vf11C();
		void doGivePowerup(Powerup powerup, bool save);
		bool vf134();
		u32 getSizeForPowerup(Powerup powerup);
		void vf144(Vec3 *);
		void vf14C(Vec3 *, float *);
		bool vf154();
		float *vf15C();
		float vf164();
		void vf16C();
		void vf174();
		void vf17C();
		bool vf19C();
		void vf1CC();
		bool vf1D4(u32);
		bool vf1DC();
		void vf1E4(u32, u32);
		void vf1EC();
		void vf1F4();
		void vf1FC();
		void vf204(u32);
		void vf224();
		void vf22C();
		void vf234();
		void vf23C();
		void vf244();
		void vf24C();
		void vf254();
		void vf25C();
		void vf2C4();
		void vf2CC();
		void vf3FC();
		void vf404();
		void vf40C();
		void vf414();
		void vf41C();
		void vf424();
		void vf444();
		void vf44C();
		void vf454();
		void vf4A4();
		void vf4AC();
		void vf4B4();
		void vf4BC(bool);
		bool vf4EC();
		u32 vf4F4();
		bool vf4FC();
		void vf504(u32, u32, float);
		void vf50C(u32, u32, float);
		bool vf514();
		void vf51C(u32);
		bool vf524(void *, u32);
		void vf52C();
		void vf534();
		void vf53C();
		void vf544();
		void vf54C();
		void vf554();
		bool vf55C(u32);
		void vf564();
		bool vf56C();
		bool vf574();
		bool vf57C(u32);
		float vf584();
		void vf58C(Vec3 *);
		void vf59C();
		void vf5A4();
		void vf5AC();
		bool vf5BC();
		bool vf5C4(bool, u8, u32, float, float);
		void vf5E4();
		void vf5EC();
		void vf5F4();
		void beginState_Jump();
		void executeState_Jump();
		void endState_Jump();
		void vf614();
		void vf61C();
		void vf624();
		void vf62C();
		void vf634();
		void vf63C();
		void vf644();
		void vf64C();
		void vf654();
		void vf65C();
		void vf664();
		void vf66C();
		void vf674();
		void vf67C();
		void vf684();
		void vf68C();
		void vf694();
		void vf69C();
		void vf6A4();
		void vf6AC();
		void vf6B4();
		void vf6BC();
		void vf6C4();
		void vf6D4();
		void vf6DC();
		void vf6E4();
		void vf6F4();
		void vf6FC();
		void vf704();
		void vf70C();
		void vf714();
		u32 vf77C();
		void vf784(bool);
		void vf78C(u32);
		void vf794(bool);
		u32 vf79C();
		void vf7A4();
		bool vf7AC();
		bool vf7B4(u32);
		void vf7BC();
		void vf7C4();
		void vf7CC();
		bool vf7D4();
		bool vf7DC();
		bool vf7EC();
		bool vf7F4(Collider *, Collider *);
		void vf7FC();
		float vf804();
		void v80C();
		void vf81C();
		void vf824(u32);
		void vf82C();
		u32 vf834();
		u32 vf83C();
		bool vf844();
		u32 vf84C();
		void vf854();
		void vf85C(float);
		void vf864(float);
		void vf86C();
		u32 vf875();
		PlayerGravityData *getGravityData();
		void updateMaxFallSpeed();
		void vf88C();
		float getJumpSpeed();
		float vf89C();
		void playJumpSound(u8);
		void vf8AC(bool);
		bool vf8B4();
		void vf8BC();
		bool hurt(Collider *);
		bool hitByActor(StageActor *actor, u32 hitType);
		bool vf8D4(u32, u32);
		bool vf8DC(float, float, u32, Direction, u32);
		bool vf8E4(void *);
		bool vf8EC(void *, bool);
		void vf8F4();
		s8 vf8FC();
		s8 vf904(u32);
		void giveStar(u32, u32);
		bool hasStar();
		void vf91C();
		void vf924(void *);
		void vf92C();
		Effects getGroundPoundEffectId();
		Effects getGroundPoundEXEffectId();
		Effects getGroundPoundNormalEffectId();
		Effects getGroundPoundBlurEffectId();
		Effects getSlipSmokeEffectId();
		Effects getTurnBrakeEffectId();
		Effects getTurnBrakeSmokeEffectId();
		u32 vf96C();
		Effects getDashSmokeEffectId();
		Effects getLandingSmokeEffectId();
		Effects getWaterSplashEffectId(bool);
		Effects getWaterSplashSEffectId();
		Effects getPoisonSplashEffectId(bool);
		Effects getLavaSplashEffectId(bool);
		Effects getLavaSplash2EffectId(bool);
		void vfA2C();
		void vfA34();
		void vfA3C();
		void vfA44();
		
		//Lots of new NSLU virtuals
		virtual void vfA4C();
		virtual void vfA54();
		virtual void vfA5C();
		virtual void vfA64();
		virtual void vfA6C();
		virtual void vfA74();
		virtual void vfA7C();
		virtual void vfA84();
		virtual void vfA8C();
		virtual void vfA94();
		virtual void vfA9C();
		virtual void vfAA4();
		virtual void vfAAC();
		virtual void vfAB4();
		virtual void vfABC();
		virtual void vfAC4();
		virtual void vfACC();
		virtual void vfAD4();
		virtual void vfADC();
		virtual void vfAE4();
		virtual void vfAEC();
		virtual void vfAF4();
		virtual void vfAFC();
		virtual void vfB04();
		virtual void vfB0C();
		virtual void vfB14();
};

class Yoshi : public PlayerBase {
	// Incomplete
	public:
		u32 actorIdInMouth;
		u32 _2754;
		YoshiModelHandler modelHandler;
		u32 _2768;
		u32 _276C;
		u32 _2770;
		u32 _2774;
		u32 _2778;
		u32 _277C;
		u32 _2780;
		u32 _2784;
		u32 _2788;
		u32 _278C;
		s32 _2790;
		u32 _2794; // Direction of some sort (maybe the tongue direction?)
		YoshiTongueState tongueState;
		u32 _279C;
		float _27A0;
		float _27A4;
		u32 _27A8;
		u32 _27AC;
		u32 _27B0;
		u32 _27B4;
		u8 _27B8;
		u8 _27B9;
		u8 _27BA;
		u8 _27BB;
		u32 _27BC;
		u8 _27C0;
		u8 _27C1;
		u8 _27C2;
		u8 _27C3;
		u32 _27C4;
		float _27C8;
		u8 _27CC;
		u8 _27CD;
		u8 _27CE;
		u8 _27CF;
		u32 _27D0;
		u32 _27D4;
		u8 _27D8;
		u8 _27D9;
		u8 _27DA;
		u8 _27DB;
		u32 flutterState;
		bool canFlutter;
		u8 _27E1;
		u8 _27E2;
		u8 _27E3;
		u32 _27E4;
		u32 _27E8;
		u32 _27EC;
		u32 _27F0;
		u32 _27F4;
		u32 _27F8;
		u32 _27FC;
		u32 _2800;
		u32 _2804;
		u32 _2808;
		u32 _280C;
		u32 _2810;
		u32 _2814;
		u32 _2818;
		u32 _281C;
		u32 _2820;
		u32 _2824;
		u32 _2828;
		u32 _282C;
		u32 _2830;
		u32 _2834;
		u32 _2838;
		u32 _283C;
		u32 _2840;
		u32 _2844;
		u32 _2848;
		u32 _284C;
		u32 _2850;
		u32 _2854;
		u32 _2858;
		u32 _285C;
		u32 _2860;
		u32 _2864;
		u32 _2868;
		u32 _286C;
		u32 _2870;
		u32 _2874;
		u32 _2878;
		u32 _287C;
		u32 _2880;
		u32 _2884;
		u32 _2888;
		u32 _288C;
		u32 _2890;
		u32 _2894;
		u32 _2898;
		u32 _289C;
		u32 _28A0;
		u32 _28A4;
		u32 _28A8;
		u32 _28AC;
		u32 _28B0;
		u32 _28B4;
		u32 _28B8;
		u32 _28BC;
		u32 _28C0;
		u32 _28C4;
		u32 _28C8;
		u32 _28CC;
		u32 _28D0;
		u32 _28D4;
		u32 _28D8;
		u32 _28DC;
		u32 _28E0;
		u32 _28E4;
		u32 _28E8;
		u32 _28EC;
		u32 _28F0;
		u32 _28F4;
		u32 _28F8;
		u32 _28FC;
		u32 _2900;
		u32 _2904;
		u32 _2908;
		u32 _290C;
		u32 _2910;
		u32 _2914;
		u32 _2918;
		u32 _291C;
		
		Yoshi(ActorBuildInfo *);
		
		int onCreate();

		bool spawnBall(bool ice); // Iceball if true, Fireball if false
		void changeState(State<Yoshi> *state);
		Player *getRidingPlayer();
		
		StageActor *getActorInMouth();
		void removeActorFromMouth();

		static State<Yoshi> StateID_DefaultState;
};
