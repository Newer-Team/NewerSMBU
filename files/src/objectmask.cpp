
#include "game.h"
#include "neweru.h"
#include "groundmask.h"

//Replaces sprite 358
class ObjectMask : public StageActor {
	public:
	agl::TextureData texdata;
	
	int onCreate();
	int onExecute();
	int onDraw();
	
	void addMask(Vec3 *pos, float radius);
	
	ObjectMask(ActorBuildInfo *);
	static Actor *build(ActorBuildInfo *);
};

ObjectMask::ObjectMask(ActorBuildInfo *buildInfo) : StageActor(buildInfo) {}
Actor *ObjectMask::build(ActorBuildInfo *buildInfo) {
	return new ObjectMask(buildInfo);
}

const ActorInfo actorInfo = {0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0};
const Profile profile(ObjectMask::build, SCAFFOLD_WITH_BOLT, "ObjectMask", &actorInfo, 0);

const ActorFiles actorFiles(SCAFFOLD_WITH_BOLT, 0, 0);

int ObjectMask::onCreate() {
	DEBUG("ObjectMask::onCreate()");
	MaskTexData::loadTexture(MaskTexture::cave, &texdata);
	onExecute();
	return 1;
}

int ObjectMask::onExecute() {
	StageActor *player = PlayerMgr::instance->players[0];
	position = player->position;
	return 1;
}

struct ActorMask {
	Actors actor;
	float radius;
};
ActorMask actorMasks[] = {
	GOOMBA, 16,
	PARAGOOMBA, 16,
	KOOPA_TROOPA, 16,
	KOOPA_PARATROOPA, 16,
	BUZZY_BEETLE, 16,
	SPIKE_TOP, 16,
	SPINY, 16,
	
	QSWITCH, 16,
	PSWITCH, 16,
	
	BUBBLE_BABY_YOSHI, 24,
	BALLOON_BABY_YOSHI, 24,
	GLOW_BABY_YOSHI, 24,
	
	MUSHROOM, 16,
	FIRE_FLOWER, 16,
	ICE_FLOWER, 16,
	PROPELLER_MUSHROOM, 16,
	PENGUIN_MUSHROOM, 16,
	ACORN_MUSHROOM, 16,
	MINI_MUSHROOM, 16,
	LIFE_MUSHROOM, 16,
	LIFE_MOON, 16,
	
	PLAYER_ICEBALL, 12,
	PLAYER_FIREBALL, 12
};
int ObjectMask::onDraw() {
	addMask(&position, 48);
	Actor **current = ActorMgr::instance->actorList.first;
	while (current < ActorMgr::instance->actorList.last) {
		Actor *actor = *current;
		if (actor) {
			Actors profileId = actor->getProfileId();
			for (u32 i = 0; i < 14; i++) {
				if (actorMasks[i].actor == profileId) {
					addMask(&((StageActor *)actor)->position, actorMasks[i].radius);
					break;
				}
			}
		}
		current++;
	}
	return 1;
}

void ObjectMask::addMask(Vec3 *pos, float radius) {
	MaskInfo tl = {{pos->X - radius, pos->Y - radius}, 1, {0, 0}};
	MaskInfo tr  = {{pos->X + radius, pos->Y - radius}, 1, {1, 0}};
	MaskInfo br = {{pos->X + radius, pos->Y + radius}, 1, {1, 1}};
	MaskInfo bl = {{pos->X - radius, pos->Y + radius}, 1, {0, 1}};
	((NewerBgRenderer *)BgRenderer::instance)->revealMasks.add(&tl, &tr, &br, &bl, &texdata, 3);
}
