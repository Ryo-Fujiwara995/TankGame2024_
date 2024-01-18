#include "TitleImage.h"
#include "Engine/Image.h"

TitleImage::TitleImage(GameObject* parent)
	:GameObject(parent,"TitleImage"),hPict_(-1)
{
}

TitleImage::~TitleImage()
{
}

void TitleImage::Initialize()
{
	hPict_ = Image::Load("title.png");
	assert(hPict_ >= 0);
}

void TitleImage::Update()
{
}

void TitleImage::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

void TitleImage::Release()
{
}
