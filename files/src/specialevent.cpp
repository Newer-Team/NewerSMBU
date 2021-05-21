
#include "game.h"
#include "neweru.h"

class SpecialEvent : public StageActor {
	public:
		u32 visibility;
		u8 physics;
		bool revealMode;

		int onCreate();
		int onExecute();
	
		bool checkEvent();
	
		static Actor *build(ActorBuildInfo *);
		SpecialEvent(ActorBuildInfo *);
};

SpecialEvent::SpecialEvent(ActorBuildInfo *buildInfo) : StageActor(buildInfo) {}

Actor *SpecialEvent::build(ActorBuildInfo *buildInfo) {
	return new SpecialEvent(buildInfo);
}

const ActorInfo actorInfo = {0};
const Profile profile(SpecialEvent::build, COMBINATION_PLATFORM, "SpecialEvent", &actorInfo, 0);
const ActorFiles actorFiles((Actors)COMBINATION_PLATFORM, 0, 0);

int SpecialEvent::onCreate() {
	DEBUG("SpecialEvent::onCreate");
	physics = settings2 & 0xF;
	visibility = settings >> 24;
	revealMode = settings2 & 0x10;
	return 1;
}

int SpecialEvent::onExecute() {
	if (checkEvent()) {
		if (visibility) {
			CourseDarknessMgr::instance->visibility = visibility;
		}
	}
	return 1;
}

bool SpecialEvent::checkEvent() {
	if (!this->eventID_3_4) {
		return true;
	}

	return EventMgr::instance->events & (1 << (eventID_3_4 - 1));
}

u8 getPhysicsType() {
	Actor **actor = ActorMgr::instance->findActorByType(COMBINATION_PLATFORM, ActorMgr::instance->actorList.first);
	
	while (actor != ActorMgr::instance->actorList.last) {
		SpecialEvent *event = *(SpecialEvent **)actor;
		if (event->physics && event->checkEvent()) {
			return event->physics;
		}
		actor = ActorMgr::instance->findActorByType(COMBINATION_PLATFORM, actor + 1);
	}

	return 0;
}

bool isRevealMode() {
	Actor **actor = ActorMgr::instance->findActorByType(COMBINATION_PLATFORM, ActorMgr::instance->actorList.first);
	
	while (actor != ActorMgr::instance->actorList.last) {
		SpecialEvent *event = *(SpecialEvent **)actor;
		if (event->revealMode && event->checkEvent()) {
			return true;
		}
		actor = ActorMgr::instance->findActorByType(COMBINATION_PLATFORM, actor + 1);
	}

	return false;
}
