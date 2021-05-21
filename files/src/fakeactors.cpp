
#include "game.h"

void fakeStarCoin(StageActor *starCoin) {
	Vec2 screenPos;
	Vec2 starCoinPos = {starCoin->position.X, starCoin->position.Y};
	mapPosToScreen(&screenPos, &starCoinPos);
	BasicSoundActor::instance->playSound("SE_OBJ_DDOOR_OPEN", &screenPos, 1);
	
	Vec3 pos = {starCoin->position.X, starCoin->position.Y - 12, starCoin->position.Z};
	spawnEffect(RP_ObakeDoor_Disapp, &pos, 0, 0);
	
	starCoin->deleted = true;
}

bool fakeFlagPole(StageActor *flagPole) {
	Vec2 screenPos;
	Vec2 flagPolePos = {flagPole->position.X, flagPole->position.Y};
	mapPosToScreen(&screenPos, &flagPolePos);
	BasicSoundActor::instance->playSound("SE_OBJ_DDOOR_OPEN", &screenPos, 1);
	
	float ypos = flagPole->position.Y;
	Vec3 scale = {1.2, 1.2, 1.2};
	for (int i = 0; i < 3; i++) {
		Vec3 pos = {flagPole->position.X, ypos, flagPole->position.Z};
		spawnEffect(RP_ObakeDoor_Disapp, &pos, 0, &scale);
		
		ypos += 60.0;
	}
	
	flagPole->deleted = true;
	return 0;
}

void fakeCoinRing(StageActor *ring) {
	Vec2 screenPos;
	Vec2 ringPos = {ring->position.X, ring->position.Y};
	mapPosToScreen(&screenPos, &ringPos);
	BasicSoundActor::instance->playSound("SE_OBJ_DDOOR_OPEN", &screenPos, 1);
	
	Vec3 pos = {ring->position.X, ring->position.Y - 16, ring->position.Z};
	spawnEffect(RP_ObakeDoor_Disapp, &pos, 0, 0);
	ring->deleted = true;
}

void fakeGhostBox(StageActor *box) {
	Vec2 screenPos;
	Vec2 boxPos = {box->position.X, box->position.Y};
	mapPosToScreen(&screenPos, &boxPos);
	BasicSoundActor::instance->playSound("SE_OBJ_DDOOR_OPEN", &screenPos, 1);
	
	u32 width = (box->settings2 >> 8) & 0xF;
	u32 height = (box->settings >> 12) & 0xF;
	for (u32 i = 0; i <= width / 3; i++) {
		for (u32 j = 0; j <= height / 3; j++) {
			Vec3 pos = {box->position.X + 24.0 + i * 48.0, box->position.Y - 40.0 - j * 48.0, box->position.Z};
			spawnEffect(RP_ObakeDoor_Disapp, &pos, 0, 0);
		}
	}
	box->deleted = true;
}

void fakeActor(StageActor *fake) {
	Vec2 screenPos;
	Vec2 fakePos = {fake->position.X, fake->position.Y};
	mapPosToScreen(&screenPos, &fakePos);
	BasicSoundActor::instance->playSound("SE_OBJ_DDOOR_OPEN", &screenPos, 1);
	
	spawnEffect(RP_ObakeDoor_Disapp, &fake->position, 0, 0);
	fake->deleted = true;
}
