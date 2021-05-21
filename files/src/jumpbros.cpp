
#include "game.h"
#include "neweru.h"

class JumpBros : public Enemy {
	public:
	Model2 * model;
	ResArchive * archive;
	u32 timer;
	
	int onCreate();
	int onExecute();
	int onDraw();
	
	bool freezeActor();
	void playerCollision(Collider *, Collider *);
	void yoshiCollision(Collider *, Collider *);
	
	void updateModel();
	
	static Actor *build(ActorBuildInfo *);
	JumpBros(ActorBuildInfo *);
	
	DECLARE_STATE(JumpBros, BeginJump)
	DECLARE_STATE(JumpBros, DoJump)
	DECLARE_STATE(JumpBros, EndJump)
	DECLARE_STATE(JumpBros, WaitJump)
};

const ActorInfo actorInfo = {8, -16, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const Profile profile(JumpBros::build, PURPLE_RING, "JumpBros", &actorInfo, 0);

const sead::String fileList[] = {"bros"};
const ActorFiles actorFiles(PURPLE_RING, 1, fileList);

CREATE_STATE(JumpBros, BeginJump)
CREATE_STATE(JumpBros, DoJump)
CREATE_STATE(JumpBros, EndJump)
CREATE_STATE(JumpBros, WaitJump)

JumpBros::JumpBros(ActorBuildInfo *buildInfo) : Enemy(buildInfo) {}

Actor *JumpBros::build(ActorBuildInfo *buildInfo) {
	return new JumpBros(buildInfo);
}

const CollisionInfo collisionInfo = {0, 16, 10, 16, 0, 3, 0, 0x26F, 0xFFFAFFFF, 0, Enemy::collisionCallback};

bool JumpBros::freezeActor() {
	IceInfo info = {1, position.X, position.Y + 2, position.Z + 2, 1.3, 1.1, 1.13, 0};
	return this->iceMgr.freezeActor(&info, 1);
}

void JumpBros::playerCollision(Collider *self, Collider *other) {
	Player * player = (Player *)other->owner;

	HitType hitType = this->processHit(self, other);
	if (hitType == Side) {Enemy::playerCollision(self, other);}
	else if (hitType == Jump) {
		Vec2 speed = {0.75, 2.0};
		this->killWithPlayer(player, &speed, &Enemy::StateID_JumpKill);
	}
	else if (hitType == SpinJump) {
		this->spinJumpKill(player);
	}
}

void JumpBros::yoshiCollision(Collider *self, Collider *other) {
	Yoshi * yoshi = (Yoshi *)other->owner;
	
	HitType hitType = this->processHit(self, other);
	if (hitType == Side) {Enemy::yoshiCollision(self, other);}
	else if (hitType == Jump) {
		this->killWithYoshi(yoshi);
	}
}

int JumpBros::onCreate() {
	archive = ResLoader::instance->getResArchive("bros");
	ModelObj * mdl = archive->getModel("bros", 2, 1, 0, 0, 0, 0, 0);
	model = new Model2(mdl, 2, 1, 0, 0, 0);
	model->init(archive, 0, 0);
	
	direction = getDirectionToPlayer(&position);
	rotation.Y = directionToRotationList[direction];
	
	Vec3 r5 = {0, 0, 0};
	Vec3 r6 = {0.0, 0.0, 32.0};
	Vec3 r7 = {4, 28, 8};
	physics.init(this, &r5, &r6, &r7);
	
	collider.init(this, &collisionInfo, 0);
	CollisionMgr::instance->addCollider(&collider);
	
	physics.processCollisions();
	
	doStateChange(&StateID_WaitJump);
	
	updateModel();
	return 1;
}

void JumpBros::updateModel() {
	Mtx mtx;
	calcMatrix(&mtx, &rotation, &position);
	model->obj->setMatrix(&mtx);
	model->obj->setScale(&scale);
	model->obj->vf6C();
	model->obj->vf74();
	model->update();
}

int JumpBros::onExecute() {
	stateMgr.stateClass.executeState();
	updateModel();
	return 1;
}

int JumpBros::onDraw() {
	Drawer::instance->drawModel(model);
	return 1;
}

void JumpBros::beginState_BeginJump() {
	sead::String name = "jump_st";
	model->sklAnims.anims[0]->play(archive, &name);
	model->sklAnims.anims[0]->setRepeat(false);
}
void JumpBros::executeState_BeginJump() {
	if (model->sklAnims.anims[0]->flags & 0x20) {
		doStateChange(&StateID_DoJump);
	}
}
void JumpBros::endState_BeginJump() {}

void JumpBros::beginState_DoJump() {
	sead::String name = "jump_md";
	model->sklAnims.anims[0]->play(archive, &name);
	model->sklAnims.anims[0]->setRepeat(false);
	speed.Y = 6;
}
void JumpBros::executeState_DoJump() {
	applyGravity();
	updatePosition();
	physics.processCollisions();
	
	if (physics.collisionFlags[0] & 1) {
		doStateChange(&StateID_EndJump);
	}
}
void JumpBros::endState_DoJump() {}

void JumpBros::beginState_EndJump() {
	sead::String name = "jump_ed";
	model->sklAnims.anims[0]->play(archive, &name);
	model->sklAnims.anims[0]->setRepeat(false);
}
void JumpBros::executeState_EndJump() {
	if (model->sklAnims.anims[0]->flags & 0x20) {
		doStateChange(&StateID_WaitJump);
	}
}
void JumpBros::endState_EndJump() {}

void JumpBros::beginState_WaitJump() {
	timer = 20;
}
void JumpBros::executeState_WaitJump() {
	if (--timer == 0) {
		doStateChange(&StateID_BeginJump);
	}
}
void JumpBros::endState_WaitJump() {}
