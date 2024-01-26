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
	Instantiate<TitleSelectImage>(this);//�w�i�݂����Ȃ�



}

void TitleSelect::Update()
{
	//�{�^���@or �}�E�X�H�H

	//���́Aspace�����ΑJ�ڂ��邱����{�^�����}�E�X�Ɂ@�Ȃ���Ώ������
	//+�� �����������΃{�^���̐F���ς��
	//�X�^�[�g
	if (Input::IsKeyDown(DIK_S)){
		SceneManager* pSM = (SceneManager*)FindObject("SceneManager");
		pSM->ChangeScene(SCENE_ID_PLAY);
	}
	//�����I����������
	if (Input::IsKeyDown(DIK_E)) {
		
	}
}

void TitleSelect::Draw()
{

}

void TitleSelect::Release()
{
}
