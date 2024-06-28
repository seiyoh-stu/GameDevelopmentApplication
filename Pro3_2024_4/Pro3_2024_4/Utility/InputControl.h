#pragma once

#define D_KEYCODE_MAX (256)
#define D_BUTTON_MAX (16)

class InputControl
{
private:
	//字クラスのポインタ（アドレスの先にインスタンスを生成する）
	static InputControl* instance;

	//キーボード入力値
	char now_key[D_KEYCODE_MAX];
	char old_key[D_KEYCODE_MAX];

	//パッド入力値
	char now_button[D_BUTTON_MAX];
	char old_button[D_BUTTON_MAX];

private:
	//コンストラクタをprivateにすることで
	//字クラスのメンバ関数でしかインスタンスを生成できないようにする
	InputControl() = default;

	//コピーガード
	//クラス外でインスタンスを生成して渡すことができないようにする
	InputControl(InputControl& v) = delete;
	InputControl& operator=(const InputControl& v) = delete;
	//~コピーガード

public:
	~InputControl() = default;

public:
	//インスタンス取得する処理
	static InputControl* GetInstance();
	//インスタンス削除する処理
	static void DeleteInstance();

	 void Update();				//更新

	 bool GetKey(int key_code)const;		//キー情報の取得
	 bool GetKeyDown(int key_code)const;	//キーが押された瞬間
	 bool GetKeyUp(int key_code)const;		//キーが離された瞬間

	 bool GetButton(int button)const;		//パッド情報の取得
	 bool GetButtonDown(int button)const;	//パッドが押された瞬間
	 bool GetButtonUp(int button)const;		//パッドが離された瞬間

private:
	 bool CheckKeyCodeRange(int key_code)const;//キーの範囲チェック

	 bool CheckButtonCodeRange(int button)const;
};