#include "Pad.h"
#include <DxLib.h>
// この上のincludeがないとコントローラーが動きません
#include "CircleMove.h"

namespace
{
	// 円の半径サイズ
	constexpr int kRadiusScale = 32;

	// 移動量
	constexpr int kMoveDistance = 8;

	// 円のカラーコード(赤)
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
	// 座標初期化
	m_posX = 0;
	m_posY = 0;
}

void CircleMove::Update()
{
	// パッドのアップデート処理
	Pad::Update();

	// 移動
	Move();
}

void CircleMove::Draw()
{
	// 座標の表示
	DrawFormatString(0, 0, 0xffffff, "m_posX : %d m_posY : %d", m_posX, m_posY);

	// 円の描画
	DrawCircle(m_posX, m_posY, kRadiusScale, kColor, true);
}

void CircleMove::Move()
{

	// パットで操作


	if (Pad::IsPress(PAD_INPUT_UP))			// 上入力
	{
		// 上に進む
		m_posY -= kMoveDistance;
	}
	else if (Pad::IsPress(PAD_INPUT_DOWN))	// 下入力
	{
		// 下に進む
		m_posY += kMoveDistance;
	}
	else if (Pad::IsPress(PAD_INPUT_LEFT))	// 左入力
	{
		// 左に進む
		m_posX -= kMoveDistance;
	}
	else if (Pad::IsPress(PAD_INPUT_RIGHT))	// 右入力
	{
		// 右に進む
		m_posX += kMoveDistance;
	}

}