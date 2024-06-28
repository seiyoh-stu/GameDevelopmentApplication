#pragma once

#include"../Utility/Vector2D.h"
class GameObject
{
protected:
	unsigned int color;	//箱の色
	Vector2D location;	//箱の場所
	Vector2D box_size;	//箱のサイズ
public:
	GameObject();			
	virtual ~GameObject();	

	void Initialize();		//初期化
	void Update();			//更新
	void Draw() const;		//描画
	void Finalize();		//終了

public:
	void SetLocation(Vector2D location);//場所の設定
	Vector2D GetLocation() const;		//場所の情報取得
	Vector2D GetBoxSize() const;		//箱のサイズ取得
};

