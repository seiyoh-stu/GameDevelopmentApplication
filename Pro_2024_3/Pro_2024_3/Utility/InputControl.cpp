#pragma once
#include "InputControl.h"
#include"DxLib.h"

//静的メンバ変数定義
InputControl* InputControl::instance = nullptr;		//クラスのインスタンスのポインタ

//入力制御クラスのインスタンス取得する処理
InputControl* InputControl::GetInstance()
{
	//インスタンスがなければ、生成する
	if (instance == nullptr)
	{
		instance = new InputControl();
	}

	//自分自身のポインタを返却する
	return instance;
}

//入力制御クラスのインスタンス削除する処理
void InputControl::DeleteInstance()
{
	//インスタンスが存在していれば、削除する
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}
void InputControl::Update()
{
	//前回の入力値を更新
	memcpy(old_key, now_key, (sizeof(char) * D_KEYCODE_MAX));
	//現在の入力値を更新
	GetHitKeyStateAll(now_key);
}

//キー取得系:押し続けているか処理
bool InputControl::GetKey(int key_code)
{
	return CheckKeyCodeRange(key_code) && ((now_key[key_code] == TRUE) && (old_key[key_code] == TRUE));
}

//キー取得系:押した瞬間
bool InputControl::GetKeyDown(int key_code)
{
	return CheckKeyCodeRange(key_code) && ((now_key[key_code] == TRUE) && (old_key[key_code] == FALSE));
}

//キー取得系:離した瞬間
bool InputControl::GetKeyUp(int key_code)
{
	return CheckKeyCodeRange(key_code) && ((now_key[key_code] == FALSE) && (old_key[key_code] == TRUE));
}

//キーコード範囲チェック
bool InputControl::CheckKeyCodeRange(int key_code)
{
	return(0 <= key_code && key_code < D_KEYCODE_MAX);
}