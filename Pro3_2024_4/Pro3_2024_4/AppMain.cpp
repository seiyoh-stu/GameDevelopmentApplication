#include "DxLib.h"
#include "Utility/ResourceManager.h"
#include "Utility/InputControl.h"
#include "Objects/Player/Player.h"


int WINAPI WinMain(_In_ HINSTANCE hInstance, 
	_In_opt_ HINSTANCE hPreInstance, 
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd)
{
	//�E�B���h�E���[�h�ŋN��
	ChangeWindowMode(TRUE);

	//window�T�C�Y�̐ݒ�
	SetGraphMode(640, 480, 32);

	//Dx���C�u���C�̏���������
	if (DxLib_Init() == -1)
	{
		OutputDebugString("DX���C�u����������������Ă��܂���ł����B\n");
		return -1;
	}

	//���[�J���ϐ���`
	GameObject* object = nullptr;
	ResourceManager* rm =ResourceManager::GetInstance();
	int result = 0;

	//�`���𗠉�ʂɐݒ�
	SetDrawScreen(DX_SCREEN_BACK);

	try
	{
		object = new Player();//�v���C���[����

		//�I�u�W�F�N�g�̏�����
		object->Initialize();

		//���C�����[�v

		while (ProcessMessage() != -1)
		{
			//���͏��̃C���X�^���X���擾
			InputControl* input = InputControl::GetInstance();

			//���͏��̍X�V
			input->Update();

			//�I�u�W�F�N�g�̍X�V����
			object->Update();

			//��ʂ̏�����
			ClearDrawScreen();

			int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

			//�I�u�W�F�N�g�̕`�揈��
			object->Draw();

			//����ʂ̓��e��\��ʂɔ��f����
			ScreenFlip();

			//esc�L�[�����͂��ꂽ��A���[�v���I������
			if (input->GetKeyUp(KEY_INPUT_ESCAPE))
			{
				break;
			}
		}
	}
	catch (std::string error_log)
	{
		//log.txt�ɃG���[���e���o�͂���
		OutputDebugString(error_log.c_str());
		//�I����Ԃ��ȏ�ɐݒ肷��
		result = -1;
	}

	//�I�u�W�F�N�g�̍폜
	if (object != nullptr)
	{
		object->Finalize();
		delete object;
		object = nullptr;
	}

	//���͋@�\�̃C���X�^���X���폜����
	InputControl::DeleteInstance();

	//�ǂݍ��񂾉摜�̊J��
	//���\�[�X�Ǘ��̃C���X�^���X���폜����
	ResourceManager::DeleteInstance();

	//Dx���C�u���C�g�p�̏I�����@
	DxLib_End();

	//�I����Ԃ̒l��ԋp����
	return result;

}