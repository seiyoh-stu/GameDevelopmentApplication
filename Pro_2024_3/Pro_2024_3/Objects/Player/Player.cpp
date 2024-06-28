#include "Player.h"
#include"../../Utility/InputControl.h"
#include "../../Utility/UserTemplate.h"
#include"../../Utility/ResourceManager.h"
#include"DxLib.h"

//コンストラクタ
Player::Player():
	velocity(0.0f),
	animation_data(),
	animation_count(0)
{

}
//デストラクタ
Player::~Player()
{

}
//初期化処理
void Player::Initialize()
{
	box_size = Vector2D(32.0f, 24.0f);		//箱のサイズ
	location = Vector2D(320.0f, 240.0f);	//スタート地点

	//アニメーション画像を読み込む
	ResourceManager* rm = ResourceManager::GetInstance();
	
}
//更新処理
void Player::Update()
{
	Movement();
}
//描画処理
void Player::Draw() const
{
	Vector2D upper_left = location - (box_size / 2.0f);
	Vector2D lower_right= location + (box_size / 2.0f);

	DrawBoxAA(upper_left.x, upper_left.y, lower_right.x, lower_right.y, color, TRUE);


}
//終了
void Player::Finalize()
{

}

//十字キー操作
void Player::Movement()
{
	Vector2D direction = Vector2D(0.0f);

	if (InputControl::GetKey(KEY_INPUT_LEFT))
	{
		//左へ移動する
		direction.x = -0.5f;
		float max_speed = Abs<float>((5.0f * direction.x));
		velocity.x += direction.x;
		velocity.x = Min<float>(Max<float>(velocity.x, -max_speed), max_speed);
	}
	else if (InputControl::GetKey(KEY_INPUT_RIGHT))
	{
		//右へ移動する
		direction.x = 0.5f;
		float max_speed = Abs<float>((5.0f * direction.x));
		velocity.x += direction.x;
		velocity.x = Min<float>(Max<float>(velocity.x, -max_speed), max_speed);
	}
	else
	{
		//減速して止める
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
	//場所をvelocityで上書きする
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
