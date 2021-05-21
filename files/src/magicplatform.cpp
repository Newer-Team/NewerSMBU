
#include "game.h"
#include "neweru.h"
 
class MagicPlatform : public StageActor {
    public:
	u8 collisionType;
	u8 locw;
	u8 loch;
	Location *location;
	SolidCollider solidCollision;
	SolidOnTopCollider solidOnTopCollision;
	MovementHandler movement;

    int onCreate();
	int onExecute();
    int onDraw();
     
    static Actor *build(ActorBuildInfo *);
    MagicPlatform(ActorBuildInfo *);
};
 
const ActorInfo actorInfo = {8.0, -8.0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const Profile profile(MagicPlatform::build, ICE_LIFT, "MagicPlatform", &actorInfo, 0);
 
const ActorFiles actorFiles(ICE_LIFT, 0, 0);

MagicPlatform::MagicPlatform(ActorBuildInfo *buildInfo) : StageActor(buildInfo) {}
 
Actor *MagicPlatform::build(ActorBuildInfo *buildInfo) {
    return new MagicPlatform(buildInfo);
}

int MagicPlatform::onCreate() {
	collisionType = (settings & 0xF00) >> 8;
	u8 locationId = settings & 0xFF;
	
	u8 areaNum = LevelInfo::instance->area;
	LevelArea *area = Level::instance->getArea(areaNum);
	location = area->getLocationById(0, locationId);
	
	if (!location) {
		DEBUG("MagicPlatform location not found.");
		return 2;
	}
	
	locw = (location->w >> 4) + 1;
	loch = (location->h >> 4) + 1;
	
	if (collisionType == 1) {
		SolidCollisionInfo solidCollisionInfo = {
			0.0, 0.0, 0.0, 0.0, -8.0, 8.0, -8.0 + locw * 16.0, 8.0 + -loch * 16.0, 0
		};
		solidCollision.init(this, &solidCollisionInfo);
		OtherCollisionMgr::instance->add(&solidCollision);
	}
	else if (collisionType == 2) {
		float stuff[] = {-8.0, 8.0, -8.0 + locw * 16.0, 8.0};
		SolidOnTopCollisionInfo collisionInfo = {
			0.0, 0.0, 0.0, 0.0, stuff, 0
		};
		solidOnTopCollision.init(this, &collisionInfo, 2, 0);
		OtherCollisionMgr::instance->add(&solidOnTopCollision);
	}
	
	MovementType movementType = (MovementType)((settings >> 12) & 0xF);
	u32 movementTypeMask = movement.getMaskForMovementType(movementType);
	movement.linkToMovementController(&position, movementTypeMask, movementId);

	return 1;
}

int MagicPlatform::onExecute() {
	movement.execute();
	position.X = movement.position.X;
	position.Y = movement.position.Y;
	rotation.Z = movement.zRotation;
	
	if (collisionType == 1) {
		solidCollision.zrot = rotation.Z;
		solidCollision.updateMovement();
	}
	else if (collisionType == 2) {
		solidOnTopCollision.zrot = rotation.Z;
		solidOnTopCollision.updateMovement();
	}
	return 1;
}

#include "../codehandler/src/globals.h"

int MagicPlatform::onDraw() {
	Vec2 horizontalOffset;
	Vec2 verticalOffset;
	float angle = ((float)rotation.Z / 0x100000000) * PI * 2;
	horizontalOffset.X = cosf(angle) * 16.0;
	horizontalOffset.Y = sinf(angle) * 16.0;
	verticalOffset.X = sinf(angle) * 16.0;
	verticalOffset.Y = -cosf(angle) * 16.0;
	
	for (int x = 0; x < locw; x++) {
		for (int y = 0; y < loch; y++) {
			u16 *tilePtr = TileMgr::instance->getTilePointer(location->x + x * 16, location->y + y * 16, 0, 0);
			if (tilePtr) {
				u16 tile = *tilePtr;
				float targetx = position.X + horizontalOffset.X * x + verticalOffset.X * y;
				float targety = position.Y + horizontalOffset.Y * x + verticalOffset.Y * y;
				Vec3 targetpos = {targetx, targety, position.Z};
				Drawer::instance->drawTile(tile, &targetpos, &rotation.Z, &scale);
			} else {
				DEBUG("MagicPlatform getTilePointer returned null pointer.");
				deleted = true;
				return 1;
			}
		}
	}
    return 1;
}
