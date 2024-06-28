#include"DxLib.h"
#include "Utility/InputControl.h"
#include"Scene/Scene.h"

//���C���֐��i�v���O�����͂�������n�܂�܂��B�j
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPreInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	//�E�B���h�E���[�h�ŋN��
	ChangeWindowMode(TRUE);

	//�E�B���h�E�T�C�Y(���F640px,�c:480px)��ݒ�
	SetGraphMode(640, 480, 32);

	//DX���C�u�����̏�����
	if (DxLib_Init() == -1)
	{
		//�ُ��ʒm
		return -1;
	}

	//���[�J���ϐ���`
	Scene* scene = new Scene();
	int result = 0;

	//�`���𗠉�ʂ���n�߂�悤�Ɏw�肷��
	SetDrawScreen(DX_SCREEN_BACK);

	try
	{
		//�V�[���̏�����
		scene->Initialize();

		//���C�����[�v�i�E�B���h�E�ُ̈픭��orESC�L�[�������ꂽ�烋�[�v�I���j
		while (ProcessMessage() != -1 && CheckHitKey(KEY_INPUT_ESCAPE) != TRUE)
		{
			//���͋@�\�̍X�V
			InputControl::Update();

			//�V�[���̍X�V����
			scene->Update();

			//��ʂ̏�����
			ClearDrawScreen();

			//�V�[���̕`�揈��
			scene->Draw();

			//���O�ʂ̓��e��\��ʂɔ��f����
			ScreenFlip();

		}
	}
	catch (const char* error_log)
	{
		//�G���[����log.txt�ɏo�͂���
		OutputDebugString(error_log);
		//�ُ��ԂɕύX����
		result = -1;
	}

	//�V�[�����̍폜������
	if (scene != nullptr)
	{
		scene->Finalize();
		delete scene;
		scene = nullptr;
	}

	


	//Dx���C�u���C�g�p�̏I�����@
	DxLib_End();

	//�I����Ԃ�ʒm
	return result;

}