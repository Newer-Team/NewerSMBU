
#include "game.h"
#include "neweru.h"
#include <stdio.h>

class NewerBgTexMgr : public BgTexMgr {
	public:
	agl::TextureData newAnimTexture;
	TileAnimation newTileAnim;
	
	void loadTilesets(u8 area);
	void update();
};

u32 delays[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
				1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
				1, 1, 1};
				
void NewerBgTexMgr::loadTilesets(u8 area) {
	BgTexMgr::loadTilesets(area);
	
	sead::String *tilesetName = TilesetLoader::instance->getTilesetName(area, 0);
	
	char filename[60];
	snprintf(filename, 60, "NewerU/long_qblock_anim_%s.gtx", tilesetName->str + 4); //Remove "Pa0_" at the front
	DEBUG(filename);
	
	sead::String filenameString = filename;
	sead::FileDevice::LoadArg loadArg = {filenameString, 0, 0, 0, 0, 0, 0, 0, 0};
	
	void *gtxData = sead::FileDeviceMgr::instance->tryLoad(&loadArg);
	newAnimTexture.loadGTX(gtxData, 0);
	delete gtxData;
	
	newTileAnim.playing = true;
	newTileAnim.reverse = false;
	newTileAnim.frameDelays = delays;
	newTileAnim.frameCount = 51;
	newTileAnim.frame = 0;
	newTileAnim.delayTimer = 0;
}

void NewerBgTexMgr::update() {
	BgTexMgr::update();
	
	//The following is a copy of the PowerPC assembly
	if (newTileAnim.playing) {
		if (newTileAnim.delayTimer > newTileAnim.frameDelays[newTileAnim.frame]) {
			newTileAnim.delayTimer = 0;
			if (newTileAnim.reverse) {
				if (newTileAnim.frame > 0) newTileAnim.frame--;
				else {
					newTileAnim.frame = newTileAnim.frameCount - 1;
				}
			} else {
				if (newTileAnim.frame < newTileAnim.frameCount - 1) newTileAnim.frame++;
				else {
					newTileAnim.frame = 0;
				}
			}
		}
		else newTileAnim.delayTimer++;
	}
}
