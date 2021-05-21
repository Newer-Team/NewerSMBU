
.include "asm_setup.S"

gravityFloatPatch:
	mr r31, r3		#Save gravity data
	mflr r30		#and link register
	bl getGravityData__FP6Player
	cmpwi r3, 0		#check special event physics
	bne returnGravityFloats
	mr r3, r31		#if no special gravity, restore original gravity
returnGravityFloats:
	mtlr r30
	lwz r0, 0x14(r1)
	blr

jumpSpeedPatch:
	fmr f1, f31		#Original speed
	mr r3, r31		#Player
	b getJumpSpeed__FfP6Player

wallJumpSpeedPatch:
	mflr r31
	fmr f1, f30
	mr r3, r30
	bl getWallJumpSpeed__FfP6Player
	stfs f1, 8(r1)
	mtlr r31
	blr

spinJumpSpeedPatch:
	mflr r30	#Save lr
	fmr f1, f13
	bl getSpinJumpSpeed__FfP6Player
	stfs f1, 8(r1)
	mr r3, r31
	addi r4, r1, 8
	mtlr r30	#Restore lr
	blr

groundPoundSpeedPatch1:
	stwu r1, -8(r1)
	mflr r0
	stw r0, 0xC(r1)
	
	mr r3, r31
	bl getGroundPoundSpeed__FP6Player
	stfs f1, 0x60(r31) #fallSpeed
	stfs f1, 0x7C(r31) #speed.Y
	
	lwz r0, 0xC(r1)
	mtlr r0
	addi r1, r1, 8
	lwz r0, 0x14(r1)
	blr
	
groundPoundSpeedPatch2:
	stwu r1, -8(r1)
	mflr r0
	stw r0, 0xC(r1)

	mr r3, r31
	bl getGroundPoundSpeed__FP6Player
	stfs f1, 0x60(r31)

	lwz r0, 0xC(r1)
	mtlr r0
	addi r1, r1, 8
	blr
	
groundPoundSpeedPatch3:
	#li r3, 0
	#stw r3, 0(r3)

	stwu r1, -0xC(r1)
	mflr r0
	stw r0, 0x10(r1)
	stw r12, 8(r1)
	
	mr r3, r31
	bl getGroundPoundSpeed__FP6Player
	stfs f1, 0x60(r31)

	lwz r12, 8(r1)
	lwz r0, 0x10(r1)
	mtlr r0
	addi r1, r1, 0xC
	blr
