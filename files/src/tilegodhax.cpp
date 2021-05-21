
#include "game.h"
#include "neweru.h"

void copyTilesFromLocation(u8 locationId, u8 layer, bool spawns, float x, float y) {
	u8 areaNum = LevelInfo::instance->area;
	LevelArea *area = Level::instance->getArea(areaNum);
	Location *loc = area->getLocationById(0, locationId);
	
	if (loc) {
		copyTilesInLocation(loc, x, y, layer, !spawns);
	} else {
		DEBUG("NewerU tile god location not found.");
	}
}
