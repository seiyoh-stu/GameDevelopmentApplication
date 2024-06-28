#pragma once

#define D_KEYCODE_MAX (256)
#define D_BUTTON_MAX (16)

class InputControl
{
private:
	//���N���X�̃|�C���^�i�A�h���X�̐�ɃC���X�^���X�𐶐�����j
	static InputControl* instance;

	//�L�[�{�[�h���͒l
	char now_key[D_KEYCODE_MAX];
	char old_key[D_KEYCODE_MAX];

	//�p�b�h���͒l
	char now_button[D_BUTTON_MAX];
	char old_button[D_BUTTON_MAX];

private:
	//�R���X�g���N�^��private�ɂ��邱�Ƃ�
	//���N���X�̃����o�֐��ł����C���X�^���X�𐶐��ł��Ȃ��悤�ɂ���
	InputControl() = default;

	//�R�s�[�K�[�h
	//�N���X�O�ŃC���X�^���X�𐶐����ēn�����Ƃ��ł��Ȃ��悤�ɂ���
	InputControl(InputControl& v) = delete;
	InputControl& operator=(const InputControl& v) = delete;
	//~�R�s�[�K�[�h

public:
	~InputControl() = default;

public:
	//�C���X�^���X�擾���鏈��
	static InputControl* GetInstance();
	//�C���X�^���X�폜���鏈��
	static void DeleteInstance();

	 void Update();				//�X�V

	 bool GetKey(int key_code)const;		//�L�[���̎擾
	 bool GetKeyDown(int key_code)const;	//�L�[�������ꂽ�u��
	 bool GetKeyUp(int key_code)const;		//�L�[�������ꂽ�u��

	 bool GetButton(int button)const;		//�p�b�h���̎擾
	 bool GetButtonDown(int button)const;	//�p�b�h�������ꂽ�u��
	 bool GetButtonUp(int button)const;		//�p�b�h�������ꂽ�u��

private:
	 bool CheckKeyCodeRange(int key_code)const;//�L�[�͈̔̓`�F�b�N

	 bool CheckButtonCodeRange(int button)const;
};