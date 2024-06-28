#pragma once

#include"../Utility/Vector2D.h"
#include"../Utility/ResourceManager.h"
class GameObject
{
protected:
	int image;			//画像
	int sound;			//音源
	int flip_flag;
	Vector2D location;	//箱の場所
	Vector2D box_size;	//箱のサイズ
public:
	GameObject();			//コンストラクタ
	virtual ~GameObject();	//デストラクタ

	virtual void Initialize();		//初期化
	virtual void Update();			//更新
	virtual void Draw() const;		//描画
	virtual void Finalize();		//終了

public:
	Vector2D GetLocation() const;		//場所の情報取得
	Vector2D GetBoxSize() const;		//箱のサイズ取得

	void SetLocation(Vector2D location);//場所の設定

};

