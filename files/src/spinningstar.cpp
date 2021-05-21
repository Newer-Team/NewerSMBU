
#include "game.h"
#include "neweru.h"

class MovingSpinningStar : public SpinningStar {
	public:
	MovementHandler mover;
	
	int onCreate();
	int onExecute();
	
	MovingSpinningStar(ActorBuildInfo *);
	static Actor *build(ActorBuildInfo *);
};

const Profile profile(MovingSpinningStar::build, SPINNING_STAR, "SpinningStar", &SpinningStar::actorInfo, 2);

MovingSpinningStar::MovingSpinningStar(ActorBuildInfo *buildInfo) : SpinningStar(buildInfo) {}
Actor *MovingSpinningStar::build(ActorBuildInfo *buildInfo) {
	return new MovingSpinningStar(buildInfo);
}

int MovingSpinningStar::onCreate() {
	MovementType movementType = (MovementType)(settings2 & 0xF);
    u32 movementTypeMask = mover.getMaskForMovementType(movementType);
    mover.linkToMovementController(&position, movementTypeMask, movementId);
	return SpinningStar::onCreate();
}

int MovingSpinningStar::onExecute() {
	mover.execute();
    position.X = mover.position.X;
    position.Y = mover.position.Y;
	return SpinningStar::onExecute();
}
