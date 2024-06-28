#include "DxLib.h"
#include"Utility/InputControl.h"
#include"Objects/Player/Player.h"
#include"Utility/ResourceManager.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, 
	_In_opt_ HINSTANCE hPreInstance,
	_In_ LPSTR lpCmdLine, 
	_In_ int nShowCmd)
{
	//ウィンドウモードで起動
	ChangeWindowMode(TRUE);

	//windowサイズの設定
	SetGraphMode(640,480,32);

	//Dxライブライの初期化処理
	if (DxLib_Init() == -1)
	{
		OutputDebugString("DXライブラリが初期化できませんでした。\n");
		return -1;
	}

	//描画先を裏画面に設定
	SetDrawScreen(DX_SCREEN_BACK);

	GameObject* objects = nullptr;
	ResourceManager* rm = ResourceManager::GetInstance();
	int result = 0;

	try
	{
		//プレイヤーの生成
		object = new Player();

		//オブジェクトの初期化
		object->Initialize();

		//メインループ
		while (ProcessMessage() != -1)
		{
			//入力情報のインスタンスを取得
			InputControl* input = InputControl::GetInstance();

			//入力情報の更新
			input->Update();

			//オブジェクトの更新処理
			object->Update();

			//画面の初期化
			ClearDrawScreen();

			//オブジェクトの描画処理
			object->Draw();
			//裏画面の内容を表画面に反映する
			ScreenFlip();

			//ESCキーが入力されたら、ループを終了する
			if (input->GetKeyUp(KEY_INPUT_ESCAPE))
			{
				break;
			}
		}
	}
	catch (std::string error_log)
	{
		//Log.txtにエラー内容を出力する
		OutputDebugString(error_log.c_str());
		//終了状態を以上に設定する
		result = -1;
	}

	//オブジェクトの削除
	if (object != nullptr)
	{
		object->Finalize();
		delete object;
		object = nullptr;
	}

	//入力機能のインスタンスを削除する
	InputControl::DeleteInstance();

	//読み込んだ画像の開放
	rm->DeleteImages();
	//リソース管理のインスタンスを削除する

	//Dxライブライ使用の終了方法
	DxLib_End();

	//終了状態の値を返却する
	return result;

}