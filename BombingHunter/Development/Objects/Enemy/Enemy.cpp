#include "Enemy.h"
#include"../../Utility/Inputcontrol.h"
#include"DxLib.h"
#include"../../Objects/Player/Player.h"
#include"../../Objects/Bullet/Bullet.h"
//#include<math.h>



//�R���X�g���N�^
Enemy::Enemy() : animation_count(0),direction(0.0f)
{
	animation[0] = NULL;
	animation[1] = NULL;
}

//�f�X�g���N�^
Enemy::~Enemy()
{

}

//����������
void Enemy::Initialize()
{
	//�摜�̓ǂݍ���
	animation[0] = LoadGraph("Resouce/Images/BoxEnemy/1.png");
	animation[1] = LoadGraph("Resouce/Images/BoxEnemy/2.png");

	//�G���[�`�F�b�N
	if (animation[0] == -1 || animation[1] == -1)
	{
		throw("�G�摜���\������܂���ł����B\n");
	}

	//�����̐ݒ�
	radian = 0.0;

	//�����蔻��̑傫����ݒ�
	box_size = 64.0f;
	//scale��box_size�ɕς�����

	//�����摜�̐ݒ�
	image = animation[0];

	//�����i�s�����̐ݒ�
	direction = Vector2D(3.0f, 0.0f);
}

//�X�V����
void Enemy::Update()
{
	//�ړ�����
	Movement();

	//�A�j���[�V��������
	AnimeControl();
}

//�`�揈��
void Enemy::Draw() const
{
	//�摜���]�t���O
	int flip_flag = FALSE;

	//�i�s�����ɂ���āA���]��Ԃ����肷��
	if (direction.x > 0.0f)
	{
		flip_flag = FALSE;
	}
	else
	{
		flip_flag = TRUE;
	}

	//�������Ƃɔ��I�摜��`�悷��
	DrawRotaGraphF(location.x, location.y, 1.0, radian, image, TRUE, flip_flag);

	//�e�N���X�̕`�揈�����Ăяo��
	__super::Draw();
}

//�I��������
void Enemy::Finalize()
{
	//�g�p�����摜���J������
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
}

//�����蔻��ʒm����
void Enemy::OnHitCollision(GameObject* hit_object)
{
	////�����������̏���
	direction = 0.0f;
}

//�ړ�����
void Enemy::Movement()
{

	//���ʒp�ɓ��B������A�i�s�����𔽓]����
	if (((location.x + direction.x) < box_size.x) 
		|| (640.0f - box_size.x) < (location.x + direction.x))
	{
		direction.x *= -1.0f;
	}

	if (((location.y + direction.y) < box_size.y) 
		|| (480.0f - box_size.y) < (location.y + direction.y))
	{
		direction.y *= -1.0f;
	}

	//�i�s�Ɍ������āA�ʒu����ύX����
	location += direction;
}

//�A�j���[�V��������
void Enemy::AnimeControl()
{

	//�t���[���J�E���g�����Z����
	animation_count++;

	//60�t���[���ڂɓ��B������
	if (animation_count >= 60)
	{
		//�J�E���g�̃��Z�b�g
		animation_count = 0;

		//�摜�̐؂�ւ�
		if (image == animation[0])
		{
			image = animation[1];
		}
		else
		{
			image = animation[0];
		}
	}
}