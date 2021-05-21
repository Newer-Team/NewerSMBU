
#include "states.h"
#include "physics.h"
#include "actorbases.h"
#include "movement.h"
#include "players.h"

class BlockCoinRelatedBase : public StateActor {
	public:
	enum Content {
		FireMushroom = 0,
		MiniMushroom = 1,
		LifeMushroom = 2,
		Mushroom = 3,
		FireFlower = 4,
		IceMushroom = 5,
		PenguinMushroom = 6,
		PropellerMushroom = 7,
		Star = 8,
		ContinuousStar = 9,
		SquirrelMushroom = 10,
		LifeMoon = 11,
		Coin = 12,
		MultiCoin = 13,
		Vine = 15,
		Yoshi = 16,
		Spring = 17,
		MushroomIfSmall = 19,
		Nothing = 21
	};
	
	u8 _17C8[0x10];
	SolidCollider solidColl;
	Vec2 _1A68;
	Vec2 _1A70;
	float _1A78;
	float _1A7C;
	float _1A80;
	u8 _1A84[0x1AB8 - 0x1A84];
	u32 content;
	u32 hitPlayerId;
	u32 spawnDirection;
	u8 _1AC4[0x1B28 - 0x1AC4];
	
	void spawnPortableSpring();
	void spawnYoshiEgg(bool multi);
	void spawnVine();
	void spawnPowerup(Vec3 *pos, u32, u32, bool spawnAsChild);
	void spawnMultiPowerup(Vec3 *pos, u32, u32, bool spawnAsChild);
	
	BlockCoinRelatedBase(ActorBuildInfo *);
	
	bool checkDerivedRuntimeTypeInfo(void *);
	~BlockCoinRelatedBase();
	
	virtual void vf18C(); //nullsub
	virtual void vf194(); //nullsub
	virtual void vf19C(); //nullsub
	virtual void vf1A4(); //nullsub
	virtual void spawnItemUp(); //nullsub
	virtual void vf1B4(); //nullsub
	virtual void vf1BC(); //nullsub
	virtual void spawnItemDown(); //nullsub
	virtual void vf1CC(); //nullsub
	virtual void vf1D4(bool);
	virtual u32 vf1DC(); //returns 0
	virtual void spawnCoinShower();
	virtual void vf1EC(); //nullsub, only exists in NSLU
	virtual void beginState_BumpUp();
	virtual void executeState_BumpUp();
	virtual void endState_BumpUp();
	virtual void beginState_BlockCoinRelatedState1();
	virtual void executeState_BlockCoinRelatedState1();
	virtual void endState_BlockCoinRelatedState1();
	virtual void beginState_BumpDown();
	virtual void executeState_BumpDown();
	virtual void endState_BumpDown();
	virtual void beginState_BlockCoinRelatedState2(); //Counts down a timer
	virtual void executeState_BlockCoinRelatedState2(); //6 frames
	virtual void endState_BlockCoinRelatedState2();
	virtual void beginState_BumpUp2();
	virtual void executeState_BumpUp2();
	virtual void endState_BumpUp2();
	virtual void beginState_BumpDown2();
	virtual void executeState_BumpDown2();
	virtual void endState_BumpDown2();
	virtual void beginState_BlockCoinRelatedState3(); //Counts down a timer
	virtual void executeState_BlockCoinRelatedState3(); //6 frames
	virtual void endState_BlockCoinRelatedState3();
	
	static State<BlockCoinRelatedBase> StateID_BumpUp;
	static State<BlockCoinRelatedBase> StateID_BlockCoinRelatedState1;
	static State<BlockCoinRelatedBase> StateID_BumpDown;
	static State<BlockCoinRelatedBase> StateID_BlockCoinRelatedState2;
	static State<BlockCoinRelatedBase> StateID_BumpUp2;
	static State<BlockCoinRelatedBase> StateID_BumpDown2;
	static State<BlockCoinRelatedBase> StateID_BlockCoinRelatedState3;
};

class BlockCoinBase : public BlockCoinRelatedBase {
	public:
	u8 _1B28[0xC];
	Vec3 _1B34;
	MovementHandler mover;
	u8 _1C38[0x1CA8 - 0x1C38];
	
	BlockCoinBase(ActorBuildInfo *);
	
	bool checkDerivedRuntimeTypeInfo(void *);
	~BlockCoinBase();

	void spawnItemUp();
	void spawnItemDown();
	u32 vf1DC();
	
	virtual void vf29C(); //nullsub
	virtual void setTileFlag();
	virtual u32 vf2AC(); //returns 0
	virtual void vf2B4(); //nullsub
	virtual void vf2BC(); //nullsub
	virtual bool vf2C4(); //checks state stuff
	virtual void vf2CC();
};

class CoinBase : public BlockCoinBase {
	public:
	class CoinYoshiEatData : public YoshiEatData {
		CoinBase *owner;
	};
	
	u32 _1CA8;
	Vec2 _1CAC;
	Vec2 _1CB4;
	float _1CBC;
	u32 _1CC0;
	u16 _1CC4;
	u32 _1CC8;
	u32 _1CCC;
	u32 _1CD0;
	u32 _1CD4;
	u32 _1CD8;
	u8 _1CDC;
	u8 _1CDD;
	u8 _1CDE;
	u8 _1CDF;
	u8 _1CE0;
	u8 _1CE1;
	u8 _1CE2;
	u8 _1CE3;
	u8 _1CE4;
	float _1CE8;
	float _1CEC;
	u32 _1CF0;
	CoinYoshiEatData yoshiEatData;
	u8 _1D1C;
	u8 _1D1D;
	u8 _1D1E;
	u32 _1D20;
	float _1D24;
	u32 _1D28;
	u8 _1D2C;
	
	CoinBase(ActorBuildInfo *);
	
	void init();
	void initCollider(u32);
	void addCollider();
	
	bool checkDerivedRuntimeTypeInfo(void *);
	~CoinBase();
	
	int onExecute();
	int onDraw();
	
	void splashWater(Vec3 *);
	void splashLava(Vec3 *);
	void splashLavaWave(Vec3 *);
	void splashPoison(Vec3 *);
	
	void vf11C();
	void vf124(float);
	u32 vf12C();
	void vf144(bool);
	u32 vf2AC();
	
	virtual u32 vf2D4();
	virtual void initYoshiEatData();
	virtual void vf2E4();
	virtual void vf2EC();
	virtual void vf2F4();
	virtual void vf2FC();
	virtual void vf304();
	virtual void vf30C();
	
	static State<CoinBase> StateID_Main;
};

class BlockBase : public BlockCoinBase {
	public:
	float _1CA8;
	float _1CAC;
	float _1CB0;
	float _1CB4;
	float _1CB8;
	u32 _1CBC;
	u32 _1CC0;
	u8 _1CC4;
	u8 _1CC5;
	u8 _1CC6;
	u32 _1CC8;
	u8 _1CCC;
	
	static void otherCollisionCallback1(OtherColliderBase *coll, Physics *phys, u32);
	static void otherCollisionCallback2(OtherColliderBase *coll, Physics *phys, u32);
	static void otherCollisionCallback3(OtherColliderBase *coll, Physics *phys, u32);
	
	BlockBase(ActorBuildInfo *);
	
	bool init(bool, bool);
	
	bool checkDerivedRuntimeTypeInfo(void *);
	~BlockBase();
	int onExecute();
	int onDraw();

	void vf19C();
	void spawnItemUp();
	void spawnItemDown();
	void vf1CC();
	
	bool vf2C4(); //checks state stuff
	
	virtual bool vf2D4();
	virtual void vf2DC(); //nullsub
	virtual u8 getContent();
	virtual void vf2EC();
	virtual void vf2F4(Vec3 *);
	virtual void execute();
	virtual void vf304(); //deletes and something
	virtual void vf30C(); //deletes and something
	virtual void vf314(); //nullsub
	virtual void vf31C(); //nullsub
	virtual void vf324(); //nullsub
	virtual u32 vf32C(); //returns 0
	virtual void beginState_Wait();
	virtual void executeState_Wait();
	virtual void endState_Wait();
	virtual void beginState_Used();
	virtual void executeState_Used();
	virtual void endState_Used();
	
	static State<BlockBase> StateID_Wait;
	static State<BlockBase> StateID_Used;
};
