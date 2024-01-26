#include "TitleSelect.h"
#include "Engine/Image.h"
#include "TitleImage.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
#include "TitleSelectImage.h"

TitleSelect::TitleSelect(GameObject* parent)
	:GameObject(parent,"TitleSelect"), hSSelect_(-1), hESelect_(-1)
{

}

TitleSelect::~TitleSelect()
{
}

void TitleSelect::Initialize()
{
	Instantiate<TitleSelectImage>(this);//背景みたいなの



}

void TitleSelect::Update()
{
	//ボタン　or マウス？？

	//今は、space押せば遷移するこれをボタンかマウスに　なければ飾りつけで
	//+α そこを押せばボタンの色が変わる
	//スタート
	if (Input::IsKeyDown(DIK_S)){
		SceneManager* pSM = (SceneManager*)FindObject("SceneManager");
		pSM->ChangeScene(SCENE_ID_PLAY);
	}
	//強制終了させたい
	if (Input::IsKeyDown(DIK_E)) {
		
	}
}

void TitleSelect::Draw()
{

}

void TitleSelect::Release()
{
}
