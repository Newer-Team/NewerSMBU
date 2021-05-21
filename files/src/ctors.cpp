
#include "../codehandler/src/globals.h"
#include "types.h"

void callNewerUCtors() {
	u32 *ctors = (u32 *)globals.ctorList;
	u32 count = ctors[0];
	for (int i = 0; i < count; i++) {
		((void (*)())(ctors[i + 1]))();
	}
}
