#include "DxLib.h"
#include"Utility/InputControl.h"
#include"Objects/GameObject.h"
#include"Objects/Player.h"


int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPreInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	//�E�B���h�E���[�h�ŋN��
	ChangeWindowMode(TRUE);


	//Dx���C�u���C�̏���������
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	SetDrawScreen(DX_SCREEN_BACK);

	GameObject* object1 = new GameObject();	//�G�̃I�u�W�F�N�g
	Player* object2 = new Player();			//����I�u�W�F�N�g

	object1->Initialize();	//���̏�����
	object2->Initialize();	//���̏�����

	while (ProcessMessage() != -1 && InputControl::GetKeyUp(KEY_INPUT_ESCAPE) == false)
	{
		InputControl::Update();	//�X�V

		object1->Update();		//�G�I�u�W�F�N�g�̍X�V
		object2->Update();		//����I�u�W�F�N�g�̍X�V

		ClearDrawScreen();		//�Q�[����ʂ̔��f

		object1->Draw();		//�G�I�u�W�F�N�g�̕`��
		object2->Draw();		//����I�u�W�F�N�g�̕`��

		ScreenFlip();			//�I�u�W�F�N�g�𓮂���
	}

	delete object1; //���̍폜
	delete object2; //���̍폜


	//Dx���C�u���C�g�p�̏I�����@
	DxLib_End();


	return 0;

}