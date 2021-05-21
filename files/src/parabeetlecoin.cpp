
#include "game.h"
#include "neweru.h"

class ParabeetleCoin : public CoinBase {
	public:
	StageActor *beetle;
	Vec3 offset;
	
	int onCreate();
	int onExecute();
	
	bool searchBeetle();
	void connectBeetle(StageActor *beetle);
	void updateBeetle();
	
	ParabeetleCoin(ActorBuildInfo *);
	static Actor *build(ActorBuildInfo *);
};

ParabeetleCoin::ParabeetleCoin(ActorBuildInfo *buildInfo) : CoinBase(buildInfo) {}
Actor *ParabeetleCoin::build(ActorBuildInfo *buildInfo) {
	return new ParabeetleCoin(buildInfo);
}
const ActorInfo actorInfo = {0};
const Profile profile(ParabeetleCoin::build, COOKIE, "ParabeetleCoin", &actorInfo, 0);

const sead::String fileList[] = {"obj_coin"};
const ActorFiles actorFiles(COOKIE, 1, fileList);

int ParabeetleCoin::onCreate() {
	init();
	initCollider(1);
	doStateChange(&StateID_Main);
	
	beetle = 0;
	searchBeetle();
	return 1;
}

int ParabeetleCoin::onExecute() {
	stateMgr.stateClass.executeState();
	updateBeetle();
	solidColl.updateMovement();
	return 1;
}

bool ParabeetleCoin::searchBeetle() {
	Actor **current = ActorMgr::instance->actorList.first;
	while (current < ActorMgr::instance->actorList.last) {
		Actor *actor = *current;
		if (actor) {
			Actors profileId = actor->getProfileId();
			if (profileId == PARABEETLE || profileId == BIG_PARABEETLE) {
				if (actor->linkId == this->linkId) {
					connectBeetle((StageActor *)actor);
					return true;
				}
			}
		}
		current++;
	}
	return false;
}

void ParabeetleCoin::connectBeetle(StageActor *beetle) {
	this->beetle = beetle;
	offset.X = beetle->position.X - position.X;
	offset.Y = beetle->position.Y - position.Y;
	offset.Z = beetle->position.Z - position.Z;
}

void ParabeetleCoin::updateBeetle() {
	if (!beetle) {
		if (!searchBeetle()) {
			return;
		}
	}
	
	if (!beetle->deleted) {
		position.X = beetle->position.X + offset.X;
		position.Y = beetle->position.Y + offset.Y;
		position.Z = beetle->position.Z + offset.Z;
	}
}
