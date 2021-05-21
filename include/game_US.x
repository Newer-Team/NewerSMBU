
SECTIONS {

/*** GHS C++ FUNCTIONS ***/
__nw__FUi = 0xf5b1594;
__nwa__FUi = 0xf5b1630;
__dl__FPv = 0xf5b1748;
__nw__FUiPQ2_4sead4Heapi = 0xf5b1858;
__vec_new = 0xf6ba350;
__vec_delete = 0xf6ba490;
__record_needed_destruction = 0xf6ba52c;
__pure_virtual_called = 0xf6ba554;
__memzero = 0xf6ba55c;
__deleted_virtual_called = 0xf6ba5e8;
__gh_long_long_printf = 0xf6ba784;
__gh_float_printf = 0xf6baba8;
vsnprintf = 0xf6bb954;
__ghs_strlen = 0xf6bd51c;
sinf = 0xf6bdd40;
cosf = 0xf6be528;
atan2f = 0xf6be670;
__gh_memclr32 = 0xf6bede0;


/*** CAFE SDK STATIC ***/
ASM_VECDistance = 0xf6b9718;


/*** CAFE SDK IMPORTS ***/
OSBlockSet = 0xf6c45b0;

inflateInit2_ = 0xf6d84dc;
inflate = 0xf6d8770;
inflateEnd = 0xf6d9d28;


/*** SEAD LIBRARY ***/
__vtbl__Q2_4sead6String = 0x105f7548;

__vtbl__Q2_4sead9IDisposer = 0x106931a8;
__dt__Q2_4sead9IDisposerFv = 0xf5ca384;

rootHeaps__Q2_4sead7HeapMgr = 0x10aec348;
getCurrentHeap__Q2_4sead7HeapMgrSFv = 0xf5cd554;

__vtbl__Q2_4sead4Heap = 0x106934ac;

instance__Q2_4sead12GlobalRandom = 0x106ea26c;
getU32__Q2_4sead6RandomFv = 0xf5d3780;

__ct__Q2_4sead15GraphicsContextFv = 0xf5c7bbc;
apply__Q2_4sead15GraphicsContextFv = 0xf5c7cb0;

__ct__Q2_4sead18GraphicsContextMRTFv = 0xf5c7e70;
apply__Q2_4sead18GraphicsContextMRTFv = 0xf5c7f90;

getDeviceProjectionMatrix__Q2_4sead10ProjectionFv = 0xf5c5a9c;

__ct__Q2_4sead15OrthoProjectionFfN51 = 0xf5c65ac;
__dt__Q2_4sead15OrthoProjectionFv = 0xf5c67c4;

bind__Q2_4sead11FrameBufferFv = 0xf5c58f0;

tryLoad__Q2_4sead10FileDeviceFPQ3_4sead10FileDevice7LoadArg = 0xf6868a4;

instance__Q2_4sead13FileDeviceMgr = 0x106ea118;
tryLoad__Q2_4sead13FileDeviceMgrFPQ3_4sead10FileDevice7LoadArg = 0xf5b8bbc;

getDecompSize__Q2_4sead15SZSDecompressorSFPCv = 0xf5d54cc;
decomp__Q2_4sead15SZSDecompressorSFPvUiPCvT2 = 0xf5d5654;


/*** AGL LIBRARY ***/
searchShaderProgramIndex__Q2_3agl20ShaderProgramArchiveFPQ2_4sead6String = 0xf5e45a8;

createUniformBlock__Q2_3agl13ShaderProgramFiPQ2_4sead4Heap = 0xf5e1720;
setUniformBlockName__Q2_3agl13ShaderProgramFiPQ2_4sead6String = 0xf5e1908;
createSamplerBlock__Q2_3agl13ShaderProgramFiPQ2_4sead4Heap = 0xf5e1980;
setSamplerBlockName__Q2_3agl13ShaderProgramFiPQ2_4sead6String = 0xf5e1b68;

__ct__Q2_3agl11TextureDataFv = 0xf5e49a0;
invalidateGPUCache__Q2_3agl11TextureDataFv = 0xf5e4a64;
initialize__Q2_3agl11TextureDataFQ2_3agl11TextureTypeQ2_3agl13TextureFormatUiN33Q2_3agl15MultiSampleType = 0xf5e4d14;
loadGTX__Q2_3agl11TextureDataFPvUi = 0xf5e4f38;

applyTextureData___Q2_3agl14TextureSamplerFPQ2_3agl11TextureData = 0xf5e5990;

__ct__Q2_3agl17RenderTargetColorFv = 0xf5defdc;
applyTextureData__Q2_3agl17RenderTargetColorFPQ2_3agl11TextureData = 0xf096070;
invalidateGPUCache__Q2_3agl17RenderTargetColorFv = 0xf5df088;

__ct__Q2_3agl17RenderTargetDepthFv = 0xf5df16c;
applyTextureData__Q2_3agl17RenderTargetDepthFPQ2_3agl11TextureData = 0xf096200;
invalidateGPUCache__Q2_3agl17RenderTargetDepthFv = 0xf5df220;

__ct__Q2_3agl12RenderBufferFP4Vec2fN32 = 0xf5deadc;
__dt__Q2_3agl12RenderBufferFv = 0xf5de33c;
clear__Q2_3agl12RenderBufferFUiT1PQ2_4sead7Color4fT1f = 0xf5de644;


/*** NW LIBRARY ***/
snprintf__Q2_2nw2utFPcUiPCce = 0xf6868a4;

GetItemLabel__Q3_2nw3snd12SoundArchiveFUi = 0xf696980;

GetString__Q5_2nw3snd8internal16SoundArchiveFile15StringBlockBodyFUi = 0xf697604;


/*** GAME ADDRESSES ***/
fileCounts = 0x105045f8;
fileLists = 0x106c541c;
directionToRotationList = 0x10702fd8;
spriteToActorList = 0x106eef8c;
tileGodList = 0x10609430;

calcMatrix__FPA3_A4_fP5Vec3iP4Vec3 = 0xebfc1c8;
mapPosToScreen__FP4Vec2T1 = 0xebe9368;
spawnEffect__F7EffectsP4Vec3P5Vec3iT2 = 0xee6b080;
moveValueTo__FPUiUiT2 = 0xf5a0de8;
moveFloatTo__FPffT2 = 0xebe7984;

__ct__7ProfileFPFP14ActorBuildInfo_P5Actor6ActorsPCcPC9ActorInfoUi = 0xebd9554;
Get__7ProfileSF6Actors = 0xebd9774;
GetProfile = 0xebd9774;

instance__8AreaTask = 0x106d3798;
getWrappedXPos__8AreaTaskFf = 0xf078034;

instance__9LevelInfo = 0x106d3aec;

getLocationById__9LevelAreaFP4RectUc = 0xf25a020;
getZoneById__9LevelAreaFUcP4Rect = 0xf259d00;

instance__5Level = 0x106dd248;
getArea__5LevelFUc = 0xf25a2dc;

instance__10LevelTimer = 0x106d37f4;
addSeconds__10LevelTimerFUi = 0xf0814c0;

instance__11LevelCamera = 0x106e9e54;

instance__8EventMgr = 0x106dd26c;

instance__9PlayerMgr = 0x106e8b94;

__ct__13EffectHandlerFv = 0xee6b868;
update__13EffectHandlerF7EffectsPA3_A4_fb = 0xee6b6ec;
update__13EffectHandlerF7EffectsP4Vec3P5Vec3iT2 = 0xee6b52c;

init__14TerrainEffectsFP4Vec3fbT311TerrainTypePQ2_4sead4Heap = 0xf4772d4;
setWaveValues__14TerrainEffectsFUiN51 = 0xf4774f4;
checkMarioWaveHit__14TerrainEffectsFv = 0xf478bf4;
updateWaveCollisions__14TerrainEffectsFv = 0xf478d5c;

onExecute__10EnvTerrainFv = 0xf2b0e9c;
setTop__10EnvTerrainFf = 0xf2b1278;

instance__7TileMgr = 0x106dcd94;
getTilePointer__7TileMgrSFUsT1UcPUi = 0xf245000;

instance__17FrameBufferKeeper = 0x106d4d88;
__CPR93__switchBuffer__17FrameBufferKeeperFQ2_J14J10BufferTypePQ3_3agl3lyr10RenderInfob = 0xf09e2bc;

__ct__10BgMaskListFv = 0xf25a3f8;
__dt__10BgMaskListFv = 0xf25a490;
init__10BgMaskListFPQ2_4sead4Heap = 0xf25a614;
add__10BgMaskListFP8MaskInfoN31PQ2_3agl11TextureDataUi = 0xf25a82c;
draw__10BgMaskListFPvT1 = 0xf25ab9c;

instance__10BgRenderer = 0x106dd1e8;
initShaders__10BgRendererSFPQ2_3agl20ShaderProgramArchivePQ2_4sead4Heap = 0xf24f5fc;
allocTexture__10BgRendererSFPQ2_4sead6StringQ4_3agl3utl23DynamicTextureAllocator12AllocateType = 0xf25048c;
allocDepthTexture__10BgRendererSFPQ2_4sead6StringPPv = 0xf250638;
freeTexture__10BgRendererSFPPQ2_3agl11TextureData = 0xf251820;
__vtbl__10BgRenderer = 0x105e7a38;
__ct__10BgRendererFv = 0xf24f034;
__dt__10BgRendererFv = 0xf25338c;
init__10BgRendererFPQ2_4sead4Heap = 0xf24f7f0;
drawLayerMasks__10BgRendererFPQ3_3agl3lyr10RenderInfo = 0xf252194;
drawTilesWithMasks__10BgRendererFPQ3_3agl3lyr10RenderInfo = 0xf25222c;
renderTileLayer__10BgRendererFPQ2_4sead8ViewportPQ2_4sead15OrthoProjectionUi = 0xf251368;
initSpotlightMaskFrameBuffer__10BgRendererFPQ3_3agl3lyr10RenderInfo = 0xf2520b0;

loadTexture__11MaskTexDataSFQ2_11MaskTexture5ShapePQ2_3agl11TextureData = 0xf3d5618;

__ct__9LightMaskFv = 0xf3d5c9c;
init__9LightMaskFPQ2_4sead4HeapQ2_11MaskTexture5Shape = 0xf3d5d20;
update__9LightMaskFv = 0xf3d5dcc;
draw__9LightMaskFv = 0xf3d60c8;

__vtbl__9LayerMask = 0x1063979c;
init__9LayerMaskFPQ2_4sead4HeapQ2_11MaskTexture5Shape = 0xf3d64c4;
update__9LayerMaskFv = 0xf3d6564;
draw__9LayerMaskFv = 0xf3d661c;

loadTilesets__8BgTexMgrFUc = 0xf253a24;
loadTexture__8BgTexMgrSFPQ2_3agl11TextureDataPQ2_4sead6StringT2 = 0xf2539b4;
update__8BgTexMgrFv = 0xf25469c;
renderAnimation__8BgTexMgrFUiN21i = 0xf2547bc;

instance__13TilesetLoader = 0x106dd1c0;
getTilesetName__13TilesetLoaderFUcT1 = 0xf24e3a0;

instance__6ResMgr = 0x106e9f94;
loadArchive__6ResMgrFPCQ2_4sead6StringT1PQ2_4sead4Heapb = 0xf5934a8;
getArchive__6ResMgrFPCQ2_4sead6String = 0xf593ca0;

instance__9ResLoader = 0x106d4f50;
getResArchive__9ResLoaderFQ2_4sead6String = 0xf0b60ec;

getModel__10ResArchiveFQ2_4sead6StringUiN42bPQ2_4sead4Heap = 0xf0ae440;

__vtbl__8ModelObj = 0x105bf130;

__ct__5ModelFP8ModelObjUiN42 = 0xf094798;
init__5ModelFP10ResArchivePQ2_4sead33PtrArrayImpl__tm__13_10ResArchivePQ2_4sead4Heap = 0xf0949a0;
update__5ModelFv = 0xf094e84;

__ct__6Model2FP8ModelObjUiN42 = 0xf09fbf0;
init__6Model2FP10ResArchivePQ2_4sead33PtrArrayImpl__tm__13_10ResArchivePQ2_4sead4Heap = 0xf09fc78;
update__6Model2Fv = 0xf09fc7c;

setRepeat__9AnimationFb = 0xf09eed4;

play__12SkeletalAnimFP10ResArchivePQ2_4sead6String = 0xf0bdadc;

__ct__14CharacterModelFPQ2_4sead6StringT1 = 0xf4e0ca8;

instance__6Drawer = 0x106d4f88;
drawModel__6DrawerFP5Model = 0xf0bac98;
drawTile__6DrawerFUiP4Vec3PUiT2 = 0xf0bad28;

init__13PlatformModelFv = 0xf37e110;
draw__13PlatformModelFv = 0xf37e4fc;
update__13PlatformModelFP4Vec3f = 0xf37e428;

__ct__9CollThingFv = 0xed61acc;

__vtbl__17OtherColliderBase = 0x10544728;

setRect__14CustomColliderFP4Vec2T1 = 0xed6d25c;

__vtbl__14CustomCollider = 0x10544888;
__ct__14CustomColliderFUiP4Vec2P9CollThingT3 = 0xed67904;
updateMovement__14CustomColliderFv = 0xed6871c;

init__13SolidColliderFP10StageActorP18SolidCollisionInfo = 0xed6d3bc;
__vtbl__13SolidCollider = 0x105fd998;
__dt__13SolidColliderFv = 0xf2ab9cc;

init__18SolidOnTopColliderFP10StageActorP23SolidOnTopCollisionInfoUiT3 = 0xed62378;
__vtbl__18SolidOnTopCollider = 0x10544438;
__ct__18SolidOnTopColliderFv = 0xed61d38;
__dt__18SolidOnTopColliderFv = 0xed61f18;
updateMovement__18SolidOnTopColliderFv = 0xed62e0c;

instance__17OtherCollisionMgr = 0x106cb560;
add__17OtherCollisionMgrFP17OtherColliderBase = 0xed5269c;

init__8ColliderFP10StageActorPC13CollisionInfoUi = 0xed5af1c;

instance__12CollisionMgr = 0x106cb7d8;
addCollider__12CollisionMgrFP8Collider = 0xed5e028;

init__7PhysicsFP10StageActorP4Vec3N22 = 0xed4af6c;
processCollisions__7PhysicsFv = 0xed4d954;

instance__17CourseDarknessMgr = 0x106e1ab4;

CurrentStateID = 0x106ec104;
executeState__10StateClassFv = 0xf584a80;

__vtbl__9StateBase = 0x10541ff8;
__dt__9StateBaseFv = 0xed4615c;
getStateId__9StateBaseFv = 0xed45da0;

freezeActor__11IceActorMgrFP7IceInfoUi = 0xef3d63c;

instance__8ActorMgr = 0x106c52c8;
createActor__8ActorMgrFP14ActorBuildInfoUi = 0xebc9a58;
findActorByType__8ActorMgrF6ActorsPP5Actor = 0xebc9b6c;

findActorById__9ActorListFPUi = 0xebca5c8;

__ct__15MovementHandlerFv = 0xf409c40;
getMaskForMovementType__15MovementHandlerF12MovementType = 0xf40a37c;
linkToMovementController__15MovementHandlerFP4Vec3UiUc = 0xf40b6f4;
execute__15MovementHandlerFv = 0xf40b8c4;

removeChild__5ActorFP5Actor = 0xebc2c8c;
getProfileId__5ActorFv = 0xebc2c80;

__vtbl__5Actor = 0x105028c0;
__ct__5ActorFP14ActorBuildInfo = 0xebc2ce0;
checkDerivedRuntimeTypeInfo__5ActorFPv = 0xebc2f40;
vf14__5ActorFv = 0xf6ba5e8;
__dt__5ActorFv = 0xebc2e68;
beforeCreate__5ActorFv = 0xebc2f7c;
onCreate__5ActorFv = 0xebc2f84;
afterCreate__5ActorFi = 0xebc2f00;
beforeExecute__5ActorFv = 0xebc2f04;
onExecute__5ActorFv = 0xebc2f8c;
afterExecute__5ActorFi = 0xebc2f34;
finalExecute__5ActorFv = 0xebc2f94;
beforeDraw__5ActorFv = 0xebc2f98;
onDraw__5ActorFv = 0xebc2fa0;
afterDraw__5ActorFi = 0xebc2f38;
beforeDelete__5ActorFv = 0xebc2fa8;
onDelete__5ActorFv = 0xebc2fb0;
afterDelete__5ActorFi = 0xebc2f3c;

getDirectionToPlayer__10StageActorFP4Vec3 = 0xebc05ec;

__vtbl__10StageActor = 0x10502468;
__ct__10StageActorFP14ActorBuildInfo = 0xebc0ac8;
checkDerivedRuntimeTypeInfo__10StageActorFPv = 0xebc2a38;
__dt__10StageActorFv = 0xebc0f18;
afterCreate__10StageActorFi = 0xebc0fb8;
beforeExecute__10StageActorFv = 0xebc0fe8;
afterExecute__10StageActorFi = 0xebc10bc;
beforeDraw__10StageActorFv = 0xebc11a0;
setPlayerId__10StageActorFUc = 0xebc2ab0;
removeColliders__10StageActorFv = 0xebc02cc;
addColliders__10StageActorFv = 0xebc0328;
getPhysics__10StageActorFv = 0xebc2ab8;
vfAC__10StageActorFv = 0xebc2ac0;
vfB4__10StageActorFv = 0xebc2ac4;
vfBC__10StageActorFv = 0xebc2acc;
vfC4__10StageActorFv = 0xebc2ad0;
vfCC__10StageActorFv = 0xebc2ad4;
killAtGoal__10StageActorFv = 0xebc2ad8;
splashWater__10StageActorFP4Vec3 = 0xebc2adc;
splashLava__10StageActorFP4Vec3 = 0xebc2ae0;
splashLavaWave__10StageActorFP4Vec3 = 0xebc0960;
splashPoison__10StageActorFP4Vec3 = 0xebc2ae4;
isOffScreen__10StageActorFv = 0xebc1254;
damageFromUnder__10StageActorFv = 0xebc2ae8;

applyGravity__12PhysicsActorFv = 0xebc39ac;

__vtbl__12PhysicsActor = 0x10502a4c;
checkDerivedRuntimeTypeInfo__12PhysicsActorFPv = 0xebc3f34;
__dt__12PhysicsActorFv = 0xebc40b0;
afterCreate__12PhysicsActorFi = 0xebc354c;
beforeExecute__12PhysicsActorFv = 0xebc35fc;
afterExecute__12PhysicsActorFi = 0xebc36d8;
onDelete__12PhysicsActorFv = 0xebc3724;
getPhysics__12PhysicsActorFv = 0xebc4010;
vf10C__12PhysicsActorFUc = 0xebc3ff0;
vf114__12PhysicsActorFv = 0xf6ba5e8;
vf11C__12PhysicsActorFv = 0xebc3ff8;
vf124__12PhysicsActorFf = 0xebc3ffc;
vf12C__12PhysicsActorFv = 0xebc4000;
vf134__12PhysicsActorFv = 0xf6ba5e8;
vf13C__12PhysicsActorFv = 0xebc4008;
vf144__12PhysicsActorFb = 0xebc375c;
vf14C__12PhysicsActorFv = 0xebc3760;
vf154__12PhysicsActorFv = 0xebc4018;
move__12PhysicsActorFP4Vec2 = 0xebc4020;
setYSpeed__12PhysicsActorFf = 0xebc4034;
vf16C__12PhysicsActorFv = 0xebc403c;
vf174__12PhysicsActorFv = 0xebc4044;
getRect__12PhysicsActorFP4Rect = 0xebc404c;

__vtbl__10StateActor = 0x10503248;
__ct__10StateActorFP14ActorBuildInfo = 0xebcaa8c;
checkDerivedRuntimeTypeInfo__10StateActorFPv = 0xebcaf94;
__dt__10StateActorFv = 0xebcb098;
doStateChange__10StateActorFP9StateBase = 0xebcb090;

__vtbl__11StateActor2 = 0x105030c8;

actorInfo__12SpinningStar = 0x1063334c;
__vtbl__12SpinningStar = 0x10633444;
__ct__12SpinningStarFP14ActorBuildInfo = 0xf3b5658;
checkDerivedRuntimeTypeInfo__12SpinningStarFPv = 0xf3b6fcc;
__dt__12SpinningStarFv = 0xf3b716c;
onCreate__12SpinningStarFv = 0xf3b5cb0;
onExecute__12SpinningStarFv = 0xf3b60ec;
onDraw__12SpinningStarFv = 0xf3b61a4;

StateID_JumpKill__5Enemy = 0x107031b0;

collisionCallback__5EnemySFP8ColliderT1 = 0xeee8c50;

spinJumpKill__5EnemyFP6Player = 0xeeecc98;
killWithPlayer__5EnemyFP6PlayerP4Vec2P19State__tm__7_5Enemy = 0xeeeda34;
killWithYoshi__5EnemyFP5Yoshi = 0xeeed31c;
processHit__5EnemyFP8ColliderT1 = 0xeee9b88;
updatePosition__5EnemyFv = 0xebc3ae4;

__vtbl__5Enemy = 0x1057429c;
__ct__5EnemyFP14ActorBuildInfo = 0xeee8494;
checkDerivedRuntimeTypeInfo__5EnemyFPv = 0xeeea70c;
__dt__5EnemyFv = 0xeeea868;
beforeExecute__5EnemyFv = 0xeee8644;
damageFromUnder__5EnemyFv = 0xeee8914;
vf14C__5EnemyFv = 0xeeedc88;
vf154__5EnemyFv = 0xeeee1a4;
doStateChange__5EnemyFP9StateBase = 0xeef0404;
vf18C__5EnemyFv = 0xeeea848;
playerCollision8A4__5EnemyFUiP8Collider = 0xeee8b84;
vf19C__5EnemyFUc = 0xeee910c;
freezeActor__5EnemyFv = 0xeef04f8;
vf1AC__5EnemyFv = 0xeef10bc;
vf1B4__5EnemyFv = 0xeee10c0;
vf1BC__5EnemyFv = 0xeef0568;
vf1C4__5EnemyFv = 0xeeea858;
vf1CC__5EnemyFv = 0xeeea85c;
vf1D4__5EnemyFUiPv = 0xeee91f8;
prePlayerCollision__5EnemyFP8ColliderT1 = 0xeee9250;
vf1E4__5EnemyFPUcP8ColliderT2 = 0xeee9520;
yoshiCollisionRelated__5EnemyFP8ColliderT1 = 0xeee9578;
preYoshiCollision__5EnemyFP8ColliderT1 = 0xeee957c;
vf1FC__5EnemyFP8ColliderT1 = 0xeee96e8;
actorCollision__5EnemyFP8ColliderT1 = 0xeee9800;
vf20C__5EnemyFv = 0xeee99f0;
playerCollision__5EnemyFP8ColliderT1 = 0xeee99f4;
yoshiCollision__5EnemyFP8ColliderT1 = 0xeee9a04;
vf224__5EnemyFP8ColliderT1 = 0xeee9a08;
vf22C__5EnemyFP8ColliderT1 = 0xeeece84;
hitJump__5EnemyFP8ColliderT1 = 0xeeecf20;
collidesSomething__5EnemyFP8ColliderT1 = 0xeeed014;
hitEnemyDown__5EnemyFP8ColliderT1 = 0xeeed0e4;
hitGroundPound__5EnemyFP8ColliderT1 = 0xeeed240;
hitYoshi__5EnemyFP8ColliderT1 = 0xeeed3b4;
hitEnemyKame2__5EnemyFP8ColliderT1 = 0xeeed48c;
hitEnemyKame3__5EnemyFP8ColliderT1 = 0xeeed49c;
callsHitJump__5EnemyFP8ColliderT1 = 0xeeed56c;
hitEnemyKameDown__5EnemyFP8ColliderT1 = 0xeeed57c;
fireballCollision__5EnemyFP8ColliderT1 = 0xeeed70c;
vf284__5EnemyFP8ColliderT1 = 0xeeed7a4;
hitNormal__5EnemyFP8ColliderT1 = 0xeeed824;
hitEnemyKame4__5EnemyFP8ColliderT1 = 0xeeed938;
vf29C__5EnemyFv = 0xeeeda04;
goldYoshiHit__5EnemyFP8ColliderT1 = 0xeeeda0c;
vf2AC__5EnemyFP8ColliderT1 = 0xeeeda14;
vf2B4__5EnemyFPUcP8ColliderT2 = 0xeeeda24;
hitEx__5EnemyFv = 0xeeedaf0;
vf2C4__5EnemyFv = 0xeeedd48;
hitEnemyKame5__5EnemyFP8ColliderT1 = 0xeeee048;
isGrounded__5EnemyFv = 0xeeee2ec;
playDownSound__5EnemyFv = 0xeeee2f8;
playDownSoundHpdp__5EnemyFv = 0xeeee358;
vf2EC__5EnemyFUi = 0xeee9ea4;
vf2F4__5EnemyFv = 0xeee9fa8;
vf2FC__5EnemyFUi = 0xeee9fac;
calls_vf2F4__5EnemyFv = 0xeee9fb0;
vf30C__5EnemyFUi = 0xeee9fc0;
playFumuSound__5EnemyFv = 0xeeea094;
playerHit__5EnemyFP10PlayerBase = 0xeeea118;
playDownSpinSound__5EnemyFv = 0xeeea1bc;
playMameStepSound__5EnemyFv = 0xeeea240;
vf334__5EnemyFv = 0xeeea24c;
playYoshiFumuSound__5EnemyFv = 0xeeea250;
spawnHipDropHitEffect__5EnemyFv = 0xeeea2d4;
increaseYSpeed__5EnemyFv = 0xeeea2e4;
positionRelated__5EnemyFv = 0xeeea2fc;
vf35C__5EnemyFPv = 0xeeea364;
vf364__5EnemyFPv = 0xeeea418;
vf36C__5EnemyFPv = 0xeeea4cc;
vf374__5EnemyFv = 0xeeea864;
beginState_JumpKill__5EnemyFv = 0xeeee518;
executeState_JumpKill__5EnemyFv = 0xeeee5e8;
endState_JumpKill__5EnemyFv = 0xeeeeed0;
beginState_FireballKill__5EnemyFv = 0xeeee63c;
executeState_FireballKill__5EnemyFv = 0xeeee640;
endState_FireballKill__5EnemyFv = 0xeeeeed4;
beginState_YoshiStamp__5EnemyFv = 0xeeee72c;
executeState_YoshiStamp__5EnemyFv = 0xeeee79c;
endState_YoshiStamp__5EnemyFv = 0xeeeeed8;
beginState_EnemyState11__5EnemyFv = 0xeeee7a8;
executeState_EnemyState11__5EnemyFv = 0xeeee7b8;
endState_EnemyState11__5EnemyFv = 0xeeeeedc;
beginState_EnemyState12__5EnemyFv = 0xeeee7c4;
executeState_EnemyState12__5EnemyFv = 0xeeee7c8;
endState_EnemyState12__5EnemyFv = 0xeeeeee0;
beginState_EnemyState13__5EnemyFv = 0xeeee7d4;
executeState_EnemyState13__5EnemyFv = 0xeeeeee4;
endState_EnemyState13__5EnemyFv = 0xeeeeee8;
beginState_ChallengeRelated__5EnemyFv = 0xeeee7e0;
executeState_ChallengeRelated__5EnemyFv = 0xeeeeeec;
endState_ChallengeRelated__5EnemyFv = 0xeeeeef0;
beginState_EnemyState2__5EnemyFv = 0xeef05e4;
executeState_EnemyState2__5EnemyFv = 0xeef05ec;
endState_EnemyState2__5EnemyFv = 0xeef10c4;
beginState_EnemyState3__5EnemyFv = 0xeef10c8;
executeState_EnemyState3__5EnemyFv = 0xeef10cc;
endState_EnemyState3__5EnemyFv = 0xeef10d0;
beginState_EnemyState4__5EnemyFv = 0xeef10d4;
executeState_EnemyState4__5EnemyFv = 0xeef10d8;
endState_EnemyState4__5EnemyFv = 0xeef10dc;
beginState_EnemyState5__5EnemyFv = 0xeef06e8;
executeState_EnemyState5__5EnemyFv = 0xeef06f0;
endState_EnemyState5__5EnemyFv = 0xeef10e0;
beginState_EnemyState6__5EnemyFv = 0xeef10e4;
executeState_EnemyState6__5EnemyFv = 0xeef10e8;
endState_EnemyState6__5EnemyFv = 0xeef10ec;
beginState_EnemyState7__5EnemyFv = 0xeef10f0;
executeState_EnemyState7__5EnemyFv = 0xeef10f4;
endState_EnemyState7__5EnemyFv = 0xeef10f8;
beginState_EnemyState8__5EnemyFv = 0xeef10fc;
executeState_EnemyState8__5EnemyFv = 0xeef1100;
endState_EnemyState8__5EnemyFv = 0xeef1104;
beginState_PenguinIceHit__5EnemyFv = 0xeef0720;
executeState_PenguinIceHit__5EnemyFv = 0xeef07a0;
endState_PenguinIceHit__5EnemyFv = 0xeef0944;

__vtbl__4Boss = 0x1050782c;
__ct__4BossFP14ActorBuildInfo = 0xebeb968;
checkDerivedRuntimeTypeInfo__4BossFPv = 0xebedab0;
__dt__4BossFv = 0xebee2e0;
onCreate__4BossFv = 0xebebb68;
beforeExecute__4BossFv = 0xebebd0c;
afterExecute__4BossFi = 0xebebddc;
onDelete__4BossFv = 0xebedc2c;
removeColliders__4BossFv = 0xebeddf0;
addColliders__4BossFv = 0xebede7c;
vf154__4BossFv = 0xebece40;
freezeActor__4BossFv = 0xebeceac;
vf1BC__4BossFv = 0xebecf64;
vf1C4__4BossFv = 0xebee2d0;
playerCollision__4BossFUiP8Collider = 0xebebfdc;
yoshiCollision__4BossFUiP8Collider = 0xebec2b4;
vf22C__4BossFv = 0xebedcc8;
hitJump__4BossFP8ColliderT1 = 0xebedcd0;
collidesSomething__4BossFP8ColliderT1 = 0xebec5d0;
hitEnemyDown__4BossFP8ColliderT1 = 0xebedcd8;
hitGroundPound__4BossFP8ColliderT1 = 0xebec3ac;
hitEnemyKame2__4BossFP8ColliderT1 = 0xebec5e0;
hitEnemyKameDown__4BossFP8ColliderT1 = 0xebec8e0;
vf27C__4BossFv = 0xebec6d4;
vf284__4BossFP8ColliderT1 = 0xebecbcc;
hitEx__4BossFv = 0xebeccb0;
vf2C4__4BossFv = 0xebedce0;
isGrounded__4BossFv = 0xebece00;
vf2F4__4BossFv = 0xebedd38;
beginState_JumpKill__4BossFv = 0xebedc9c;
executeState_JumpKill__4BossFv = 0xebedca0;
endState_JumpKill__4BossFv = 0xebedca4;
beginState_BossState1__4BossFv = 0xebebecc;
executeState_BossState1__4BossFv = 0xebebedc;
endState_BossState1__4BossFv = 0xebebeec;
beginState_BossState2__4BossFv = 0xebebefc;
executeState_BossState2__4BossFv = 0xebebf0c;
endState_BossState2__4BossFv = 0xebebf1c;
beginState_BossState3__4BossFv = 0xebebf2c;
executeState_BossState3__4BossFv = 0xebebf3c;
endState_BossState3__4BossFv = 0xebebf4c;
beginState_BossState4__4BossFv = 0xebebf5c;
executeState_BossState4__4BossFv = 0xebebf6c;
endState_BossState4__4BossFv = 0xebebf7c;
beginState_BossState5__4BossFv = 0xebebf8c;
executeState_BossState5__4BossFv = 0xebebf9c;
endState_BossState5__4BossFv = 0xebebfac;
vf55C__4BossFv = 0xebedca8;
vf564__4BossFv = 0xebedcb4;
vf56C__4BossFv = 0xebedcc0;
vf574__4BossFv = 0xebebfbc;
vf57C__4BossFv = 0xebedcc4;
vf584__4BossFv = 0xf6ba5e8;
vf58C__4BossFv = 0xebedd3c;
vf594__4BossFv = 0xebedd4c;
vf59C__4BossFv = 0xf6ba5e8;
vf5A4__4BossFv = 0xf6ba5e8;
vf5AC__4BossFv = 0xf6ba5e8;
vf5B4__4BossFv = 0xebedd90;
vf5BC__4BossFUi = 0xebedd98;
vf604__4BossFv = 0xebeddbc;
vf60C__4BossFv = 0xebeddc0;
vf614__4BossFv = 0xebeddc4;
vf61C__4BossFv = 0xebeddc8;
vf624__4BossFv = 0xf6ba5e8;
vf62C__4BossFv = 0xebeddd0;
vf634__4BossFP10StageActor = 0xebeddd8;
vf63C__4BossFP10StageActor = 0xebedde4;
vf644__4BossFv = 0xebed120;
vf64C__4BossFUi = 0xebed214;
vf654__4BossFv = 0xebedf28;
changeState_JumpKill__4BossFv = 0xebedf2c;
vf664__4BossFv = 0xebedf44;
changeState_State1__4BossFv = 0xebedf48;
vf674__4BossFv = 0xebedf60;
vf67C__4BossFv = 0xebedf70;
vf684__4BossFv = 0xf6ba5e8;
vf68C__4BossFv = 0xf6ba5e8;
vf694__4BossFv = 0xf6ba5e8;
vf69C__4BossFv = 0xf6ba5e8;
vf6A4__4BossFv = 0xebedf80;
changeState_State5__4BossFv = 0xebedf84;
vf6B4__4BossFv = 0xebedf9c;
changeState_State3__4BossFv = 0xebedfa0;
vf6C4__4BossFv = 0xf6ba5e8;
vf6CC__4BossFv = 0xf6ba5e8;
vf6D4__4BossFv = 0xebedfb8;
vf6DC__4BossFv = 0xebedfc0;
vf6E4__4BossFv = 0xebedfc4;
vf6EC__4BossFv = 0xebedfd4;
vf6F4__4BossFv = 0xebedfdc;
vf6FC__4BossFv = 0xebedfe4;
vf704__4BossFv = 0xebedfec;
vf70C__4BossFv = 0xf6ba5e8;
vf714__4BossFv = 0xf6ba5e8;
vf71C__4BossFv = 0xf6ba5e8;
vf724__4BossFv = 0xebedff4;
vf72C__4BossFv = 0xebedff8;
vf734__4BossFv = 0xebedffc;
vf73C__4BossFv = 0xf6ba5e8;
vf744__4BossFv = 0xebee000;
stomp__4BossFv = 0xebee004;
lastStomp__4BossFv = 0xebee01c;
vf75C__4BossFv = 0xf6ba5e8;
damageStar__4BossFv = 0xebee034;
vf76C__4BossFv = 0xf6ba5e8;
damageLast__4BossFv = 0xebee04c;
damageFire__4BossFv = 0xebee064;
damageFireLast__4BossFv = 0xebee0d8;
damageFire2__4BossFv = 0xebee130;
damageFireLast2__4BossFv = 0xebee1a4;
damageStarDef__4BossFv = 0xebee1fc;
damageLast2__4BossFv = 0xebee214;
vf7AC__4BossFv = 0xebee22c;
vf7B4__4BossFv = 0xf6ba5e8;
vf7BC__4BossFv = 0xf6ba5e8;
vf7C4__4BossFv = 0xebee230;
vf7CC__4BossFv = 0xebed3bc;
initBossCollider__4BossFv = 0xebed3f4;
initModels__4BossFv = 0xebee2b8;
vf7E4__4BossFv = 0xebee2bc;
vf7EC__4BossFv = 0xebee2c0;
vf7F4__4BossFv = 0xebee2c4;
vf7FC__4BossFv = 0xebee2c8;

__ct__16WalkingEnemyBaseFP14ActorBuildInfo = 0xeeab09c;
__vtbl__16WalkingEnemyBase = 0x105647bc;
__dt__16WalkingEnemyBase = 0xeead710;
beforeExecute__16WalkingEnemyBaseFv = 0xeeab18c;
onDelete__16WalkingEnemyBaseFv = 0xeeab218;
setPlayerId__16WalkingEnemyBaseFUc = 0xefab7e4;
getPhysics__16WalkingEnemyBaseFv = 0xefab810;
vfBC__16WalkingEnemyBaseFv = 0xeeab368;
move__16WalkingEnemyBaseFP4Vec2 = 0xefab818;
setYSpeed__16WalkingEnemyBaseFf = 0xefab82c;
getRect__16WalkingEnemyBaseFP4Rect = 0xefab844;
vf214__16WalkingEnemyBaseFP8ColliderT1 = 0xeeabc60;
vf274__16WalkingEnemyBaseFP8ColliderT1 = 0xeeac18c;
vf284__16WalkingEnemyBaseFP8ColliderT1 = 0xeeac130;
vf2B4__16WalkingEnemyBaseFPUcP8ColliderT2 = 0xeeac59c;
vf4F4__16WalkingEnemyBaseFv = 0xeeabd84;
vf4FC__16WalkingEnemyBaseFP8ColliderT1 = 0xeeabe7c;
vf504__16WalkingEnemyBaseFP8ColliderT1 = 0xeeabfec;
vf50C__16WalkingEnemyBaseFP8ColliderT1 = 0xeeac06c;
vf514__16WalkingEnemyBaseFv = 0xeead6fc;
vf52C__16WalkingEnemyBaseFv = 0xeeacd00;
vf534__16WalkingEnemyBaseFv = 0xeeacd8c;
vf53C__16WalkingEnemyBaseFv = 0xeeacf84;
vf544__16WalkingEnemyBaseFv = 0xeead700;
vf54C__16WalkingEnemyBaseFv = 0xeead704;
vf554__16WalkingEnemyBaseFv = 0xeead708;
vf55C__16WalkingEnemyBaseFv = 0xeead02c;
vf564__16WalkingEnemyBaseFv = 0xeead70c;
vf56C__16WalkingEnemyBaseFv = 0xeead07c;

__vtbl__13WindGenerator = 0x10658288;
__dt__13WindGeneratorFv = 0xf44efa0;
onCreate__13WindGeneratorFv = 0xf44ebc4;
onExecute__13WindGeneratorFv = 0xf44ecf0;

instance__11AreaRumbler = 0x106d3860;
rumbleScreen__11AreaRumblerFUcUiN32 = 0xf084bd8;

instance__11ItemSpawner = 0x106d5180;
getExtraPlayerCount__11ItemSpawnerFv = 0xf0ddea4;

instance__7CoinMgr = 0x106dd63c;
dropCoins__7CoinMgrFP4Vec3 = 0xf28db20;
spawnItemCoin__7CoinMgrFP4Vec3UiUc = 0xf28abb4;

spawnBabyEgg__8YoshiMgrSFP4Vec3UcUi = 0xf303bb0;

__vtbl__20BlockCoinRelatedBase = 0x10603c80;
checkDerivedRuntimeTypeInfo__20BlockCoinRelatedBaseFPv = 0xf2c8dc0;
__dt__20BlockCoinRelatedBaseFv = 0xf2c8f48;
vf18C__20BlockCoinRelatedBaseFv = 0xf2c8efc;
vf194__20BlockCoinRelatedBaseFv = 0xf2c8f00;
vf19C__20BlockCoinRelatedBaseFv = 0xf2c8f04;
vf1A4__20BlockCoinRelatedBaseFv = 0xf2c8f08;
spawnItemUp__20BlockCoinRelatedBaseFv = 0xf2c8f0c;
vf1B4__20BlockCoinRelatedBaseFv = 0xf2c8f10;
vf1BC__20BlockCoinRelatedBaseFv = 0xf2c8f14;
spawnItemDown__20BlockCoinRelatedBaseFv = 0xf2c8f18;
vf1CC__20BlockCoinRelatedBaseFv = 0xf2c8f1c;
vf1D4__20BlockCoinRelatedBaseFb = 0xf2c4868;
vf1DC__20BlockCoinRelatedBaseFv = 0xf2c8f20;
spawnCoinShower__20BlockCoinRelatedBaseFv = 0xf2c48e4;
vf1EC__20BlockCoinRelatedBaseFv = 0xf2c8f28;
beginState_BumpUp__20BlockCoinRelatedBaseFv = 0xf2c7cb4;
executeState_BumpUp__20BlockCoinRelatedBaseFv = 0xf2c7cf0;
endState_BumpUp__20BlockCoinRelatedBaseFv = 0xf2c8f2c;
beginState_BlockCoinRelatedState1__20BlockCoinRelatedBaseFv = 0xf2c7d94;
executeState_BlockCoinRelatedState1__20BlockCoinRelatedBaseFv = 0xf2c7da0;
endState_BlockCoinRelatedState1__20BlockCoinRelatedBaseFv = 0xf2c8f30;
beginState_BumpDown__20BlockCoinRelatedBaseFv = 0xf2c7db8;
executeState_BumpDown__20BlockCoinRelatedBaseFv = 0xf2c7dfc;
endState_BumpDown__20BlockCoinRelatedBaseFv = 0xf2c8f34;
beginState_BlockCoinRelatedState2__20BlockCoinRelatedBaseFv = 0xf2c7e9c;
executeState_BlockCoinRelatedState2__20BlockCoinRelatedBaseFv = 0xf2c7ea8;
endState_BlockCoinRelatedState2__20BlockCoinRelatedBaseFv = 0xf2c8f38;
beginState_BumpUp2__20BlockCoinRelatedBaseFv = 0xf2c7ed0;
executeState_BumpUp2__20BlockCoinRelatedBaseFv = 0xf2c7f58;
endState_BumpUp2__20BlockCoinRelatedBaseFv = 0xf2c8f3c;
beginState_BumpDown2__20BlockCoinRelatedBaseFv = 0xf2c812c;
executeState_BumpDown2__20BlockCoinRelatedBaseFv = 0xf2c8198;
endState_BumpDown2__20BlockCoinRelatedBaseFv = 0xf2c8f40;
beginState_BlockCoinRelatedState3__20BlockCoinRelatedBaseFv = 0xf2c828c;
executeState_BlockCoinRelatedState3__20BlockCoinRelatedBaseFv = 0xf2c8298;
endState_BlockCoinRelatedState3__20BlockCoinRelatedBaseFv = 0xf2c8f44;

spawnPortableSpring__20BlockCoinRelatedBaseFv = 0xf2c6430;
spawnVine__20BlockCoinRelatedBaseFv = 0xf2c62a8;
spawnYoshiEgg__20BlockCoinRelatedBaseFb = 0xf2c6ba4;
spawnPowerup__20BlockCoinRelatedBaseFP4Vec3UiT2b = 0xf2c6d1c;
spawnMultiPowerup__20BlockCoinRelatedBaseFP4Vec3UiT2b = 0xf2c6ff4;

__vtbl__13BlockCoinBase = 0x106097ac;
checkDerivedRuntimeTypeInfo__13BlockCoinBaseFPv = 0xf2e7a08;
__dt__13BlockCoinBaseFv = 0xf2e7ba4;
spawnItemUp__13BlockCoinBaseFv = 0xf2e6610;
spawnItemDown__13BlockCoinBaseFv = 0xf2e6634;
vf1DC__13BlockCoinBaseFv = 0xf2e6644;
vf1EC__20BlockCoinRelatedBaseFv = 0xf2e7980;
vf29C__13BlockCoinBaseFv = 0xf2e7984;
setTileFlag__13BlockCoinBaseFv = 0xf2e65bc;
vf2AC__13BlockCoinBaseFv = 0xf2e7988;
vf2B4__13BlockCoinBaseFv = 0xf2e7990;
vf2BC__13BlockCoinBaseFv = 0xf2e7994;
vf2C4__13BlockCoinBaseFv = 0xf2e7998;
vf2CC__13BlockCoinBaseFv = 0xf2e6654;

StateID_Wait__9BlockBase = 0x10720ae0;
StateID_Used__9BlockBase = 0x10720b04;

otherCollisionCallback1__9BlockBaseSFP17OtherColliderBaseP7PhysicsUi = 0xf2c50f0;
otherCollisionCallback2__9BlockBaseSFP17OtherColliderBaseP7PhysicsUi = 0xf2c595c;
otherCollisionCallback3__9BlockBaseSFP17OtherColliderBaseP7PhysicsUi = 0xf2c60c0;

init__9BlockBaseFbT1 = 0xf25f6c8;

__vtbl__9BlockBase = 0x105e8b60;
__ct__9BlockBaseFP14ActorBuildInfo = 0xf25e614;
checkDerivedRuntimeTypeInfo__9BlockBaseFPv = 0xf260460;
__dt__9BlockBaseFv = 0xf26062c;
onExecute__9BlockBaseFv = 0xf25e6c4;
onDraw__9BlockBaseFv = 0xf25e77c;
vf19C__9BlockBaseFv = 0xf25f400;
spawnItemUp__9BlockBaseFv = 0xf25ebc0;
spawnItemDown__9BlockBaseFv = 0xf25ebc4;
vf1CC__9BlockBaseFv = 0xf25ec04;
vf2C4__9BlockBaseFv = 0xf25f410;
vf2D4__9BlockBaseFv = 0xf25ec1c;
vf2DC__9BlockBaseFv = 0xf260404;
getContent__9BlockBaseFv = 0xf260408;
vf2EC__9BlockBaseFv = 0xf25efe4;
vf2F4__9BlockBaseFP4Vec3 = 0xf260418;
execute__9BlockBaseFv = 0xf25f078;
vf304__9BlockBaseFv = 0xf25f25c;
vf30C__9BlockBaseFv = 0xf25f33c;
vf314__9BlockBaseFv = 0xf260434;
vf31C__9BlockBaseFv = 0xf260438;
vf324__9BlockBaseFv = 0xf26043c;
vf32C__9BlockBaseFv = 0xf260440;
beginState_Wait__9BlockBaseFv = 0xf26061c;
executeState_Wait__9BlockBaseFv = 0xf260068;
endState_Wait__9BlockBaseFv = 0xf260620;
beginState_Used__9BlockBaseFv = 0xf260624;
executeState_Used__9BlockBaseFv = 0xf260074;
endState_Used__9BlockBaseFv = 0xf260628;

StateID_Main__8CoinBase = 0x10722f70;

__vtbl__8CoinBase = 0x105f3cf0;
__ct__8CoinBaseFP14ActorBuildInfo = 0xf27f78c;
init__8CoinBaseFv = 0xf27ff4c;
initCollider__8CoinBaseFUi = 0xf280e24;
addCollider__8CoinBaseFv = 0xf2e6760;
checkDerivedRuntimeTypeInfo__8CoinBaseFPv = 0xf281c10;
__dt__8CoinBaseFv = 0xf281de8;
onExecute__8CoinBaseFv = 0xf27f9d0;
onDraw__8CoinBaseFv = 0xf27fb9c;
splashWater__8CoinBaseFP4Vec3 = 0xf27fdc4;
splashLava__8CoinBaseFP4Vec3 = 0xf27fe20;
splashLavaWave__8CoinBaseFP4Vec3 = 0xf27fe84;
splashPoison__8CoinBaseFP4Vec3 = 0xf27fee8;
vf11C__8CoinBaseFv = 0xf27fd18;
vf124__8CoinBaseFf = 0xf27fd30;
vf12C__8CoinBaseFv = 0xf281c00;
vf144__8CoinBaseFb = 0xf27fc58;
vf2AC__8CoinBaseFv = 0xf27fc40;
vf2D4__8CoinBaseFv = 0xf281c08;
initYoshiEatData__8CoinBaseFv = 0xf27fd40;
vf2E4__8CoinBaseFv = 0xf280f7c;
vf2EC__8CoinBaseFv = 0xf281084;
vf2F4__8CoinBaseFv = 0xf281dcc;
vf2FC__8CoinBaseFv = 0xf2811f8;
vf304__8CoinBaseFv = 0xf281300;
vf30C__8CoinBaseFv = 0xf281dd0;

getTilt__10ControllerFPUif = 0xf0cecac;

instance__8InputMgr = 0x106d4ff8;

__vtbl__10PlayerBase = 0x10669084;
playSound__10PlayerBaseFPcb = 0xf4cb9a4;
groundPound__10PlayerBaseFv = 0xf4ca38c;
playLandSound__10PlayerBaseFv = 0xf4cbe64;
doLandEffects__10PlayerBaseFv = 0xf4c46d8;
spawnGroundPoundBlurEffect__10PlayerBaseFv = 0xf4c4128;
usedByGoalPole__10PlayerBaseFv = 0xf4c2b30;

StateID_DefaultState__5Yoshi = 0x1072d9e0;

onCreate__5YoshiFv = 0xf51e1d4;

getRidingPlayer__5YoshiFv = 0xf52b3c4;
changeState__5YoshiFP19State__tm__7_5Yoshi = 0xf52226c;
spawnBall__5YoshiFb = 0xf5227c8;
getActorInMouth__5YoshiFv = 0xf52255c;
removeActorFromMouth__5YoshiFv = 0xf522c04;

__vtbl__6Player = 0x1066e350;

instance__15BasicSoundActor = 0x106c85d0;
playSound__15BasicSoundActorFPCcP4Vec2Ui = 0xf57ed48;

instance__18AmbientSoundPlayer = 0x106c85d4;
__vtbl__18AmbientSoundPlayer = 0x105072f0;

instance__11SoundSystem = 0x106e9e84;
getSoundArchive__11SoundSystemFv = 0xf573ba8;
playSound__11SoundSystem2FPCcUi = 0xf5754c0;

instance__12EnemyCounter = 0x106c52d0;
killEnemiesGoal__12EnemyCounterFv = 0xebcbaf4;

/*** HACK ADDRESSES ***/
returnTileGod = 0xf2e5d0c;
returnInitRaftState = 0xf2b130c;
continueRenderTileAnim = 0xf2549b4;

/*** UNKNOWN PURPOSE ADDRESSES ***/

/*** ITEM(BASE) ***/
ModelUpdateThing__8ItemBaseFv = 0xf0d8a4c;
setupActor__8ItemBaseFv = 0xf0d7f90;
setupState__8ItemBaseFv = 0xf0d8470;

sub_24FE8F8__8ItemBaseFv = 0xf0d8f94;
sub_24FDD10__8ItemBaseFv = 0xf0d83ac;

}
