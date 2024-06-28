#include "Player.h"
#include"../../Utility/InputControl.h"
#include "../../Utility/UserTemplate.h"
#include "../../Utility/ResourceManager.h"
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
	box_size = Vector2D(32.0f);		//箱のサイズ
	location = Vector2D(320.0f, 240.0f);	//スタート地点

	ResourceManager* rm = ResourceManager::GetInstance();
	std::vector<int> tmp;

	tmp = rm->GetImages("Resource/images/Tri-pilot/1.png");  //画像の描画
	animation_data.push_back(tmp[0]);
	tmp = rm->GetImages("Resource/images/Tri-pilot/2.png");
	animation_data.push_back(tmp[0]);
	sound = rm->GetSound("Resource/Sounds/Evaluation/BGM_arrows.wav");//音源情報の取得



	//初期画像の設定
	image = animation_data[0];

	

	//アニメーションにかかわる設定
	animation_count = 0;
}
//更新処理
void Player::Update()
{
	Movement();

	AnimationControl();
}
//描画処理
void Player::Draw() const
{
	//親クラスに書かれた描画処理の内容を実行する
	__super::Draw();

}
//終了
void Player::Finalize()
{
	//アニメーションに使用した動的配列を開放する
	animation_data.clear();
}

//十字キー操作
void Player::Movement()
{

	//入力情報取得
	InputControl* input = InputControl::GetInstance();

	//入力情報によって、向きを変更する
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
		//左の慣性
		if (velocity.x < -1e-6f)
		{
			float calc_speed = velocity.x + 0.1;
			velocity.x = Min<float>(calc_speed, 0.0f);
		}
		//右の慣性
		else if(1e-6f < velocity.x)
		{
			float calc_speed = velocity.x - 0.1;
			velocity.x = Max<float>(calc_speed, 0.0f);
		}
	}
	//画面外に行かないようにする処理
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

//画像の描画
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
