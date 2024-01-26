#pragma once
#include "Engine/GameObject.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

class TitleSelectImage :
	public GameObject
{
private:
	int hTTitle_;//Title画面

	int hStart_;//Startボタン
	int hExit_;//Exitボタン

	
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	TitleSelectImage(GameObject* parent);
	~TitleSelectImage();
	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

};