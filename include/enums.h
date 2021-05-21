
#pragma once

enum PlatformType {
	Wood = 0,
	Stone = 1,
	PinkMushroom = 2,
	BoltPlatform = 3,
	Crashes = 4, //boss_koopa_lift
	Bowser = 5,
	YellowMushroom = 6,
	WoodSnow = 7,
	Sky = 8,
	Tower = 9,
	Karansha = 10
};

enum TerrainType {
	Water = 0,
	Lava = 1,
	Poison = 2,
	LavaWaves = 3,
	QuickSand = 4
};

enum Powerup {
	Small = 0,
	Big = 1,
	Fire = 2,
	Mini = 3,
	Propeller = 4,
	Penguin = 5,
	Ice = 6,
	Acorn = 7,
	PAcorn = 8
};

enum ItemType {
	Mushroom      = 0,
	FireFlower    = 1,
	SuperStar     = 2,
	IceFlower     = 3,
	LifeMushroom  = 4,
	PropellerSuit = 5,
	MiniMushroom  = 6,
	PenguinSuit   = 7,
	SquirrelSuit  = 8,
	NewerU_Kamek  = 9,
	LifeMoon      = 12,
	DRCStar       = 13	
};

enum PlayerType {
	NoPlayer = 0,
	NormalPlayer = 1,
	YoshiPlayer = 2,
	TreasureChestMaybe = 3,
	Unknown = 4
};

enum Direction {
	Right = 0,
	Left = 1,
	Up = 2,
	Down = 3
};

enum HitType {
	Side = 0,
	Jump = 1,
	SpinJump = 3
};

enum CollisionFlags {
	Ground = 1 << 0,
	RightWall = 1 << 18,
	LeftWall = 1 << 19
};

enum MovementType {
	None,
	Rotation, //68, 69, 116, 118
	Bolt, //238
	Path, //100
	TwoWay, //70
	Nothing,
	ScrewMushroomWithBolt, //241
	ScrewMushroomWithoutBolt, //242
	RotatingPlates, //132
	RotationController, //214, 484
	RollingHill, //424
	ColorMushroomLift //210
};

enum YoshiTongueState {
	InMouth = 0,
	MovingAway = 1,
	CarriesSthThatCanBeSpitOut = 2,
	CarriesEdible = 3,
	CarriesBerry = 4,
	CarriesNothing = 5
};

enum YoshiFoodSpitType {
	UNKNOWN_0 = 0,
	SpitActorItself = 1,
	UNKNOWN_2 = 2,
	Default_maybe = 3,
	UNKNOWN_4 = 4,
	SpitFireball = 5,
	SpitIceball = 6
};
