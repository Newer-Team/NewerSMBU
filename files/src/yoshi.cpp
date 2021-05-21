#include "game.h"
#include "neweru.h"

sead::String yoshiAnimFile = "YoshiAnm";
sead::String yoshiColors[] = {"Yoshi_TexGreen", "Yoshi_TexPink", "Yoshi_TexYellow", "Yoshi_TexLightBlue"};

class NewerYoshi : public Yoshi {
	public:
	u8 stompCount;
	bool hasYellowShell;
	
	/* Patches Yoshi::onCreate() */
	int onCreate_();
	
	/* See documentation below */
	void eatActor(StageActor *actor);
	void flutterEnd();
	void land();
};

int NewerYoshi::onCreate_() {
	this->stompCount = 0;
	this->hasYellowShell = false;
	return Yoshi::onCreate();
}

/*
 * NewerYoshi::eatActor(StageActor *actor)
 * Process Yoshi's food.
 *
 * Arguments:   StageActor *
 *              The actor being eaten.
 * Returns:     None 
*/
void NewerYoshi::eatActor(StageActor *actor) {
	if (actor->profile->profileId == KOOPA_TROOPA) {
		u8 color = actor->settings & 7;
		switch (color) {
			/* Red: Spit fireball */
			case 1: 
				this->spawnBall(false);
				break;

			/* Yellow: Do three ground pounds */
			case 2:
				// Delete actor in mouth
				StageActor *another = this->getActorInMouth();
				another->deleted = true;

				// Reset stompcount and set the flag
				this->stompCount = 0;
				this->hasYellowShell = true;
				break;

			/* Dark blue: Fly */
			case 3:
				// TODO
				break;

			/* Light blue: Spit iceball */
			case 4:
				this->spawnBall(true);
				break;

			/* Green / not implemented */
			default:
				break;
		}
	}
}

/*
 * NewerYoshi::flutterEnd()
 *
 *
 * Arguments: None
 * Returns:   None
*/
void NewerYoshi::flutterEnd() {
	this->flutterState = 4;
	StageActor *actor = getActorInMouth();
	if (actor) {
		if (actor->profile->profileId == KOOPA_TROOPA) {
			if ((actor->settings & 7) == 3) {
				this->flutterState = 0;
				this->canFlutter = true;
			}
		}
	}
}

/*
 * NewerYoshi::flutterEnd()
 *
 *
 * Arguments: None
 * Returns:   None
*/
void NewerYoshi::land() {
	if (this->hasYellowShell) {
		this->groundPound();
		AreaRumbler::instance->rumbleScreen(playerId, 12, 3, 12, 0);
		CoinMgr::instance->dropCoins(&position);
		this->stompCount++;
		if (this->stompCount == 3) {
			this->removeActorFromMouth();
			this->hasYellowShell = false;
			this->stompCount = 0;
		}
	}
	this->doLandEffects();
}