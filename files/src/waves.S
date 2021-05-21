
.include "asm_setup.S"

allocEventWaves:
	addi r3, r3, 0x10
	b __nw__FUi

initWaterWaves:
	mr r3, r31
	b initWaterWaves__FP10EnvTerrainP4Vec3fbT411TerrainTypePQ2_4sead4Heap
	
updateWaterWaves:
	mr r3, r31
	mflr r31
	bl updateWaterWaves__FP14TerrainEffects
	mtlr r31
	lwz r0, 0x1C(r1)
	blr
	
waterWaveCollision:
	li r3, 4
	cmpwi r4, 1
	beqlr #Lava waves
	li r3, 1
	cmpwi r4, 2
	beqlr #Water waves
	li r3, 5
	blr #Poison waves
	
waterWaveCollision2:
	li r3, 4
	cmpwi r12, 1
	beqlr #Lava waves
	li r3, 1
	cmpwi r12, 2
	beqlr #Water waves
	li r3, 5
	blr #Poison waves
