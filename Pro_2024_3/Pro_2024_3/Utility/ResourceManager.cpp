#include "ResourceManager.h"
#include"DxLib.h"

//�ÓI�����o�ϐ���`
ResourceManager* ResourceManager::instance = nullptr; //�N���X�̃C���X�^���X�̃|�C���^

//���\�[�X�Ǘ��N���X�̃C���X�^���X���擾���鏈��
ResourceManager* ResourceManager::GetInstance()
{
	//�C���X�^���X���Ȃ���΁A��������
	if (instance == nullptr)
	{
		instance = new ResourceManager();
	}

	//�������g�̃|�C���^��ԋp����
	return instance;
}

//���\�[�X�Ǘ��N���X�̃C���X�^���X�폜���鏈��
void ResourceManager::DeleteInstance()
{
	//�C���X�^���X�����݂��Ă���΁A�폜����
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}


//�摜�擾����
const std::vector<int>& ResourceManager::GetImages(std::string file_path)
{
	//�R���e�i���ɉ摜���Ȃ���΁A�摜��ǂݍ���
	if (image_container.count(file_path) == NULL)
	{
		//�摜�ǂݍ��ݏ���
		int handle = LoadGraph(file_path.c_str());

		//�G���[�`�F�b�N
		if (handle == -1)
		{
			throw(file_path + "�̉摜���ǂݍ��߂܂���ł���\n");
		}

		//�R���e�i���ɉ摜���i�[����
		image_container[file_path].push_back(handle);
	}
	//�R���e�i���̉摜�f�[�^��ԋp
	return image_container[file_path];
}

//�摜�擾����
const std::vector<int>& ResourceManager::GetImages(std::string file_path, int all_num, int x_num, int y_num, int x_size, int y_size)
{
	//�R���e�i���ɉ摜���Ȃ���΁A�摜��ǂݍ���
	if (image_container.count(file_path) == NULL)
	{
		//���I�z��̊m�ہi�����������̃��������m�ہj
		int* handle = new int[all_num];

		//�摜�̕����ǂݍ���
		int result = LoadDivGraph(file_path.c_str(), all_num, x_num, y_num, x_size, y_size, handle);

		//�G���[�`�F�b�N
		if (result == -1)
		{
			throw(file_path + "�̉摜���ǂݍ��߂܂���ł���\n");
		}

		//�R���e�i���ɉ摜���i�[����
		for (int i = 0; i < all_num; i++)
		{
			image_container[file_path].push_back(handle[i]);
		}

		//���I�������̊J��
		delete[] handle;
	}

	//�R���e�i���̉摜�f�[�^��ԋp
	return image_container[file_path];
}

//�ǂݍ��񂾉摜�̊J��
void ResourceManager::DeleteImages()
{
	//�R���e�i���Ƀf�[�^��������΁A�������I������
	if (image_container.size() == NULL)
	{
		return;
	}

	//������Ɖ摜�n���h���f�[�^�̃Z�b�g�Ń��[�v���s��
	for (std::pair<std::string, std::vector<int>> value : image_container)
	{
		//�ǂݍ��񂾉摜�̊J��
		DeleteSharingGraph(value.second[0]);
		//���I�z��̉��
		value.second.clear();
	}
	//�摜�R���e�i�̉��
	image_container.clear();
}