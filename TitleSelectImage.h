#pragma once
#include "Engine/GameObject.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

class TitleSelectImage :
	public GameObject
{
private:
	int hTTitle_;//Title���

	int hStart_;//Start�{�^��
	int hExit_;//Exit�{�^��

	
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	TitleSelectImage(GameObject* parent);
	~TitleSelectImage();
	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

};