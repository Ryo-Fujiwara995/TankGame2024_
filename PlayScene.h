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
	//コンストラクタ
//引数：parent  親オブジェクト（SceneManager）
	PlayScene(GameObject* parent);
	~PlayScene();
	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

};

