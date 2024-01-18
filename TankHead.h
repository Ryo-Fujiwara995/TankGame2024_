#pragma once
#include "Engine/GameObject.h"
class TankHead :
    public GameObject
{
private:
	int hModel_; //TankHeadのモデルを読む変数
	//モデル自体はグローバル領域に保存されている
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="parent">親のオブジェクトのポインタ</param>
	TankHead(GameObject* parent);
	~TankHead();
	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	/// <summary>
	/// モデル番号を返す関数
	/// </summary>
	/// <returns>int hModel:モデル番号</returns>
	int GetModelHandle() { return hModel_; }

	//XMFLOAT3 GetCannonTopPos() { return Model::GetBonePosition(hModel_, "CannonPos"); }
	//XMFLOAT3 GetCannonRootPos() { return Model::GetBonePosition(hModel_, "CannonRoot"); }
};

