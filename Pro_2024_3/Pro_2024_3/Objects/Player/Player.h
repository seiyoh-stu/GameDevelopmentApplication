#pragma once

#include"../GameObject.h"
#include<vector>

class Player :public GameObject

{
private:
	Vector2D velocity;						//速度の定義
	std::vector<int> animation_data;		//アニメーションデータ
	int animation_count;					//アニメーションの時間


public:
	Player();	//コンストラクタ
	~Player();	//デストラクタ

	virtual void Initialize();	//初期化処理
	virtual void Update();		//更新処理
	virtual void Draw() const;	//描画処理
	virtual void Finalize();	//終了時処理

private:
	void Movement();		//移動時処理
	void AnimationControl();//アニメーションの制御
};

