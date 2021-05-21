
#pragma once

#include "nw4f.h"
#include "physics.h"
#include "actors.h"
#include "states.h"
#include "enums.h"
#include "effectclasses.h"
#include "graphics.h"

class Profile;
class Actor;
class YoshiEatData;
class ItemYoshiEatData;
class StateActor;
class Enemy;
class ItemBase;

class PlayerBase;
class Player;
class Yoshi;

struct ActorInfo {
	s32 xoffs;
	s32 yoffs;
	u32 _8;
	u32 _C;
	u32 _10;
	u32 _14;
	u16 _18;
	u16 _1A;
	u32 _1C;
	u16 flags;
	u16 _22;
};

struct ActorBuildInfo {
	u32 settings;
	u32 settings2;
	u32 parentId;
	Profile *profile;
	Vec3 position;
	u32 rotation;
	u8 layer;
	u8 Nybble3_4;
	u8 Nybble1_2;
	u8 _23;
	u8 movementId;
	u8 linkId;
	bool initStateFlag;
	u8 _27;
	u32 spriteRelated;
};

class YoshiEatData {
	public:
		u32 ownerActorId;
		u32 _4;
		u32 _8;
		YoshiFoodSpitType spitType;
		Vec3 scale;
		s32 _1C; // Related to whether the score is displayed. If 1 or 0, the score is displayed. Otherwise, it isn't. It probably has other uses as well.
		void *vtable;
};

class ItemYoshiEatData : YoshiEatData {
	public:
		ItemBase *parent;
};

class Profile {
	public:
		Profile(Actor *(ActorBuildInfo *), Actors actorId, const char * name, const ActorInfo * info, u32);

		Actor *(*buildMethod)(ActorBuildInfo *);
		u32 profileId;
		ActorInfo *actorInfo;
		u8 hasLoadedResources;
		u32 flags;
	
		static Profile *Get(Actors);
};

class PlayerLookTarget : public sead::IDisposer {
	u32 ownerId;
	Vec2 _14;
	u32 _1C;
	u32 _20;
	u32 _24;
	u32 _28;
};

class Actor {
	public:
		void * heap;
		u32 id;
		Profile *profile;
		bool wasNotDefered;
		bool isSprite;
		bool created;
		bool deleted;
		u32 settings; 		// Nybble 5 - 12
		u32 settings2; 		// Nybble 13 - 20
		u8 movementId; 		// Nybble 21 - 22
		u8 linkId; 			// Nybble 23 - 24
		u8 initStateFlag; // Spritedata + 0x14
		sead::ListImpl childList;
		sead::ListNode childNode;
		Actor *parent;
		sead::ListNode actorListNode;
		sead::ListNode drawListNode;
		u32 _48;
	
		Actor(ActorBuildInfo *);
		
		void removeChild(Actor *);
		Actors getProfileId();
	
		virtual bool checkDerivedRuntimeTypeInfo(void *);
		virtual void vf14(); //deleted
		virtual ~Actor();
	
		virtual int beforeCreate();
		virtual int onCreate();
		virtual void afterCreate(int);
	
		virtual int beforeExecute();
		virtual int onExecute();
		virtual void afterExecute(int);
		virtual void finalExecute();
	
		virtual int beforeDraw();
		virtual int onDraw();
		virtual void afterDraw(int);
	
		virtual int beforeDelete();
		virtual int onDelete();
		virtual void afterDelete(int);
};

class StageActor : public Actor {
	public:
		u32 direction;
		u8 playerId;
		u8 controllerLayoutPlayerId;
		u8 layer;
		u8 layer2;
		float XSpeed;
		float TargetXspeed_maybe;
		float fallSpeed;
		float gravity;
		float XAccel;
		Vec3 position;
		Vec3 speed;
		Vec3 maxSpeed;
		Vec3 scale;
		Vec3i rotation;
		u32 _A8;
		u32 _AC;
		u32 _B0;
		Vec2 posDelta;
		Collider collider;
		Rect rect;
		Vec2 size;
		Rect _1FC;
		u8 zone;
		u8 playerType;
		u8 isActive;
		u8 isVisible;
		bool noSpriteRespawn;
		u8 _211;
		u8 _212;
		u8 eventID_3_4;
		u8 eventID_1_2;
		u8 _215;
		u8 actorInfoFlags;
		u8 _217;
		u32 bumpDamageTimer;
		u32 _21C;
		u32 _220;
		u32 _224;
		u32 _228;
		u32 killStreak;
		u32 profile0x10;
		Vec3 offset;
		Vec3 position2;
		Vec3 position3;
		Vec3 position4;
		YoshiEatData *yoshiEatData;
		void * babyYoshiEatData;
		u32 _26C;
		u8 *spriteFlags;
		u32 _274;
		void *yoshiBubbleData;
	
		StageActor(ActorBuildInfo *);
			
		Direction getDirectionToPlayer(Vec3 *);
		
		bool checkDerivedRuntimeTypeInfo(void *);
		~StageActor();
		void afterCreate(int);
		int beforeExecute();
		void afterExecute(int);
		int beforeDraw();
	
		virtual void setPlayerId(u8);
		virtual void removeColliders();
		virtual void addColliders();
		virtual Physics * getPhysics();
		virtual void vfAC();
		virtual u32 vfB4();
		virtual void vfBC();
		virtual void vfC4();
		virtual void vfCC();
		virtual void killAtGoal();
		virtual void splashWater(Vec3 *);
		virtual void splashLava(Vec3 *);
		virtual void splashLavaWave(Vec3 *);
		virtual void splashPoison(Vec3 *);
		virtual bool isOffScreen();
		virtual void damageFromUnder();
};

class PhysicsActor : public StageActor {
	public:
	u32 _27C;
	ActorPhysics physics;
	u32 _1760;
	u32 _1764;
	Vec3 * positionPtr;
	u8 _176C;
	u8 _176D;
	u8 _176E;
	u8 _176F;
	u32 mightBeTileRelated;
	u32 _1774;
	u32 _1778;
	u32 _177C;
	u32 _1780;
	u32 _1784;
	float maxYSpeed;
	float minYSpeed;
	float pgravity;
	u8 _1794;
	u8 _1795;
	bool hasYSpeedLimitation;
	u8 _1797;
	u8 _1798;
	u8 _1799;
	u8 _179A;
	u8 _179B;
	u32 _179C;
	
	PhysicsActor(ActorBuildInfo *);
	
	void applyGravity();
	
	bool checkDerivedRuntimeTypeInfo(void *);
	~PhysicsActor();
	void afterCreate(int);
	int beforeExecute();
	void afterExecute(int);
	int onDelete();
	
	Physics *getPhysics();
	
	virtual void vf10C(u8);
	virtual void vf114(); //deleted
	virtual void vf11C();
	virtual void vf124(float);
	virtual u32 vf12C();
	virtual void vf134(); //deleted
	virtual u32 vf13C();
	virtual void vf144(bool);
	virtual void vf14C();
	virtual u32 vf154();
	virtual void move(Vec2 *);
	virtual void setYSpeed(float);
	virtual u32 vf16C();
	virtual u32 vf174();
	virtual void getRect(Rect *);
};

class StateActor2 : public PhysicsActor {
	public:
	StateMgr<StateActor> stateMgr;
	
	StateActor2(ActorBuildInfo *);
	
	bool checkDerivedRuntimeTypeInfo(void *);
	~StateActor2();
};

class StateActor : public StateActor2 {
	public:
	StateActor(ActorBuildInfo *);
	
	bool checkDerivedRuntimeTypeInfo(void *);
	~StateActor();

	virtual void doStateChange(StateBase *);
};

class ItemBase : StateActor {
	u32 _17A0;
	u32 _17A4;
	Vec3 Position2;
	Vec3 _17B4;
	
	u32 _17C0;
	u32 _17C4;
	u32 _17C8;
	u32 _17CC;
	u32 _17D0;
	u32 _17D4;

	Model *model;
	ModelAnimation *texAnims;
	ItemType itemType;

	u32 _17E4;
	u32 _17E8;
	u32 _17EC;
	u32 _17F0;
	u32 _17F4;
	u32 _17F8;

	u8 _17FC;
	u8 _17FD;
	u8 _17FE;
	u8 _17FF;
	u8 _1800;
	u8 _1801;
	u8 _1802;
	u8 _1803;

	u32 _1804;

	s32 _1808;
	
	u32 _180C;
	u32 _1810;
	u32 _1814;
	u32 _1818;
	u32 _181C;
	
	s32 _1820;
	
	u32 _1824;
	u32 _1828;
	u32 _182C;
	
	u16 _1830;
	u8 _1832;
	u8 _1833;

	u16 _1834;
	u8 _1835;
	u8 _1836;
	
	u8 _1837;
	u8 _1838;
	u8 _1839;
	u8 _183A;
	u8 _183B;

	ItemYoshiEatData itemYoshiEatData;
	Vec3 _1864;
	
	u32 _1870;
	u32 _1874;
	u32 _1878;
	u32 _187C;
	u32 _1880;
	
	Collider collider;
	
	u8 _19A8;
	u8 _19A9;
	u8 _19AA;
	u8 _19AB;

	float _19AC;
	float _19B0;
	
	u32 _19B4;
	
	float _19B8;
	float _19BC;
	float _19C0;
	
	u32 _19C4;
	u32 _19C8;
	u32 _19CC;
	u32 _19D0;
	u32 _19D4;
	
	EffectHandler effectHandler;
	
	u32 _1A40;

	u8 _1A44;
	u8 _1A45;
	u8 _1A46;
	u8 _1A47;

	u32 _1A48;
	u32 _1A4C;
	
	u8 _1A50;
	u8 _1A51;
	u8 _1A52;
	u8 _1A53;
	
	u32 _1A54;
	u32 _1A58;

	void setupActor();
	void setupState();

	void ModelUpdateThing();
	
	void sub_24FE8F8();
	void sub_24FDD10();
};

struct IceInfo {
	u32 _0;
	float X;
	float Y;
	float Z;
	float _10;
	float _14;
	float _18;
	u32 _1C;
};

class IceActorMgr {
	public:
	u32 _0;
	u32 _4[0xC];
	u8 _34;
	u8 _35;
	u8 _36;
	u8 _37;
	u32 _38;
	Enemy *owner;
	u16 _40;
	u16 _42;
	u8 _44;
	u8 _45;
	u8 _46;
	u8 _47;
	u8 _48;
	u8 _49;
	u8 _4A;
	u8 _4B;
	u8 _4C;
	u8 _4D;
	u8 _4E;
	u8 _4F;
	
	bool freezeActor(IceInfo *, u32);
};

class EnemyClass2Base {
	public:
	Enemy *owner;
	u32 _4;
	u32 _8;
	u32 _C;
	u32 _10;
	u32 _14;
	void *_18;
	
	virtual void vf0C(u32); //calls vf35C on parent
	virtual void vf14(u32); //calls vf364 on parent
	virtual void vf1C(u32); //calls vf36C on parent
	virtual void vf24(u32);    //calls vf374 on parent
};

class EnemyClass2 : public EnemyClass2Base {
	public:
	void vf0C(u32);
	void vf14(u32);
	void vf1C(u32);
	void vf24(u32);
};

class Enemy : public StateActor {
	public:
	u32 _17C8;
	u32 _17CC;
	float _17D0;
	float _17D4;
	u32 _17D8;
	u32 _17DC;
	u8 _17E0;
	u8 _17E1;
	u8 _17E2;
	u8 _17E3;
	u16 _17E4[4];
	u32 _17EC;
	IceActorMgr iceMgr;
	EnemyClass2 _1840;
	Enemy *self;
	void *_1864;
	u8 _1868;
	u8 _1869;
	u8 _186A;
	u8 _186B;
	u16 _186C;
	u16 _186E;
	u32 _1870;
	u8 _1874;
	u8 _1875;
	u8 _1876;
	u8 _1877;
	u32 _1878;
	u8 _187C;
	u8 _187D;
	u8 _187E;
	u8 _187F;
	
	static void collisionCallback(Collider *, Collider *);
	
	void killWithPlayer(Player *, Vec2 *, State<Enemy> *);
	void spinJumpKill(Player *);
	void killWithYoshi(Yoshi *);
	HitType processHit(Collider *, Collider *);
	void updatePosition();
	
	Enemy(ActorBuildInfo *);
	
	bool checkDerivedRuntimeTypeInfo(void *);
	~Enemy();
	int beforeExecute();
	
	void damageFromUnder();
	
	void vf14C();
	u32 vf154();
	
	void doStateChange(StateBase *);
	
	virtual u32 vf18C();
	virtual void playerCollision8A4(u32, Collider *);
	virtual bool vf19C(u8); //Uses _1878
	virtual bool freezeActor();
	virtual void vf1AC(); //nullsub
	virtual void vf1B4(); //nullsub
	virtual void vf1BC();
	virtual void vf1C4(); //nullsub
	virtual u32 vf1CC();
	virtual bool vf1D4(u32, void *); //calls hitEnemyKameDown
	virtual bool prePlayerCollision(Collider *self, Collider *other);
	virtual bool vf1E4(u8 *, Collider *self, Collider *other);
	virtual void yoshiCollisionRelated(Collider *self, Collider *other); //nullsub
	virtual bool preYoshiCollision(Collider *self, Collider *other);
	virtual bool vf1FC(Collider *self, Collider *other);
	virtual bool actorCollision(Collider *self, Collider *other);
	virtual void vf20C(); //nullsub
	virtual void playerCollision(Collider *self, Collider *other);
	virtual void yoshiCollision(Collider *self, Collider *other);
	virtual void vf224(Collider *self, Collider *other); //nullsub
	virtual void vf22C(Collider *self, Collider *other); //calls vf2CC
	virtual bool hitJump(Collider *self, Collider *other);
	virtual bool collidesSomething(Collider *, Collider *); //calls playDownSoundHpdp and vf344
	virtual bool hitEnemyDown(Collider *, Collider *);
	virtual bool hitGroundPound(Collider *, Collider *);
	virtual bool hitYoshi(Collider *, Collider *);
	virtual bool hitEnemyKame2(Collider *, Collider *);
	virtual bool hitEnemyKame3(Collider *, Collider *);
	virtual bool callsHitJump(Collider *, Collider *);
	virtual bool hitEnemyKameDown(Collider *, Collider *);
	virtual bool fireballCollision(Collider *self, Collider *other);
	virtual bool vf284(Collider *, Collider *);
	virtual bool hitNormal(Collider *, Collider *); //calls playDownSound
	virtual bool hitEnemyKame4(Collider *, Collider *);
	virtual u32 vf29C();
	virtual u32 goldYoshiHit(Collider *self, Collider *other);
	virtual void vf2AC(Collider *, Collider *);
	virtual bool vf2B4(u8 *, Collider *, Collider *);
	virtual void hitEx();
	virtual void vf2C4();
	virtual bool hitEnemyKame5(Collider *, Collider *); //calls vf8DC
	virtual bool isGrounded();
	virtual void playDownSound();
	virtual void playDownSoundHpdp();
	virtual void vf2EC(u32);
	virtual void vf2F4();
	virtual void vf2FC(u32); //calls vf2EC
	virtual void calls_vf2F4();
	virtual void vf30C(u32);
	virtual void playFumuSound();
	virtual void playerHit(PlayerBase *);
	virtual void playDownSpinSound();
	virtual void playMameStepSound();
	virtual void vf334(); //nullsub
	virtual void playYoshiFumuSound();
	virtual void spawnHipDropHitEffect();
	virtual void increaseYSpeed();
	virtual bool positionRelated();
	virtual void vf35C(void *);
	virtual void vf364(void *);
	virtual void vf36C(void *);
	virtual void vf374(); //nullsub
	virtual void beginState_JumpKill();
	virtual void executeState_JumpKill();
	virtual void endState_JumpKill(); //nullsub
	virtual void beginState_FireballKill(); //calls physicsRelated
	virtual void executeState_FireballKill();
	virtual void endState_FireballKill(); //nullsub
	virtual void beginState_YoshiStamp();
	virtual void executeState_YoshiStamp();
	virtual void endState_YoshiStamp(); //nullsub
	virtual void beginState_EnemyState11();
	virtual void executeState_EnemyState11();
	virtual void endState_EnemyState11(); //nullsub
	virtual void beginState_EnemyState12();
	virtual void executeState_EnemyState12();
	virtual void endState_EnemyState12(); //nullsub
	virtual void beginState_EnemyState13();
	virtual void executeState_EnemyState13(); //nullsub
	virtual void endState_EnemyState13(); //nullsub
	virtual void beginState_ChallengeRelated(); //calls vf94 and deletes itself
	virtual void executeState_ChallengeRelated(); //nullsub
	virtual void endState_ChallengeRelated(); //nullsub
	virtual void beginState_EnemyState2();
	virtual void executeState_EnemyState2();
	virtual void endState_EnemyState2(); //nullsub
	virtual void beginState_EnemyState3(); //nullsub
	virtual void executeState_EnemyState3(); //nullsub
	virtual void endState_EnemyState3(); //nullsub
	virtual void beginState_EnemyState4(); //nullsub
	virtual void executeState_EnemyState4(); //nullsub
	virtual void endState_EnemyState4(); //nullsub
	virtual void beginState_EnemyState5();
	virtual void executeState_EnemyState5(); //switches to EnemyState6
	virtual void endState_EnemyState5(); //nullsub
	virtual void beginState_EnemyState6(); //nullsub
	virtual void executeState_EnemyState6(); //nullsub
	virtual void endState_EnemyState6(); //nullsub
	virtual void beginState_EnemyState7(); //nullsub
	virtual void executeState_EnemyState7(); //nullsub
	virtual void endState_EnemyState7(); //nullsub
	virtual void beginState_EnemyState8(); //nullsub
	virtual void executeState_EnemyState8(); //nullsub
	virtual void endState_EnemyState8(); //nullsub
	virtual void beginState_PenguinIceHit();
	virtual void executeState_PenguinIceHit();
	virtual void endState_PenguinIceHit();
	
	static State<Enemy> StateID_JumpKill;
	static State<Enemy> StateID_FireballKill;
	static State<Enemy> StateID_YoshiStamp;
	static State<Enemy> StateID_EnemyState11;
	static State<Enemy> StateID_EnemyState12;
	static State<Enemy> StateID_EnemyState13;
	static State<Enemy> StateID_ChallengeRelated;
	
	static State<Enemy> StateID_EnemyState2;
	static State<Enemy> StateID_EnemyState3;
	static State<Enemy> StateID_EnemyState4;
	static State<Enemy> StateID_EnemyState5;
	static State<Enemy> StateID_EnemyState6;
	static State<Enemy> StateID_EnemyState7;
	static State<Enemy> StateID_EnemyState8;
	static State<Enemy> StateID_PenguinIceHit;
};

class WalkingEnemyBase : public Enemy {
	public:
   
	Vec3 _1888;
	Vec2 _1894;
	Vec2 _189C;
	float _18A4;
	u32 _18A8;
	u32 _18AC;
	u8 _18B0;
	u32 _18B4;
	u8 _18B8;
	u8 _18B9;
	u32 _18BC;
   
	WalkingEnemyBase(ActorBuildInfo *);
   
	bool checkDerivedRuntimeTypeInfo(void *);
	~WalkingEnemyBase();
	
	int beforeExecute();
	int onDelete();

	void setPlayerId(u8);
	Physics *getPhysics();
	u32 vfB4();
	void vfBC();
	void move(Vec2 *);
	void setYSpeed(float);
	void getRect(Rect *);
	void vf214(Collider *, Collider );
	bool vf274(Collider *, Collider *);
	bool vf284(Collider *, Collider *);
	bool vf2B4(u8 *, Collider *, Collider *);
	void vf4F4();
	bool vf4FC(Collider *, Collider *);
	bool vf504(Collider *, Collider *);
	bool vf50C(Collider *, Collider *);
	void vf52C();
	void vf534();
	void beginState_WalkingBaseState1(); //nullsub
	void executeState_WalkingBaseState1(); //nullsub
	void endState_WalkingBaseState1(); //nullsub
	
	static State<WalkingEnemyBase> StateID_WalkingBaseState1;

};
