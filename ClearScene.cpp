#include "ClearScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
ClearScene::ClearScene(GameObject* parent)
	:GameObject(parent,"ClearScene"),hPict_(-1)
{
}

void ClearScene::Initialize()
{
	hPict_ = Image::Load("Clear.png");
	assert(hPict_ >= 0);
}

void ClearScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* pSM = (SceneManager*)FindObject("SceneManager");
		pSM->ChangeScene(SCENE_ID_TITLESELECT);
	}
}

void ClearScene::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

void ClearScene::Release()
{
}
