
.include "asm_setup.S"

.set GLOBALS, globals

.set FSOpenFile, 0x0106F9C4
.set FSCloseFile, 0x0106FAD0
.set FSReadFile, 0x0106FB50
.set FSWriteFile, 0x0106FC70
.set FSSetPosFile, 0x0106FF78
.set FSGetStatFile, 0x0106FFE8
.set FSGetStat, 0x01070810

b _main__FiPPc
b openFile
b readFile
b writeFile
b closeFile
b getStat
b getStatFile
b setPosFile
b openSave

openSave:
	mr r22, r3			#The
	mflr r0				#patched
	stw r0, 0x54(r1)	#instructions
	mr r29, r9
	
	lis r12, GLOBALS@ha
	lwz r12, GLOBALS@l(r12)
	cmpwi r12, 0x1357	# Initialized?
	bne cafeSaveOpen	# If not, use cafe SAVEOpenFile

	bl openSave__FP8FSClientP10FSCmdBlockUcPCcT4PiUi
	cmpwi r3, 0			# Server file?
	beq returnSaveOpen	# If yes, return
						# Otherwise, use cafe SAVEOpenFile
cafeSaveOpen:
	lis r12, (SAVEOpenFile + 0x2C)@h
	ori r12, r12, (SAVEOpenFile + 0x2C)@l
	mtctr r12
	bctr
returnSaveOpen:
	lis r12, (SAVEOpenFile + 0x1E8)@h
	ori r12, r12, (SAVEOpenFile + 0x1E8)@l
	mtctr r12
	bctr


openFile:
	lis r30, GLOBALS@ha
	lwz r30, GLOBALS@l(r30)
	cmpwi r30, 0x1357	# Initialized?
	mr r30, r4			# The patched instruction
	bne cafeOpen		# If not, use cafe FSOpenFile

	mr r5, r31			# const char *path
	bl openFile__FP8FSClientP10FSCmdBlockPCcT3PiUi
	cmpwi r3, 0			# Server file?
	beq returnOpen		# If yes, return
	
	mr r3, r29			# Otherwise restore registers
	mr r4, r30			# And use cafe FSOpenFile
	addi r5, r1, 8
cafeOpen:
	ba FSOpenFile + 0x2C
returnOpen:
	ba FSOpenFile + 0x64

	
readFile:
	lis r30, GLOBALS@ha
	lwz r30, GLOBALS@l(r30)
	cmpwi r30, 0x1357	# Initialized?
	mr r30, r4			# The patched instruction
	bne cafeRead		# If not, use cafe FSReadFile
	
	mr r5, r31			# u8 *dest
	bl readFile__FP8FSClientP10FSCmdBlockPcUiT4iN24
	cmpwi r3, -1		# Server file?
	bne returnRead		# If yes, return
	
	mr r3, r29			# Otherwise restore registers
	mr r4, r30			# And use cafe FSReadFile
	addi r5, r1, 0xC
cafeRead:
	ba FSReadFile + 0x34
returnRead:
	ba FSReadFile + 0x78

	
writeFile:
	lis r30, GLOBALS@ha
	lwz r30, GLOBALS@l(r30)
	cmpwi r30, 0x1357	# Initialized?
	mr r30, r4			# The patched instruction
	bne cafeWrite		# If not, use cafe FSWriteFile
	
	mr r5, r31			# u8 *dest
	bl writeFile__FP8FSClientP10FSCmdBlockPcUiT4iN24
	cmpwi r3, 0			# Server file?
	beq returnWrite		# If yes, return
	
	mr r3, r29			# Otherwise restore registers
	mr r4, r30			# And use cafe FSWriteFile
	addi r5, r1, 0xC
cafeWrite:
	ba FSWriteFile + 0x34
returnWrite:
	mr r3, r25
	ba FSWriteFile + 0x78
	
	
closeFile:
	lis r29, GLOBALS@ha
	lwz r29, GLOBALS@l(r29)
	cmpwi r29, 0x1357	# Initialized?
	mr r29, r3			# The patched instruction
	bne cafeClose		# If not, use cafe FSCloseFile

	mr r5, r31			# FSFileHandle fileHandle
	bl closeFile__FP8FSClientP10FSCmdBlockiUi
	cmpwi r3, 0			# Server file?
	beq returnClose		# If yes, return

	mr r3, r29			# Otherwise restore registers
	mr r4, r30			# And use cafe FSCloseFile
	addi r5, r1, 8
cafeClose:
	ba FSCloseFile + 0x30
returnClose:
	ba FSCloseFile + 0x60
	
	
setPosFile:
	lis r29, GLOBALS@ha
	lwz r29, GLOBALS@l(r29)
	cmpwi r29, 0x1357	# Initialized?
	mr r29, r3			# The patched instruction
	bne cafeSetPos		# If not, use cafe FSSetPosFile
	
	mr r5, r31			# FSFileHandle fileHandle
	bl setPosFile__FP8FSClientP10FSCmdBlockiUiT4
	cmpwi r3, 0			# Server file?
	beq returnSetPos	# If yes, return
	
	mr r3, r29			# Otherwise restore registers
	mr r4, r30			# And use cafe FSSetPosFile
	addi r5, r1, 8
cafeSetPos:
	ba FSSetPosFile + 0x28
returnSetPos:
	ba FSSetPosFile + 0x5C


getStatFile:
	lis r29, GLOBALS@ha
	lwz r29, GLOBALS@l(r29)
	cmpwi r29, 0x1357	# Initialized?
	mr r29, r3			# The patched instruction
	bne cafeStatFile	# If not, use cafe FSGetStat
	
	mr r5, r31			# FSFileHandle fileHandle
	bl getStatFile__FP8FSClientP10FSCmdBlockiP6FSStatUi
	cmpwi r3, 0			# Server file?
	beq returnStatFile	# If yes, return
	
	mr r3, r29			# Otherwise restore registers
	mr r4, r30			# And use cafe FSGetStatFile
	addi r5, r1, 8
cafeStatFile:
	ba FSGetStatFile + 0x28
returnStatFile:
	ba FSGetStatFile + 0x5C


getStat:
	lis r29, GLOBALS@ha
	lwz r29, GLOBALS@l(r29)
	cmpwi r29, 0x1357	# Initialized?
	mr r29, r3			# The patched instruction
	bne cafeStat		# If not, use cafe FSGetStat
	
	mr r5, r31			# const char *path
	bl getStat__FP8FSClientP10FSCmdBlockPCcP6FSStatUi
	cmpwi r3, 0			# Server file?
	beq returnStat		# If yes, return
	
	mr r3, r29			# Otherwise restore registers
	mr r4, r30			# And use cafe FSGetStat
	addi r5, r1, 8
cafeStat:
	ba FSGetStat + 0x28
returnStat:
	ba FSGetStat + 0x5C
