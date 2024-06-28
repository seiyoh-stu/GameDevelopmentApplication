#include "GameObject.h"
#include"../Utility/ResourceManager.h"
#include"../Objects/Player/Player.h"
#include "DxLib.h"

//コンストラクタ
GameObject::GameObject() :
	image(NULL),
	location(0.0f),
	box_size(0.0f),
	flip_flag(FALSE),
	sound(NULL)
{

}
//デストラクタ
GameObject::~GameObject()
{

}

//初期化処理
void GameObject::Initialize()
{
	image = NULL;		//画像

	sound = NULL;

	box_size = Vector2D(32.0f);	//箱のサイズ

	location = box_size;	//始まりの場所
}

//更新処理
void GameObject::Update()
{
	
}

//描画処理
void GameObject::Draw() const
{

	PlaySoundMem(sound, DX_PLAYTYPE_BACK, FALSE);

	DrawRotaGraphF(location.x, location.y, 1.0, 0.0, image, TRUE,flip_flag);

	Vector2D upper_left = location - (box_size / 2.0f);
	Vector2D lower_right = location + (box_size / 2.0f);

	DrawBoxAA(upper_left.x, upper_left.y, lower_right.x, lower_right.y,
		GetColor(255, 0, 0), FALSE);
}

//終了時処理
void GameObject::Finalize()
{

}

Vector2D GameObject::GetLocation() const
{
	return this->location;
}

Vector2D GameObject::GetBoxSize() const
{
	return this->box_size;
}

void GameObject::SetLocation(Vector2D location)
{
	this->location = location;
}