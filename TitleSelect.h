#pragma once
#include "Engine/GameObject.h"
class TitleSelect :
	public GameObject
{
private:
	int hSSelect_;//hStart_の変化後のボタン
	int hESelect_;//hExit_の変化後のボタン
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	TitleSelect(GameObject* parent);
	~TitleSelect();
	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

};

