
.include "asm_setup.S"

fooCloudType_onCreate:
	bnelr #Nybble 12 is checked
	lwz r29, 0x10(r30)
	b fooCloudType

fooCloudType_breathIn:
	bnelr #Nybble 12 is checked
	lwz r29, 0x10(r31)
fooCloudType:
	srwi. r29, r29, 28
	beqlr
	li r29, 0xB0
	blr


fooCloudUpdate:
	cmpwi r0, 0xB
	beqlr
	cmpwi r0, 1
	blr
	
fooCloudTexture:
	cmpwi r7, 0xB
	beqlr
	cmpwi r7, 5
	blr
	

fooCloudColorDark:
	mr r15, r28
	#Cloud type is 1955 in NSMBU, 194D in NSLU
	#But nybble 11 in both games
	lwz r9, 0x10(r31)
	extrwi r9, r9, 4, 24
	cmpwi r9, 0xB
	bnelr
	
	lis r9, deathCloudColorDark@h
	ori r9, r9, deathCloudColorDark@l
	stw r9, 0x10(r1)
	blr

	
fooCloudColorLight:
	lwz r10, 0x10(r31)
	extrwi r10, r10, 4, 24
	cmpwi r10, 0xB
	bne storeLightCloudColor
	
	lis r10, deathCloudColorLight@ha
	lbzu r9, deathCloudColorLight@l(r10)
	insrwi r26, r9, 8, 0
	lbz r9, 1(r10)
	insrwi r26, r9, 8, 8
	lbz r9, 2(r10)
	insrwi r26, r9, 8, 16
	
storeLightCloudColor:
	stw r26, 0(r7)
	blr

	
deathFooCollision:
	mflr r23
	bl ASM_VECDistance
	lwz r12, 0x10(r31)
	extrwi r12, r12, 4, 24
	cmpwi r12, 0xB
	mtlr r23
	li r23, 10
	bnelr
	
	lis r12, deathCloudSize@ha
	lfs f6, deathCloudSize@l(r12)
	fcmpu cr0, f1, f6
	bgelr
	
	#Check the transparency
	clrlwi. r12, r26, 24
	cmpwi r12, 0xE0
	blelr
	
	mflr r23
	fmr f16, f1
	lwz r12, 0x4C(r11)
	lwz r12, 0x8D4(r12) #vf8B4 in NSMBU
	# hi
	mtctr r12
	mr r3, r11
	li r4, 0
	li r5, 0x10
	bctrl
	fmr f1, f16
	mtlr r23
	li r23, 10
	blr

.section .rodata
deathCloudColorDark: .byte 5, 0, 0, 255
deathCloudColorLight: .byte 145, 0, 55, 255
deathCloudSize: .float 20.0
