
.include "asm_setup.S"

#######
### Fake star coin:  nybble 14
### Fake checkpoint: nybble 13
### Fake goal pole:  nybble 6 mask 4
### Fake coin ring:  nybble 20
### Fake switch:     nybble 20
### Fake ghost box:  nybble 12
#######

fakeStarCoin:
	stw r0, 0x3C(r1)
	lwz r4, 0x14(r3)
	extrwi. r4, r4, 1, 7 #Checkbox at nybble 14
	beqlr

	bl fakeStarCoin__FP10StageActor
	
	lwz r28, 0x28(r1)
	lwz r29, 0x2C(r1)
	lwz r0, 0x3C(r1)
	lwz r30, 0x30(r1)
	mtlr r0
	lwz r31, 0x34(r1)
	addi r1, r1, 0x38
	blr

	
fakeFlagPole:
	lwz r3, 0x40(r30)
	lwz r11, 0x10(r3)
	extrwi. r11, r11, 1, 5
	bne fakeFlagPole__FP10StageActor
	mr r3, r31
	b usedByGoalPole__10PlayerBaseFv
	
	
fakeCheckpoint:
	lwz r9, 0x14(r30)	#Read the nybbles
	srwi. r9, r9, 28	#Checkbox at nybble 20
	lbz r9, 0x20D(r3)	#Patched instruction, reading player type
	beqlr				#If checkbox not checked, return
	
	mflr r29					#Save link register
	cmpwi r9, 1					#Compare player type
	beq fakeCheckpointTrigger	#If player, trigger the ghost effect
	cmpwi r9, 2					#If Yoshi, perform an additional check
	bne fakeCheckpointReturn	#Otherwise, return
	
	mr r31, r3						#Save r3, in case the Yoshi check fails
	bl getRidingPlayer__5YoshiFv	#Is a player sitting on Yoshi?
	cmpwi r3, 0
	bne fakeCheckpointTrigger		#If yes, trigger the ghost effect
	mr r3, r31						#Otherwise, restore r3, r29 and lr and return
	
fakeCheckpointReturn:
	mtlr r29			#Restore link register
	lbz r29, 0x54(r3)	#Restore r29
	extsb r29, r29
	blr					#And return
	
fakeCheckpointTrigger:
	mr r3, r30	#Pass the checkpoint flag as first argument
	b fakeActor__FP10StageActor #And call the C function
	li r9, 0	#Load PlayerType.NoPlayer into r9 to skip the original function
	mtlr r29	#Restore link register
	blr			#And return

	
fakeCoinRing:
	lwz r6, 0x14(r31)
	clrlwi. r6, r6, 31
	beqctr

	#Coin ring is in r3 already
	bl fakeCoinRing__FP10StageActor

	lmw r26, 0x38(r1)
	lfs f30, 0x58(r1)
	lfs f31, 0x68(r1)
	lfd f30, 0x50(r1)
	lfd f31, 0x60(r1)
	isync
	lwz r0, 0x74(r1)
	mtlr r0
	addi r1, r1, 0x70
	blr
	
	
fakeSwitch:
	lwz r12, 0x14(r3)
	clrlwi. r12, r12, 31
	beqctr
	
	bl fakeActor__FP10StageActor
	
	lwz r0, 0x24(r1)
	lwz r30, 0x18(r1)
	mtlr r0
	lwz r31, 0x1C(r1)
	addi r1, r1, 0x20
	blr
	
	
fakeGhostBox:
	lwz r0, 0x10(r3)
	clrlwi. r0, r0, 31
	beqctr
	
	b fakeGhostBox__FP10StageActor

