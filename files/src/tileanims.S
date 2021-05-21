
#0x1038 = sizeof(BgTexMgr) + sizeof(agl::TextureData) + sizeof(BgTexMgrAnimation)
#		= 0xF88			   + 0x9C					  + 0x14

.include "asm_setup.S"

updateBGPatch:
	stwu r1, -8(r1)
	mflr r0
	stw r0, 0xC(r1)
	
	mr r3, r30
	li r4, 0xA7 #Row 11, column 8
	li r5, 9
	li r6, 6
	li r7, 1
	bl renderAnimation__8BgTexMgrFUiN21i
	
	li r5, 0
	lwz r0, 0xC(r1)
	mtlr r0
	addi r1, r1, 8
	blr
	
renderTileAnimPatch1:
	addi r28, r30, 0xF88
	lwz r0, 0x78(r28)
	blr

renderTileAnimPatch2:
	addi r30, r30, (0xF88 + 0x9C - 0xCF0)
	b continueRenderTileAnim
