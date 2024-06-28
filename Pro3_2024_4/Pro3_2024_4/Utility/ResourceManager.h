#pragma once

#include<map>
#include<string>
#include<vector>

struct MaterialParam
{
	std::string file_path;
	int all_num;
	int num_x;[]
	int num_y;
	int size_x;
	int size_y;
};

//���\�[�X�Ǘ��N���X
class ResourceManager
{
private:
	//���N���X�̃|�C���^�i�A�h���X�̐�ɃC���X�^���X�𐶐�����j
	static ResourceManager* instance;

	//�摜�i�[�R���e�i
	std::map<std::string, std::vector<int>> image_container;

	//�����i�[�R���e�i
	std::map<std::string,int> sound_container;



private:
	//�R���X�g���N�^��private�ɂ��邱�ƂŁA
	//���N���X�̃����o�֐��ł����C���X�^���X�𐶐��ł��Ȃ��悤�ɂ���
	ResourceManager() = default;;	

	//�R�s�[�K�[�h
	//�N���X�O�ŃC���X�^���X�𐶐����ēn�����Ƃ��ł��Ȃ��悤�ɂ���
	ResourceManager(ResourceManager& v) = delete;
	ResourceManager& operator=(const ResourceManager& v) = delete;
	//~�R�s�[�K�[�h

public:
	~ResourceManager() = default;

public:
	//�C���X�^���X�擾���鏈��
	static ResourceManager* GetInstance();
	//�C���X�^���X�폜���鏈��
	static void DeleteInstance();

public:
	///<summary>
	///�摜�擾����
	///</summary>
	///<param name="file_path">�摜��file�p�X</param>
	///<returns>�����摜�̔z��f�[�^</returns>
	const std::vector<int>& GetImages(MaterialParam element);//�摜

	///<summary>
	///�摜�擾����
	///</summary>
	///<param name="file_path">�摜��file�p�X</param>
	///<param name="all_num">����������</param>
	///<param name="X_num">�������̕�����</param>
	///<param name="Y_num">�c�����̕�����</param>
	///<param name="X_size">�����摜1��������̃s�N�Z�����i���j</param>
	///<param name="Y_size">�����摜1��������̃s�N�Z�����i�c�j</param>
	const std::vector<int>& GetImages(std::string file_name, int all_num = 1,
		int num_x = 1, int num_y = 1, int size_x = 0, int size_y = 0);		//���ɉ摜���ړ�������
	const std::vector<int>& GetImages(const char* file_name, int all_num = 1,
		int num_x = 1, int num_y = 1, int size_x = 0, int size_y = 0);
	int GetSound(const std::string& file_name);

	void UnloadResourcesALL();
	void UnloadSoundResource();

private:
	/*
	*�摜�n���h����ǂݍ��݃��\�[�X���쐬����
	* @param file_name file�p�X
	*/
	void CreateImagesResource(std::string file_name);

	void CreateSoundsResource(std::string file_name);

	/*
	*�摜�n���h����ǂݍ��݃��\�[�X���쐬����
	* @param file_name �t�@�C���p�X
	* @param all_num�@�摜�̑���
	* @param num_x�@���̑���
	* @param num_y�@�c�̑���
	* @param size_x�@���̃T�C�Y(px)
	* @param size_y�@�c�̃T�C�Y(px)
	*/
	void CreateImagesResource(std::string file_name, int all_num,
		int num_x, int num_y, int size_x, int size_y);
};

