#pragma once
#include "Engine/GameObject.h"
#include "vector"
#include "Engine/Text.h"

class HUD :
    public GameObject{
public:
	HUD(GameObject* parent);
	//デストラクタ（Releaseもあるから区別が難しいがこっちはC++的なやつ）
	int hHUD_;//残り○○の画像
	int hNumbers_;//数字の画像
	int hKinoko_;//
	Transform tHud_;
	//Transform tKinoko_;
	std::vector<Transform> tNumbers_;
	
	~HUD();
	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};

