
#include "game.h"

class ActorFiles {
	public:
	ActorFiles(Actors actorId, u8 count, const sead::String files[]);
};

void copyTilesInLocation(Location *loc, float x, float y, u8 layer=0, bool destroy=false);

void DEBUG(const char *message);
void DEBUG_FMT(const char *message, ...);
void DEBUG_FILE(const char *filename, const char *buffer, u32 length);
