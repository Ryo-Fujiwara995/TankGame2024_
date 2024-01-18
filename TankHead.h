#pragma once
#include "Engine/GameObject.h"
class TankHead :
    public GameObject
{
private:
	int hModel_; //TankHead�̃��f����ǂޕϐ�
	//���f�����̂̓O���[�o���̈�ɕۑ�����Ă���
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="parent">�e�̃I�u�W�F�N�g�̃|�C���^</param>
	TankHead(GameObject* parent);
	~TankHead();
	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	/// <summary>
	/// ���f���ԍ���Ԃ��֐�
	/// </summary>
	/// <returns>int hModel:���f���ԍ�</returns>
	int GetModelHandle() { return hModel_; }

	//XMFLOAT3 GetCannonTopPos() { return Model::GetBonePosition(hModel_, "CannonPos"); }
	//XMFLOAT3 GetCannonRootPos() { return Model::GetBonePosition(hModel_, "CannonRoot"); }
};

