#pragma once

#include"../GameObject.h"
#include<vector>

class Player :public GameObject

{
private:
	Vector2D velocity;						//���x�̒�`
	std::vector<int> animation_data;		//�A�j���[�V�����f�[�^
	int animation_count;					//�A�j���[�V�����̎���


public:
	Player();	//�R���X�g���N�^
	~Player();	//�f�X�g���N�^

	virtual void Initialize();	//����������
	virtual void Update();		//�X�V����
	virtual void Draw() const;	//�`�揈��
	virtual void Finalize();	//�I��������

private:
	void Movement();		//�ړ�������
	void AnimationControl();//�A�j���[�V�����̐���
};

