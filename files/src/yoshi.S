
.include "asm_setup.S"

yoshiColorPatch:
	mflr r29

	lis r3, instance__Q2_4sead12GlobalRandom@ha
	lwz r3, instance__Q2_4sead12GlobalRandom@l(r3)
	bl getU32__Q2_4sead6RandomFv
	
	andi. r3, r3, 3
	mulli r3, r3, 8
	
	lis r9, yoshiColors@ha
	addi r9, r9, yoshiColors@l
	add r4, r9, r3
	
	lis r9, yoshiAnimFile@ha
	addi r5, r9, yoshiAnimFile@l
	
	mr r3, r31
	mtlr r29
	b __ct__14CharacterModelFPQ2_4sead6StringT1


yoshiEatActor:
	mflr r29
	mr r3, r30
	mr r4, r31
	bl eatActor__10NewerYoshiFP10StageActor
	lwz r12, 0x264(r31)
	mtlr r29
	blr
	
flutterEnd:
	mr r3, r31
	b flutterEnd__10NewerYoshiFv
