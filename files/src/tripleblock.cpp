
#include "game.h"
#include "neweru.h"

//Replaces sprite 178, actor 0x42

class TripleBlock : public BlockBase {
	public:
	u8 contentLeft;
	u8 contentCenter;
	u8 contentRight;
	bool multiLeft;
	bool multiCenter;
	bool multiRight;
	bool isUsed;
	
	int onCreate();
	int onDraw();
	
	void spawnItemUp();
	void spawnItemDown();
	
	void updateModel();
	void spawnItems();
	void spawnItem(u8 item, bool multi);
	void spawnSwitch(Actors actorId);
	void spawnBabyYoshiEgg(u8 type);

	static Actor *build(ActorBuildInfo *);
	TripleBlock(ActorBuildInfo *);
};

const ActorInfo actorInfo = {8.0, -16.0};
const Profile profile(TripleBlock::build, ROTATING_TURRET_BIG, "TripleBlock", &actorInfo, 0);

const sead::String fileList[] = {"switch", "YoshiChibi_TexBubble",
								 "YoshiChibi_TexBalloon", "YoshiChibi_TexLight",
								 "I_yoshichibi_egg", "balloon"};
const ActorFiles actorFiles(ROTATING_TURRET_BIG, 6, fileList);

TripleBlock::TripleBlock(ActorBuildInfo *buildInfo) : BlockBase(buildInfo) {}

Actor *TripleBlock::build(ActorBuildInfo *buildInfo) {
	return new TripleBlock(buildInfo);
}

int TripleBlock::onCreate() {
	if (!init(true, true)) return 2;
	
	contentLeft = settings >> 24;
	contentCenter = (settings >> 16) & 0xFF;
	contentRight = (settings >> 8) & 0xFF;
	
	multiLeft = settings & 4;
	multiCenter = settings & 2;
	multiRight = settings & 1;
	
	Vec2 topLeft = {-24.0, 16.0};
	Vec2 bottomRight = {24.0, 0.0};
	solidColl.setRect(&topLeft, &bottomRight);
	
	doStateChange(&StateID_Wait);
	return 1;
}

int TripleBlock::onDraw() {
	Vec3 Pos1 = {this->position.X - 16, this->position.Y + 8, this->position.Z};
	Vec3 Pos2 = {this->position.X +  0,	this->position.Y + 8, this->position.Z};
	Vec3 Pos3 = {this->position.X + 16,	this->position.Y + 8, this->position.Z};

	if (isUsed) {
		Drawer::instance->drawTile(0xAA, &Pos1, &rotation.Z, &scale);
		Drawer::instance->drawTile(0xAB, &Pos1, &rotation.Z, &scale);
		Drawer::instance->drawTile(0xAC, &Pos1, &rotation.Z, &scale);
	} else {
		Drawer::instance->drawTile(0xA7, &Pos1, &rotation.Z, &scale);
		Drawer::instance->drawTile(0xA8, &Pos2, &rotation.Z, &scale);
		Drawer::instance->drawTile(0xA9, &Pos3, &rotation.Z, &scale);
	}
	return 1;
}

void TripleBlock::spawnItemUp() {
	spawnItems();
}

void TripleBlock::spawnItemDown() {
	spawnItems();
}

void TripleBlock::spawnItems() {
	bool multi = ItemSpawner::instance->getExtraPlayerCount() > 0;
	spawnItem(contentCenter, multi && multiCenter);
	position.X -= 16;
	spawnItem(contentLeft, multi && multiLeft);
	position.X += 32;
	spawnItem(contentRight, multi && multiRight);
	position.X -= 16;

	isUsed = true;
	doStateChange(&StateID_Used);
	solidColl.collCB1 = BlockBase::otherCollisionCallback1;
	solidColl.collCB2 = BlockBase::otherCollisionCallback2;
	solidColl.collCB3 = BlockBase::otherCollisionCallback3;
}

void TripleBlock::spawnItem(u8 item, bool multi) {
	if (item == 0) return;
	else if (item == 1) spawnPortableSpring();
	else if (item == 2) spawnVine();
	else if (item == 3) spawnYoshiEgg(multi);
	else if (item <= 15) {
		content = item - 4;
		if (multi) spawnMultiPowerup(&position, 0, 1, false);
		else spawnPowerup(&position, 0, 1, false);
	}
	else if (item == 16) CoinMgr::instance->spawnItemCoin(&position, spawnDirection, hitPlayerId);
	else if (item == 17) spawnSwitch(QSWITCH);
	else if (item == 18) spawnSwitch(PSWITCH);
	else if (item <= 21) spawnBabyYoshiEgg(item - 19);
}

void TripleBlock::spawnSwitch(Actors actorId) {
	ActorBuildInfo buildInfo;
	OSBlockSet(&buildInfo, 0, sizeof(buildInfo));
	
	u32 settings = 0x10000000;
	settings |= spawnDirection == Down;
	settings |= settings2 & 0x100000; //Non-timed
	settings |= settings2 & 0x1000; //Deactivates target
	settings |= settings2 & 0x100; //Multiple uses
	
	Vec3 pos = position;
	if (spawnDirection == Up) pos.Y += 24.0;
	else pos.Y -= 16.0;
	
	buildInfo.profile = Profile::Get(actorId);
	buildInfo.settings = settings;
	buildInfo.Nybble3_4 = eventID_3_4;
	buildInfo.position = pos;
	buildInfo.layer = layer;
	ActorMgr::instance->createActor(&buildInfo, 0);
	
	Vec3 effectPos = pos;
	effectPos.Z = 4500.0;
	spawnEffect(RP_CSelect_AppSmoke, &effectPos, 0, 0);
	
	Vec2 screenPos;
	Vec2 soundPos = {position.X, position.Y};
	mapPosToScreen(&screenPos, &soundPos);
	BasicSoundActor::instance->playSound("SE_OBJ_SWITCH_APP", &screenPos, 1);
}

void TripleBlock::spawnBabyYoshiEgg(u8 type) {
	Vec3 eggPos = {position.X, position.Y - 8.0, position.Z};
	if (spawnDirection == Up) {
		eggPos = (Vec3){position.X, position.Y + 14.0, position.Z};
	}
	YoshiMgr::instance->spawnBabyEgg(&eggPos, type, 1 + (spawnDirection == Down));
	
	Vec2 screenPos;
	Vec2 soundPos = {eggPos.X, eggPos.Y};
	mapPosToScreen(&screenPos, &soundPos);
	BasicSoundActor::instance->playSound("SE_OBJ_ITEM_APPEAR", &screenPos, 1);
}
