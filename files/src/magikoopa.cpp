/* NewerU Sprite - Magikoopa
 *
 * Actor: ???
 * Sprite ID: ???
 *
 * Unfinised. Does Magikoopa things. Supposed to shoot kamekmagic.
 */

const ActorInfo actorInfo = {8, -16, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const Profile profile(Magikoopa::build, , "Magikoopa", &actorInfo, 0);
const sead::String fileList[] = {"kameck"};
const ActorFiles actorFiles( , 1, fileList);
const CollisionInfo collisionInfo = {0, 16, 10, 16, 0, 3, 0, 0x26F, 0xFFFAFFFF, 0, Enemy::collisionCallback};

Magikoopa::Magikoopa(ActorBuildInfo *buildInfo) : Enemy(buildInfo) {}

Actor * Magikoopa::build(ActorBuildInfo *buildInfo) {
	return new Magikoopa(buildInfo);
}

class Magikoopa : public Enemy {
	Model2 model;
	ResArchive archive;

	int onCreate();
	int onExecute();
	int onDraw();
	
	DECLARE_STATE(Magikoopa, Shoot)
	DECLARE_STATE(Magikoopa, WaitShoot)
}

int Magikoopa::onCreate() {
	this->archive = ResLoader::instance->getResArchive("kameck");
	ModelObj * mdl = archive->getModel("kameck", 2, 0, 1, 0, 0, 0);
	this->model = new Model2(mdl, 2, 0, 1, 0, 0);
	this->model->init(archive, 0, 0);
	
	this->direction = this->getDirectionToPlayer(&this->position);
	this->rotation.Y = directionToRotationList[this->direction];
	this->scale = (Vec3) {0.9f, 0.9f, 0.9f};
	
	Vec3 r5 = {-16.0, 16.0,  0.0};
	Vec3 r6 = {-16.0, 16.0, 40.0};
	Vec3 r7 = { 10.0, 30.0, 25.0};
	this->physics.init(this, &r5, &r6, &r7);
	
	this->collider.init(this, &collisionInfo, 0);
	CollisionMgr::instance->addCollider(&this->collider);
	
	this->physics.processCollisions();
	
	doStateChange(&StateID_WaitShoot);
	return 1;
}

int Magikoopa::onExecute() {
	this->direction = this->getDirectionToPlayer(&this->position);
	this->rotation.Y = directionToRotationList[this->direction];

	this->stateMgr.stateClass.executeState();
	return 1;
}

int Magikoopa::onDraw() {
	Drawer::instance->drawModel(this->model);
	return 1;
}

/* * * * * * * * * * * * * * * * *
 *        STATE WAITSHOOT        *
 * * * * * * * * * * * * * * * * */
CREATE_STATE(Magikoopa, WaitShoot)

void Magikoopa::beginState_WaitShoot() {
	sead::String name = "demo_battleA";
	model->sklAnims.anims[0]->play(this->archive, &name);
	model->sklAnims.anims[0]->setRepeat(false);
}

void Magikoopa::executeState_WaitShoot() {
	if (model->sklAnims.anims[0]->flags & 0x20) {
		this->doStateChange(&StateID_Shoot);
	}
}

void Magikoopa::endState_WaitShoot() {}

/* * * * * * * * * * * * * * * * *
 *          STATE SHOOT          *
 * * * * * * * * * * * * * * * * */
CREATE_STATE(Magikoopa, Shoot)

void Magikoopa::beginState_Shoot() { }

void Magikoopa::executeState_Shoot() {
	BasicSoundActor::instance->playSound("SE_VOC_KMC_MAGIC_SHOT", (Vec2) {this->position.X, this->position.Y}, 0);
	
}

void Magikoopa::endState_Shoot() {
	
}