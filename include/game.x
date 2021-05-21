
SECTIONS {

	/*** GHS C++ FUNCTIONS ***/
	__nw__FUi = 0xF5B199C;
	__nwa__FUi = 0xF5B1A38;
	__dl__FPv = 0xF5B1B50;
	__nw__FUiPQ2_4sead4Heapi = 0xF5B1C60;
	__vec_new = 0xF6BA750;
	__vec_delete = 0xF6BA890;
	__record_needed_destruction = 0xF6BA92C;
	__pure_virtual_called = 0xF6BA954;
	__memzero = 0xF6BA95C;
	__deleted_virtual_called = 0xF6BA9E8;
	__gh_long_long_printf = 0xF6BAB84;
	__gh_float_printf = 0xF6BAFA8;
	vsnprintf = 0xF6BBD54;
	__ghs_strlen = 0xF6BD91C;
	sinf = 0xF6BE140;
	cosf = 0xF6BE928;
	atan2f = 0xF6BEA70;
	__gh_memclr32 = 0xF6BF1E0;
	
	
	/*** CAFE SDK STATIC ***/
	ASM_VECDistance = 0xF6B9B18;
	

	/*** CAFE SDK IMPORTS ***/
	OSBlockSet = 0xF6C49B0;
	
	inflateInit2_ = 0xF6D88DC;
	inflate = 0xF6D8B70;
	inflateEnd = 0xF6DA128;
	
	
	/*** SEAD LIBRARY ***/
	__vtbl__Q2_4sead6String = 0x105F7568;
	
	__vtbl__Q2_4sead9IDisposer = 0x10693208;
	__dt__Q2_4sead9IDisposerFv = 0xF5CA78C;
	
	rootHeaps__Q2_4sead7HeapMgr = 0x10AEC348;
	getCurrentHeap__Q2_4sead7HeapMgrSFv = 0xF5CD95C;
	
	__vtbl__Q2_4sead4Heap = 0x1069350C;
	
	instance__Q2_4sead12GlobalRandom = 0x106EA26C;
	getU32__Q2_4sead6RandomFv = 0xF5D3B88;
	
	__ct__Q2_4sead15GraphicsContextFv = 0xF5C7FC4;
	apply__Q2_4sead15GraphicsContextFv = 0xF5C80B8;
	
	__ct__Q2_4sead18GraphicsContextMRTFv = 0xF5C8278;
	apply__Q2_4sead18GraphicsContextMRTFv = 0xF5C8398;
	
	getDeviceProjectionMatrix__Q2_4sead10ProjectionFv = 0xF5C5EA4;
	
	__ct__Q2_4sead15OrthoProjectionFfN51 = 0xF5C69B4;
	__dt__Q2_4sead15OrthoProjectionFv = 0xF5C6BCC;
	
	bind__Q2_4sead11FrameBufferFv = 0xF5C5CF8;
	
	tryLoad__Q2_4sead10FileDeviceFPQ3_4sead10FileDevice7LoadArg = 0xF686CA4;
	
	instance__Q2_4sead13FileDeviceMgr = 0x106EA118;
	tryLoad__Q2_4sead13FileDeviceMgrFPQ3_4sead10FileDevice7LoadArg = 0xF5B8FC4;
	
	getDecompSize__Q2_4sead15SZSDecompressorSFPCv = 0xF5D58CC;
	decomp__Q2_4sead15SZSDecompressorSFPvUiPCvT2 = 0xF5D5A54;
	
	
	/*** AGL LIBRARY ***/
	searchShaderProgramIndex__Q2_3agl20ShaderProgramArchiveFPQ2_4sead6String = 0xF5E49A8;
	
	createUniformBlock__Q2_3agl13ShaderProgramFiPQ2_4sead4Heap = 0xF5E1B20;
	setUniformBlockName__Q2_3agl13ShaderProgramFiPQ2_4sead6String = 0xF5E1D08;
	createSamplerBlock__Q2_3agl13ShaderProgramFiPQ2_4sead4Heap = 0xF5E1D80;
	setSamplerBlockName__Q2_3agl13ShaderProgramFiPQ2_4sead6String = 0xF5E1F68;
	
	__ct__Q2_3agl11TextureDataFv = 0xF5E4DA0;
	invalidateGPUCache__Q2_3agl11TextureDataFv = 0xF5E4E64;
	initialize__Q2_3agl11TextureDataFQ2_3agl11TextureTypeQ2_3agl13TextureFormatUiN33Q2_3agl15MultiSampleType = 0xF5E5114;
	loadGTX__Q2_3agl11TextureDataFPvUi = 0xF5E5338;
	
	applyTextureData___Q2_3agl14TextureSamplerFPQ2_3agl11TextureData = 0xF5E5D90;
	
	__ct__Q2_3agl17RenderTargetColorFv = 0xF5DF3DC;
	applyTextureData__Q2_3agl17RenderTargetColorFPQ2_3agl11TextureData = 0xF096070;
	invalidateGPUCache__Q2_3agl17RenderTargetColorFv = 0xF5DF488;
	
	__ct__Q2_3agl17RenderTargetDepthFv = 0xF5DF56C;
	applyTextureData__Q2_3agl17RenderTargetDepthFPQ2_3agl11TextureData = 0xF096200;
	invalidateGPUCache__Q2_3agl17RenderTargetDepthFv = 0xF5DF620;
	
	__ct__Q2_3agl12RenderBufferFP4Vec2fN32 = 0xF5DEEDC;
	__dt__Q2_3agl12RenderBufferFv = 0xF5DE73C;
	clear__Q2_3agl12RenderBufferFUiT1PQ2_4sead7Color4fT1f = 0xF5DEA44;
	
	
	/*** NW LIBRARY ***/
	snprintf__Q2_2nw2utFPcUiPCce = 0xF686CA4;
	
	GetItemLabel__Q3_2nw3snd12SoundArchiveFUi = 0xF696D80;
	
	GetString__Q5_2nw3snd8internal16SoundArchiveFile15StringBlockBodyFUi = 0xF697A04;
	
	
	/*** GAME ADDRESSES ***/
	fileCounts = 0x105045F8;
	fileLists = 0x106C541C;
	directionToRotationList = 0x10702FD8;
	spriteToActorList = 0x106EEF8C;
	tileGodList = 0x10609450;
	
	calcMatrix__FPA3_A4_fP5Vec3iP4Vec3 = 0xEBFC1C8;
	mapPosToScreen__FP4Vec2T1 = 0xEBE9368;
	spawnEffect__F7EffectsP4Vec3P5Vec3iT2 = 0xEE6B080;
	moveValueTo__FPUiUiT2 = 0xF5A11F0;
	moveFloatTo__FPffT2 = 0xEBE7984;
	
	__ct__7ProfileFPFP14ActorBuildInfo_P5Actor6ActorsPCcPC9ActorInfoUi = 0xEBD9554;
	Get__7ProfileSF6Actors = 0xEBD9774;
	GetProfile = 0xEBD9774;
	
	instance__8AreaTask = 0x106D3798;
	getWrappedXPos__8AreaTaskFf = 0xF078034;
	
	instance__9LevelInfo = 0x106D3AEC;
	
	getLocationById__9LevelAreaFP4RectUc = 0xF25A0C4;
	getZoneById__9LevelAreaFUcP4Rect = 0xF259DA4;
	
	instance__5Level = 0x106DD248;
	getArea__5LevelFUc = 0xF25A380;
	
	instance__10LevelTimer = 0x106D37F4;
	addSeconds__10LevelTimerFUi = 0xF0814C0;
	
	instance__11LevelCamera = 0x106E9E54;
	
	instance__8EventMgr = 0x106DD26C;
	
	instance__9PlayerMgr = 0x106E8B94;
	
	__ct__13EffectHandlerFv = 0xEE6B868;
	update__13EffectHandlerF7EffectsPA3_A4_fb = 0xEE6B6EC;
	update__13EffectHandlerF7EffectsP4Vec3P5Vec3iT2 = 0xEE6B52C;
	
	init__14TerrainEffectsFP4Vec3fbT311TerrainTypePQ2_4sead4Heap = 0xF477378;
	setWaveValues__14TerrainEffectsFUiN51 = 0xF477598;
	checkMarioWaveHit__14TerrainEffectsFv = 0xF478C98;
	updateWaveCollisions__14TerrainEffectsFv = 0xF478E00;
	
	onExecute__10EnvTerrainFv = 0xF2B0F40;
	setTop__10EnvTerrainFf = 0xF2B131C;
	
	instance__7TileMgr = 0x106DCD94;
	getTilePointer__7TileMgrSFUsT1UcPUi = 0xF2450A4;
	
	instance__17FrameBufferKeeper = 0x106D4D88;
	__CPR93__switchBuffer__17FrameBufferKeeperFQ2_J14J10BufferTypePQ3_3agl3lyr10RenderInfob = 0xF09E2BC;
	
	__ct__10BgMaskListFv = 0xF25A49C;
	__dt__10BgMaskListFv = 0xF25A534;
	init__10BgMaskListFPQ2_4sead4Heap = 0xF25A6B8;
	add__10BgMaskListFP8MaskInfoN31PQ2_3agl11TextureDataUi = 0xF25A8D0;
	draw__10BgMaskListFPvT1 = 0xF25AC40;
	
	instance__10BgRenderer = 0x106DD1E8;
	initShaders__10BgRendererSFPQ2_3agl20ShaderProgramArchivePQ2_4sead4Heap = 0xF24F6A0;
	allocTexture__10BgRendererSFPQ2_4sead6StringQ4_3agl3utl23DynamicTextureAllocator12AllocateType = 0xF250530;
	allocDepthTexture__10BgRendererSFPQ2_4sead6StringPPv = 0xF2506DC;
	freeTexture__10BgRendererSFPPQ2_3agl11TextureData = 0xF2518C4;
	__vtbl__10BgRenderer = 0x105E7A58;
	__ct__10BgRendererFv = 0xF24F0D8;
	__dt__10BgRendererFv = 0xF253430;
	init__10BgRendererFPQ2_4sead4Heap = 0xF24F894;
	drawLayerMasks__10BgRendererFPQ3_3agl3lyr10RenderInfo = 0xF252238;
	drawTilesWithMasks__10BgRendererFPQ3_3agl3lyr10RenderInfo = 0xF2522D0;
	renderTileLayer__10BgRendererFPQ2_4sead8ViewportPQ2_4sead15OrthoProjectionUi = 0xF25140C;
	initSpotlightMaskFrameBuffer__10BgRendererFPQ3_3agl3lyr10RenderInfo = 0xF252154;
	
	loadTexture__11MaskTexDataSFQ2_11MaskTexture5ShapePQ2_3agl11TextureData = 0xF3D56BC;
	
	__ct__9LightMaskFv = 0xF3D5D40;
	init__9LightMaskFPQ2_4sead4HeapQ2_11MaskTexture5Shape = 0xF3D5DC4;
	update__9LightMaskFv = 0xF3D5E70;
	draw__9LightMaskFv = 0xF3D616C;
	
	__vtbl__9LayerMask = 0x106397BC;
	init__9LayerMaskFPQ2_4sead4HeapQ2_11MaskTexture5Shape = 0xF3D6568;
	update__9LayerMaskFv = 0xF3D6608;
	draw__9LayerMaskFv = 0xF3D66C0;
	
	loadTilesets__8BgTexMgrFUc = 0xF253AC8;
	loadTexture__8BgTexMgrSFPQ2_3agl11TextureDataPQ2_4sead6StringT2 = 0xF253A58;
	update__8BgTexMgrFv = 0xF254740;
	renderAnimation__8BgTexMgrFUiN21i = 0xF254860;
	
	instance__13TilesetLoader = 0x106DD1C0;
	getTilesetName__13TilesetLoaderFUcT1 = 0xF24E444;
	
	instance__6ResMgr = 0x106E9F94;
	loadArchive__6ResMgrFPCQ2_4sead6StringT1PQ2_4sead4Heapb = 0xF5938B0;
	getArchive__6ResMgrFPCQ2_4sead6String = 0xF5940A8;
	
	instance__9ResLoader = 0x106D4F50;
	getResArchive__9ResLoaderFQ2_4sead6String = 0xF0B60EC;
	
	getModel__10ResArchiveFQ2_4sead6StringUiN42bPQ2_4sead4Heap = 0xF0AE440;
	
	__vtbl__8ModelObj = 0x105BF130;
	
	__ct__5ModelFP8ModelObjUiN42 = 0xF094798;
	init__5ModelFP10ResArchivePQ2_4sead33PtrArrayImpl__tm__13_10ResArchivePQ2_4sead4Heap = 0xF0949A0;
	update__5ModelFv = 0xF094E84;
	
	__ct__6Model2FP8ModelObjUiN42 = 0xF09FBF0;
	init__6Model2FP10ResArchivePQ2_4sead33PtrArrayImpl__tm__13_10ResArchivePQ2_4sead4Heap = 0xF09FC78;
	update__6Model2Fv = 0xF09FC7C;
	
	setRepeat__9AnimationFb = 0xF09EED4;
	
	play__12SkeletalAnimFP10ResArchivePQ2_4sead6String = 0xF0BDB80;
	
	__ct__14CharacterModelFPQ2_4sead6StringT1 = 0xF4E0D4C;
	
	instance__6Drawer = 0x106D4F88;
	drawModel__6DrawerFP5Model = 0xF0BAD3C;
	drawTile__6DrawerFUiP4Vec3PUiT2 = 0xF0BADCC;
	
	init__13PlatformModelFv = 0xF37E1B4;
	draw__13PlatformModelFv = 0xF37E5A0;
	update__13PlatformModelFP4Vec3f = 0xF37E4CC;
	
	__ct__9CollThingFv = 0xED61ACC;
	
	__vtbl__17OtherColliderBase = 0x10544728;
	
	setRect__14CustomColliderFP4Vec2T1 = 0xED6D25C;
	
	__vtbl__14CustomCollider = 0x10544888;
	__ct__14CustomColliderFUiP4Vec2P9CollThingT3 = 0xED67904;
	updateMovement__14CustomColliderFv = 0xED6871C;
	
	init__13SolidColliderFP10StageActorP18SolidCollisionInfo = 0xED6D3BC;
	__vtbl__13SolidCollider = 0x105FD9B8;
	__dt__13SolidColliderFv = 0xF2ABA70;
	
	init__18SolidOnTopColliderFP10StageActorP23SolidOnTopCollisionInfoUiT3 = 0xED62378;
	__vtbl__18SolidOnTopCollider = 0x10544438;
	__ct__18SolidOnTopColliderFv = 0xED61D38;
	__dt__18SolidOnTopColliderFv = 0xED61F18;
	updateMovement__18SolidOnTopColliderFv = 0xED62E0C;

	instance__17OtherCollisionMgr = 0x106CB560;
	add__17OtherCollisionMgrFP17OtherColliderBase = 0xED5269C;
	
	init__8ColliderFP10StageActorPC13CollisionInfoUi = 0xED5AF1C;
	
	instance__12CollisionMgr = 0x106CB7D8;
	addCollider__12CollisionMgrFP8Collider = 0xED5E028;
	
	init__7PhysicsFP10StageActorP4Vec3N22 = 0xED4AF6C;
	processCollisions__7PhysicsFv = 0xED4D954;
	
	instance__17CourseDarknessMgr = 0x106E1AB4;
	
	CurrentStateID = 0x106EC104;
	executeState__10StateClassFv = 0xF584B24;
	
	__vtbl__9StateBase = 0x10541FF8;
	__dt__9StateBaseFv = 0xED4615C;
	getStateId__9StateBaseFv = 0xED45DA0;
	
	freezeActor__11IceActorMgrFP7IceInfoUi = 0xEF3D63C;
	
	instance__8ActorMgr = 0x106C52C8;
	createActor__8ActorMgrFP14ActorBuildInfoUi = 0xEBC9A58;
	findActorByType__8ActorMgrF6ActorsPP5Actor = 0xEBC9B6C;
	
	findActorById__9ActorListFPUi = 0xEBCA5C8;
	
	__ct__15MovementHandlerFv = 0xF409CE4;
	getMaskForMovementType__15MovementHandlerF12MovementType = 0xF40A420;
	linkToMovementController__15MovementHandlerFP4Vec3UiUc = 0xF40B798;
	execute__15MovementHandlerFv = 0xF40B968;
	
	removeChild__5ActorFP5Actor = 0xEBC2C8C;
	getProfileId__5ActorFv = 0xEBC2C80;
	
	__vtbl__5Actor = 0x105028C0;
	__ct__5ActorFP14ActorBuildInfo = 0xEBC2CE0;
	checkDerivedRuntimeTypeInfo__5ActorFPv = 0xEBC2F40;
	vf14__5ActorFv = __deleted_virtual_called;
	__dt__5ActorFv = 0xEBC2E68;
	beforeCreate__5ActorFv = 0xEBC2F7C;
	onCreate__5ActorFv = 0xEBC2F84;
	afterCreate__5ActorFi = 0xEBC2F00;
	beforeExecute__5ActorFv = 0xEBC2F04;
	onExecute__5ActorFv = 0xEBC2F8C;
	afterExecute__5ActorFi = 0xEBC2F34;
	finalExecute__5ActorFv = 0xEBC2F94;
	beforeDraw__5ActorFv = 0xEBC2F98;
	onDraw__5ActorFv = 0xEBC2FA0;
	afterDraw__5ActorFi = 0xEBC2F38;
	beforeDelete__5ActorFv = 0xEBC2FA8;
	onDelete__5ActorFv = 0xEBC2FB0;
	afterDelete__5ActorFi = 0xEBC2F3C;
	
	getDirectionToPlayer__10StageActorFP4Vec3 = 0xEBC05EC;
	
	__vtbl__10StageActor = 0x10502468;
	__ct__10StageActorFP14ActorBuildInfo = 0xEBC0AC8;
	checkDerivedRuntimeTypeInfo__10StageActorFPv = 0xEBC2A38;
	__dt__10StageActorFv = 0xEBC0F18;
	afterCreate__10StageActorFi = 0xEBC0FB8;
	beforeExecute__10StageActorFv = 0xEBC0FE8;
	afterExecute__10StageActorFi = 0xEBC10BC;
	beforeDraw__10StageActorFv = 0xEBC11A0;
	setPlayerId__10StageActorFUc = 0xEBC2AB0;
	removeColliders__10StageActorFv = 0xEBC02CC;
	addColliders__10StageActorFv = 0xEBC0328;
	getPhysics__10StageActorFv = 0xEBC2AB8;
	vfAC__10StageActorFv = 0xEBC2AC0;
	vfB4__10StageActorFv = 0xEBC2AC4;
	vfBC__10StageActorFv = 0xEBC2ACC;
	vfC4__10StageActorFv = 0xEBC2AD0;
	vfCC__10StageActorFv = 0xEBC2AD4;
	killAtGoal__10StageActorFv = 0xEBC2AD8;
	splashWater__10StageActorFP4Vec3 = 0xEBC2ADC;
	splashLava__10StageActorFP4Vec3 = 0xEBC2AE0;
	splashLavaWave__10StageActorFP4Vec3 = 0xEBC0960;
	splashPoison__10StageActorFP4Vec3 = 0xEBC2AE4;
	isOffScreen__10StageActorFv = 0xEBC1254;
	damageFromUnder__10StageActorFv = 0xEBC2AE8;
	
	applyGravity__12PhysicsActorFv = 0xEBC39AC;
	
	__vtbl__12PhysicsActor = 0x10502A4C;
	checkDerivedRuntimeTypeInfo__12PhysicsActorFPv = 0xEBC3F34;
	__dt__12PhysicsActorFv = 0xEBC40B0;
	afterCreate__12PhysicsActorFi = 0xEBC354C;
	beforeExecute__12PhysicsActorFv = 0xEBC35FC;
	afterExecute__12PhysicsActorFi = 0xEBC36D8;
	onDelete__12PhysicsActorFv = 0xEBC3724;
	getPhysics__12PhysicsActorFv = 0xEBC4010;
	vf10C__12PhysicsActorFUc = 0xEBC3FF0;
	vf114__12PhysicsActorFv = __deleted_virtual_called;
	vf11C__12PhysicsActorFv = 0xEBC3FF8;
	vf124__12PhysicsActorFf = 0xEBC3FFC;
	vf12C__12PhysicsActorFv = 0xEBC4000;
	vf134__12PhysicsActorFv = __deleted_virtual_called;
	vf13C__12PhysicsActorFv = 0xEBC4008;
	vf144__12PhysicsActorFb = 0xEBC375C;
	vf14C__12PhysicsActorFv = 0xEBC3760;
	vf154__12PhysicsActorFv = 0xEBC4018;
	move__12PhysicsActorFP4Vec2 = 0xEBC4020;
	setYSpeed__12PhysicsActorFf = 0xEBC4034;
	vf16C__12PhysicsActorFv = 0xEBC403C;
	vf174__12PhysicsActorFv = 0xEBC4044;
	getRect__12PhysicsActorFP4Rect = 0xEBC404C;
	
	__vtbl__10StateActor = 0x10503248;
	__ct__10StateActorFP14ActorBuildInfo = 0xEBCAA8C;
	checkDerivedRuntimeTypeInfo__10StateActorFPv = 0xEBCAF94;
	__dt__10StateActorFv = 0xEBCB098;
	doStateChange__10StateActorFP9StateBase = 0xEBCB090;

	__vtbl__11StateActor2 = 0x105030C8;
	
	actorInfo__12SpinningStar = 0x1063336C;
	__vtbl__12SpinningStar = 0x10633464;
	__ct__12SpinningStarFP14ActorBuildInfo = 0xF3B56FC;
	checkDerivedRuntimeTypeInfo__12SpinningStarFPv = 0xF3B7070;
	__dt__12SpinningStarFv = 0xF3B7210;
	onCreate__12SpinningStarFv = 0xF3B5D54;
	onExecute__12SpinningStarFv = 0xF3B6190;
	onDraw__12SpinningStarFv = 0xF3B6248;
	
	StateID_JumpKill__5Enemy = 0x107031B0;
	
	collisionCallback__5EnemySFP8ColliderT1 = 0xEEE8C50;
	
	spinJumpKill__5EnemyFP6Player = 0xEEECC98;
	killWithPlayer__5EnemyFP6PlayerP4Vec2P19State__tm__7_5Enemy = 0xEEEDA34;
	killWithYoshi__5EnemyFP5Yoshi = 0xEEED31C;
	processHit__5EnemyFP8ColliderT1 = 0xEEE9B88;
	updatePosition__5EnemyFv = 0xEBC3AE4;
	
	__vtbl__5Enemy = 0x1057429C;
	__ct__5EnemyFP14ActorBuildInfo = 0xEEE8494;
	checkDerivedRuntimeTypeInfo__5EnemyFPv = 0xEEEA70C;
	__dt__5EnemyFv = 0xEEEA868;
	beforeExecute__5EnemyFv = 0xEEE8644;
	damageFromUnder__5EnemyFv = 0xEEE8914;
	vf14C__5EnemyFv = 0xEEEDC88;
	vf154__5EnemyFv = 0xEEEE1A4;
	doStateChange__5EnemyFP9StateBase = 0xEEF0404;
	vf18C__5EnemyFv = 0xEEEA848;
	playerCollision8A4__5EnemyFUiP8Collider = 0xEEE8B84;
	vf19C__5EnemyFUc = 0xEEE910C;
	freezeActor__5EnemyFv = 0xEEF04F8;
	vf1AC__5EnemyFv = 0xEEF10BC;
	vf1B4__5EnemyFv = 0xEEE10C0;
	vf1BC__5EnemyFv = 0xEEF0568;
	vf1C4__5EnemyFv = 0xEEEA858;
	vf1CC__5EnemyFv = 0xEEEA85C;
	vf1D4__5EnemyFUiPv = 0xEEE91F8;
	prePlayerCollision__5EnemyFP8ColliderT1 = 0xEEE9250;
	vf1E4__5EnemyFPUcP8ColliderT2 = 0xEEE9520;
	yoshiCollisionRelated__5EnemyFP8ColliderT1 = 0xEEE9578;
	preYoshiCollision__5EnemyFP8ColliderT1 = 0xEEE957C;
	vf1FC__5EnemyFP8ColliderT1 = 0xEEE96E8;
	actorCollision__5EnemyFP8ColliderT1 = 0xEEE9800;
	vf20C__5EnemyFv = 0xEEE99F0;
	playerCollision__5EnemyFP8ColliderT1 = 0xEEE99F4;
	yoshiCollision__5EnemyFP8ColliderT1 = 0xEEE9A04;
	vf224__5EnemyFP8ColliderT1 = 0xEEE9A08;
	vf22C__5EnemyFP8ColliderT1 = 0xEEECE84;
	hitJump__5EnemyFP8ColliderT1 = 0xEEECF20;
	collidesSomething__5EnemyFP8ColliderT1 = 0xEEED014;
	hitEnemyDown__5EnemyFP8ColliderT1 = 0xEEED0E4;
	hitGroundPound__5EnemyFP8ColliderT1 = 0xEEED240;
	hitYoshi__5EnemyFP8ColliderT1 = 0xEEED3B4;
	hitEnemyKame2__5EnemyFP8ColliderT1 = 0xEEED48C;
	hitEnemyKame3__5EnemyFP8ColliderT1 = 0xEEED49C;
	callsHitJump__5EnemyFP8ColliderT1 = 0xEEED56C;
	hitEnemyKameDown__5EnemyFP8ColliderT1 = 0xEEED57C;
	fireballCollision__5EnemyFP8ColliderT1 = 0xEEED70C;
	vf284__5EnemyFP8ColliderT1 = 0xEEED7A4;
	hitNormal__5EnemyFP8ColliderT1 = 0xEEED824;
	hitEnemyKame4__5EnemyFP8ColliderT1 = 0xEEED938;
	vf29C__5EnemyFv = 0xEEEDA04;
	goldYoshiHit__5EnemyFP8ColliderT1 = 0xEEEDA0C;
	vf2AC__5EnemyFP8ColliderT1 = 0xEEEDA14;
	vf2B4__5EnemyFPUcP8ColliderT2 = 0xEEEDA24;
	hitEx__5EnemyFv = 0xEEEDAF0;
	vf2C4__5EnemyFv = 0xEEEDD48;
	hitEnemyKame5__5EnemyFP8ColliderT1 = 0xEEEE048;
	isGrounded__5EnemyFv = 0xEEEE2EC;
	playDownSound__5EnemyFv = 0xEEEE2F8;
	playDownSoundHpdp__5EnemyFv = 0xEEEE358;
	vf2EC__5EnemyFUi = 0xEEE9EA4;
	vf2F4__5EnemyFv = 0xEEE9FA8;
	vf2FC__5EnemyFUi = 0xEEE9FAC;
	calls_vf2F4__5EnemyFv = 0xEEE9FB0;
	vf30C__5EnemyFUi = 0xEEE9FC0;
	playFumuSound__5EnemyFv = 0xEEEA094;
	playerHit__5EnemyFP10PlayerBase = 0xEEEA118;
	playDownSpinSound__5EnemyFv = 0xEEEA1BC;
	playMameStepSound__5EnemyFv = 0xEEEA240;
	vf334__5EnemyFv = 0xEEEA24C;
	playYoshiFumuSound__5EnemyFv = 0xEEEA250;
	spawnHipDropHitEffect__5EnemyFv = 0xEEEA2D4;
	increaseYSpeed__5EnemyFv = 0xEEEA2E4;
	positionRelated__5EnemyFv = 0xEEEA2FC;
	vf35C__5EnemyFPv = 0xEEEA364;
	vf364__5EnemyFPv = 0xEEEA418;
	vf36C__5EnemyFPv = 0xEEEA4CC;
	vf374__5EnemyFv = 0xEEEA864;
	beginState_JumpKill__5EnemyFv = 0xEEEE518;
	executeState_JumpKill__5EnemyFv = 0xEEEE5E8;
	endState_JumpKill__5EnemyFv = 0xEEEEED0;
	beginState_FireballKill__5EnemyFv = 0xEEEE63C;
	executeState_FireballKill__5EnemyFv = 0xEEEE640;
	endState_FireballKill__5EnemyFv = 0xEEEEED4;
	beginState_YoshiStamp__5EnemyFv = 0xEEEE72C;
	executeState_YoshiStamp__5EnemyFv = 0xEEEE79C;
	endState_YoshiStamp__5EnemyFv = 0xEEEEED8;
	beginState_EnemyState11__5EnemyFv = 0xEEEE7A8;
	executeState_EnemyState11__5EnemyFv = 0xEEEE7B8;
	endState_EnemyState11__5EnemyFv = 0xEEEEEDC;
	beginState_EnemyState12__5EnemyFv = 0xEEEE7C4;
	executeState_EnemyState12__5EnemyFv = 0xEEEE7C8;
	endState_EnemyState12__5EnemyFv = 0xEEEEEE0;
	beginState_EnemyState13__5EnemyFv = 0xEEEE7D4;
	executeState_EnemyState13__5EnemyFv = 0xEEEEEE4;
	endState_EnemyState13__5EnemyFv = 0xEEEEEE8;
	beginState_ChallengeRelated__5EnemyFv = 0xEEEE7E0;
	executeState_ChallengeRelated__5EnemyFv = 0xEEEEEEC;
	endState_ChallengeRelated__5EnemyFv = 0xEEEEEF0;
	beginState_EnemyState2__5EnemyFv = 0xEEF05E4;
	executeState_EnemyState2__5EnemyFv = 0xEEF05EC;
	endState_EnemyState2__5EnemyFv = 0xEEF10C4;
	beginState_EnemyState3__5EnemyFv = 0xEEF10C8;
	executeState_EnemyState3__5EnemyFv = 0xEEF10CC;
	endState_EnemyState3__5EnemyFv = 0xEEF10D0;
	beginState_EnemyState4__5EnemyFv = 0xEEF10D4;
	executeState_EnemyState4__5EnemyFv = 0xEEF10D8;
	endState_EnemyState4__5EnemyFv = 0xEEF10DC;
	beginState_EnemyState5__5EnemyFv = 0xEEF06E8;
	executeState_EnemyState5__5EnemyFv = 0xEEF06F0;
	endState_EnemyState5__5EnemyFv = 0xEEF10E0;
	beginState_EnemyState6__5EnemyFv = 0xEEF10E4;
	executeState_EnemyState6__5EnemyFv = 0xEEF10E8;
	endState_EnemyState6__5EnemyFv = 0xEEF10EC;
	beginState_EnemyState7__5EnemyFv = 0xEEF10F0;
	executeState_EnemyState7__5EnemyFv = 0xEEF10F4;
	endState_EnemyState7__5EnemyFv = 0xEEF10F8;
	beginState_EnemyState8__5EnemyFv = 0xEEF10FC;
	executeState_EnemyState8__5EnemyFv = 0xEEF1100;
	endState_EnemyState8__5EnemyFv = 0xEEF1104;
	beginState_PenguinIceHit__5EnemyFv = 0xEEF0720;
	executeState_PenguinIceHit__5EnemyFv = 0xEEF07A0;
	endState_PenguinIceHit__5EnemyFv = 0xEEF0944;
	
	__vtbl__4Boss = 0x1050782C;
	__ct__4BossFP14ActorBuildInfo = 0xEBEB968;
	checkDerivedRuntimeTypeInfo__4BossFPv = 0xEBEDAB0;
	__dt__4BossFv = 0xEBEE2E0;
	onCreate__4BossFv = 0xEBEBB68;
	beforeExecute__4BossFv = 0xEBEBD0C;
	afterExecute__4BossFi = 0xEBEBDDC;
	onDelete__4BossFv = 0xEBEDC2C;
	removeColliders__4BossFv = 0xEBEDDF0;
	addColliders__4BossFv = 0xEBEDE7C;
	vf154__4BossFv = 0xEBECE40;
	freezeActor__4BossFv = 0xEBECEAC;
	vf1BC__4BossFv = 0xEBECF64;
	vf1C4__4BossFv = 0xEBEE2D0;
	playerCollision__4BossFUiP8Collider = 0xEBEBFDC;
	yoshiCollision__4BossFUiP8Collider = 0xEBEC2B4;
	vf22C__4BossFv = 0xEBEDCC8;
	hitJump__4BossFP8ColliderT1 = 0xEBEDCD0;
	collidesSomething__4BossFP8ColliderT1 = 0xEBEC5D0;
	hitEnemyDown__4BossFP8ColliderT1 = 0xEBEDCD8;
	hitGroundPound__4BossFP8ColliderT1 = 0xEBEC3AC;
	hitEnemyKame2__4BossFP8ColliderT1 = 0xEBEC5E0;
	hitEnemyKameDown__4BossFP8ColliderT1 = 0xEBEC8E0;
	vf27C__4BossFv = 0xEBEC6D4;
	vf284__4BossFP8ColliderT1 = 0xEBECBCC;
	hitEx__4BossFv = 0xEBECCB0;
	vf2C4__4BossFv = 0xEBEDCE0;
	isGrounded__4BossFv = 0xEBECE00;
	vf2F4__4BossFv = 0xEBEDD38;
	beginState_JumpKill__4BossFv = 0xEBEDC9C;
	executeState_JumpKill__4BossFv = 0xEBEDCA0;
	endState_JumpKill__4BossFv = 0xEBEDCA4;
	beginState_BossState1__4BossFv = 0xEBEBECC;
	executeState_BossState1__4BossFv = 0xEBEBEDC;
	endState_BossState1__4BossFv = 0xEBEBEEC;
	beginState_BossState2__4BossFv = 0xEBEBEFC;
	executeState_BossState2__4BossFv = 0xEBEBF0C;
	endState_BossState2__4BossFv = 0xEBEBF1C;
	beginState_BossState3__4BossFv = 0xEBEBF2C;
	executeState_BossState3__4BossFv = 0xEBEBF3C;
	endState_BossState3__4BossFv = 0xEBEBF4C;
	beginState_BossState4__4BossFv = 0xEBEBF5C;
	executeState_BossState4__4BossFv = 0xEBEBF6C;
	endState_BossState4__4BossFv = 0xEBEBF7C;
	beginState_BossState5__4BossFv = 0xEBEBF8C;
	executeState_BossState5__4BossFv = 0xEBEBF9C;
	endState_BossState5__4BossFv = 0xEBEBFAC;
	vf55C__4BossFv = 0xEBEDCA8;
	vf564__4BossFv = 0xEBEDCB4;
	vf56C__4BossFv = 0xEBEDCC0;
	vf574__4BossFv = 0xEBEBFBC;
	vf57C__4BossFv = 0xEBEDCC4;
	vf584__4BossFv = __deleted_virtual_called;
	vf58C__4BossFv = 0xEBEDD3C;
	vf594__4BossFv = 0xEBEDD4C;
	vf59C__4BossFv = __deleted_virtual_called;
	vf5A4__4BossFv = __deleted_virtual_called;
	vf5AC__4BossFv = __deleted_virtual_called;
	vf5B4__4BossFv = 0xEBEDD90;
	vf5BC__4BossFUi = 0xEBEDD98;
	vf604__4BossFv = 0xEBEDDBC;
	vf60C__4BossFv = 0xEBEDDC0;
	vf614__4BossFv = 0xEBEDDC4;
	vf61C__4BossFv = 0xEBEDDC8;
	vf624__4BossFv = __deleted_virtual_called;
	vf62C__4BossFv = 0xEBEDDD0;
	vf634__4BossFP10StageActor = 0xEBEDDD8;
	vf63C__4BossFP10StageActor = 0xEBEDDE4;
	vf644__4BossFv = 0xEBED120;
	vf64C__4BossFUi = 0xEBED214;
	vf654__4BossFv = 0xEBEDF28;
	changeState_JumpKill__4BossFv = 0xEBEDF2C;
	vf664__4BossFv = 0xEBEDF44;
	changeState_State1__4BossFv = 0xEBEDF48;
	vf674__4BossFv = 0xEBEDF60;
	vf67C__4BossFv = 0xEBEDF70;
	vf684__4BossFv = __deleted_virtual_called;
	vf68C__4BossFv = __deleted_virtual_called;
	vf694__4BossFv = __deleted_virtual_called;
	vf69C__4BossFv = __deleted_virtual_called;
	vf6A4__4BossFv = 0xEBEDF80;
	changeState_State5__4BossFv = 0xEBEDF84;
	vf6B4__4BossFv = 0xEBEDF9C;
	changeState_State3__4BossFv = 0xEBEDFA0;
	vf6C4__4BossFv = __deleted_virtual_called;
	vf6CC__4BossFv = __deleted_virtual_called;
	vf6D4__4BossFv = 0xEBEDFB8;
	vf6DC__4BossFv = 0xEBEDFC0;
	vf6E4__4BossFv = 0xEBEDFC4;
	vf6EC__4BossFv = 0xEBEDFD4;
	vf6F4__4BossFv = 0xEBEDFDC;
	vf6FC__4BossFv = 0xEBEDFE4;
	vf704__4BossFv = 0xEBEDFEC;
	vf70C__4BossFv = __deleted_virtual_called;
	vf714__4BossFv = __deleted_virtual_called;
	vf71C__4BossFv = __deleted_virtual_called;
	vf724__4BossFv = 0xEBEDFF4;
	vf72C__4BossFv = 0xEBEDFF8;
	vf734__4BossFv = 0xEBEDFFC;
	vf73C__4BossFv = __deleted_virtual_called;
	vf744__4BossFv = 0xEBEE000;
	stomp__4BossFv = 0xEBEE004;
	lastStomp__4BossFv = 0xEBEE01C;
	vf75C__4BossFv = __deleted_virtual_called;
	damageStar__4BossFv = 0xEBEE034;
	vf76C__4BossFv = __deleted_virtual_called;
	damageLast__4BossFv = 0xEBEE04C;
	damageFire__4BossFv = 0xEBEE064;
	damageFireLast__4BossFv = 0xEBEE0D8;
	damageFire2__4BossFv = 0xEBEE130;
	damageFireLast2__4BossFv = 0xEBEE1A4;
	damageStarDef__4BossFv = 0xEBEE1FC;
	damageLast2__4BossFv = 0xEBEE214;
	vf7AC__4BossFv = 0xEBEE22C;
	vf7B4__4BossFv = __deleted_virtual_called;
	vf7BC__4BossFv = __deleted_virtual_called;
	vf7C4__4BossFv = 0xEBEE230;
	vf7CC__4BossFv = 0xEBED3BC;
	initBossCollider__4BossFv = 0xEBED3F4;
	initModels__4BossFv = 0xEBEE2B8;
	vf7E4__4BossFv = 0xEBEE2BC;
	vf7EC__4BossFv = 0xEBEE2C0;
	vf7F4__4BossFv = 0xEBEE2C4;
	vf7FC__4BossFv = 0xEBEE2C8;
	
	__ct__16WalkingEnemyBaseFP14ActorBuildInfo = 0xEEAB09C;
	__vtbl__16WalkingEnemyBase = 0x105647BC;
	__dt__16WalkingEnemyBase = 0xEEAD710;
	beforeExecute__16WalkingEnemyBaseFv = 0xEEAB18C;
	onDelete__16WalkingEnemyBaseFv = 0xEEAB218;
	setPlayerId__16WalkingEnemyBaseFUc = 0xEFAB7E4;
	getPhysics__16WalkingEnemyBaseFv = 0xEFAB810;
	vfBC__16WalkingEnemyBaseFv = 0xEEAB368;
	move__16WalkingEnemyBaseFP4Vec2 = 0xEFAB818;
	setYSpeed__16WalkingEnemyBaseFf = 0xEFAB82C;
	getRect__16WalkingEnemyBaseFP4Rect = 0xEFAB844;
	vf214__16WalkingEnemyBaseFP8ColliderT1 = 0xEEABC60;
	vf274__16WalkingEnemyBaseFP8ColliderT1 = 0xEEAC18C;
	vf284__16WalkingEnemyBaseFP8ColliderT1 = 0xEEAC130;
	vf2B4__16WalkingEnemyBaseFPUcP8ColliderT2 = 0xEEAC59C;
	vf4F4__16WalkingEnemyBaseFv = 0xEEABD84;
	vf4FC__16WalkingEnemyBaseFP8ColliderT1 = 0xEEABE7C;
	vf504__16WalkingEnemyBaseFP8ColliderT1 = 0xEEABFEC;
	vf50C__16WalkingEnemyBaseFP8ColliderT1 = 0xEEAC06C;
	vf514__16WalkingEnemyBaseFv = 0xEEAD6FC;
	vf52C__16WalkingEnemyBaseFv = 0xEEACD00;
	vf534__16WalkingEnemyBaseFv = 0xEEACD8C;
	vf53C__16WalkingEnemyBaseFv = 0xEEACF84;
	vf544__16WalkingEnemyBaseFv = 0xEEAD700;
	vf54C__16WalkingEnemyBaseFv = 0xEEAD704;
	vf554__16WalkingEnemyBaseFv = 0xEEAD708;
	vf55C__16WalkingEnemyBaseFv = 0xEEAD02C;
	vf564__16WalkingEnemyBaseFv = 0xEEAD70C;
	vf56C__16WalkingEnemyBaseFv = 0xEEAD07C;
	
	__vtbl__13WindGenerator = 0x106582A8;
	__dt__13WindGeneratorFv = 0xF44F044;
	onCreate__13WindGeneratorFv = 0xF44EC68;
	onExecute__13WindGeneratorFv = 0xF44ED94;
	
	instance__11AreaRumbler = 0x106D3860;
	rumbleScreen__11AreaRumblerFUcUiN32 = 0xF084BD8;
	
	instance__11ItemSpawner = 0x106D5180;
	getExtraPlayerCount__11ItemSpawnerFv = 0xF0DDF48;
	
	instance__7CoinMgr = 0x106DD63C;
	dropCoins__7CoinMgrFP4Vec3 = 0xF28DBC4;
	spawnItemCoin__7CoinMgrFP4Vec3UiUc = 0xF28AC58;
	
	spawnBabyEgg__8YoshiMgrSFP4Vec3UcUi = 0xF303C54;
	
	__vtbl__20BlockCoinRelatedBase = 0x10603CA0;
	checkDerivedRuntimeTypeInfo__20BlockCoinRelatedBaseFPv = 0xF2C8E64;
	__dt__20BlockCoinRelatedBaseFv = 0xF2C8FEC;
	vf18C__20BlockCoinRelatedBaseFv = 0xF2C8FA0;
	vf194__20BlockCoinRelatedBaseFv = 0xF2C8FA4;
	vf19C__20BlockCoinRelatedBaseFv = 0xF2C8FA8;
	vf1A4__20BlockCoinRelatedBaseFv = 0xF2C8FAC;
	spawnItemUp__20BlockCoinRelatedBaseFv = 0xF2C8FB0;
	vf1B4__20BlockCoinRelatedBaseFv = 0xF2C8FB4;
	vf1BC__20BlockCoinRelatedBaseFv = 0xF2C8FB8;
	spawnItemDown__20BlockCoinRelatedBaseFv = 0xF2C8FBC;
	vf1CC__20BlockCoinRelatedBaseFv = 0xF2C8FC0;
	vf1D4__20BlockCoinRelatedBaseFb = 0xF2C490C;
	vf1DC__20BlockCoinRelatedBaseFv = 0xF2C8FC4;
	spawnCoinShower__20BlockCoinRelatedBaseFv = 0xF2C4988;
	vf1EC__20BlockCoinRelatedBaseFv = 0xF2C8FCC;
	beginState_BumpUp__20BlockCoinRelatedBaseFv = 0xF2C7D58;
	executeState_BumpUp__20BlockCoinRelatedBaseFv = 0xF2C7D94;
	endState_BumpUp__20BlockCoinRelatedBaseFv = 0xF2C8FD0;
	beginState_BlockCoinRelatedState1__20BlockCoinRelatedBaseFv = 0xF2C7E38;
	executeState_BlockCoinRelatedState1__20BlockCoinRelatedBaseFv = 0xF2C7E44;
	endState_BlockCoinRelatedState1__20BlockCoinRelatedBaseFv = 0xF2C8FD4;
	beginState_BumpDown__20BlockCoinRelatedBaseFv = 0xF2C7E5C;
	executeState_BumpDown__20BlockCoinRelatedBaseFv = 0xF2C7EA0;
	endState_BumpDown__20BlockCoinRelatedBaseFv = 0xF2C8FD8;
	beginState_BlockCoinRelatedState2__20BlockCoinRelatedBaseFv = 0xF2C7F40;
	executeState_BlockCoinRelatedState2__20BlockCoinRelatedBaseFv = 0xF2C7F4C;
	endState_BlockCoinRelatedState2__20BlockCoinRelatedBaseFv = 0xF2C8FDC;
	beginState_BumpUp2__20BlockCoinRelatedBaseFv = 0xF2C7F74;
	executeState_BumpUp2__20BlockCoinRelatedBaseFv = 0xF2C7FFC;
	endState_BumpUp2__20BlockCoinRelatedBaseFv = 0xF2C8FE0;
	beginState_BumpDown2__20BlockCoinRelatedBaseFv = 0xF2C81D0;
	executeState_BumpDown2__20BlockCoinRelatedBaseFv = 0xF2C823C;
	endState_BumpDown2__20BlockCoinRelatedBaseFv = 0xF2C8FE4;
	beginState_BlockCoinRelatedState3__20BlockCoinRelatedBaseFv = 0xF2C8330;
	executeState_BlockCoinRelatedState3__20BlockCoinRelatedBaseFv = 0xF2C833C;
	endState_BlockCoinRelatedState3__20BlockCoinRelatedBaseFv = 0xF2C8FE8;
	
	spawnPortableSpring__20BlockCoinRelatedBaseFv = 0xF2C64D4;
	spawnVine__20BlockCoinRelatedBaseFv = 0xF2C634C;
	spawnYoshiEgg__20BlockCoinRelatedBaseFb = 0xF2C6C48;
	spawnPowerup__20BlockCoinRelatedBaseFP4Vec3UiT2b = 0xF2C6DC0;
	spawnMultiPowerup__20BlockCoinRelatedBaseFP4Vec3UiT2b = 0xF2C7098;
	
	__vtbl__13BlockCoinBase = 0x106097CC;
	checkDerivedRuntimeTypeInfo__13BlockCoinBaseFPv = 0xF2E7AAC;
	__dt__13BlockCoinBaseFv = 0xF2E7C48;
	spawnItemUp__13BlockCoinBaseFv = 0xF2E66B4;
	spawnItemDown__13BlockCoinBaseFv = 0xF2E66D8;
	vf1DC__13BlockCoinBaseFv = 0xF2E66E8;
	vf1EC__20BlockCoinRelatedBaseFv = 0xF2E7A24;
	vf29C__13BlockCoinBaseFv = 0xF2E7A28;
	setTileFlag__13BlockCoinBaseFv = 0xF2E6660;
	vf2AC__13BlockCoinBaseFv = 0xF2E7A2C;
	vf2B4__13BlockCoinBaseFv = 0xF2E7A34;
	vf2BC__13BlockCoinBaseFv = 0xF2E7A38;
	vf2C4__13BlockCoinBaseFv = 0xF2E7A3C;
	vf2CC__13BlockCoinBaseFv = 0xF2E66F8;
	
	StateID_Wait__9BlockBase = 0x10720AE0;
	StateID_Used__9BlockBase = 0x10720B04;
	
	otherCollisionCallback1__9BlockBaseSFP17OtherColliderBaseP7PhysicsUi = 0xF2C5194;
	otherCollisionCallback2__9BlockBaseSFP17OtherColliderBaseP7PhysicsUi = 0xF2C5A00;
	otherCollisionCallback3__9BlockBaseSFP17OtherColliderBaseP7PhysicsUi = 0xF2C6164;
	
	init__9BlockBaseFbT1 = 0xF25F76C;
	
	__vtbl__9BlockBase = 0x105E8B80;
	__ct__9BlockBaseFP14ActorBuildInfo = 0xF25E6B8;
	checkDerivedRuntimeTypeInfo__9BlockBaseFPv = 0xF260504;
	__dt__9BlockBaseFv = 0xF2606D0;
	onExecute__9BlockBaseFv = 0xF25E768;
	onDraw__9BlockBaseFv = 0xF25E820;
	vf19C__9BlockBaseFv = 0xF25F4A4;
	spawnItemUp__9BlockBaseFv = 0xF25EC64;
	spawnItemDown__9BlockBaseFv = 0xF25EC68;
	vf1CC__9BlockBaseFv = 0xF25ECA8;
	vf2C4__9BlockBaseFv = 0xF25F4B4;
	vf2D4__9BlockBaseFv = 0xF25ECC0;
	vf2DC__9BlockBaseFv = 0xF2604A8;
	getContent__9BlockBaseFv = 0xF2604AC;
	vf2EC__9BlockBaseFv = 0xF25F088;
	vf2F4__9BlockBaseFP4Vec3 = 0xF2604BC;
	execute__9BlockBaseFv = 0xF25F11C;
	vf304__9BlockBaseFv = 0xF25F300;
	vf30C__9BlockBaseFv = 0xF25F3E0;
	vf314__9BlockBaseFv = 0xF2604D8;
	vf31C__9BlockBaseFv = 0xF2604DC;
	vf324__9BlockBaseFv = 0xF2604E0;
	vf32C__9BlockBaseFv = 0xF2604E4;
	beginState_Wait__9BlockBaseFv = 0xF2606C0;
	executeState_Wait__9BlockBaseFv = 0xF26010C;
	endState_Wait__9BlockBaseFv = 0xF2606C4;
	beginState_Used__9BlockBaseFv = 0xF2606C8;
	executeState_Used__9BlockBaseFv = 0xF260118;
	endState_Used__9BlockBaseFv = 0xF2606CC;
	
	StateID_Main__8CoinBase = 0x10722F70;
	
	__vtbl__8CoinBase = 0x105F3D10;
	__ct__8CoinBaseFP14ActorBuildInfo = 0xF27F830;
	init__8CoinBaseFv = 0xF27FFF0;
	initCollider__8CoinBaseFUi = 0xF280EC8;
	addCollider__8CoinBaseFv = 0xF2E6804;
	checkDerivedRuntimeTypeInfo__8CoinBaseFPv = 0xF281CB4;
	__dt__8CoinBaseFv = 0xF281E8C;
	onExecute__8CoinBaseFv = 0xF27FA74;
	onDraw__8CoinBaseFv = 0xF27FC40;
	splashWater__8CoinBaseFP4Vec3 = 0xF27FE68;
	splashLava__8CoinBaseFP4Vec3 = 0xF27FEC4;
	splashLavaWave__8CoinBaseFP4Vec3 = 0xF27FF28;
	splashPoison__8CoinBaseFP4Vec3 = 0xF27FF8C;
	vf11C__8CoinBaseFv = 0xF27FDBC;
	vf124__8CoinBaseFf = 0xF27FDD4;
	vf12C__8CoinBaseFv = 0xF281CA4;
	vf144__8CoinBaseFb = 0xF27FCFC;
	vf2AC__8CoinBaseFv = 0xF27FCE4;
	vf2D4__8CoinBaseFv = 0xF281CAC;
	initYoshiEatData__8CoinBaseFv = 0xF27FDE4;
	vf2E4__8CoinBaseFv = 0xF281020;
	vf2EC__8CoinBaseFv = 0xF281128;
	vf2F4__8CoinBaseFv = 0xF281E70;
	vf2FC__8CoinBaseFv = 0xF28129C;
	vf304__8CoinBaseFv = 0xF2813A4;
	vf30C__8CoinBaseFv = 0xF281E74;
	
	getTilt__10ControllerFPUif = 0xF0CED50;
	
	instance__8InputMgr = 0x106D4FF8;
	
	__vtbl__10PlayerBase = 0x106690A4;
	playSound__10PlayerBaseFPcb = 0xF4CBA48;
	groundPound__10PlayerBaseFv = 0xF4CA430;
	playLandSound__10PlayerBaseFv = 0xF4CBF08;
	doLandEffects__10PlayerBaseFv = 0xF4C477C;
	spawnGroundPoundBlurEffect__10PlayerBaseFv = 0xF4C41CC;
	usedByGoalPole__10PlayerBaseFv = 0xF4C2BD4;
	
	StateID_DefaultState__5Yoshi = 0x1072D9E0;
	
	onCreate__5YoshiFv = 0xF51E278;

	getRidingPlayer__5YoshiFv = 0xF52B468;
	changeState__5YoshiFP19State__tm__7_5Yoshi = 0xF522310;
	spawnBall__5YoshiFb = 0xF52286C;
	getActorInMouth__5YoshiFv = 0xF522600;
	removeActorFromMouth__5YoshiFv = 0xF522CA8;
	
	__vtbl__6Player = 0x1066E370;
	
	instance__15BasicSoundActor = 0x106C85D0;
	playSound__15BasicSoundActorFPCcP4Vec2Ui = 0xF57EDEC;
	
	instance__18AmbientSoundPlayer = 0x106C85D4;
	__vtbl__18AmbientSoundPlayer = 0x105072F0;
	
	instance__11SoundSystem = 0x106E9E84;
	getSoundArchive__11SoundSystemFv = 0xF573C4C;
	playSound__11SoundSystem2FPCcUi = 0xF575564;
	
	instance__12EnemyCounter = 0x106C52D0;
	killEnemiesGoal__12EnemyCounterFv = 0xEBCBAF4;

	/*** HACK ADDRESSES ***/
	returnTileGod = 0xF2E5DB0;
	returnInitRaftState = 0xF2B13B0;
	continueRenderTileAnim = 0xF254A58;

	/*** UNKNOWN PURPOSE ADDRESSES ***/

	/*** ITEM(BASE) ***/
	ModelUpdateThing__8ItemBaseFv = 0xF0D8AF0;
	setupActor__8ItemBaseFv = 0xF0D8034;
	setupState__8ItemBaseFv = 0xF0D8514;

	sub_24FE8F8__8ItemBaseFv = 0xF0D9038;
	sub_24FDD10__8ItemBaseFv = 0xF0D8450;

}
