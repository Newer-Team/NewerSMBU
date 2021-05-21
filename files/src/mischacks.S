
.include "asm_setup.S"

noOneUpFlagPole:
	lwz r8, 0x10(r31)
	extrwi. r8, r8, 1, 6
	bnelr
	b addCollider__12CollisionMgrFP8Collider
	
jumpOverFlagPole:
	lwz r8, 0x10(r31)
	extrwi. r8, r8, 1, 7
	bnelr
	b addCollider__12CollisionMgrFP8Collider
	

prepareDecomp:
	mr r3, r31 #The patched instruction
	mr r7, r21 #Pass the heap as 5th argument
	blr


StageActor_verticalWrap:
	stwu r1, -8(r1)
	mflr r0
	stw r0, 0xC(r1)

	bl doVerticalWrap__FP10StageActor
	lfs f1, 0x24C(r30)	#Execute the patched instruction

	lwz r0, 0xC(r1)
	mtlr r0
	addi r1, r1, 8
	blr
	
TileColl_verticalWrap:
	stwu r1, -0xC(r1)
	mflr r0
	stw r0, 0x10(r1)
	stfs f31, 8(r1)
	
	#I patched the call to AreaTask::getWrappedXPos
	bl getWrappedXPos__8AreaTaskFf
	fmr f31, f1
	mr r3, r30
	bl getWrappedYPos__FUs
	mr r30, r3	#Overwrite the ypos register here
	fmr f1, f31
	
	lfs f31, 8(r1)
	lwz r0, 0x10(r1)
	mtlr r0
	addi r1, r1, 0xC
	blr
