#pragma once
#include "InputControl.h"
#include "DxLib.h"

//静的メンバ変数定義
InputControl* InputControl::instance = nullptr;//クラスのインスタンスのポインタ

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
	//前回入力値の更新
	memcpy(old_key, now_key, (sizeof(char) * D_KEYCODE_MAX));
	memcpy(old_button, now_button, (sizeof(char) * D_BUTTON_MAX));
	

	//現在入力値の更新
	GetHitKeyStateAll(now_key);
	XINPUT_STATE input_state{};
	GetJoypadXInputState(DX_INPUT_PAD1,&input_state);
}

//キーが押されているか確認する処理
bool InputControl::GetKey(int key_code) const
{
	return(CheckKeyCodeRange(key_code) && (now_key[key_code] == TRUE && old_key[key_code] == TRUE));
}
//キーが離された瞬間か確認する
bool InputControl::GetKeyUp(int key_code) const
{
	return(CheckKeyCodeRange(key_code) && (now_key[key_code] == FALSE && old_key[key_code] == TRUE));
}
//キーが押された瞬間か確認する処理
bool InputControl::GetKeyDown(int key_code) const
{
	return(CheckKeyCodeRange(key_code) && (now_key[key_code] == TRUE && old_key[key_code] == FALSE));
}
//キーコードの範囲内か確認する処理
bool InputControl::CheckKeyCodeRange(int key_code) const
{
	return(0 <= key_code && key_code < D_KEYCODE_MAX);
}

/*
pad入力制御
*/
//キーが押されているか確認する処理
bool InputControl::GetButton(int button)const
{
	return(CheckKeyCodeRange(button) && (now_button[button] == TRUE && old_button[button] == TRUE));
}
//キーが離された瞬間か確認する
bool InputControl::GetButtonUp(int button) const
{
	return(CheckKeyCodeRange(button) && (now_button[button] == FALSE && old_button[button] == TRUE));
}
//キーが押された瞬間か確認する処理
bool InputControl::GetButtonDown(int button) const
{
	return(CheckKeyCodeRange(button) && (now_button[button] == TRUE && old_button[button] == FALSE));
}
//キーコードの範囲内か確認する処理
bool InputControl::CheckButtonCodeRange(int button) const
{
	return(0 <= button && button < D_BUTTON_MAX);
}