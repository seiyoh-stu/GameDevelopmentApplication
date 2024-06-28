#pragma once

#define D_KEYCODE_MAX (256)

class InputControl
{
private:
	//���N���X�̃|�C���^�i�A�h���X�̐�ɃC���X�^���X�𐶐�����j
	static InputControl* instance;

	//�L�[�{�[�h���͒l
	static char now_key[D_KEYCODE_MAX];
	static char old_key[D_KEYCODE_MAX];

private:
	//���񂷂Ƃ炭����private�ɂ��邱�Ƃ�
	//�����N���X�̃����o�֐��ł����C���X�^���X�𐶐��ł��Ȃ��悤�ɂ���
	InputControl() = default;

	//�R�s�[�K�[�h
	//�N���X�O�ŃC���X�^���X�𐶐����ēn�����Ƃ��ł��Ȃ��悤�ɂ���
	InputControl(InputControl& v) = delete;
	InputControl& operator=(const InputControl& v) = delete;
	//�`�R�s�[�K�[�h

public:
	~InputControl() = default;

public:
	//�C���X�^���X�擾���鏈��
	static InputControl* GetInstance();
	//�C���X�^���X�폜���鏈��
	static void DeleteInstance();

public:
	static void Update();				//�X�V

	static bool GetKey(int key_code);		//�L�[���̎擾
	static bool GetKeyDown(int key_code);	//�L�[�������ꂽ�u��
	static bool GetKeyUp(int key_code);		//�L�[�������ꂽ�u��

private:
	static bool CheckKeyCodeRange(int key_code);//�L�[�͈̔̓`�F�b�N
};