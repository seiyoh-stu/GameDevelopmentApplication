#pragma once

// �}�N����`
#define D_KEYCODE_MAX 256	// �L�[�R�[�h�ő吔

// ���͐���N���X
class InputControl
{
private:
	// ���N���X�̃|�C���^�i�A�h���X��ɃC���X�^���X�𐶐�����j
	static InputControl* instance;

	// �L�[�{�[�h���͒l
	char now_key[D_KEYCODE_MAX]; // ���݂̓��͒l
	char old_key[D_KEYCODE_MAX]; // �O��̓��͒l
	
private:
	// �R���X�^���X��private�ɂ��邱�ƂŁA
	// ���N���X�̃����o�֐��ł����C���X�^���X�𐶐��ł��Ȃ��悤�ɂ���
	InputControl() = default;

	// �R�s�[�K�[�h
	// �N���X�O�ŃC���X�^���X�𐶐����ēn�����Ƃ��ł��Ȃ��悤�ɂ���
	InputControl(InputControl& v) = default;
	InputControl& operator=(const InputControl& v) = default;

public:
	~InputControl() = default;

public:
	// �C���X�^���X���擾���鏈��
	static InputControl* GetInstance();
	// �C���X�^���X���폜���鏈��
	static void DeleteInstance();

public:
	// �L�[���͍X�V����
	void Update();

	// �L�[���͏�Ԃ��擾����
	bool GetKey(int key_code) const;		// �����Ă����
	bool GetKeyDown(int key_code) const;	// �������u��
	bool GetKeyUp(int key_code) const;		// �������u��
	
private:
	// �L�[���͈͂̔͂��m�F����
	bool CheckKeyCodeRange(int key_code) const;	//�L�[�͈̔�
};