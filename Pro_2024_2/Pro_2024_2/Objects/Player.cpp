#include "Player.h"
#include"../Utility/InputControl.h"
#include"DxLib.h"

//�R���X�g���N�^
Player::Player()
{

}
//�f�X�g���N�^
Player::~Player()
{

}
//����������
void Player::Initialize()
{
	location = Vector2D(320.0f, 240.0f);	//�X�^�[�g�n�_
	box_size = Vector2D(32.0f, 24.0f);		//���̃T�C�Y
	color = GetColor(255, 0, 0);			//���̐F
}
//�X�V����
void Player::Update()
{
	Movement();
}
//�`�揈��
void Player::Draw() const
{
	Vector2D tl = this->location - (this->box_size / 2.0f);
	Vector2D br = this->location + (this->box_size / 2.0f);

	DrawBoxAA(tl.x, tl.y, br.x, br.y, color, TRUE);


}
//�I��
void Player::Finalize()
{

}

//�\���L�[����
void Player::Movement()
{
	Vector2D direction = Vector2D(0.0f);

	if (InputControl::GetKey(KEY_INPUT_UP))
	{
		direction.y = -1.0f;
	}
	if (InputControl::GetKey(KEY_INPUT_DOWN))
	{
		direction.y = 1.0f;
	}
	if (InputControl::GetKey(KEY_INPUT_RIGHT))
	{
		direction.x = 1.0f;
	}
	if (InputControl::GetKey(KEY_INPUT_LEFT))
	{
		direction.x = -1.0f;
	}

	location += direction;
}
