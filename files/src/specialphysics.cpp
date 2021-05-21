
#include "game.h"
#include "specialevent.h"

PlayerGravityData OceanGravityMini = {-.1, 2.3, 1.8, 0.0, -0.1, -2.0, -.1, -.1, -.1, -.06, -.08, 0, -.03, -.035, -.05, -.045, -.05, 0};
PlayerGravityData OceanGravityNormal = {-.1, 2.3, 1.8, 0.0, -0.1, -2.0, -.1, -.1, -.1, -.06, -.08, 0, -.03, -.035, -.05, -.045, -.05, 0};

PlayerGravityData *getGravityData(Player *player) {
	u8 physics = getPhysicsType();
	if (physics == 1) {
		if (player->powerup == Mini) return &OceanGravityMini;
		return &OceanGravityNormal;
	}
	return 0;
}

float getJumpSpeed(float originalSpeed, Player *player) {
	u8 physics = getPhysicsType();
	if (physics == 1) {
		if (player->powerup == Mini) return 2.5;
		return 2.5;
	}
	return originalSpeed;
}

float getWallJumpSpeed(float originalSpeed, Player *player) {
	u8 physics = getPhysicsType();
	if (physics == 1) {
		if (player->powerup == Mini) return 2.5;
		return 2.5;
	}
	return originalSpeed;
}

float getSpinJumpSpeed(float originalSpeed, Player *player) {
	u8 physics = getPhysicsType();
	if (physics == 1) {
		if (player->powerup == Mini) return 2.5;
		return 2.5;
	}
	return originalSpeed;
}

float getGroundPoundSpeed(Player *player) {
	u8 physics = getPhysicsType();
	if (physics == 1) return -3.0;
	return -6.0;
}
