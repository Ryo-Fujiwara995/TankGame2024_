#include "HUD.h"
#include "Engine/Image.h"
#include "PlayScene.h"

HUD::HUD(GameObject* parent)
	:GameObject(parent ,"HUD"),hHUD_(-1),hNumbers_(-1),hKinoko_(-1)
{ 
}

HUD::~HUD()
{
}

void HUD::Initialize()
{
	//画像が透け透けになるように調整?
	hHUD_ = Image::Load("zanki_3.png");
	assert(hHUD_ >= 0);
	hNumbers_ = Image::Load("nums_5.png");
	assert(hNumbers_ >= 0);
	//hKinoko_ = Image::Load("kinoko0.png");
	//assert(hKinoko_ >= 0);

}

void HUD::Update()
{
	//tHud_.scale_ = { 0.5,0.5,1.0 };
	tHud_.position_ = { -0.6,0.85,0 };
}

void HUD::Draw()
{
	Image::SetTransform(hHUD_, tHud_);
	Image::Draw(hHUD_);
	Transform trans;
	trans.scale_ = { 0.5,0.5,1.0 };
	trans.position_ = { -0.6,0.855,0 };
	Image::SetRect(hNumbers_, 51.2 * 2, 0 , 51.2, 99);
	Image::SetTransform(hNumbers_, trans);
	Image::Draw(hNumbers_);
	trans.position_ = { -0.57,0.855,0 };
	Image::SetRect(hNumbers_, 51.2 * 6, 0, 51.2, 99);
	Image::SetTransform(hNumbers_, trans);
	Image::Draw(hNumbers_);

	//残機が変わる処理
	//キノコが減ったら、残機が減る処理を書けばいい
	//for(int i =0;i<)


}

void HUD::Release()
{
}
