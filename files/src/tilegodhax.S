
.include "asm_setup.S"

tileGodHacks:
	lwz r16, 0x14(r26)
	srwi. r15, r16, 28		#Use NewerU tile god?
	beq tileGodHacks_retail #If not, use the retail code
	extrwi r3, r16, 4, 8	#Location ID
	extrwi r4, r16, 4, 4	#Layer
	mr r5, r27
	lfs f1, 0x6C(r26)		#X
	lfs f2, 0x70(r26)		#Y
	bl copyTilesFromLocation__FUcT1bfT4
	b returnTileGod
tileGodHacks_retail:
	li r16, 1
	blr
