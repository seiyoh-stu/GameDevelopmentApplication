#pragma once
#include "InputControl.h"
#include"DxLib.h"

//�ÓI�����o�ϐ���`
InputControl* InputControl::instance = nullptr;		//�N���X�̃C���X�^���X�̃|�C���^

//���͐���N���X�̃C���X�^���X�擾���鏈��
InputControl* InputControl::GetInstance()
{
	//�C���X�^���X���Ȃ���΁A��������
	if (instance == nullptr)
	{
		instance = new InputControl();
	}

	//�������g�̃|�C���^��ԋp����
	return instance;
}

//���͐���N���X�̃C���X�^���X�폜���鏈��
void InputControl::DeleteInstance()
{
	//�C���X�^���X�����݂��Ă���΁A�폜����
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}
void InputControl::Update()
{
	//�O��̓��͒l���X�V
	memcpy(old_key, now_key, (sizeof(char) * D_KEYCODE_MAX));
	//���݂̓��͒l���X�V
	GetHitKeyStateAll(now_key);
}

//�L�[�擾�n:���������Ă��邩����
bool InputControl::GetKey(int key_code)
{
	return CheckKeyCodeRange(key_code) && ((now_key[key_code] == TRUE) && (old_key[key_code] == TRUE));
}

//�L�[�擾�n:�������u��
bool InputControl::GetKeyDown(int key_code)
{
	return CheckKeyCodeRange(key_code) && ((now_key[key_code] == TRUE) && (old_key[key_code] == FALSE));
}

//�L�[�擾�n:�������u��
bool InputControl::GetKeyUp(int key_code)
{
	return CheckKeyCodeRange(key_code) && ((now_key[key_code] == FALSE) && (old_key[key_code] == TRUE));
}

//�L�[�R�[�h�͈̓`�F�b�N
bool InputControl::CheckKeyCodeRange(int key_code)
{
	return(0 <= key_code && key_code < D_KEYCODE_MAX);
}