
.include "asm_setup.S"

handleJumpSwitch:
	stfs f0, 0x34CC(r31)
	b handleJump__11SwitchBlockSFv
