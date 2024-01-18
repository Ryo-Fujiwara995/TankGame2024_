#pragma once
#include "Engine/GameObject.h"
class TitleImage :
    public GameObject
{
private:
	int hPict_;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	TitleImage(GameObject* parent);
	~TitleImage();
	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

};

