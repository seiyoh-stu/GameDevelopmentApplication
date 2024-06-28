#include "Player.h"
#include"../../Utility/InputControl.h"
#include "../../Utility/UserTemplate.h"
#include"../../Utility/ResourceManager.h"
#include"DxLib.h"

//�R���X�g���N�^
Player::Player():
	velocity(0.0f),
	animation_data(),
	animation_count(0)
{

}
//�f�X�g���N�^
Player::~Player()
{

}
//����������
void Player::Initialize()
{
	box_size = Vector2D(32.0f, 24.0f);		//���̃T�C�Y
	location = Vector2D(320.0f, 240.0f);	//�X�^�[�g�n�_

	//�A�j���[�V�����摜��ǂݍ���
	ResourceManager* rm = ResourceManager::GetInstance();
	
}
//�X�V����
void Player::Update()
{
	Movement();
}
//�`�揈��
void Player::Draw() const
{
	Vector2D upper_left = location - (box_size / 2.0f);
	Vector2D lower_right= location + (box_size / 2.0f);

	DrawBoxAA(upper_left.x, upper_left.y, lower_right.x, lower_right.y, color, TRUE);


}
//�I��
void Player::Finalize()
{

}

//�\���L�[����
void Player::Movement()
{
	Vector2D direction = Vector2D(0.0f);

	if (InputControl::GetKey(KEY_INPUT_LEFT))
	{
		//���ֈړ�����
		direction.x = -0.5f;
		float max_speed = Abs<float>((5.0f * direction.x));
		velocity.x += direction.x;
		velocity.x = Min<float>(Max<float>(velocity.x, -max_speed), max_speed);
	}
	else if (InputControl::GetKey(KEY_INPUT_RIGHT))
	{
		//�E�ֈړ�����
		direction.x = 0.5f;
		float max_speed = Abs<float>((5.0f * direction.x));
		velocity.x += direction.x;
		velocity.x = Min<float>(Max<float>(velocity.x, -max_speed), max_speed);
	}
	else
	{
		//�������Ď~�߂�
		if (velocity.x > 1e-6f)
		{
			float calc_speed = velocity.x - 0.1f;
			velocity.x = Min<float>(Max<float>(calc_speed, 0.0f), velocity.x);
		}
		else if(velocity.x < -1e-6f)
		{
			float calc_speed = velocity.x + 0.1f;
			velocity.x = Min<float>(Max<float>(calc_speed, velocity.x), 0.0f);
		}
	}
	//�ꏊ��velocity�ŏ㏑������
	if (location.x < (box_size.x / 2.0f))
	{
		velocity.x = 0.0f;
		location.x = box_size.x / 2.0f;
	}
	else if (location.x > (640.0f - box_size.x / 2.0f))
	{
		velocity.x = 0.0f;
		location.x = 640.0f - box_size.x / 2.0f;
	}
	location += velocity;
}
