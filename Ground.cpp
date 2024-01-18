#include "Ground.h"
#include "Engine/Model.h"

Ground::Ground(GameObject* parent)
	:GameObject(parent,"Ground"), hModel_(-1)
{
}

Ground::~Ground()
{
	//�ȁ[������Ȃ��B
}

void Ground::Initialize()
{
	hModel_ = Model::Load("Ground.fbx");
	assert(hModel_ >= 0);
}

void Ground::Update()
{
}

void Ground::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Ground::Release()
{
}
