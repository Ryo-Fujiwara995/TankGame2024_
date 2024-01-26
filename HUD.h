#pragma once
#include "Engine/GameObject.h"
#include "vector"
#include "Engine/Text.h"

class HUD :
    public GameObject{
public:
	HUD(GameObject* parent);
	//�f�X�g���N�^�iRelease�����邩���ʂ��������������C++�I�Ȃ�j
	int hHUD_;//�c�聛���̉摜
	int hNumbers_;//�����̉摜
	int hKinoko_;//
	Transform tHud_;
	//Transform tKinoko_;
	std::vector<Transform> tNumbers_;
	
	~HUD();
	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

