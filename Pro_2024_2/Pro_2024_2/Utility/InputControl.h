#pragma once

#define D_KEYCODE_MAX (256)

class InputControl
{
private:
	static char now_key[D_KEYCODE_MAX];
	static char old_key[D_KEYCODE_MAX];

public:
	static void Update();				//更新

	static bool GetKey(int key_code);		//キー情報の取得
	static bool GetKeyDown(int key_code);	//キーが押された瞬間
	static bool GetKeyUp(int key_code);		//キーが離された瞬間

private:
	static bool CheckKeyCodeRange(int key_code);//キーの範囲チェック
};