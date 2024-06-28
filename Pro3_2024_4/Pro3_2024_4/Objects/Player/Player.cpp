#include "Player.h"
#include"../../Utility/InputControl.h"
#include "../../Utility/UserTemplate.h"
#include "../../Utility/ResourceManager.h"
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
	box_size = Vector2D(32.0f);		//���̃T�C�Y
	location = Vector2D(320.0f, 240.0f);	//�X�^�[�g�n�_

	ResourceManager* rm = ResourceManager::GetInstance();
	std::vector<int> tmp;

	tmp = rm->GetImages("Resource/images/Tri-pilot/1.png");  //�摜�̕`��
	animation_data.push_back(tmp[0]);
	tmp = rm->GetImages("Resource/images/Tri-pilot/2.png");
	animation_data.push_back(tmp[0]);
	sound = rm->GetSound("Resource/Sounds/Evaluation/BGM_arrows.wav");//�������̎擾



	//�����摜�̐ݒ�
	image = animation_data[0];

	

	//�A�j���[�V�����ɂ������ݒ�
	animation_count = 0;
}
//�X�V����
void Player::Update()
{
	Movement();

	AnimationControl();
}
//�`�揈��
void Player::Draw() const
{
	//�e�N���X�ɏ����ꂽ�`�揈���̓��e�����s����
	__super::Draw();

}
//�I��
void Player::Finalize()
{
	//�A�j���[�V�����Ɏg�p�������I�z����J������
	animation_data.clear();
}

//�\���L�[����
void Player::Movement()
{

	//���͏��擾
	InputControl* input = InputControl::GetInstance();

	//���͏��ɂ���āA������ύX����
;	float direction = 0.0f;
	if (input->GetKey(KEY_INPUT_LEFT))
	{
		direction = -1.0f;
		flip_flag = TRUE;
	}
	else if (input->GetKey(KEY_INPUT_RIGHT))
	{
		direction = 1.0f;
		flip_flag = FALSE;
	}

	if (input->GetButton(KEY_INPUT_LEFT))
	{
		direction = -1.0f;
		flip_flag = TRUE;
	}
	else if (input->GetButton(KEY_INPUT_RIGHT))
	{
		direction = 1.0f;
			flip_flag = FALSE;
	}
		
	if (direction != 0.0f)
	{
		float max_speed = Abs<float>((5.0f * 0.5 * direction));
		velocity.x += 0.5 * direction;
		velocity.x = Min<float>(Max<float>(velocity.x, -max_speed), max_speed);
	}
	else
	{
		//���̊���
		if (velocity.x < -1e-6f)
		{
			float calc_speed = velocity.x + 0.1;
			velocity.x = Min<float>(calc_speed, 0.0f);
		}
		//�E�̊���
		else if(1e-6f < velocity.x)
		{
			float calc_speed = velocity.x - 0.1;
			velocity.x = Max<float>(calc_speed, 0.0f);
		}
	}
	//��ʊO�ɍs���Ȃ��悤�ɂ��鏈��
	if (location.x < (box_size.x / 2.0f))
	{
		velocity.x = 0.0f;
		location.x = box_size.x / 2.0f;
	}
	else if ((640.0f - (box_size.x / 2.0f)) < location.x)
	{
		velocity.x = 0.0f;
		location.x = 640.0f - (box_size.x / 2.0f);
	}
	location += velocity;
}

//�摜�̕`��
void Player::AnimationControl()
{
	animation_count++;

	if (animation_count >= 30)
	{
		animation_count = 0;

		if (image == animation_data[0])
		{
			image = animation_data[1];
		}
		else
		{
			image = animation_data[0];
		}
	}
}
