#include "SceneManager.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"

#include "TitleScene.h"

SceneManager::SceneManager() :current_scene(nullptr)
{
}

SceneManager::~SceneManager()
{
	//����Y��h�~
	Finalize();
}

///<summary>
///����������
/// </summary>
void SceneManager::Initialize()
{
	//�E�B���h�E���[�h�ŋN��
	ChangeWindowMode(TRUE);

	//��ʃT�C�Y�̐ݒ�
	SetGraphMode(640, 480, 32);

	//DX���C�u�����̏�����
	if (DxLib_Init() == -1)
	{
		throw("DX���C�u�������������ł��܂���ł���\n");
	}

	//����ʂ���`����n�߂�
	SetDrawScreen(DX_SCREEN_BACK);

	//�^�C�g����ʂ���V�[�����J�n����
	ChangeScene(eSceneType::eTitle);
}

///<summary>
///���s����
/// </summary>
void SceneManager::Run()
{
	//���͋@�\�̃C���X�^���X���擾����
	InputControl* input = InputControl::GetInstance();

	//���C�����[�v�i�E�B���h�E��������orESC�L�[�����͂��ꂽ�@�Ń��[�v���I������j
	while (ProcessMessage() != -1 && input->GetKeyUp(KEY_INPUT_ESCAPE) != true)
	{
		//�V�[���̍X�V����
		eSceneType next_scene_type = current_scene->Update();

		//�V�[���̕`�揈��
		Draw();

		//�V�[���̐؂�ւ�
		if (next_scene_type != current_scene->GetNowSceneType())
		{
			ChangeScene(next_scene_type);
		}
	}
}

///<summary>
///�I��������
/// </summary>
void SceneManager::Finalize()
{
	//�V�[����񂪐�������Ă���΁A�폜����
	if (current_scene != nullptr)
	{
		current_scene->Finalize();
		delete current_scene;
		current_scene = nullptr;
	}

	//���͋@�\�̃C���X�^���X���폜
	InputControl::DeleteInstance();

	//DX���C�u�����̏I��������
	DxLib_End();
}

///<summary>
///�`�揈��
/// </summary>
void SceneManager::Draw() const
{
	//��ʂ̏�����
	ClearDrawScreen();

	//�V�[���̕`�揈��
	current_scene->Draw();

	//����ʂ̓��e��\��ʂɔ��f����
	ScreenFlip();
}

///<summary>
///�V�[���̐؂�ւ�����
/// </summary>
/// <param name="type">�V�[�����</param>
void SceneManager::ChangeScene(eSceneType type)
{
	//�����œn���ꂽ��񂩂�V�����V�[�����쐬����
	SceneBase* new_scene = CreateScene(type);

	//�G���[�`�F�b�N
	if (new_scene == nullptr)
	{
		throw("�V�[���������ł��܂���ł���\n");
	}

	//���݂̏I��������
	if (current_scene != nullptr)
	{
		current_scene->Finalize();
		delete current_scene;
	}
	//�V�����V�[���̏�����
	new_scene->Initialize();
	current_scene = new_scene;
}

/// <summary>
/// �V�[����������
/// </summary>
/// <param name="type">�V�[�����</param>
/// <returns>�V�[���N���X�̃|�C���^</returns>
SceneBase* SceneManager::CreateScene(eSceneType type)
{
	//�V�[�����ɂ���āA��������V�[����؂�ւ���
	switch (type)
	{
	case eSceneType::eTitle:
		return dynamic_cast<SceneBase*>(new TitleScene());
	default:
		return nullptr;
	}
}