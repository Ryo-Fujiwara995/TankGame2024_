#pragma once
#include "Engine/GameObject.h"

class Text;
class Tank;

class PlayScene :
    public GameObject
{
	Text* pText;
	Tank* player;
	int enemyNum;
public:
	//�R���X�g���N�^
//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	PlayScene(GameObject* parent);
	~PlayScene();
	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

};

