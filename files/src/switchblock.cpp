
#include "game.h"
#include "neweru.h"

class SwitchBlock : public StageActor {
	public:
	Location *location1;
	Location *location2;
	u8 layer;
	bool state;
	
	int onCreate();
	
	void swapTiles();
	void setLocation(Location *);
	
	static void handleJump();
	
	static Actor *build(ActorBuildInfo *);
	SwitchBlock(ActorBuildInfo *);
};

SwitchBlock::SwitchBlock(ActorBuildInfo *buildInfo) : StageActor(buildInfo) {}

Actor *SwitchBlock::build(ActorBuildInfo *buildInfo) {
	return new SwitchBlock(buildInfo);
}

const ActorInfo actorInfo = {0};
const Profile profile(SwitchBlock::build, TREASURE_KEY, "SwitchBlock", &actorInfo, 0);
const ActorFiles actorFiles((Actors)TREASURE_KEY, 0, 0);

int SwitchBlock::onCreate() {
	LevelArea *area = Level::instance->getArea(LevelInfo::instance->area);
	location1 = area->getLocationById(0, (settings >> 16) & 0xFF);
	location2 = area->getLocationById(0, settings >> 24);
	layer = settings2 & 0xF;
	
	if (!location1) {
		DEBUG("SwitchBlock location1 not found.");
		return 2;
	}
	if (!location2) {
		DEBUG("SwitchBlock location2 not found.");
		return 2;
	}
	
	if (settings2 & 0x10) {
		setLocation(location2);
		state = 1;
	}
	else {
		setLocation(location1);
		state = 0;
	}
	return 1;
}

void SwitchBlock::setLocation(Location * loc) {
	copyTilesInLocation(loc, position.X, position.Y, layer);
}

void SwitchBlock::swapTiles() {
	if (state == 0) {
		setLocation(location2);
		state = 1;
	}
	else {
		setLocation(location1);
		state = 0;
	}
}

void SwitchBlock::handleJump() {
	Actor **block = ActorMgr::instance->findActorByType(TREASURE_KEY, ActorMgr::instance->actorList.first);
	while (block != ActorMgr::instance->actorList.last) {
		(*(SwitchBlock **)block)->swapTiles();
		block = ActorMgr::instance->findActorByType(TREASURE_KEY, block + 1);
	}
}
