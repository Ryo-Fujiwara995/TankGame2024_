#pragma once
#include "Engine/GameObject.h"
#include "Engine/BoxCollider.h"

class Tank :
    public GameObject
{
	int hModel_;     //モデルのハンドル
	XMVECTOR front_; //前ベクトル z+方向　大きさ1
	float speed_;    //0.05 0.05*60 m/s
	int camState_;//カメラタイプ
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Tank(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	//何かに当たった
	//引数：Enemy 当たった相手
	void OnCollision(GameObject* pTarget) override;
};

