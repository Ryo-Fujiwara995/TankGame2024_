#pragma once
#include "Engine/GameObject.h"
class Ground :
    public GameObject
{

	int hModel_; //�n�ʂ̃��f����ǂނ��߂̃��f���ԍ��i���f���̃n���h���j
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Ground(GameObject* parent);
	~Ground();

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	int GetModelHandle() { return(hModel_); }
};

