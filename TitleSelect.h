#pragma once
#include "Engine/GameObject.h"
class TitleSelect :
	public GameObject
{
private:
	int hSSelect_;//hStart_�̕ω���̃{�^��
	int hESelect_;//hExit_�̕ω���̃{�^��
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	TitleSelect(GameObject* parent);
	~TitleSelect();
	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

};

