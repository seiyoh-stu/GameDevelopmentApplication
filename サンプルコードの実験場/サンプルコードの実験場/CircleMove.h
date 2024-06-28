#pragma once

class CircleMove
{
public:

	CircleMove();
	virtual ~CircleMove();


	void Init();	// ‰Šúˆ—
	void Update();	// XVˆ—
	void Draw();	// •`‰æˆ—

private:

	void Move();	// ˆÚ“®

private:

	// À•W
	int m_posX;
	int m_posY;
};
