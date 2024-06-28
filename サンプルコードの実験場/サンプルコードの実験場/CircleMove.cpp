#include "Pad.h"
#include <DxLib.h>
// ���̏��include���Ȃ��ƃR���g���[���[�������܂���
#include "CircleMove.h"

namespace
{
	// �~�̔��a�T�C�Y
	constexpr int kRadiusScale = 32;

	// �ړ���
	constexpr int kMoveDistance = 8;

	// �~�̃J���[�R�[�h(��)
	constexpr int kColor = 0xff0000;
}

CircleMove::CircleMove():
	m_posX(),
	m_posY()
{
}

CircleMove::~CircleMove()
{
}

void CircleMove::Init()
{
	// ���W������
	m_posX = 0;
	m_posY = 0;
}

void CircleMove::Update()
{
	// �p�b�h�̃A�b�v�f�[�g����
	Pad::Update();

	// �ړ�
	Move();
}

void CircleMove::Draw()
{
	// ���W�̕\��
	DrawFormatString(0, 0, 0xffffff, "m_posX : %d m_posY : %d", m_posX, m_posY);

	// �~�̕`��
	DrawCircle(m_posX, m_posY, kRadiusScale, kColor, true);
}

void CircleMove::Move()
{

	// �p�b�g�ő���


	if (Pad::IsPress(PAD_INPUT_UP))			// �����
	{
		// ��ɐi��
		m_posY -= kMoveDistance;
	}
	else if (Pad::IsPress(PAD_INPUT_DOWN))	// ������
	{
		// ���ɐi��
		m_posY += kMoveDistance;
	}
	else if (Pad::IsPress(PAD_INPUT_LEFT))	// ������
	{
		// ���ɐi��
		m_posX -= kMoveDistance;
	}
	else if (Pad::IsPress(PAD_INPUT_RIGHT))	// �E����
	{
		// �E�ɐi��
		m_posX += kMoveDistance;
	}

}