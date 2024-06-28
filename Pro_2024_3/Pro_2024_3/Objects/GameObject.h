#pragma once

#include"../Utility/Vector2D.h"
class GameObject
{
protected:

	Vector2D location;	//箱の場所
	Vector2D box_size;	//箱のサイズ
	int image;
	int flip_flag;

public:
	GameObject();
	virtual ~GameObject();

	virtual void Initialize();		//初期化
	virtual void Update();			//更新
	virtual void Draw() const;		//描画
	virtual void Finalize();		//終了

public:
	Vector2D GetLocation() const;		//場所の情報取得
	Vector2D GetBoxSize() const;		//箱のサイズ取得

	void SetLocation(Vector2D location);//場所の設定
};

