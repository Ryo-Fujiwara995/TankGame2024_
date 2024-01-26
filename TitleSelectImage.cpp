#include "TitleSelectImage.h"
#include "Engine/Image.h"


TitleSelectImage::TitleSelectImage(GameObject* parent)
	:GameObject(parent, "TitleImage"),hTTitle_(-1) ,hStart_(-1), hExit_(-1)
{
}

TitleSelectImage::~TitleSelectImage()
{
}

void TitleSelectImage::Initialize()
{
	//�w�i�̕\��
	hTTitle_ = Image::Load("TankTitle.png");
	assert(hTTitle_ >= 0);
	//Start�{�^���̕\��
	hStart_ = Image::Load("Start2.png");
	assert(hStart_ >= 0);
	//Exit�{�^���̕\��
	hExit_ = Image::Load("Exit.png");
	assert(hExit_ >= 0);
}	

void TitleSelectImage::Update()
{
}

void TitleSelectImage::Draw(){
	//�w�i�̕\��
	int Width = 1280;
	int Height = 720;
	Image::SetTransform(hTTitle_, transform_);
	Image::Draw(hTTitle_);
	////Start�{�^���̕\��
	Image::SetTransform(hStart_, transform_);
	Image::Draw(hStart_);
	//Draw(30, 30, "Yahoo!");
	////Exit�{�^���̕\��
	//Image::SetTransform(hTTitle_, transform_);
	//Image::Draw(hExit_);
}

void TitleSelectImage::Release()
{
}
