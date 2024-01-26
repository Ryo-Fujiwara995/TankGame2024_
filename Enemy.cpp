#include "Enemy.h"
#include "Engine/Model.h"
#include "Ground.h"
#include "Engine/SphereCollider.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy"),hModel_(-1){

}

void Enemy::Initialize(){
	hModel_ = Model::Load("Mushroom 1.fbx");
	assert(hModel_ >= 0);

	SphereCollider* collider = new SphereCollider(XMFLOAT3(0, 0, 0), 1.0);
	AddCollider(collider);

	//ƒAƒjƒ[ƒVƒ‡ƒ“‚ÌƒZƒbƒg
	Model::SetAnimFrame(hModel_, 0, 60, 1);
	float x = (float)rand() / RAND_MAX;//0-1‚Ì—”

	x = 2.0 * x; // 0-5‚Ì—”
	transform_.position_.x = 25.0*(x - 1.0); //25*(-1.0 ` 1.0)‚Ì—”
	float z = (float)rand() / RAND_MAX;//0-1‚Ì—”
	z = 2.0 * z; // 0-5‚Ì—”
	transform_.position_.z = 25.0*(z - 1.0); //25*(-1.0 ` 1.0)‚Ì—”
	transform_.position_.y = 0;

	Ground* pGround = (Ground*)FindObject("Ground");
	int hGmodel = pGround->GetModelHandle();
	RayCastData data;
	data.start = transform_.position_;
	data.dir = XMFLOAT3({ 0,-1, 0 });
	Model::RayCast(hGmodel, &data);

	if (data.hit == true)
	{
		transform_.position_.y = -data.dist + 0.5;
	}
}

void Enemy::Update()
{

}

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy::Release()
{
}

void Enemy::OnCollision(GameObject* pTarget){
	//“–‚½‚Á‚½‚Æ‚«‚Ìˆ—
	//“G‚ª’e‚É“–‚½‚Á‚½‚Æ‚« “G‚ªÁ‚¦‚éˆ—
	if (pTarget->GetObjectName() == "Bullet") {
		KillMe();
	}
	//Tank ‚ª“G‚É“–‚½‚Á‚½‚Æ‚« Enemy ‚ªÁ‚¦‚éˆ—
	if (pTarget->GetObjectName() == "Tank") {
		KillMe();
	}
}



