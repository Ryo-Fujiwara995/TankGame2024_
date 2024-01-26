#include "Tank.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Debug.h"
#include "Ground.h"
#include "TankHead.h"
#include "Engine/Camera.h"

//���_�ړ�
enum CAM_TYPE{
	FIXED_TYPE,      //�Œ�
	TPS_NOROT_TYPE,  //3�l�̉�]�Ȃ�
	TPS_TYPE,        //3�l��
	FPS_TYPE,       //1�l��
	MAX_TYPE,       //�ԕ�����i�`�F�b�N�p�̒l�j
};

Tank::Tank(GameObject* parent)
	:GameObject(parent, "Tank"), hModel_(-1),speed_(0.05),front_({0,0,1,0})
	,camState_(CAM_TYPE::FIXED_TYPE){
}

void Tank::Initialize(){
	hModel_ = Model::Load("TankBody.fbx");
	assert(hModel_ >= 0);
	//speed_ = 0.05;
	//front_ = XMVECTOR({ 0,0,1,0 });
	Instantiate<TankHead>(this);
	BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(1, 1, 1));
	AddCollider(collision);
}

void Tank::Update(){
	
	XMMATRIX rotY = XMMatrixIdentity();//�s���1�@�P�ʍs��
	XMVECTOR move { 0,0,0,0 };
	XMVECTOR rotVec {0,0,0,0};
	float dir = 0;
	if (Input::IsKey(DIK_W)){
		dir = 1.0;
	}
	if (Input::IsKey(DIK_S)){
		dir = -1.0;
		//��]�s������߂�
		//rotY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));
		////�x�N�g���̉�]���ʂ����߂�
		//rotVec = XMVector3TransformCoord(front_, rotY);

	}
	if (Input::IsKey(DIK_A)){
		this->transform_.rotate_.y -= 1;

	}
	if (Input::IsKey(DIK_D)){
		this->transform_.rotate_.y += 1;
	}
	//��]�s������߂�
	rotY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));
	//�x�N�g���̉�]���ʂ����߂�
	rotVec = XMVector3TransformCoord(front_, rotY);
	move = speed_ * rotVec;
	XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
	pos = pos + dir * move;
	XMStoreFloat3(&(transform_.position_), pos);

	//Debug::Log("angle = ");
	//Debug::Log(transform_.rotate_.y, true);
	Ground* pGround = (Ground*)FindObject("Ground");
	int hGmodel = pGround->GetModelHandle();

	RayCastData data;
	data.start = transform_.position_;
	data.start.y = 0;
	data.dir = XMFLOAT3({ 0,-1,0 });
	Model::RayCast(hGmodel, &data);

	if (data.hit == true){
		transform_.position_.y = -data.dist + 0.5f;
	}
	if (Input::IsKeyDown(DIK_Z)) {
		camState_++;
		//camState_ = (++camState_) % (CAM_TYPE::MAX);
		if (camState_ == CAM_TYPE::MAX_TYPE) {
			camState_ == CAM_TYPE::FIXED_TYPE;
		}
	}

	switch (camState_){
	
	case CAM_TYPE::FIXED_TYPE: {
		Camera::SetPosition(XMFLOAT3{ 0,20,-20 });
		Camera::SetTarget(XMFLOAT3{ 0,0,0 });
		break;
	}
	case CAM_TYPE::TPS_NOROT_TYPE: {
		XMFLOAT3 camPos = transform_.position_;
		camPos.y = transform_.position_.y + 20.0f;
		camPos.z = transform_.position_.z - 10.0f;
		Camera::SetPosition(camPos);
		Camera::SetTarget(transform_.position_);
		break;
	}
	case CAM_TYPE::TPS_TYPE: {
		//Camera::SetPosition(XMFLOAT3{ 0,20,-30 });
		Camera::SetTarget(transform_.position_);
		XMVECTOR vEye{0,5,-10,0};
		XMFLOAT3 camPos;
		//��������A��]
		vEye = XMVector3TransformCoord(vEye, rotY);
		XMStoreFloat3(&camPos,pos + vEye);
		Camera::SetPosition(camPos);
		break;
	}
	case CAM_TYPE::FPS_TYPE: {
		
		Camera::SetTarget(transform_.position_);
		XMFLOAT3 camTarget;

		XMStoreFloat3(&camTarget, pos + dir * move);
		Camera::SetPosition(camTarget);
		break;

	}
	case CAM_TYPE::MAX_TYPE: {
		Camera::SetPosition(XMFLOAT3{});
		Camera::SetTarget(XMFLOAT3{0,0,0});
		break;

	}
	default:
		break;
	}
}

void Tank::Draw(){

	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Tank::Release(){

}

void Tank::OnCollision(GameObject* pTarget){
	//���������Ƃ��̏���
	//Tank ���e�ɓ��������Ƃ� Tank �������鏈��(�ꉞ)
	if (pTarget->GetObjectName() == "Ballet") {
		KillMe();
	}
}
