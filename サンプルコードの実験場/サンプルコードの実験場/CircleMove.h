#pragma once

class CircleMove
{
public:

	CircleMove();
	virtual ~CircleMove();


	void Init();	// ��������
	void Update();	// �X�V����
	void Draw();	// �`�揈��

private:

	void Move();	// �ړ�

private:

	// ���W
	int m_posX;
	int m_posY;
};
