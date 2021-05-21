
#pragma once

#include "actorbases.h"
#include "players.h"
#include "physics.h"
#include "effectclasses.h"
#include "states.h"
#include "sounds.h"
#include "graphics.h"
#include "blockcoin.h"
#include "movement.h"
#include "imports.h"
#include "ghs.h"
#include "miis.h"

void *operator new(u32 size, sead::Heap *heap, int alignment);

/***********
 * CLASSES
 *******/
struct AreaSettings {
	u64 eventIds;
	u16 flags;
	u16 timeLimit;
	u32 _C;
	u8 entranceId;
	u8 _11;
	u8 _12;
	u16 midwayTimeLimit;
	u16 midwayTimeLimit2;
};

struct Zone {
	u16 x;
	u16 y;
	u16 w;
	u16 h;
	u16 theme;
	u16 _A;
	u8 zoneId;
	u8 boundId;
	u8 cammode;
	u8 camzoom;
	u8 _10;
	u8 visibility;
	u8 backgroundId;
	u8 _13;
	u8 _14;
	u8 _15;
	u8 musicId;
	u8 _17;
	u8 _18;
	u8 _19;
	u8 _1A;
	u8 _1B;
};

struct Location {
	u16 x;
	u16 y;
	u16 w;
	u16 h;
	u8 id;
};

class LevelInfo : public sead::IDisposer {
	public:
		static LevelInfo *instance;
		u8 world;
		u8 level;
		u8 area;
		u8 entrance;
		u32 zone;
		u32 entranceType; //This is not the entrance type you see in Reggie
		u8 destWorld;
		u8 destLevel;
		u8 destArea;
		u8 destEntrance;
		u32 destEntranceType;
};

class LevelArea {
	public:
		enum BlockType {
			TilesetNames = 0,
			AreaSettings,
			ZoneBoundData,
			Backgrounds = 4,
			Entrances = 6,
			Sprites,
			LoadedSprites,
			Zones,
			Locations,
			Paths = 13,
			PathNodes
		};
		
		u32 areaNumber;
		void *blockPtrs[15];
		u32 blockSizes[15];
		u32 blockEntryCounts[15];
		u8 _B8[0x100];
		u8 _1B8[0x100];
		u8 _2B8[0x100];

		Location *getLocationById(Rect *dst, u8 id);
		Zone *getZoneById(u8 id, Rect *dst);
};

class Level {
	public:
		static Level *instance;
		LevelArea *getArea(u8 areaNum);
};
	
class LevelCamera : public sead::IDisposer {	
	public:		
		static LevelCamera *instance;		
			
		float _10;		
		float _14;		
		Rect zoneBox;		
		Rect someRects[4];		
		float cameraWidth;		
		float cameraHeight;		
		float cameraLeft;		
		float cameraCenterX;		
		float cameraRight;		
		float cameraTop;		
		float cameraCenterY;		
		float cameraBottom;		
		//.... zoom area, scroll limit, etc.		
};

class LevelTimer : public sead::IDisposer {
	public:
		static LevelTimer *instance;
		u32 timeLimit;
		u32 startTimeLimit;
		bool hurryUp;
		u8 freezingPlayers;
	
		~LevelTimer();
	
		void addSeconds(u32 amount);
};

class AdditionalActorHeap : public sead::IDisposer {
	public:
	sead::Heap *heap;
	~AdditionalActorHeap();
};

class ResMgr {
	public:
		static ResMgr *instance;
		bool loadArchive(const sead::String *name, const sead::String *filename, sead::Heap *heap, bool decompress);
		sead::SharcArchiveRes *getArchive(const sead::String *name);
		void *extract(const sead::String *arcname, const sead::String *subfilename, u32 *filesize);
};

class ResLoader {
	public:
		static ResLoader *instance;
		u8 _0[0x4428];
	
		ResArchive *getResArchive(sead::String filename);
};

class EventMgr : public sead::IDisposer {
	public:
		static EventMgr *instance;
		u64 events;
		u8 _18[0x940-0x18];
};

class TilesetLoader : public sead::IDisposer {
	public:
	static TilesetLoader *instance;
	sead::String *getTilesetName(u8 area, u8 slot);
};

class TileMgr : public sead::IDisposer {
	public:
		static TileMgr *instance;

		void *d_bgchk_data;		
		float liquidTop;		
		float liquidTop2;		
		float waveFloats[1280];		
		float waveFloats2[1280];		
		u8 waveType;		
		u8 hasWaves;		
		u8 _281E;		
		u8 _281F;		
		u32 liquidType;

		static u16 *getTilePointer(u16 x, u16 y, u8 layer, u32 *dstBlockIdx);
};

class ActorList {
	public:
		u32 maxCount;
		Actor **first;
		u32 usedCount;
		Actor **last;
		u32 actorId;
		u32 _14;
	
		Actor *findActorById(u32 * id);
};

class ActorMgr : public sead::IDisposer {
	public:
		static ActorMgr *instance;

		void *playerUnitHeap;
		void *actorUnitHeap;
		u8 _18[0x5988-0x18];
		sead::ListImpl createList;
		sead::ListImpl deleteList;
		sead::ListImpl activeActors;
		sead::ListImpl drawnActors;
		u8 _59C8[0x6A20-0x59C8];
		ActorList actorList;
		u8 _6A38[0x6A44-0x6A38];
	
		Actor *createActor(ActorBuildInfo *, u32);
		Actor **findActorByType(Actors actorId, Actor **);
};

class ItemSpawner : public sead::IDisposer {
	public:
	static ItemSpawner *instance;
	int getExtraPlayerCount();
};

class AreaRumbler : public sead::IDisposer {
	public:
	static AreaRumbler *instance;
	void rumbleScreen(u8 playerId, u32, u32, u32, u32);
};

class CoinMgr : public sead::IDisposer {
	public:
	static CoinMgr *instance;
	void spawnItemCoin(Vec3 *pos, u32 direction, u8 playerId);
	void dropCoins(Vec3 *pos);
};

class YoshiMgr : public sead::IDisposer {
	public:
	static YoshiMgr *instance;
	static void spawnBabyEgg(Vec3 *pos, u8 type, u32);
};

class AreaTask : public sead::CalculateTask {
	public:
	static AreaTask *instance;
	u8 _C8[0x71C - 0xC8];
	Rect zoneRect;
	u32 wrapFlag;
	u8 _730[0xBE0 - 0x730];
	
	float getWrappedXPos(float xpos);
};

class Item : ItemBase {
	u32 _1A5C;
	u32 _1A60;
};

class SpinningStar : public StateActor2 {
	public:
	Vec3 _17D0;
	u32 _17DC;
	float _17E0;
	float _17E4;
	u32 _17E8;
	u32 _17EC;
	u8 customCollider[0x5A8];
	Vec3 _1D98;
	u32 _1DA4;
	u8 _1DA8;
	u32 _1DAC;
	u16 _1DB0;
	u16 _1DB2;
	u16 _1DB4;
	u16 _1DB6;
	u16 _1DB8;
	u8 _1DBA;
	u8 _1DBB;
	u8 _1DBC;
	u8 _1DBD;
	u8 _1DBE;
	u8 _1DBF;
	u8 _1DC0;
	u8 _1DC1;
	u32 _1DC4;
	
	static ActorInfo actorInfo;
	
	SpinningStar(ActorBuildInfo *);
	
	bool checkDerivedRuntimeTypeInfo(void *);
	~SpinningStar();
	
	int onCreate();
	int onExecute();
	int onDraw();
};

class ActorScaler {
	public:
	Vec3 scale;
	float _C;
	u32 _10;
	u32 _14;
	StageActor *owner;
	
	virtual void getScale();
};

class Boss : public Enemy {
	public:
	u32 hitsToDeath;
	u32 hitsToDamage;
	u32 timer;
	bool isRumbling;
	bool isDemoRunning;
	u8 _188E;
	u8 _188F;
	u8 _1890[0x10];
	MovingSoundActor soundActor;
	u16 _19BC;
	u16 _19BE;
	PlayerLookTarget lookTarget;
	ActorScaler scaler;
	Collider bossCollider;
	void * _1B34; //some kind of vtable
	Vec3 _1B38;
	Vec3 _1B44;
	Vec3 _1B50;
	Vec3 _1B5C;
	float _1B68;
	float _1B6C;
	u32 _1B70;
	u32 _1B74;
	
	Boss(ActorBuildInfo *);
	
	bool checkDerivedRuntimeTypeInfo(void *);
	~Boss();
	int onCreate();
	int beforeExecute();
	void afterExecute(int);
	int onDelete();
	
	void removeColliders();
	void addColliders();
	u32 vf154();
	
	bool freezeActor();
	void vf1BC();
	void vf1C4(); //Calls vf7E4
	void playerCollision(Collider *, Collider *);
	void yoshiCollision(Collider *, Collider *);
	void vf22C(Collider *, Collider *);
	bool hitJump(Collider *, Collider *);
	bool collidesSomething(Collider *, Collider *);
	bool hitEnemyDown(Collider *, Collider *);
	bool hitGroundPound(Collider *, Collider *);
	bool hitEnemyKame2(Collider *, Collider *);
	bool hitEnemyKameDown(Collider *, Collider *);
	bool fireballCollision(Collider *self, Collider *other);
	bool vf284(Collider *, Collider *);
	void hitEx();
	void vf2C4();
	bool isGrounded();
	void vf2F4();
	void beginState_JumpKill();
	void executeState_JumpKill();
	void endState_JumpKill();
	
	virtual void beginState_BossState1(); //calls JumpKill methods
	virtual void executeState_BossState1();
	virtual void endState_BossState1();
	virtual void beginState_BossState2(); //calls JumpKill methods
	virtual void executeState_BossState2();
	virtual void endState_BossState2();
	virtual void beginState_BossState3(); //calls JumpKill methods
	virtual void executeState_BossState3();
	virtual void endState_BossState3();
	virtual void beginState_BossState4(); //calls JumpKill methods
	virtual void executeState_BossState4();
	virtual void endState_BossState4();
	virtual void beginState_BossState5(); //calls JumpKill methods
	virtual void executeState_BossState5();
	virtual void endState_BossState5();
	virtual void demoStart();
	virtual void demoEnd();
	virtual void vf56C(); //nullsub
	virtual void vf574();
	virtual void vf57C(); //nullsub
	virtual void vf584(); //deleted
	virtual u8 vf58C();
	virtual void vf594();
	virtual void vf59C(); //deleted
	virtual bool isNextDamageKill(); //deleted
	virtual void vf5AC(); //deleted
	virtual bool isDamageHit();
	virtual void processHits(u32 amount);
	virtual u32 getFireDamage() = 0;
	virtual u32 getStompDamage() = 0;
	virtual u32 getGroundPoundDamage() = 0;
	virtual u32 vf5DC() = 0; //deleted by sumo boss
	virtual u32 vf5E4() = 0; //deleted by sumo boss
	virtual u32 vf5EC() = 0; //deleted by sumo boss
	virtual u32 getStompDamage2() = 0;
	virtual u32 getStompDamageEx() = 0;
	virtual void playDamageAnim(); //nullsub
	virtual void timerEnd(); //nullsub
	virtual void beforeUpdate(); //nullsub
	virtual u32 fireTime(); //returns 24
	virtual void vf624(); //deleted
	virtual u32 stompTime(); //returns 24
	virtual void vf634(StageActor *);
	virtual void vf63C(StageActor *);
	virtual void vf644(); //Searches actor "Register for Fever -" and deletes it
	virtual void onStomp(StageActor *player);
	virtual void onStompDamage(StageActor *other); //nullsub
	virtual void onStompKill(StageActor *killer);
	virtual void vf664(); //nullsub
	virtual void changeState_State1();
	virtual void onGroundPoundDamage(); //calls vf654
	virtual void onGroundPoundKill();
	virtual void vf684(); //deleted
	virtual void vf68C(); //deleted
	virtual void vf694(); //deleted
	virtual void vf69C(); //deleted
	virtual void onStompDamageEx(); //nullsub
	virtual void onStompKillEx();
	virtual void onStompDamage2(); //nullsub
	virtual void onStompKill2();
	virtual void vf6C4(); //deleted
	virtual void vf6CC(); //deleted
	virtual u32 vf6D4();
	virtual void onDamage(); //nullsub
	virtual void onKill(); //calls vf574
	virtual bool immuneToGroundPound();
	virtual u32 vf6F4();
	virtual u32 vf6FC();
	virtual bool immuneToFire();
	virtual void vf70C(); //deleted
	virtual void vf714(); //deleted
	virtual void vf71C(); //deleted
	virtual EffectHandler *spawnDamageKillEffect(); //nullsub
	virtual EffectHandler *spawnDamageNormalEffect(); //nullsub
	virtual EffectHandler *spawnDamageEffect(); //nullsub
	virtual void vf73C(); //deleted
	virtual u32 vf744(); //nullsub
	virtual void playStompSound();
	virtual void playStompKillSound();
	virtual void vf75C(); //deleted
	virtual void playStarKillSound();
	virtual void vf76C(); //deleted
	virtual void playDamageKillSound();
	virtual void playFireDamageSound();
	virtual void playDamageKillFSound();
	virtual void playFireDamageSound2();
	virtual void playFireKillSound();
	virtual void playStarDamageSound();
	virtual void playDamageKillFSound2();
	virtual void playLoseSound(); //nullsub
	virtual void vf7B4(); //deleted
	virtual void vf7BC(); //deleted
	virtual void vf7C4(); //does some position stuff
	virtual u32 vf7CC();
	virtual void initCollider();
	virtual void initModels();
	virtual void updateModel();
	virtual void initHitsToDeath();
	virtual void initHitsToDamage();
	virtual int init();
	
	static State<Boss> StateID_JumpKill;
	
	static State<Boss> StateID_BossState1;
	static State<Boss> StateID_BossState2;
	static State<Boss> StateID_BossState3;
	static State<Boss> StateID_BossState4;
	static State<Boss> StateID_BossState5;
};

class WindGenerator : public StageActor {
	public:
	float finalWindStrength;
	float windStrengthValue;
	float strengthMultiplier;
	float directionMultiplier;
	u32 _28C;
	u32 timeOn;
	u32 timeOff;
	u32 windState;
	u32 timer;
	
	inline WindGenerator(ActorBuildInfo *buildInfo) : StageActor(buildInfo) {}
	
	~WindGenerator();
	int onCreate();
	int onExecute();
};

class YoshiEgg : public StateActor {
	// Incomplete
	public:
		u8 _17C8[0x30];
		u32 color;
		/* more data here */
};

class TerrainEffects {
	// Incomplete
	public:
	void *renderer;
	u32 _4;			
	Vec3 position;	
	u8 _14[12];				
	Vec3 _20;		
	u8 _2C[48];		
	u8 _5C[48];		
	u32 width;		
	u32 _90;		
	u32 _94;		
	u32 _98;		
	u32 _9C;		
	u32 _A0;		
	u32 _A4;		
	u32 _A8;		
	u32 _AC;		
	u32 _B0;		
	u32 _B4;		
	u32 _B8;		
	u32 _BC;		
	u32 _C0;		
	u32 waveSpeed;			
	u32 waveAnimSpeed;			
	u32 _CC;				
	u32 _D0;				
	u32 waveWidth;		
	u32 waveType;			
	float waveHeight;			
	float waveAnimHeight;	
	u8 type;		
	u8 noLocation;			
	u8 _E6;				
	u8 _E7;				
	u8 data[0xF8F4 + 0x658 - 0xE8];

	void init(Vec3 *pos, float width, bool noLoc, bool layer0, TerrainType type, sead::Heap *heap);	
	void setWaveValues(u32 h, u32 eftHeight, u32 spd, u32 anmSpeed, u32 w, u32 eft);		
	void checkMarioWaveHit();
	void updateWaveCollisions();
};

class EnvTerrain : public StateActor {
	public:
		u32 _17C8;
		u32 _17CC;
		Vec3 _17D0;
		Vec3 _17DC;
		SolidCollider collision;
		u8 _1A78[4 * 8];
		u32 _1A98;
		Vec2 _1A9C;
		u32 _1AA4;
		u32 _1AA8;
		float _1AAC;
		float _1AB0;
		float riseTop;
		float _1AB8;
		float _1ABC;
		float _1AC0;
		float risingSpeed;
		float _1AC8;
		float currentHeight;
		u32 _1AD0;
		u32 _1AD4;
		u16 _1AD8;
		u16 loweringDelay;
		bool onlyRenderWaves;
		u8 _1ADD;
		u8 _1ADE;
		u8 _1ADF;
		u32 _1AE0;
		TerrainEffects terrain;

		sead::IDisposer disposer;
		sead::Heap *additionalHeap;
		u32 _11A44;
		u64 eventMask;
		u32 _11A50;
		u32 _11A54;
		u64 eventMask2;
		u32 _11A60;
		float risingHeight;
		float _11A68;
		u32 _11A6C;
		u32 _11A70;
		u32 _11A74;
	
		EnvTerrain(ActorBuildInfo *);
		
		int onExecute();
	
		void setTop(float top);
};

class PoisonWater : public EnvTerrain {
	public:
	u32 _11A78;
	u32 _11A7C;
};

class Water : public EnvTerrain {
	public:
	float _11A78;
	u32 _11A7C;
	u32 _11A80;
	u32 _11A84;
};

class PlayerMgr : public sead::IDisposer {
	public:
		static PlayerMgr *instance;

		u8 _10[0x20 - 0x10];
		Player *players[4];
		/* incomplete */
};

class EnemyCounter {
	/* incomplete */
	public:
		static EnemyCounter *instance;

		void killEnemiesGoal();
};

//Inherits sead::ControllerBase
class Controller {
	public:
	s32 getTilt(u32 *, float multiplier);
};

class InputMgr : public sead::IDisposer {
	public:
	static InputMgr *instance;

	Controller controllers[4];
	//...
};

extern u8 fileCounts[];
extern const sead::String *fileLists[];
extern u32 directionToRotationList[];
extern Actors spriteToActorList[];

bool moveValueTo(u32 *, u32 target, u32 amount);	
bool moveFloatTo(float *, float target, float amount);

void calcMatrix(Mtx *, Vec3i *, Vec3 *);
void mapPosToScreen(Vec2 *, Vec2 *);
EffectHandler *spawnEffect(Effects effect, Vec3 *pos, Vec3i *rot, Vec3 *scale);

void killAllEnemiesOnScreen(u32 *unkptr, s32 playerId, u32 unk1, u32 unk2, u32 unk3, u32 unk4);
