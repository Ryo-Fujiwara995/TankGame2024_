#pragma once
#include "Engine/GameObject.h"
#include "Engine/SphereCollider.h"


class Enemy :
    public GameObject
{
	int hModel_;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Enemy(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	//何かに当たった
	//引数：Bullet 当たった相手
	void OnCollision(GameObject* pTarget) override;
};

