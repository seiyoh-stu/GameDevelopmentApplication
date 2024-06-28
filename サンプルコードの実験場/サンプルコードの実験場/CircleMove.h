#pragma once

class CircleMove
{
public:

	CircleMove();
	virtual ~CircleMove();


	void Init();	// 初期処理
	void Update();	// 更新処理
	void Draw();	// 描画処理

private:

	void Move();	// 移動

private:

	// 座標
	int m_posX;
	int m_posY;
};
