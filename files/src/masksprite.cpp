
#include "game.h"
#include "neweru.h"
#include "groundmask.h"

//Replaces sprite 360
class MaskSprite : public StageActor {
	public:
	MaskTexture::Shape shape;
	agl::TextureData texdata;
	MovementHandler movement;
	float radius;
	u8 type;
	
	int onCreate();
	int onExecute();
	int onDraw();
	
	MaskSprite(ActorBuildInfo *);
	static Actor *build(ActorBuildInfo *);
};

MaskSprite::MaskSprite(ActorBuildInfo *buildInfo) : StageActor(buildInfo) {}
Actor *MaskSprite::build(ActorBuildInfo *buildInfo) {
	return new MaskSprite(buildInfo);
}

const ActorInfo actorInfo = {0};
const Profile profile(MaskSprite::build, BOLT_CONTROLLED_WIRE, "MaskSprite", &actorInfo, 0);

const ActorFiles actorFiles(BOLT_CONTROLLED_WIRE, 0, 0);

int MaskSprite::onCreate() {
	radius = settings2 & 0xFF;
	type = settings2 >> 28;
	
	shape = (MaskTexture::Shape)((settings2 >> 8) & 0xF);
	MaskTexData::loadTexture(shape, &texdata);
	
	MovementType movementType = (MovementType)(settings >> 28);
	u32 movementTypeMask = movement.getMaskForMovementType(movementType);
	movement.linkToMovementController(&position, movementTypeMask, movementId);
	return 1;
}

int MaskSprite::onExecute() {
	movement.execute();
	position.X = movement.position.X;
	position.Y = movement.position.Y;
	rotation.Z = movement.zRotation;
	return 1;
}

int MaskSprite::onDraw() {
	MaskInfo tl = {{position.X - radius, position.Y - radius}, 1, {0, 0}};
	MaskInfo tr  = {{position.X + radius, position.Y - radius}, 1, {1, 0}};
	MaskInfo br = {{position.X + radius, position.Y + radius}, 1, {1, 1}};
	MaskInfo bl = {{position.X - radius, position.Y + radius}, 1, {0, 1}};
	if (type == 0) ((NewerBgRenderer *)BgRenderer::instance)->revealMasks.add(&tl, &tr, &br, &bl, &texdata, 3);
	else if (type == 1) BgRenderer::instance->layerMasks.add(&tl, &tr, &br, &bl, &texdata, 3);
	else if (type == 2) BgRenderer::instance->lightMasks.add(&tl, &tr, &br, &bl, &texdata, 3);
	return 1;
}
