#include "DxLib.h"
#include"Utility/InputControl.h"
#include"Objects/GameObject.h"
#include"Objects/Player.h"


int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPreInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	//ウィンドウモードで起動
	ChangeWindowMode(TRUE);


	//Dxライブライの初期化処理
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	SetDrawScreen(DX_SCREEN_BACK);

	GameObject* object1 = new GameObject();	//敵のオブジェクト
	Player* object2 = new Player();			//操作オブジェクト

	object1->Initialize();	//箱の初期化
	object2->Initialize();	//箱の初期化

	while (ProcessMessage() != -1 && InputControl::GetKeyUp(KEY_INPUT_ESCAPE) == false)
	{
		InputControl::Update();	//更新

		object1->Update();		//敵オブジェクトの更新
		object2->Update();		//操作オブジェクトの更新

		ClearDrawScreen();		//ゲーム画面の反映

		object1->Draw();		//敵オブジェクトの描画
		object2->Draw();		//操作オブジェクトの描画

		ScreenFlip();			//オブジェクトを動かす
	}

	delete object1; //箱の削除
	delete object2; //箱の削除


	//Dxライブライ使用の終了方法
	DxLib_End();


	return 0;

}