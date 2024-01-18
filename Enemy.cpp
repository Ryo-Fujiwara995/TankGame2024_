#include "Enemy.h"
#include "Engine/Model.h"
#include "Ground.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy"),hModel_(-1)
{
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("Mushroom 1.fbx");
	assert(hModel_ >= 0);
	//アニメーションのセット
	Model::SetAnimFrame(hModel_, 0, 60, 1);
	float x = (float)rand() / RAND_MAX;//0-1の乱数

	x = 2.0 * x; // 0-5の乱数
	transform_.position_.x = 25.0*(x - 1.0); //25*(-1.0 ～ 1.0)の乱数
	float z = (float)rand() / RAND_MAX;//0-1の乱数
	z = 2.0 * z; // 0-5の乱数
	transform_.position_.z = 25.0*(z - 1.0); //25*(-1.0 ～ 1.0)の乱数
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
