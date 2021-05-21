
#include "game.h"
#include "neweru.h"

class WindActor : public WindGenerator {
	public:
	EffectHandler windEffect;
	
	int onCreate();
	int onExecute();
	
	WindActor(ActorBuildInfo *);
	static Actor *build(ActorBuildInfo *);
	
	void updateEffects();
};

WindActor::WindActor(ActorBuildInfo *buildInfo) : WindGenerator(buildInfo) {}
Actor *WindActor::build(ActorBuildInfo *buildInfo) {
	return new WindActor(buildInfo);
}

const ActorInfo actorInfo = {0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0};
const Profile profile(WindActor::build, WIND_GENERATOR, "WindActor", &actorInfo, 0);

sead::String fileList[] = {"env_snow"};
const ActorFiles actorFiles(WIND_GENERATOR, 1, fileList);

int WindActor::onCreate() {
	WindGenerator::onCreate();
	return 1;
}

// actors that will be affected by wind
Actors windActors[] = {
	GOOMBA, PARAGOOMBA,
	KOOPA_TROOPA, KOOPA_PARATROOPA,
	BUZZY_BEETLE, SPIKE_TOP, SPINY, POKEY,
	BUBBLE_BABY_YOSHI, BALLOON_BABY_YOSHI, GLOW_BABY_YOSHI
};
int WindActor::onExecute() {
	if (settings2 & 1) {
		u32 blarg = 0;
		s32 tilt = InputMgr::instance->controllers[0].getTilt(&blarg, 0.5);
		finalWindStrength = (float)tilt * windStrengthValue / 0x20000000;
		
		if (finalWindStrength > 0.5 * windStrengthValue || finalWindStrength < -0.5 * windStrengthValue) {
			updateEffects();
		}
	}
	else {
		WindGenerator::onExecute();
		if (windState == 0 || windState == 1) updateEffects();
	}
	
	if (!(settings2 & 2)) {
		for (int i = 0; i < 4; i++) {
			Player *player = PlayerMgr::instance->players[i];
			if (player) {
				player->position.X += finalWindStrength * 2.5;
			}
		}
		
		Actor **current = ActorMgr::instance->actorList.first;
		while (current < ActorMgr::instance->actorList.last) {
			Actor *actor = *current;
			if (actor) {
				Actors profileId = actor->getProfileId();
				for (u32 i = 0; i < 13; i++) {
					if (windActors[i] == profileId) {
						((StageActor *)actor)->position.X += finalWindStrength * 2.5;
						break;
					}
				}
			}
			current++;
		}
	}
	return 1;
}

void WindActor::updateEffects() {
	AmbientSoundPlayer::instance->updateSound("SE_AMB_RP_BIG_WINDY", 1);
	
	Vec3 pos = {0, 0, 0};
	Vec3 scale = {1, 1, 1};
	if (finalWindStrength > 0) {
		pos.X = 1024;
		scale.X = -1;
	}
	windEffect.update(RP_UI_BoostLine_loop, &pos, 0, &scale);
}
