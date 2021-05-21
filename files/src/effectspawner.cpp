
// replaces sprite 202
#include "game.h"
#include "neweru.h"
 
class EffectSpawner : public StateActor {
    public:
        Effects effectId; // ID of the effect spawned
        u16 soundId; // ID of the sound spawned
		bool multiUse;
		bool updateEffect;
		
		MovementHandler movement;
		EffectHandler effect;
 
        int onCreate(); // on creation
        int onExecute(); // on execution
     
        static Actor *build(ActorBuildInfo *);
        EffectSpawner(ActorBuildInfo *);
		
		DECLARE_STATE(EffectSpawner, Wait)
		DECLARE_STATE(EffectSpawner, Spawn)
};

CREATE_STATE(EffectSpawner, Wait)
CREATE_STATE(EffectSpawner, Spawn)
 
EffectSpawner::EffectSpawner(ActorBuildInfo *buildInfo) : StateActor(buildInfo) {}
 
Actor *EffectSpawner::build(ActorBuildInfo *buildInfo) {
    return new EffectSpawner(buildInfo);
}
 
const ActorInfo actorInfo = {0}; // we don't load models
const Profile profile(EffectSpawner::build, PROPELLER_BLOCK, "EffectSpawner", &actorInfo, 0);
const ActorFiles actorFiles(PROPELLER_BLOCK, 0, 0);

float effectScaleValues[] = {1.0, 0.1, 0.25, 0.5, 0.75, 0.8, 0.9, 1.1, 1.2, 1.25, 1.5, 2.0, 2.5, 3.0, 4.0, 5.0};
 
int EffectSpawner::onCreate() {
	float individualscale = effectScaleValues[(settings >> 28)];
	Vec3 newscale;
	newscale.X = individualscale;
	newscale.Y = individualscale;
	newscale.Z = individualscale;
	this->scale = newscale;
	
	rotation.Z = (settings & 0xFF) << 24;
	
	effectId = (Effects)((settings >> 12) & 0xFFF); // nybble 7-9
	soundId = settings2 & 0xFFF;
	multiUse = (settings >> 24) & 1;
	updateEffect = (settings >> 25) & 1;
	
	MovementType movementType = (MovementType)((settings >> 8) & 0xF);
    u32 movementTypeMask = movement.getMaskForMovementType(movementType);
    movement.linkToMovementController(&position, movementTypeMask, movementId);

	// not hooked into an event
    if (!this->eventID_3_4) {
        DEBUG("EffectSpawner: No event found. Deleting.");
        return 2;
    }
	
	doStateChange(&StateID_Wait);
	
    return 1;
}
 
int EffectSpawner::onExecute() {
	movement.execute();
    position.X = movement.position.X;
    position.Y = movement.position.Y;
    rotation.Z = movement.zRotation;
	
	stateMgr.stateClass.executeState();
	return 1;
}

void EffectSpawner::beginState_Wait() {}
void EffectSpawner::executeState_Wait() {
	// if the event is activated...
    if (EventMgr::instance->events & (1 << (eventID_3_4 - 1))) {
		doStateChange(&StateID_Spawn);
    }
}
void EffectSpawner::endState_Wait() {}

void EffectSpawner::beginState_Spawn() {
	if (soundId != 0xFFF) {
		Vec2 screenPos;
		Vec2 soundPos = {position.X, position.Y};
		mapPosToScreen(&screenPos, &soundPos);
		
		nw::snd::SoundArchive *soundArchive = SoundSystem::instance->getSoundArchive();
		char *soundName = soundArchive->fileReader->stringBlock->GetString(soundId);
		if (!soundName) {
			DEBUG("Invalid sound id");
			return;
		}
		BasicSoundActor::instance->playSound(soundName, &screenPos, 1);
	}
	if (effectId != 0xFFF) {
		if (!updateEffect) {
			spawnEffect(effectId, &position, &rotation, &scale);
		}
	}
}
void EffectSpawner::executeState_Spawn() {
	if (!(EventMgr::instance->events & (1 << (eventID_3_4 - 1)))) {
		if (multiUse) doStateChange(&StateID_Wait);
		else deleted = true;
	} else {
		if (updateEffect) {
			Mtx matrix;
			calcMatrix(&matrix, &rotation, &position);
			effect.update(effectId, &matrix, false);
		}
	}
}
void EffectSpawner::endState_Spawn() {}
