
#include "cafe.h"

namespace nn {
	
	class Result {
		// ...
	};
	
	namespace act {
		
		typedef Result (*Initialize_t)(void);
		typedef u8     (*GetSlotNo_t)(void);
	}
}

typedef s32 SAVEStatus;

typedef SAVEStatus (*SAVEInit_t)(void);
typedef SAVEStatus (*SAVEInitSaveDir_t)(u8 accountSlotNo);
typedef FSStatus   (*SAVEOpenFile_t)(FSClient *client, FSCmdBlock *block, u8 accountSloto, const char *path, const char *mode, FSFileHandle *fileHandle, FSRetFlag errHandling);
