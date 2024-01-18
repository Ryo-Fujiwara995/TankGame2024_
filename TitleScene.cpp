#include "TitleScene.h"
#include "TitleImage.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"


TitleScene::TitleScene(GameObject* parent)
	:GameObject(parent, "TitleScene")
{
}

void TitleScene::Initialize()
{
	Instantiate<TitleImage>(this);
}

void TitleScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* pSM = (SceneManager*)FindObject("SceneManager");
		pSM->ChangeScene(SCENE_ID_PLAY);
	}
}

void TitleScene::Draw()
{
}

void TitleScene::Release()
{
}
