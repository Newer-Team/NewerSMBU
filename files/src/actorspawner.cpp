
#include "game.h"
#include "neweru.h"

class ActorSpawner : public StageActor {
	public:
	u16 spriteId;
	u32 actorSettings;
	
	int onCreate();
	int onExecute();
	
	static Actor *build(ActorBuildInfo *);
	ActorSpawner(ActorBuildInfo *);
};

ActorSpawner::ActorSpawner(ActorBuildInfo *buildInfo) : StageActor(buildInfo) {}

Actor *ActorSpawner::build(ActorBuildInfo *buildInfo) {
	return new ActorSpawner(buildInfo);
}

const ActorInfo actorInfo = {0};
const Profile profile(ActorSpawner::build, ROTATING_TURRET, "ActorSpawner", &actorInfo, 0);
const ActorFiles actorFiles(ROTATING_TURRET, 0, 0);

int ActorSpawner::onCreate() {
	spriteId = settings & 0xFFF;
	actorSettings = (settings & 0xFFFF0000) | (eventID_3_4 << 8) | linkId;
	
	if (!eventID_1_2) {
		DEBUG("ActorSpawner without triggering event id.");
		return 2;
	}
	return 1;
}

int ActorSpawner::onExecute() {
	if (EventMgr::instance->events & (1 << (eventID_1_2 - 1))) {
		ActorBuildInfo buildInfo;
		__memzero(&buildInfo, sizeof(buildInfo));
		if ((settings >> 12) & 2) {
			buildInfo.profile = Profile::Get((Actors)spriteId);
		}
		else {
			buildInfo.profile = Profile::Get(spriteToActorList[spriteId]);
		}
		buildInfo.position.X = this->position.X;
		buildInfo.position.Y = this->position.Y;
		buildInfo.position.Z = this->position.Z;
		buildInfo.settings = actorSettings;
		buildInfo.settings2 = settings2;
		buildInfo.movementId = movementId;
		buildInfo.linkId = initStateFlag;
		buildInfo.initStateFlag = (settings >> 12) & 0x1;
		buildInfo.layer = layer;
		ActorMgr::instance->createActor(&buildInfo, 0);
		this->deleted = true;
	}
	return 1;
}
