
#include "game.h"
#include "neweru.h"

class EventWaves {
	public:
	float flatHeight;
	float waveHeight;
	u32 waveSpeed;
	u8 eventId;
	
	void init(TerrainEffects *terrain, float flatHeight, float animSpeed, u8 eventId);
	void update(TerrainEffects *terrain);
};

class NewerWater : public Water {
	public:
	EventWaves waves;
	
	int updateWaveEvents();
};

class NewerPoison : public PoisonWater {
	public:
	EventWaves waves;
	
	int updateWaveEvents();
};

void EventWaves::init(TerrainEffects *terrain, float flatHeight, float animSpeed, u8 eventId) {
	terrain->waveAnimSpeed = (u32)(animSpeed * 0x80000000 / 180);
	terrain->waveAnimHeight = 1.55;
	this->flatHeight = flatHeight;
	this->eventId = eventId;
	if (eventId) {
		waveHeight = terrain->waveHeight;
		waveSpeed = terrain->waveSpeed;
		if (!(EventMgr::instance->events & (1 << (eventId - 1)))) {
			terrain->waveHeight = flatHeight;
			terrain->waveSpeed = 0;
		}
	}
}

void EventWaves::update(TerrainEffects *terrain) {
	if (eventId) {
		float targetHeight = flatHeight;
		u32 targetSpeed = 0;
		if (EventMgr::instance->events & (1 << (eventId - 1))) {
			targetHeight = waveHeight;
			targetSpeed = waveSpeed;
		}
		moveFloatTo(&terrain->waveHeight, targetHeight, 0.4);
		moveValueTo(&terrain->waveSpeed, targetSpeed, 0x20000);
	}
}

int NewerWater::updateWaveEvents() {
	waves.update(&terrain);
	return EnvTerrain::onExecute();
}

int NewerPoison::updateWaveEvents() {
	waves.update(&terrain);
	return EnvTerrain::onExecute();
}

void initWaterWaves(EnvTerrain *water, Vec3 *pos, float width,
					bool noLoc, bool layer0, TerrainType type,
					sead::Heap *heap) {
	water->terrain.init(pos, width, noLoc, layer0, type, heap);
	if (water->settings2 & 1) {
		u32 waveHeight = (water->settings2 >> 20) & 0xF;
		u32 waveSpeed = (water->settings2 >> 4) & 0xF;
		water->terrain.setWaveValues(waveHeight, 0, waveSpeed, 0, 0, 0);
		water->terrain.type = type;
		TileMgr::instance->hasWaves = true;
		
		u8 eventId = (water->settings2 >> 8) & 0xFF;
		if (type == Water) {
			TileMgr::instance->waveType = 2;
			((NewerWater *)water)->waves.init(&water->terrain, 1.0, 8.0, eventId);
		} else if (type == Poison) {
			TileMgr::instance->waveType = 3;
			((NewerPoison *)water)->waves.init(&water->terrain, 0.8, -4.0, eventId);
		}
	}
}

void updateWaterWaves(TerrainEffects *effects) {
	if (TileMgr::instance->waveType == 2 || TileMgr::instance->waveType == 3) {
		effects->updateWaveCollisions();
	}
}

int updateWavePlatforms() {
	Actor **platform = ActorMgr::instance->findActorByType(LINE_MUSHROOM_BLOCK, ActorMgr::instance->actorList.first);
	while (platform != ActorMgr::instance->actorList.last) {
		(*platform)->onExecute();
		platform = ActorMgr::instance->findActorByType(LINE_MUSHROOM_BLOCK, platform + 1);
	}
	return 1;
}
