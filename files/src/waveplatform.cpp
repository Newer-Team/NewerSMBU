
#include "game.h"
#include "neweru.h"

class WavePlatform : public StageActor {
	public:
	SolidOnTopCollider solidOnTop;
	PlatformModel model;
	float targetpos;
	u32 targetrot;
	bool offscreen;
	u8 width;
	
	int onCreate();
	int onExecute();
	int onDraw();
	
	bool updateWaveTargets();
	
	static Actor *build(ActorBuildInfo *);
	WavePlatform(ActorBuildInfo *);
};

const ActorInfo actorInfo = {0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0};
const Profile profile(WavePlatform::build, LINE_MUSHROOM_BLOCK, "WavePlatform", &actorInfo, 0);

const sead::String fileList[] = {"lift_han_wood", "lift_han_stone",
								 "lift_kinoko_yoko", "lift_han_spin",
								 "lift_kinoko_shiso", "lift_han_sky"};
const ActorFiles actorFiles(LINE_MUSHROOM_BLOCK, 6, fileList);
 
WavePlatform::WavePlatform(ActorBuildInfo *buildInfo) : StageActor(buildInfo) {}
 
Actor *WavePlatform::build(ActorBuildInfo *buildInfo) {
	return new WavePlatform(buildInfo);
}
 
int WavePlatform::onCreate() {
	width = settings & 0xF;
	if (width < 2) width = 2;
	
	Vec3i nullvec3i = {0, 0, 0};
	Vec3 nullvec3 = {0, 0, 0};
	model.type = (PlatformType)(settings >> 28);
	model.width = width;
	model.rotation = nullvec3i;
	model._A0 = nullvec3;
	model.init();
	 
	float stuff[] = {4.0 - width * 8.0, 8.0, -4.0 + width * 8.0, 8.0};
	SolidOnTopCollisionInfo collisionInfo = {
		0.0, 0.0, 0.0, 0.0, stuff, 0
	};
	solidOnTop.init(this, &collisionInfo, 2, 0);
	OtherCollisionMgr::instance->add(&solidOnTop);

	offscreen = true;
	onExecute();

	return 1;
}

int WavePlatform::onExecute() {
	if (!updateWaveTargets()) {
		offscreen = true;
		return 1;
	}
	
	//There are not *exactly* 18 blocks between each wave
	//To prevent a sudden jump in height and tilt, set a
	//target and move towards it by a certain amount
	//
	//However, if the platform is off screen, it can move
	//to a Y-position of -8192. In that case, immediately
	//change its values to their targets.
	if (offscreen) {
		position.Y = targetpos;
		rotation.Z = targetrot;
		offscreen = false;
	} else {
		moveFloatTo(&position.Y, targetpos, 2.0);
		moveValueTo(&rotation.Z, targetrot, 0x01800000);
	}
	
	solidOnTop.zrot = rotation.Z;
	solidOnTop.updateMovement();

	Vec3 modelpos = {position.X - width * 8.0, position.Y, position.Z};
	model.rotation.Z = rotation.Z;
	model.update(&modelpos, width * 16.0);
	return 1;
}

int WavePlatform::onDraw() {
	model.draw();
	return 1;
}

bool WavePlatform::updateWaveTargets() {
	float leftedge = LevelCamera::instance->someRects[0].left;
	
	//There are about 18 blocks between each wave; 144 = 0.5 * (18 * 16)
	//Return when even the next wave is off screen, platform is invisible anyway
	//Wave list contains 1280 floats, but entries behind the right edge of the
	//screen are set to -8192.
	s32 index = (s32)((position.X - leftedge) * 0.5 + 0.5);
	
	if (index < 10 - 144 || index >= 1190 + 1140) return 0;
	
	if (index < 10) index += 144;
	if (index >= 1190) index -= 144;
	
	if (TileMgr::instance->waveFloats2[index + 10] == -8192) index -= 144;
	
	//Take an average to soften the impact of the small waves
	//on top of the big waves
	float ypos_l, ypos_m, ypos_r;
	ypos_m = TileMgr::instance->waveFloats2[index];
	ypos_l = TileMgr::instance->waveFloats2[index - 10];
	ypos_r = TileMgr::instance->waveFloats2[index + 10];
	targetpos = (ypos_l + ypos_m + ypos_r) / 3 + 4.0;
	
	if (ypos_m == -8192 || ypos_l == -8192 || ypos_r == -8192
		|| ypos_m == 0 || ypos_l == 0 || ypos_r == 0) return 0;
	
	//Take an average here as well
	float ydiff1 = ypos_m - ypos_l;
	float ydiff2 = ypos_r - ypos_m;
	float ydiffavg = (ydiff1 + ydiff2) / 2;
	targetrot = (u32)(atan2f(ydiffavg, 20.0) / (2 * PI) * 0x100000000);

	return 1;
}
