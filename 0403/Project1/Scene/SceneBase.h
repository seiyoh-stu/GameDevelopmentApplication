#pragma once

enum eSceneType
{
	eTitle,
	eInGame,
	eResult,
	eEnd,
};

class SceneBase
{
protected:
	//�S�V�[���ŏ��L���郁���o�ϐ���錾

public:
	SceneBase(){}
	virtual ~SceneBase(){}

	//����������
	virtual void Initialize(){}

	/**********************************
	* �X�V����
	* �����F1�t���[��������̎���
	* �߂�l�G���̃V�[���̃^�C�v
	***********************************/

	virtual eSceneType Update()
	{
		return GetNowSceneType();
	}

	//�`�揈��
	virtual void Draw() const{}

	//�I��������
	virtual void Finalize(){}

	//���݂̃V�[���^�C�v�i�I�[�o�[���C�h�K�{�j
	virtual eSceneType GetNowSceneType() const = 0;
};