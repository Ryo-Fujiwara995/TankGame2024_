#pragma once
#include "Engine/GameObject.h"
class TitleImage :
    public GameObject
{
private:
	int hPict_;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	TitleImage(GameObject* parent);
	~TitleImage();
	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

};

