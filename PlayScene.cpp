#include "PlayScene.h"
#include "Ground.h"
#include "Tank.h"
#include "Enemy.h"
#include "HUD.h"
#include "Engine/Text.h"
#include "Engine/Camera.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
//#include "TankHead.h"

namespace {
	const int ENEMY_NUM = { 30 };
}


PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene"),pText(nullptr)
{
}

PlayScene::~PlayScene()
{
}

void PlayScene::Initialize()
{

	Instantiate<Ground>(this);
	player = Instantiate<Tank>(this);
	//Instantiate<TankHead>(this);
	//�G���C���X�^���X��
	enemyNum = ENEMY_NUM;
	for(int i=0;i< ENEMY_NUM;i++)
		Instantiate<Enemy>(this);

	//enemyNum = 30;
	
	pText = new Text;
	pText->Initialize();

	Instantiate<HUD>(this);//�c�@�\��
}

void PlayScene::Update()
{
	////�^���N�ƈꏏ�ɃJ�����𓮂�����
	//Camera::SetTarget(player->GetPosition());
	//XMFLOAT3 camPos = player->GetPosition();
	//camPos.y += 8;
	//camPos.z -= 15;
	//Camera::SetPosition(camPos);
	//Clear�Ȃ̂�C
	if (Input::IsKeyDown(DIK_C))
	{
		SceneManager* pSM = (SceneManager*)FindObject("SceneManager");
		pSM->ChangeScene(SCENE_ID_CLEAR);
	}
}

void PlayScene::Draw()
{
	//pText->Draw(30, 30, "Yahoo!");

}

void PlayScene::Release()
{
}
