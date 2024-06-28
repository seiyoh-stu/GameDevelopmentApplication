#pragma once

// マクロ定義
#define D_KEYCODE_MAX 256	// キーコード最大数

// 入力制御クラス
class InputControl
{
private:
	// 自クラスのポインタ（アドレス先にインスタンスを生成する）
	static InputControl* instance;

	// キーボード入力値
	char now_key[D_KEYCODE_MAX]; // 現在の入力値
	char old_key[D_KEYCODE_MAX]; // 前回の入力値
	
private:
	// コンスタンスをprivateにすることで、
	// 自クラスのメンバ関数でしかインスタンスを生成できないようにする
	InputControl() = default;

	// コピーガード
	// クラス外でインスタンスを生成して渡すことができないようにする
	InputControl(InputControl& v) = default;
	InputControl& operator=(const InputControl& v) = default;

public:
	~InputControl() = default;

public:
	// インスタンスを取得する処理
	static InputControl* GetInstance();
	// インスタンスを削除する処理
	static void DeleteInstance();

public:
	// キー入力更新処理
	void Update();

	// キー入力状態を取得する
	bool GetKey(int key_code) const;		// 押している間
	bool GetKeyDown(int key_code) const;	// 押した瞬間
	bool GetKeyUp(int key_code) const;		// 離した瞬間
	
private:
	// キー入力の範囲を確認する
	bool CheckKeyCodeRange(int key_code) const;	//キーの範囲
};