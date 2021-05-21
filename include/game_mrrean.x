
SECTIONS {

/*** GHS C++ FUNCTIONS ***/
__nw__FUi = 0xf310f08;
__nwa__FUi = 0xf310fa4;
__dl__FPv = 0xf3110bc;
__nw__FUiPQ2_4sead4Heapi = 0xf3111cc;
__vec_new = 0xf468c3c;
__vec_delete = 0xf468d7c;
__record_needed_destruction = 0xf468e18;
__pure_virtual_called = 0xf468e40;
__memzero = 0xf468e48;
__deleted_virtual_called = 0xf468ed4;
__gh_long_long_printf = 0xf469070;
__gh_float_printf = 0xf469494;
__ghs_strlen = 0xf46be14;
sinf = 0xf46c638;
cosf = 0xf46ce20;
atan2f = 0xf46cf68;


/*** CAFE SDK STATIC ***/
ASM_VECDistance = 0xf468004;


/*** CAFE SDK IMPORTS ***/
OSBlockSet = 0xf473210;


/*** SEAD LIBRARY ***/
__vtbl__Q2_4sead6String = 0x105fa808;

__vtbl__Q2_4sead9IDisposer = 0x10697470;
__dt__Q2_4sead9IDisposerFv = 0xf329d14;

instance__Q2_4sead12GlobalRandom = 0x106f7ebc;
getU32__Q2_4sead6RandomFv = 0xf333164;

__ct__Q2_4sead15GraphicsContextFv = 0xf32754c;
apply__Q2_4sead15GraphicsContextFv = 0xf327640;

__ct__Q2_4sead18GraphicsContextMRTFv = 0xf327800;
apply__Q2_4sead18GraphicsContextMRTFv = 0xf327920;

getDeviceProjectionMatrix__Q2_4sead10ProjectionFv = 0xf32542c;

__ct__Q2_4sead15OrthoProjectionFfN51 = 0xf325f3c;
__dt__Q2_4sead15OrthoProjectionFv = 0xf326154;

bind__Q2_4sead11FrameBufferFv = 0xf325280;

decomp__Q2_4sead15SZSDecompressorSFPvUiPCvT2 = 0xf335034;


/*** AGL LIBRARY ***/
searchShaderProgramIndex__Q2_3agl20ShaderProgramArchiveFPQ2_4sead6String = 0xf343f88;

createUniformBlock__Q2_3agl13ShaderProgramFiPQ2_4sead4Heap = 0xf341100;
setUniformBlockName__Q2_3agl13ShaderProgramFiPQ2_4sead6String = 0xf3412e8;
createSamplerBlock__Q2_3agl13ShaderProgramFiPQ2_4sead4Heap = 0xf341360;
setSamplerBlockName__Q2_3agl13ShaderProgramFiPQ2_4sead6String = 0xf341548;

__ct__Q2_3agl11TextureDataFv = 0xf344380;
invalidateGPUCache__Q2_3agl11TextureDataFv = 0xf344444;
initialize__Q2_3agl11TextureDataFQ2_3agl11TextureTypeQ2_3agl13TextureFormatUiN33Q2_3agl15MultiSampleType = 0xf3446f4;

applyTextureData___Q2_3agl14TextureSamplerFPQ2_3agl11TextureData = 0xf345370;

__ct__Q2_3agl17RenderTargetColorFv = 0xf33e9bc;
applyTextureData__Q2_3agl17RenderTargetColorFPQ2_3agl11TextureData = 0xedd6240;
invalidateGPUCache__Q2_3agl17RenderTargetColorFv = 0xf33ea68;

invalidateGPUCache__Q2_3agl17RenderTargetDepthFv = 0xf33ec00;

__ct__Q2_3agl12RenderBufferFP4Vec2fN32 = 0xf33e4bc;
__dt__Q2_3agl12RenderBufferFv = 0xf33dd1c;
clear__Q2_3agl12RenderBufferFUiT1PQ2_4sead7Color4fT1f = 0xf33e024;


/*** NW LIBRARY ***/
GetItemLabel__Q3_2nw3snd12SoundArchiveFUi = 0xf44526c;

GetString__Q5_2nw3snd8internal16SoundArchiveFile15StringBlockBodyFUi = 0xf445ef0;


/*** GAME ADDRESSES ***/
fileCounts = 0x105045f8;
fileLists = 0x106d289c;
directionToRotationList = 0x10710d20;
spriteToActorList = 0x106fccd4;
tileGodList = 0x1060c6f0;

calcMatrix__FPA3_A4_fP5Vec3iP4Vec3 = 0xe93c398;
mapPosToScreen__FP4Vec2T1 = 0xe929368;
spawnEffect__F7EffectsP4Vec3P5Vec3iT2 = 0xebab250;
moveValueTo__FPUiUiT2 = 0xf30075c;
moveFloatTo__FPffT2 = 0xe927984;

__ct__7ProfileFPFP14ActorBuildInfo_P5Actor6ActorsPCcPC9ActorInfoUi = 0xe919554;
Get__7ProfileSF6Actors = 0xe919774;
GetProfile = 0xe919774;

instance__9LevelInfo = 0x106e0f6c;

getLocationById__9LevelAreaFP4RectUc = 0xefad6d4;
getZoneById__9LevelAreaFUcP4Rect = 0xefad3b4;

instance__5Level = 0x106eacb8;
getArea__5LevelFUc = 0xefad990;

instance__10LevelTimer = 0x106e0c74;
addSeconds__10LevelTimerFUi = 0xedc1690;

instance__11LevelCamera = 0x106f7aa8;

instance__8EventMgr = 0x106eacdc;

instance__9PlayerMgr = 0x106f6754;

__ct__13EffectHandlerFv = 0xebaba38;
update__13EffectHandlerF7EffectsPA3_A4_fb = 0xebab8bc;
update__13EffectHandlerF7EffectsP4Vec3P5Vec3iT2 = 0xebab6fc;

init__14TerrainEffectsFP4Vec3fbT311TerrainTypePQ2_4sead4Heap = 0xf1ca99c;
setWaveValues__14TerrainEffectsFUiN51 = 0xf1cabbc;
checkMarioWaveHit__14TerrainEffectsFv = 0xf1cc2bc;
updateWaveCollisions__14TerrainEffectsFv = 0xf1cc424;

onExecute__10EnvTerrainFv = 0xf004564;
setTop__10EnvTerrainFf = 0xf004940;

instance__7TileMgr = 0x106ea804;
getTilePointer__7TileMgrSFUsT1UcPUi = 0xef986b4;

instance__17FrameBufferKeeper = 0x106e2208;
__CPR93__switchBuffer__17FrameBufferKeeperFQ2_J14J10BufferTypePQ3_3agl3lyr10RenderInfob = 0xedde48c;

__ct__10BgMaskListFv = 0xefadac0;
__dt__10BgMaskListFv = 0xefadb58;
init__10BgMaskListFPQ2_4sead4Heap = 0xefadcdc;
add__10BgMaskListFP8MaskInfoN31PQ2_3agl11TextureDataUi = 0xefadef4;
draw__10BgMaskListFPvT1 = 0xefae264;

instance__10BgRenderer = 0x106eac58;
initShaders__10BgRendererSFPQ2_3agl20ShaderProgramArchivePQ2_4sead4Heap = 0xefa2cb0;
allocTexture__10BgRendererSFPQ2_4sead6StringQ4_3agl3utl23DynamicTextureAllocator12AllocateType = 0xefa3b40;
freeTexture__10BgRendererSFPPQ2_3agl11TextureData = 0xefa4ed4;
__vtbl__10BgRenderer = 0x105eace0;
__ct__10BgRendererFv = 0xefa26e8;
__dt__10BgRendererFv = 0xefa6a40;
init__10BgRendererFPQ2_4sead4Heap = 0xefa2ea4;
drawLayerMasks__10BgRendererFPQ3_3agl3lyr10RenderInfo = 0xefa5848;
drawTilesWithMasks__10BgRendererFPQ3_3agl3lyr10RenderInfo = 0xefa58e0;
renderTileLayer__10BgRendererFPQ2_4sead8ViewportPQ2_4sead15OrthoProjectionUi = 0xefa4a1c;
initSpotlightMaskFrameBuffer__10BgRendererFPQ3_3agl3lyr10RenderInfo = 0xefa5764;

loadTexture__11MaskTexDataSFQ2_11MaskTexture5ShapePQ2_3agl11TextureData = 0xf128ce0;

__ct__9LightMaskFv = 0xf129364;
init__9LightMaskFPQ2_4sead4HeapQ2_11MaskTexture5Shape = 0xf1293e8;
update__9LightMaskFv = 0xf129494;
draw__9LightMaskFv = 0xf129790;

__vtbl__9LayerMask = 0x1063ca5c;
init__9LayerMaskFPQ2_4sead4HeapQ2_11MaskTexture5Shape = 0xf129b8c;
update__9LayerMaskFv = 0xf129c2c;
draw__9LayerMaskFv = 0xf129ce4;

loadTilesets__8BgTexMgrFUc = 0xefa70d8;
loadTexture__8BgTexMgrSFPQ2_3agl11TextureDataPQ2_4sead6StringT2 = 0xefa7068;
update__8BgTexMgrFv = 0xefa7d50;
renderAnimation__8BgTexMgrFUiN21i = 0xefa7e70;

instance__13TilesetLoader = 0x106eac30;
getTilesetName__13TilesetLoaderFUcT1 = 0xefa1a54;

instance__6ResMgr = 0x106f7be4;
loadArchive__6ResMgrFPCQ2_4sead6StringT1PQ2_4sead4Heapb = 0xf2f3114;
getArchive__6ResMgrFPCQ2_4sead6String = 0xf2f390c;

instance__9ResLoader = 0x106e23d0;
getResArchive__9ResLoaderFQ2_4sead6String = 0xedf62bc;

getModel__10ResArchiveFQ2_4sead6StringUiN42bPQ2_4sead4Heap = 0xedee610;

__vtbl__8ModelObj = 0x105bf138;

__ct__5ModelFP8ModelObjUiN42 = 0xedd4968;
init__5ModelFP10ResArchivePQ2_4sead33PtrArrayImpl__tm__13_10ResArchivePQ2_4sead4Heap = 0xedd4b70;
update__5ModelFv = 0xedd5054;

__ct__6Model2FP8ModelObjUiN42 = 0xeddfdc0;
init__6Model2FP10ResArchivePQ2_4sead33PtrArrayImpl__tm__13_10ResArchivePQ2_4sead4Heap = 0xeddfe48;
update__6Model2Fv = 0xeddfe4c;

setRepeat__9AnimationFb = 0xeddf0a4;

play__12SkeletalAnimFP10ResArchivePQ2_4sead6String = 0xedfdd50;

__ct__14CharacterModelFPQ2_4sead6StringT1 = 0xf23cd5c;

instance__6Drawer = 0x106e2408;
drawModel__6DrawerFP5Model = 0xedfaf0c;
drawTile__6DrawerFUiP4Vec3PUiT2 = 0xedfaf9c;

init__13PlatformModelFv = 0xf0d17d8;
draw__13PlatformModelFv = 0xf0d1bc4;
update__13PlatformModelFP4Vec3f = 0xf0d1af0;

__ct__9CollThingFv = 0xeaa1c9c;

__vtbl__17OtherColliderBase = 0x10544728;

setRect__14CustomColliderFP4Vec2T1 = 0xeaad42c;

__vtbl__14CustomCollider = 0x10544888;
__ct__14CustomColliderFUiP4Vec2P9CollThingT3 = 0xeaa7ad4;
updateMovement__14CustomColliderFv = 0xeaa88ec;

init__13SolidColliderFP10StageActorP18SolidCollisionInfo = 0xeaad58c;
__vtbl__13SolidCollider = 0x10600c58;
__dt__13SolidColliderFv = 0xefff094;

init__18SolidOnTopColliderFP10StageActorP23SolidOnTopCollisionInfoUiT3 = 0xeaa2548;
__vtbl__18SolidOnTopCollider = 0x10544438;
__ct__18SolidOnTopColliderFv = 0xeaa1f08;
__dt__18SolidOnTopColliderFv = 0xeaa20e8;
updateMovement__18SolidOnTopColliderFv = 0xeaa2fdc;

instance__17OtherCollisionMgr = 0x106d89e0;
add__17OtherCollisionMgrFP17OtherColliderBase = 0xea9286c;

init__8ColliderFP10StageActorPC13CollisionInfoUi = 0xea9b0ec;

instance__12CollisionMgr = 0x106d8c58;
addCollider__12CollisionMgrFP8Collider = 0xea9e1f8;

init__7PhysicsFP10StageActorP4Vec3N22 = 0xea8b13c;
processCollisions__7PhysicsFv = 0xea8db24;

instance__17CourseDarknessMgr = 0x106ef524;

CurrentStateID = 0x106f9e04;
executeState__10StateClassFv = 0xf2e4550;

__vtbl__9StateBase = 0x10541ff8;
__dt__9StateBaseFv = 0xea8632c;
getStateId__9StateBaseFv = 0xea85f70;

freezeActor__11IceActorMgrFP7IceInfoUi = 0xec7d80c;

instance__8ActorMgr = 0x106d2748;
createActor__8ActorMgrFP14ActorBuildInfoUi = 0xe909a58;
findActorByType__8ActorMgrF6ActorsPP5Actor = 0xe909b6c;

findActorById__9ActorListFPUi = 0xe90a5c8;

__ct__15MovementHandlerFv = 0xf15d308;
getMaskForMovementType__15MovementHandlerF12MovementType = 0xf15da44;
linkToMovementController__15MovementHandlerFP4Vec3UiUc = 0xf15edbc;
execute__15MovementHandlerFv = 0xf15ef8c;

removeChild__5ActorFP5Actor = 0xe902c8c;
getProfileId__5ActorFv = 0xe902c80;

__vtbl__5Actor = 0x105028c0;
__ct__5ActorFP14ActorBuildInfo = 0xe902ce0;
checkDerivedRuntimeTypeInfo__5ActorFPv = 0xe902f40;
vf14__5ActorFv = 0xf468ed4;
__dt__5ActorFv = 0xe902e68;
beforeCreate__5ActorFv = 0xe902f7c;
onCreate__5ActorFv = 0xe902f84;
afterCreate__5ActorFi = 0xe902f00;
beforeExecute__5ActorFv = 0xe902f04;
onExecute__5ActorFv = 0xe902f8c;
afterExecute__5ActorFi = 0xe902f34;
finalExecute__5ActorFv = 0xe902f94;
beforeDraw__5ActorFv = 0xe902f98;
onDraw__5ActorFv = 0xe902fa0;
afterDraw__5ActorFi = 0xe902f38;
beforeDelete__5ActorFv = 0xe902fa8;
onDelete__5ActorFv = 0xe902fb0;
afterDelete__5ActorFi = 0xe902f3c;

getDirectionToPlayer__10StageActorFP4Vec3 = 0xe9005ec;

__vtbl__10StageActor = 0x10502468;
__ct__10StageActorFP14ActorBuildInfo = 0xe900ac8;
checkDerivedRuntimeTypeInfo__10StageActorFPv = 0xe902a38;
__dt__10StageActorFv = 0xe900f18;
afterCreate__10StageActorFi = 0xe900fb8;
beforeExecute__10StageActorFv = 0xe900fe8;
afterExecute__10StageActorFi = 0xe9010bc;
beforeDraw__10StageActorFv = 0xe9011a0;
setPlayerId__10StageActorFUc = 0xe902ab0;
removeColliders__10StageActorFv = 0xe9002cc;
addColliders__10StageActorFv = 0xe900328;
getPhysics__10StageActorFv = 0xe902ab8;
vfAC__10StageActorFv = 0xe902ac0;
vfB4__10StageActorFv = 0xe902ac4;
vfBC__10StageActorFv = 0xe902acc;
vfC4__10StageActorFv = 0xe902ad0;
vfCC__10StageActorFv = 0xe902ad4;
killAtGoal__10StageActorFv = 0xe902ad8;
splashWater__10StageActorF4Vec3 = 0xe902adc;
splashLava__10StageActorF4Vec3 = 0xe902ae0;
splashLavaWave__10StageActorF4Vec3 = 0xe900960;
splashPoison__10StageActorF4Vec3 = 0xe902ae4;
isOffScreen__10StageActorFv = 0xe901254;
damageFromUnder__10StageActorFv = 0xe902ae8;

applyGravity__12PhysicsActorFv = 0xe9039ac;

__vtbl__12PhysicsActor = 0x10502a4c;
checkDerivedRuntimeTypeInfo__12PhysicsActorFPv = 0xe903f34;
__dt__12PhysicsActorFv = 0xe9040b0;
afterCreate__12PhysicsActorFi = 0xe90354c;
beforeExecute__12PhysicsActorFv = 0xe9035fc;
afterExecute__12PhysicsActorFi = 0xe9036d8;
onDelete__12PhysicsActorFv = 0xe903724;
setPlayerId__12PhysicsActorFUc = 0xe903f10;
getPhysics__12PhysicsActorFv = 0xe904010;
vfAC__12PhysicsActorFv = 0xe903f18;
vfB4__12PhysicsActorFv = 0xe903f1c;
vfBC__12PhysicsActorFv = 0xe903f20;
vfC4__12PhysicsActorFv = 0xe903f24;
vfCC__12PhysicsActorFv = 0xe903f28;
damageFromUnder__12PhysicsActorFv = 0xe903f2c;
vf10C__12PhysicsActorFUc = 0xe903ff0;
vf114__12PhysicsActorFv = 0xf468ed4;
vf11C__12PhysicsActorFv = 0xe903ff8;
vf124__12PhysicsActorFv = 0xe903ffc;
vf12C__12PhysicsActorFv = 0xe904000;
vf134__12PhysicsActorFv = 0xf468ed4;
vf13C__12PhysicsActorFv = 0xe904008;
vf144__12PhysicsActorFv = 0xe90375c;
vf14C__12PhysicsActorFv = 0xe903760;
vf154__12PhysicsActorFv = 0xe904018;
move__12PhysicsActorFP4Vec2 = 0xe904020;
setYSpeed__12PhysicsActorFf = 0xe904034;
vf16C__12PhysicsActorFv = 0xe90403c;
vf174__12PhysicsActorFv = 0xe904044;
getRect__12PhysicsActorFP4Rect = 0xe90404c;

__vtbl__10StateActor = 0x10503248;
__ct__10StateActorFP14ActorBuildInfo = 0xe90aa8c;
checkDerivedRuntimeTypeInfo__10StateActorFPv = 0xe90af94;
__dt__10StateActorFv = 0xe90b098;
doStateChange__10StateActorFP9StateBase = 0xe90b090;

__vtbl__11StateActor2 = 0x105030c8;
setPlayerId__11StateActor2FUc = 0xe90aba8;
getPhysics__11StateActor2Fv = 0xe90abe4;
vfAC__11StateActor2Fv = 0xe90abb0;
vfB4__11StateActor2Fv = 0xe90abb4;
vfBC__11StateActor2Fv = 0xe90abbc;
vfC4__11StateActor2Fv = 0xe90abc0;
vfCC__11StateActor2Fv = 0xe90abc4;
damageFromUnder__11StateActor2Fv = 0xe90abc8;
vf10C__11StateActor2FUc = 0xe90abcc;
vf11C__11StateActor2Fv = 0xe90abd4;
vf124__11StateActor2Fv = 0xe90abd8;
vf12C__11StateActor2Fv = 0xe90abdc;
vf154__11StateActor2Fv = 0xe90abec;
move__11StateActor2FP4Vec2 = 0xe90abf4;
setYSpeed__11StateActor2Ff = 0xe90ac08;
vf16C__11StateActor2Fv = 0xe90ac10;
vf174__11StateActor2Fv = 0xe90ac18;
getRect__11StateActor2FP4Rect = 0xe90ac20;

actorInfo__12SpinningStar = 0x1063660c;
__vtbl__12SpinningStar = 0x10636704;
__ct__12SpinningStarFP14ActorBuildInfo = 0xf108d20;
checkDerivedRuntimeTypeInfo__12SpinningStarFPv = 0xf10a694;
__dt__12SpinningStarFv = 0xf10a834;
onCreate__12SpinningStarFv = 0xf109378;
onExecute__12SpinningStarFv = 0xf1097b4;
onDraw__12SpinningStarFv = 0xf10986c;

StateID_JumpKill__5Enemy = 0x10710ef8;

collisionCallback__5EnemySFP8ColliderT1 = 0xec28e20;

spinJumpKill__5EnemyFP6Player = 0xec2ce68;
killWithPlayer__5EnemyFP6PlayerP4Vec2P19State__tm__7_5Enemy = 0xec2dc04;
killWithYoshi__5EnemyFP5Yoshi = 0xec2d4ec;
processHit__5EnemyFP8ColliderT1 = 0xec29d58;
updatePosition__5EnemyFv = 0xe903ae4;

__vtbl__5Enemy = 0x1057429c;
__ct__5EnemyFP14ActorBuildInfo = 0xec28664;
checkDerivedRuntimeTypeInfo__5EnemyFPv = 0xec2a8dc;
__dt__5EnemyFv = 0xec2aa38;
beforeExecute__5EnemyFv = 0xec28814;
setPlayerId__5EnemyFUc = 0xec2a80c;
getPhysics__5EnemyFv = 0xec2a844;
vfAC__5EnemyFv = 0xec2a814;
vfB4__5EnemyFv = 0xec2a818;
vfBC__5EnemyFv = 0xec2a820;
vfC4__5EnemyFv = 0xec2a824;
vfCC__5EnemyFv = 0xec2a828;
damageFromUnder__5EnemyFv = 0xec28ae4;
vf10C__5EnemyFUc = 0xec2a82c;
vf11C__5EnemyFv = 0xec2a834;
vf124__5EnemyFv = 0xec2a838;
vf12C__5EnemyFv = 0xec2a83c;
vf14C__5EnemyFv = 0xec2de58;
vf154__5EnemyFv = 0xec2e374;
move__5EnemyFP4Vec2 = 0xec2a84c;
setYSpeed__5EnemyFf = 0xec2a860;
vf16C__5EnemyFv = 0xec2a868;
vf174__5EnemyFv = 0xec2a870;
getRect__5EnemyFP4Rect = 0xec2a878;
doStateChange__5EnemyFP9StateBase = 0xec305d4;
vf18C__5EnemyFv = 0xec2aa18;
playerCollision8A4__5EnemyFUiP8Collider = 0xec28d54;
vf19C__5EnemyFUc = 0xec292dc;
freezeActor__5EnemyFv = 0xec306c8;
vf1AC__5EnemyFv = 0xec3128c;
vf1B4__5EnemyFv = 0xec21290;
vf1BC__5EnemyFv = 0xec30738;
vf1C4__5EnemyFv = 0xec2aa28;
vf1CC__5EnemyFv = 0xec2aa2c;
vf1D4__5EnemyFUiPv = 0xec293c8;
prePlayerCollision__5EnemyFP8ColliderT1 = 0xec29420;
vf1E4__5EnemyFPUcP8ColliderT2 = 0xec296f0;
yoshiCollisionRelated__5EnemyFP8ColliderT1 = 0xec29748;
preYoshiCollision__5EnemyFP8ColliderT1 = 0xec2974c;
vf1FC__5EnemyFP8ColliderT1 = 0xec298b8;
actorCollision__5EnemyFP8ColliderT1 = 0xec299d0;
vf20C__5EnemyFv = 0xec29bc0;
playerCollision__5EnemyFP8ColliderT1 = 0xec29bc4;
yoshiCollision__5EnemyFP8ColliderT1 = 0xec29bd4;
vf224__5EnemyFP8ColliderT1 = 0xec29bd8;
vf22C__5EnemyFP8ColliderT1 = 0xec2d054;
hitJump__5EnemyFP8ColliderT1 = 0xec2d0f0;
collidesSomething__5EnemyFP8ColliderT1 = 0xec2d1e4;
hitEnemyDown__5EnemyFP8ColliderT1 = 0xec2d2b4;
hitGroundPound__5EnemyFP8ColliderT1 = 0xec2d410;
hitYoshi__5EnemyFP8ColliderT1 = 0xec2d584;
hitEnemyKame2__5EnemyFP8ColliderT1 = 0xec2d65c;
hitEnemyKame3__5EnemyFP8ColliderT1 = 0xec2d66c;
callsHitJump__5EnemyFP8ColliderT1 = 0xec2d73c;
hitEnemyKameDown__5EnemyFP8ColliderT1 = 0xec2d74c;
fireballCollision__5EnemyFP8ColliderT1 = 0xec2d8dc;
vf284__5EnemyFv = 0xec2d974;
hitNormal__5EnemyFP8ColliderT1 = 0xec2d9f4;
hitEnemyKame4__5EnemyFP8ColliderT1 = 0xec2db08;
vf29C__5EnemyFv = 0xec2dbd4;
goldYoshiHit__5EnemyFP8ColliderT1 = 0xec2dbdc;
calls_vf2CC_2__5EnemyFv = 0xec2dbe4;
vf2B4__5EnemyFPUc = 0xec2dbf4;
hitEx__5EnemyFv = 0xec2dcc0;
vf2C4__5EnemyFv = 0xec2df18;
hitEnemyKame5__5EnemyFP8ColliderT1 = 0xec2e218;
isGrounded__5EnemyFv = 0xec2e4bc;
playDownSound__5EnemyFv = 0xec2e4c8;
playDownSoundHpdp__5EnemyFv = 0xec2e528;
vf2EC__5EnemyFUi = 0xec2a074;
vf2F4__5EnemyFv = 0xec2a178;
vf2FC__5EnemyFUi = 0xec2a17c;
calls_vf2F4__5EnemyFv = 0xec2a180;
vf30C__5EnemyFUi = 0xec2a190;
playFumuSound__5EnemyFv = 0xec2a264;
playerHit__5EnemyFP10PlayerBase = 0xec2a2e8;
playDownSpinSound__5EnemyFv = 0xec2a38c;
playMameStepSound__5EnemyFv = 0xec2a410;
vf334__5EnemyFv = 0xec2a41c;
playYoshiFumuSound__5EnemyFv = 0xec2a420;
spawnHipDropHitEffect__5EnemyFv = 0xec2a4a4;
increaseYSpeed__5EnemyFv = 0xec2a4b4;
positionRelated__5EnemyFv = 0xec2a4cc;
vf35C__5EnemyFPv = 0xec2a534;
vf364__5EnemyFPv = 0xec2a5e8;
vf36C__5EnemyFPv = 0xec2a69c;
vf374__5EnemyFv = 0xec2aa34;
beginState_JumpKill__5EnemyFv = 0xec2e6e8;
executeState_JumpKill__5EnemyFv = 0xec2e7b8;
endState_JumpKill__5EnemyFv = 0xec2f0a0;
beginState_FireballKill__5EnemyFv = 0xec2e80c;
executeState_FireballKill__5EnemyFv = 0xec2e810;
endState_FireballKill__5EnemyFv = 0xec2f0a4;
beginState_YoshiStamp__5EnemyFv = 0xec2e8fc;
executeState_YoshiStamp__5EnemyFv = 0xec2e96c;
endState_YoshiStamp__5EnemyFv = 0xec2f0a8;
beginState_EnemyState11__5EnemyFv = 0xec2e978;
executeState_EnemyState11__5EnemyFv = 0xec2e988;
endState_EnemyState11__5EnemyFv = 0xec2f0ac;
beginState_EnemyState12__5EnemyFv = 0xec2e994;
executeState_EnemyState12__5EnemyFv = 0xec2e998;
endState_EnemyState12__5EnemyFv = 0xec2f0b0;
beginState_EnemyState13__5EnemyFv = 0xec2e9a4;
executeState_EnemyState13__5EnemyFv = 0xec2f0b4;
endState_EnemyState13__5EnemyFv = 0xec2f0b8;
beginState_ChallengeRelated__5EnemyFv = 0xec2e9b0;
executeState_ChallengeRelated__5EnemyFv = 0xec2f0bc;
endState_ChallengeRelated__5EnemyFv = 0xec2f0c0;
beginState_EnemyState2__5EnemyFv = 0xec307b4;
executeState_EnemyState2__5EnemyFv = 0xec307bc;
endState_EnemyState2__5EnemyFv = 0xec31294;
beginState_EnemyState3__5EnemyFv = 0xec31298;
executeState_EnemyState3__5EnemyFv = 0xec3129c;
endState_EnemyState3__5EnemyFv = 0xec312a0;
beginState_EnemyState4__5EnemyFv = 0xec312a4;
executeState_EnemyState4__5EnemyFv = 0xec312a8;
endState_EnemyState4__5EnemyFv = 0xec312ac;
beginState_EnemyState5__5EnemyFv = 0xec308b8;
executeState_EnemyState5__5EnemyFv = 0xec308c0;
endState_EnemyState5__5EnemyFv = 0xec312b0;
beginState_EnemyState6__5EnemyFv = 0xec312b4;
executeState_EnemyState6__5EnemyFv = 0xec312b8;
endState_EnemyState6__5EnemyFv = 0xec312bc;
beginState_EnemyState7__5EnemyFv = 0xec312c0;
executeState_EnemyState7__5EnemyFv = 0xec312c4;
endState_EnemyState7__5EnemyFv = 0xec312c8;
beginState_EnemyState8__5EnemyFv = 0xec312cc;
executeState_EnemyState8__5EnemyFv = 0xec312d0;
endState_EnemyState8__5EnemyFv = 0xec312d4;
beginState_PenguinIceHit__5EnemyFv = 0xec308f0;
executeState_PenguinIceHit__5EnemyFv = 0xec30970;
endState_PenguinIceHit__5EnemyFv = 0xec30b14;

__vtbl__4Boss = 0x1050782c;
__ct__4BossFP14ActorBuildInfo = 0xe92bb38;
checkDerivedRuntimeTypeInfo__4BossFPv = 0xe92dc80;
__dt__4BossFv = 0xe92e4b0;
onCreate__4BossFv = 0xe92bd38;
beforeExecute__4BossFv = 0xe92bedc;
afterExecute__4BossFi = 0xe92bfac;
onDelete__4BossFv = 0xe92ddfc;
setPlayerId__4BossFUc = 0xe92db90;
removeColliders__4BossFv = 0xe92dfc0;
addColliders__4BossFv = 0xe92e04c;
getPhysics__4BossFv = 0xe92dbc8;
vfAC__4BossFv = 0xe92db98;
vfB4__4BossFv = 0xe92db9c;
vfBC__4BossFv = 0xe92dba4;
vfC4__4BossFv = 0xe92dba8;
vfCC__4BossFv = 0xe92dbac;
vf10C__4BossFUc = 0xe92dbb0;
vf11C__4BossFv = 0xe92dbb8;
vf124__4BossFv = 0xe92dbbc;
vf12C__4BossFv = 0xe92dbc0;
vf154__4BossFv = 0xe92d010;
move__4BossFP4Vec2 = 0xe92dbd0;
setYSpeed__4BossFf = 0xe92dbe4;
vf16C__4BossFv = 0xe92dbec;
vf174__4BossFv = 0xe92dbf4;
vf18C__4BossFv = 0xe92dc78;
getRect__4BossFP4Rect = 0xe92e424;
freezeActor__4BossFv = 0xe92d07c;
vf1BC__4BossFv = 0xe92d134;
vf1C4__4BossFv = 0xe92e4a0;
playerCollision__4BossFUiP8Collider = 0xe92c1ac;
yoshiCollision__4BossFUiP8Collider = 0xe92c484;
vf22C__4BossFv = 0xe92de98;
hitJump__4BossFP8ColliderT1 = 0xe92dea0;
collidesSomething__4BossFP8ColliderT1 = 0xe92c7a0;
hitEnemyDown__4BossFP8ColliderT1 = 0xe92dea8;
hitGroundPound__4BossFP8ColliderT1 = 0xe92c57c;
hitEnemyKame2__4BossFP8ColliderT1 = 0xe92c7b0;
hitEnemyKameDown__4BossFP8ColliderT1 = 0xe92cab0;
vf27C__4BossFv = 0xe92c8a4;
vf284__4BossFv = 0xe92cd9c;
hitEx__4BossFv = 0xe92ce80;
vf2C4__4BossFv = 0xe92deb0;
isGrounded__4BossFv = 0xe92cfd0;
vf2F4__4BossFv = 0xe92df08;
beginState_JumpKill__4BossFv = 0xe92de6c;
executeState_JumpKill__4BossFv = 0xe92de70;
endState_JumpKill__4BossFv = 0xe92de74;
beginState_BossState1__4BossFv = 0xe92c09c;
executeState_BossState1__4BossFv = 0xe92c0ac;
endState_BossState1__4BossFv = 0xe92c0bc;
beginState_BossState2__4BossFv = 0xe92c0cc;
executeState_BossState2__4BossFv = 0xe92c0dc;
endState_BossState2__4BossFv = 0xe92c0ec;
beginState_BossState3__4BossFv = 0xe92c0fc;
executeState_BossState3__4BossFv = 0xe92c10c;
endState_BossState3__4BossFv = 0xe92c11c;
beginState_BossState4__4BossFv = 0xe92c12c;
executeState_BossState4__4BossFv = 0xe92c13c;
endState_BossState4__4BossFv = 0xe92c14c;
beginState_BossState5__4BossFv = 0xe92c15c;
executeState_BossState5__4BossFv = 0xe92c16c;
endState_BossState5__4BossFv = 0xe92c17c;
vf55C__4BossFv = 0xe92de78;
vf564__4BossFv = 0xe92de84;
vf56C__4BossFv = 0xe92de90;
vf574__4BossFv = 0xe92c18c;
vf57C__4BossFv = 0xe92de94;
vf584__4BossFv = 0xf468ed4;
vf58C__4BossFv = 0xe92df0c;
vf594__4BossFv = 0xe92df1c;
vf59C__4BossFv = 0xf468ed4;
vf5A4__4BossFv = 0xf468ed4;
vf5AC__4BossFv = 0xf468ed4;
vf5B4__4BossFv = 0xe92df60;
vf5BC__4BossFUi = 0xe92df68;
vf604__4BossFv = 0xe92df8c;
vf60C__4BossFv = 0xe92df90;
vf614__4BossFv = 0xe92df94;
vf61C__4BossFv = 0xe92df98;
vf624__4BossFv = 0xf468ed4;
vf62C__4BossFv = 0xe92dfa0;
vf634__4BossFP10StageActor = 0xe92dfa8;
vf63C__4BossFP10StageActor = 0xe92dfb4;
vf644__4BossFv = 0xe92d2f0;
vf64C__4BossFUi = 0xe92d3e4;
vf654__4BossFv = 0xe92e0f8;
changeState_JumpKill__4BossFv = 0xe92e0fc;
vf664__4BossFv = 0xe92e114;
changeState_State1__4BossFv = 0xe92e118;
vf674__4BossFv = 0xe92e130;
vf67C__4BossFv = 0xe92e140;
vf684__4BossFv = 0xf468ed4;
vf68C__4BossFv = 0xf468ed4;
vf694__4BossFv = 0xf468ed4;
vf69C__4BossFv = 0xf468ed4;
vf6A4__4BossFv = 0xe92e150;
changeState_State5__4BossFv = 0xe92e154;
vf6B4__4BossFv = 0xe92e16c;
changeState_State3__4BossFv = 0xe92e170;
vf6C4__4BossFv = 0xf468ed4;
vf6CC__4BossFv = 0xf468ed4;
vf6D4__4BossFv = 0xe92e188;
vf6DC__4BossFv = 0xe92e190;
vf6E4__4BossFv = 0xe92e194;
vf6EC__4BossFv = 0xe92e1a4;
vf6F4__4BossFv = 0xe92e1ac;
vf6FC__4BossFv = 0xe92e1b4;
vf704__4BossFv = 0xe92e1bc;
vf70C__4BossFv = 0xf468ed4;
vf714__4BossFv = 0xf468ed4;
vf71C__4BossFv = 0xf468ed4;
vf724__4BossFv = 0xe92e1c4;
vf72C__4BossFv = 0xe92e1c8;
vf734__4BossFv = 0xe92e1cc;
vf73C__4BossFv = 0xf468ed4;
vf744__4BossFv = 0xe92e1d0;
stomp__4BossFv = 0xe92e1d4;
lastStomp__4BossFv = 0xe92e1ec;
vf75C__4BossFv = 0xf468ed4;
damageStar__4BossFv = 0xe92e204;
vf76C__4BossFv = 0xf468ed4;
damageLast__4BossFv = 0xe92e21c;
damageFire__4BossFv = 0xe92e234;
damageFireLast__4BossFv = 0xe92e2a8;
damageFire2__4BossFv = 0xe92e300;
damageFireLast2__4BossFv = 0xe92e374;
damageStarDef__4BossFv = 0xe92e3cc;
damageLast2__4BossFv = 0xe92e3e4;
vf7AC__4BossFv = 0xe92e3fc;
vf7B4__4BossFv = 0xf468ed4;
vf7BC__4BossFv = 0xf468ed4;
vf7C4__4BossFv = 0xe92e400;
vf7CC__4BossFv = 0xe92d58c;
initBossCollider__4BossFv = 0xe92d5c4;
initModels__4BossFv = 0xe92e488;
vf7E4__4BossFv = 0xe92e48c;
vf7EC__4BossFv = 0xe92e490;
vf7F4__4BossFv = 0xe92e494;
vf7FC__4BossFv = 0xe92e498;

__vtbl__13WindGenerator = 0x1065b548;
__dt__13WindGeneratorFv = 0xf1a2668;
onCreate__13WindGeneratorFv = 0xf1a228c;
onExecute__13WindGeneratorFv = 0xf1a23b8;

instance__11AreaRumbler = 0x106e0ce0;
rumbleScreen__11AreaRumblerFUcUiN32 = 0xedc4da8;

instance__11ItemSpawner = 0x106e2600;
getExtraPlayerCount__11ItemSpawnerFv = 0xee1e118;

instance__7CoinMgr = 0x106eb0ac;
dropCoins__7CoinMgrFP4Vec3 = 0xefe11e8;
spawnItemCoin__7CoinMgrFP4Vec3UiUc = 0xefde27c;

spawnBabyEgg__8YoshiMgrSFP4Vec3UcUi = 0xf057278;

__vtbl__20BlockCoinRelatedBase = 0x10606f40;
checkDerivedRuntimeTypeInfo__20BlockCoinRelatedBaseFPv = 0xf01c488;
__dt__20BlockCoinRelatedBaseFv = 0xf01c610;
setPlayerId__20BlockCoinRelatedBaseFUc = 0xf01c044;
getPhysics__20BlockCoinRelatedBaseFv = 0xf01c080;
vfAC__20BlockCoinRelatedBaseFv = 0xf01c04c;
vfB4__20BlockCoinRelatedBaseFv = 0xf01c050;
vfBC__20BlockCoinRelatedBaseFv = 0xf01c058;
vfC4__20BlockCoinRelatedBaseFv = 0xf01c05c;
vfCC__20BlockCoinRelatedBaseFv = 0xf01c060;
damageFromUnder__20BlockCoinRelatedBaseFv = 0xf01c064;
vf10C__20BlockCoinRelatedBaseFUc = 0xf01c068;
vf11C__20BlockCoinRelatedBaseFv = 0xf01c070;
vf124__20BlockCoinRelatedBaseFv = 0xf01c074;
vf12C__20BlockCoinRelatedBaseFv = 0xf01c078;
vf154__20BlockCoinRelatedBaseFv = 0xf01c088;
move__20BlockCoinRelatedBaseFP4Vec2 = 0xf01c090;
setYSpeed__20BlockCoinRelatedBaseFf = 0xf01c0a4;
vf16C__20BlockCoinRelatedBaseFv = 0xf01c0ac;
vf174__20BlockCoinRelatedBaseFv = 0xf01c0b4;
getRect__20BlockCoinRelatedBaseFP4Rect = 0xf01c0bc;
doStateChange__20BlockCoinRelatedBaseFP9StateBase = 0xf01c128;
vf18C__20BlockCoinRelatedBaseFv = 0xf01c5c4;
vf194__20BlockCoinRelatedBaseFv = 0xf01c5c8;
vf19C__20BlockCoinRelatedBaseFv = 0xf01c5cc;
vf1A4__20BlockCoinRelatedBaseFv = 0xf01c5d0;
spawnItemUp__20BlockCoinRelatedBaseFv = 0xf01c5d4;
vf1B4__20BlockCoinRelatedBaseFv = 0xf01c5d8;
vf1BC__20BlockCoinRelatedBaseFv = 0xf01c5dc;
spawnItemDown__20BlockCoinRelatedBaseFv = 0xf01c5e0;
vf1CC__20BlockCoinRelatedBaseFv = 0xf01c5e4;
vf1D4__20BlockCoinRelatedBaseFb = 0xf017f30;
vf1DC__20BlockCoinRelatedBaseFv = 0xf01c5e8;
spawnCoinShower__20BlockCoinRelatedBaseFv = 0xf017fac;
vf1EC__20BlockCoinRelatedBaseFv = 0xf01c5f0;
beginState_BumpUp__20BlockCoinRelatedBaseFv = 0xf01b37c;
executeState_BumpUp__20BlockCoinRelatedBaseFv = 0xf01b3b8;
endState_BumpUp__20BlockCoinRelatedBaseFv = 0xf01c5f4;
beginState_BlockCoinRelatedState1__20BlockCoinRelatedBaseFv = 0xf01b45c;
executeState_BlockCoinRelatedState1__20BlockCoinRelatedBaseFv = 0xf01b468;
endState_BlockCoinRelatedState1__20BlockCoinRelatedBaseFv = 0xf01c5f8;
beginState_BumpDown__20BlockCoinRelatedBaseFv = 0xf01b480;
executeState_BumpDown__20BlockCoinRelatedBaseFv = 0xf01b4c4;
endState_BumpDown__20BlockCoinRelatedBaseFv = 0xf01c5fc;
beginState_BlockCoinRelatedState2__20BlockCoinRelatedBaseFv = 0xf01b564;
executeState_BlockCoinRelatedState2__20BlockCoinRelatedBaseFv = 0xf01b570;
endState_BlockCoinRelatedState2__20BlockCoinRelatedBaseFv = 0xf01c600;
beginState_BumpUp2__20BlockCoinRelatedBaseFv = 0xf01b598;
executeState_BumpUp2__20BlockCoinRelatedBaseFv = 0xf01b620;
endState_BumpUp2__20BlockCoinRelatedBaseFv = 0xf01c604;
beginState_BumpDown2__20BlockCoinRelatedBaseFv = 0xf01b7f4;
executeState_BumpDown2__20BlockCoinRelatedBaseFv = 0xf01b860;
endState_BumpDown2__20BlockCoinRelatedBaseFv = 0xf01c608;
beginState_BlockCoinRelatedState3__20BlockCoinRelatedBaseFv = 0xf01b954;
executeState_BlockCoinRelatedState3__20BlockCoinRelatedBaseFv = 0xf01b960;
endState_BlockCoinRelatedState3__20BlockCoinRelatedBaseFv = 0xf01c60c;

spawnPortableSpring__20BlockCoinRelatedBaseFv = 0xf019af8;
spawnVine__20BlockCoinRelatedBaseFv = 0xf019970;
spawnYoshiEgg__20BlockCoinRelatedBaseFb = 0xf01a26c;
spawnPowerup__20BlockCoinRelatedBaseFP4Vec3UiT2b = 0xf01a3e4;
spawnMultiPowerup__20BlockCoinRelatedBaseFP4Vec3UiT2b = 0xf01a6bc;

__vtbl__13BlockCoinBase = 0x1060ca6c;
checkDerivedRuntimeTypeInfo__13BlockCoinBaseFPv = 0xf03b0d0;
__dt__13BlockCoinBaseFv = 0xf03b26c;
setPlayerId__13BlockCoinBaseFUc = 0xf03af30;
getPhysics__13BlockCoinBaseFv = 0xf03af6c;
vfAC__13BlockCoinBaseFv = 0xf03af38;
vfB4__13BlockCoinBaseFv = 0xf03af3c;
vfBC__13BlockCoinBaseFv = 0xf03af44;
vfC4__13BlockCoinBaseFv = 0xf03af48;
vfCC__13BlockCoinBaseFv = 0xf03af4c;
damageFromUnder__13BlockCoinBaseFv = 0xf03af50;
vf10C__13BlockCoinBaseFUc = 0xf03af54;
vf11C__13BlockCoinBaseFv = 0xf03af5c;
vf124__13BlockCoinBaseFv = 0xf03af60;
vf12C__13BlockCoinBaseFv = 0xf03af64;
vf154__13BlockCoinBaseFv = 0xf03af74;
move__13BlockCoinBaseFP4Vec2 = 0xf03af7c;
setYSpeed__13BlockCoinBaseFf = 0xf03af90;
vf16C__13BlockCoinBaseFv = 0xf03af98;
vf174__13BlockCoinBaseFv = 0xf03afa0;
getRect__13BlockCoinBaseFP4Rect = 0xf03afa8;
doStateChange__13BlockCoinBaseFP9StateBase = 0xf03b00c;
vf18C__13BlockCoinBaseFv = 0xf03b02c;
vf194__13BlockCoinBaseFv = 0xf03b030;
vf19C__13BlockCoinBaseFv = 0xf03b034;
vf1A4__13BlockCoinBaseFv = 0xf03b038;
spawnItemUp__13BlockCoinBaseFv = 0xf039cd8;
vf1B4__13BlockCoinBaseFv = 0xf03b03c;
vf1BC__13BlockCoinBaseFv = 0xf03b040;
spawnItemDown__13BlockCoinBaseFv = 0xf039cfc;
vf1CC__13BlockCoinBaseFv = 0xf03b044;
vf1DC__13BlockCoinBaseFv = 0xf039d0c;
vf1EC__20BlockCoinRelatedBaseFv = 0xf03b048;
vf29C__13BlockCoinBaseFv = 0xf03b04c;
setTileFlag__13BlockCoinBaseFv = 0xf039c84;
vf2AC__13BlockCoinBaseFv = 0xf03b050;
vf2B4__13BlockCoinBaseFv = 0xf03b058;
vf2BC__13BlockCoinBaseFv = 0xf03b05c;
vf2C4__13BlockCoinBaseFv = 0xf03b060;
vf2CC__13BlockCoinBaseFv = 0xf039d1c;

StateID_Wait__9BlockBase = 0x1072fdec;
StateID_Used__9BlockBase = 0x1072fe10;

otherCollisionCallback1__9BlockBaseSFP17OtherColliderBaseP7PhysicsUi = 0xf0187b8;
otherCollisionCallback2__9BlockBaseSFP17OtherColliderBaseP7PhysicsUi = 0xf019024;
otherCollisionCallback3__9BlockBaseSFP17OtherColliderBaseP7PhysicsUi = 0xf019788;

init__9BlockBaseFbT1 = 0xefb2d90;

__vtbl__9BlockBase = 0x105ebe20;
__ct__9BlockBaseFP14ActorBuildInfo = 0xefb1cdc;
checkDerivedRuntimeTypeInfo__9BlockBaseFPv = 0xefb3b28;
__dt__9BlockBaseFv = 0xefb3cf4;
onExecute__9BlockBaseFv = 0xefb1d8c;
onDraw__9BlockBaseFv = 0xefb1e44;
setPlayerId__9BlockBaseFUc = 0xefb39b8;
getPhysics__9BlockBaseFv = 0xefb39f8;
vfAC__9BlockBaseFv = 0xefb39c0;
vfB4__9BlockBaseFv = 0xefb39c4;
vfBC__9BlockBaseFv = 0xefb39cc;
vfC4__9BlockBaseFv = 0xefb39d0;
vfCC__9BlockBaseFv = 0xefb39d4;
damageFromUnder__9BlockBaseFv = 0xefb3ac8;
vf10C__9BlockBaseFUc = 0xefb39e0;
vf11C__9BlockBaseFv = 0xefb39e8;
vf124__9BlockBaseFv = 0xefb39ec;
vf12C__9BlockBaseFv = 0xefb39f0;
vf154__9BlockBaseFv = 0xefb3a00;
move__9BlockBaseFP4Vec2 = 0xefb3a08;
setYSpeed__9BlockBaseFf = 0xefb3a1c;
vf16C__9BlockBaseFv = 0xefb3a24;
vf174__9BlockBaseFv = 0xefb3a2c;
getRect__9BlockBaseFP4Rect = 0xefb3a34;
doStateChange__9BlockBaseFP9StateBase = 0xefb3a98;
vf18C__9BlockBaseFv = 0xefb3aa0;
vf194__9BlockBaseFv = 0xefb3aa4;
vf19C__9BlockBaseFv = 0xefb2ac8;
vf1A4__9BlockBaseFv = 0xefb3aa8;
spawnItemUp__9BlockBaseFv = 0xefb2288;
vf1B4__9BlockBaseFv = 0xefb3aac;
vf1BC__9BlockBaseFv = 0xefb3ab0;
spawnItemDown__9BlockBaseFv = 0xefb228c;
vf1CC__9BlockBaseFv = 0xefb22cc;
vf1EC__20BlockCoinRelatedBaseFv = 0xefb2d3c;
vf29C__9BlockBaseFv = 0xefb3ab4;
vf2AC__9BlockBaseFv = 0xefb3ab8;
vf2B4__9BlockBaseFv = 0xefb3ac0;
vf2BC__9BlockBaseFv = 0xefb3ac4;
vf2C4__9BlockBaseFv = 0xefb2ad8;
vf2D4__9BlockBaseFv = 0xefb22e4;
vf2DC__9BlockBaseFv = 0xefb3acc;
getContent__9BlockBaseFv = 0xefb3ad0;
vf2EC__9BlockBaseFv = 0xefb26ac;
vf2F4__9BlockBaseFP4Vec3 = 0xefb3ae0;
execute__9BlockBaseFv = 0xefb2740;
vf304__9BlockBaseFv = 0xefb2924;
vf30C__9BlockBaseFv = 0xefb2a04;
vf314__9BlockBaseFv = 0xefb3afc;
vf31C__9BlockBaseFv = 0xefb3b00;
vf324__9BlockBaseFv = 0xefb3b04;
vf32C__9BlockBaseFv = 0xefb3b08;
beginState_Wait__9BlockBaseFv = 0xefb3ce4;
executeState_Wait__9BlockBaseFv = 0xefb3730;
endState_Wait__9BlockBaseFv = 0xefb3ce8;
beginState_Used__9BlockBaseFv = 0xefb3cec;
executeState_Used__9BlockBaseFv = 0xefb373c;
endState_Used__9BlockBaseFv = 0xefb3cf0;

getTilt__10ControllerFPUif = 0xee0ef20;

instance__8InputMgr = 0x106e2478;

__vtbl__10PlayerBase = 0x1066cb2c;
playSound__10PlayerBaseFPcb = 0xf227a58;
groundPound__10PlayerBaseFv = 0xf226440;
playLandSound__10PlayerBaseFv = 0xf227f18;
doLandEffects__10PlayerBaseFv = 0xf22078c;
spawnGroundPoundBlurEffect__10PlayerBaseFv = 0xf2201dc;
usedByGoalPole__10PlayerBaseFv = 0xf21ebe4;

StateID_DefaultState__5Yoshi = 0x1073cf90;

onCreate__5YoshiFv = 0xf27a288;

getRidingPlayer__5YoshiFv = 0xf287478;
changeState__5YoshiFP19State__tm__7_5Yoshi = 0xf27e320;
spawnBall__5YoshiFb = 0xf27e87c;
getActorInMouth__5YoshiFv = 0xf27e610;
removeActorFromMouth__5YoshiFv = 0xf27ecb8;

__vtbl__6Player = 0x10671df8;

instance__15BasicSoundActor = 0x106d5a50;
playSound__15BasicSoundActorFPCcP4Vec2Ui = 0xf2de7f8;

instance__18AmbientSoundPlayer = 0x106d5a54;
__vtbl__18AmbientSoundPlayer = 0x105072f0;

instance__11SoundSystem = 0x106f7ad8;
getSoundArchive__11SoundSystemFv = 0xf2d35a0;
playSound__11SoundSystem2FPCcUi = 0xf2d4ecc;

instance__12EnemyCounter = 0x106d2750;
killEnemiesGoal__12EnemyCounterFv = 0xe90baf4;

/*** HACK ADDRESSES ***/
returnTileGod = 0xf0393d4;
returnInitRaftState = 0xf0049d4;
continueRenderTileAnim = 0xefa8068;
}
