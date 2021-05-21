
#pragma once

class Collider;
class OtherColliderBase;
class Physics;

class StageActor;

typedef void (*collisionCallback)(Collider *one, Collider *two);
typedef void (*otherCollisionCallback)(OtherColliderBase *self, Physics *other, u32);

class CollThing {
	public:
		u8 _0[0x18];
		u32 _18;
		u32 _1C;
	
		CollThing();
};

class OtherColliderBase : public sead::IDisposer {
	public:
	u8 _10[0xC * 8];
	Rect rect;
	Vec2 _80;
	u32 _88;
	u32 _8C;
	StageActor *owner;
	u32 _94;
	u32 _98;
	u32 _9C;
	u32 _A0;
	u32 _A4;
	u32 _A8;
	Vec2 _AC[6];
	u8 _DC;
	u8 _DD;
	u8 _DE;
	u8 _DF;
	u32 _E0;
	float _E4[4];
	u32 zrot;
	u32 _F8;
	u8 _FC[0xC * 4];
	u32 _12C;
	u32 _130;
	u32 _134;
	otherCollisionCallback collCB1;
	otherCollisionCallback collCB2;
	otherCollisionCallback collCB3;
	u32 _144;
	u32 _148;
	u32 _14C;
	u32 _150;
	u32 _154;
	
	OtherColliderBase();
	
	virtual ~OtherColliderBase();
	virtual bool checkDerivedRuntimeTypeInfo(void *);
	virtual void vf1C(); //deleted
	virtual bool vf24(u32 *, u32);
	virtual void vf2C(); //deleted
	virtual void vf34() = 0;
	virtual void updateMovement() = 0;
	virtual bool vf44(void *, u16 *, Vec2 *, Vec2 *, u32) = 0;
	virtual bool vf4C(void *, Vec2 *, Vec2 *, u32, void *) = 0;
	virtual bool vf54(u8 *, Vec2 *) = 0;
	virtual void vf5C() = 0; //pure, deleted by subclasses
	virtual void vf64();
	virtual void vf6C() = 0;
	virtual void vf74(u32 *) = 0; //u32[2]
	virtual bool vf7C(Vec2 *) = 0;
};

class CustomCollider : public OtherColliderBase {
	public:
	u8 _158[0x18];
	
	void setRect(Vec2 *topLeft, Vec2 *bottomRight);
	CustomCollider(u32, Vec2 *, CollThing *, CollThing *);
	
	~CustomCollider();
	bool checkDerivedRuntimeTypeInfo(void *);
	//bool vf24(u32 *, u32);
	void vf34();
	void updateMovement();
	bool vf44(void *, u16 *, Vec2 *, Vec2 *, u32);
	bool vf4C(void *, Vec2 *, Vec2 *, u32, void *);
	bool vf54(u8 *, Vec2 *);
	void vf5C(); //deleted
	void vf64();
	void vf6C();
	void vf74(u32 *);
	bool vf7C(Vec2 *);
};

struct SolidCollisionInfo {
	float _0[4];
	float _10[4];
	u32 rot;
};

class SolidCollider : public CustomCollider {
	public:
	Vec2 _170[4];
	CollThing _190[4];
	CollThing _210[4];
	
	inline SolidCollider() : CustomCollider(4, _170, _190, _210) {}
	
	void init(StageActor *, SolidCollisionInfo *);
	
	~SolidCollider();
	bool checkDerivedRuntimeTypeInfo(void *);
	//bool vf24(u32 *, u32);
	bool vf54(u8 *, Vec2 *);
};

struct SolidOnTopCollisionInfo {
	float _0[4];
	float *stuff;
	u32 rot;
};

class SolidOnTopCollider : public OtherColliderBase {
	public:
		u32 _158[2];
		u32 _160[2];
		u32 _168[2];
		u32 _16C;
		float _170;
		
		SolidOnTopCollider();
	
		void init(StageActor *, SolidOnTopCollisionInfo *, u32, u32);
	
		~SolidOnTopCollider();
		bool checkDerivedRuntimeTypeInfo(void *);
		//bool vf24(u32 *, u32);
		void vf34();
		void updateMovement();
		bool vf44(void *, u16 *, Vec2 *, Vec2 *, u32);
		bool vf4C(void *, Vec2 *, Vec2 *, u32, void *);
		bool vf54(u8 *, Vec2 *);
		void vf5C(); //deleted
		void vf64();
		void vf6C();
		void vf74(u32 *);
		bool vf7C(Vec2 *);
};

class OtherCollisionMgr {
	public:
		static OtherCollisionMgr *instance;
		void add(OtherColliderBase *);
};

struct CollisionInfo {
	float x;
	float y;
	float w;
	float h;
	u32 someKindOfFlag;
	u32 _14;
	u32 _18;
	u32 _1C;
	u32 _20;
	u32 flags;
	collisionCallback callback;
};

struct ColliderNode {
	Collider *owner;
	ColliderNode *next;
	ColliderNode *prev;
};

class Collider : public sead::IDisposer {
	public:
		ColliderNode activeNode;
		ColliderNode createNode;
		ColliderNode node3;
		ColliderNode node4;
		StageActor *owner;
		u32 somethingOwnerRelated;
		u32 _48;
		u32 _4C;
		u32 _50;
		Vec2 _54;
		u32 _5C;
		u32 _60;
		u32 _64;
		u32 _68;
		u8 stageActorField57;
		u8 layer;
		u8 flags;
		u8 _6F;
		u32 _70;
		CollisionInfo collisionInfo;
		u8 _A0[0x128 - 0xA0];
		
		void init(StageActor *, const CollisionInfo *, u32);
		
		~Collider();
};

class ColliderList {
	public:
	ColliderNode *first;
	ColliderNode *last;
	void *vtbl;
};

class CollisionMgr : public sead::IDisposer {
	public:
		static CollisionMgr *instance;
		ColliderList activeList;
		ColliderList createList;
		ColliderList list3;
		ColliderList list4;
		
		void addCollider(Collider *);
};

class WeirdBase {
	public:
	u8 _0;
	u8 _1;
	u8 _2;
	u8 _3;
	u32 _4;
	u32 _8;
	u32 _C;
	sead::PtrArrayImpl<void> someList;
	u32 someList_C;
	u8 someListBuffer[0xA * 4];
	u32 _48;
};

struct UsedByPhysics {
	u32 _0;
	Physics *physics;
	u32 _8;
};

struct UsedByPhysics2 {
	u32 _0;
	u32 _4;
};

struct UsedByPhysics3 {
	float max1;
	float max2;
	float min1;
	float min2;
};

struct UsedByPhysics4 {
	u8 _0[0x30];
};

class UsedByPhysics5b {
	public:
	u8 _0;
	u8 _1;
	u8 _2;
	u8 _3;
	u32 _4;
	u32 _8;
	Vec2 _C;
	Vec2 _14;
	u32 _1C;
	u32 _20;
	u32 _24;
	u32 _28;
	u32 _2C;
	float _30;
	u32 _34;
};

class UsedByPhysics5a {
	public:
	UsedByPhysics5b _0[6];
};

struct UsedByPhysics5 {
	UsedByPhysics5a _0[4];
};

class Physics : public WeirdBase {
	public:
	void *_4C;
	Physics *self;
	sead::PtrArrayImpl<void> someList2;
	u8 someList2Buffer[0x200 * 4];
	UsedByPhysics _860[4];
	u32 _890;
	u32 _894;
	u32 _898;
	u32 _89C;
	u32 _8A0;
	u32 _8A4;
	u32 _8A8;
	u32 collisionFlags[2];
	UsedByPhysics3 _8B4[5];
	Vec2 _904;
	float _90C;
	u32 _910;
	u8 _914;
	u8 _915;
	u8 _916;
	u8 _917;
	u8 _918[0x10];
	UsedByPhysics4 _928[3];
	u8 _9B8[0x18];
	u16 _9D0;
	u16 _9D2;
	UsedByPhysics2 _9D4[4];
	u8 _9F4[0x10];
	u8 _A04[0x10];
	u32 _A14;
	UsedByPhysics5 _A18[2];
	u8 _1498[0x20];
	u8 _14B8[0x20];
	u32 _14D8;
	
	Physics();
	
	void init(StageActor *, Vec3 *, Vec3 *, Vec3 *);
	
	virtual void vf0C(); //deleted
	virtual void vf14(); //deleted
	virtual ~Physics();
	virtual void processCollisions();
	virtual void vf2C();
	virtual void vf34();
	virtual u32 vf3C(); //pure
	virtual u32 vf44(void *, u32); //pure
	virtual u32 vf4C(); //pure
	virtual void vf54();
	virtual void vf5C();
	virtual void vf64();
	virtual void vf6C(u32);
};

class ActorPhysics : public Physics {
	public:
	ActorPhysics();
	
	u32 vf3C();
	u32 vf44(void *, u32);
	u32 vf4C();
};

class PlayerPhysics : public Physics {
	public:
	PlayerPhysics();
	
	u32 _14E0;
	u32 _14E4;
	u32 _14E8;
	u8 _14EC;
	u8 _14ED;
	u16 _14EE;
	u8 _14F0;
	u8 _14F1;
	u8 _14F2;
	u8 _14F3;
	u32 _14F4;
	u32 _14F8;
	float _14FC;
	float _1500;
	float _1504;
	float _1508;
	float _150C;
	float _1510;
	float _1514;
	float _1518;
	float _151C;
	float _1520;
	u32 _1524;
	UsedByPhysics5b _1528;
	UsedByPhysics5b _1560;
	u32 _1598;
	u32 _159C;
	
	~PlayerPhysics();
	void processCollisions();
	void vf2C();
	void vf34();
	u32 vf3C();
	u32 vf44(void *, u32);
	u32 vf4C();
};
