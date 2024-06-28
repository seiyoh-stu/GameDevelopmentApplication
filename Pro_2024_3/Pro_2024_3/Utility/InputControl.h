#pragma once

#define D_KEYCODE_MAX (256)

class InputControl
{
private:
	//自クラスのポインタ（アドレスの先にインスタンスを生成する）
	static InputControl* instance;

	//キーボード入力値
	static char now_key[D_KEYCODE_MAX];
	static char old_key[D_KEYCODE_MAX];

private:
	//こんすとらくたをprivateにすることで
	//自分クラスのメンバ関数でしたインスタンスを生成できないようにする
	InputControl() = default;

	//コピーガード
	//クラス外でインスタンスを生成して渡すことができないようにする
	InputControl(InputControl& v) = delete;
	InputControl& operator=(const InputControl& v) = delete;
	//～コピーガード

public:
	~InputControl() = default;

public:
	//インスタンス取得する処理
	static InputControl* GetInstance();
	//インスタンス削除する処理
	static void DeleteInstance();

public:
	static void Update();				//更新

	static bool GetKey(int key_code);		//キー情報の取得
	static bool GetKeyDown(int key_code);	//キーが押された瞬間
	static bool GetKeyUp(int key_code);		//キーが離された瞬間

private:
	static bool CheckKeyCodeRange(int key_code);//キーの範囲チェック
};