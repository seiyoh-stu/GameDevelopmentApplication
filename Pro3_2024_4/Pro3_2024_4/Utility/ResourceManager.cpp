#include"ResourceManager.h"
#include "DxLib.h"

//静的メンバ変数定義
ResourceManager* ResourceManager::instance = nullptr;  //クラスのインスタンスのポインタ

//<summary>
//リソース管理クラスのインスタンス取得する処理
//</summary>
//<returns>クラスポインタ</returns>
ResourceManager* ResourceManager::GetInstance()
{
	//インスタンスがなければ、生成する
	if (instance == nullptr)
	{
		instance = new ResourceManager();
	}

	//自分自身のポインタを返却する
	return instance;
}
//<summary>
//リソース管理クラスのインスタンス削除する処理
//<summary>
void ResourceManager::DeleteInstance()
{
	//インスタンスが存在していれば削除する
	if (instance != nullptr)
	{
		instance->UnloadResourcesALL();
		instance->UnloadSoundResource();
		delete instance;
		instance = nullptr;
	}
}
/*
画像を取得する
* @param file_name ファイルパス
	* @param all_num　画像の総数
	* @param num_x　横の総数
	* @param num_y　縦の総数
	* @param size_x　横のサイズ(px)
	* @param size_y　縦のサイズ(px)
	* @return 読み込んだ画像ハンドルのstd::vector配列
*/
const std::vector<int>& ResourceManager::GetImages(std::string file_name, int all_num,
	int num_x, int num_y, int size_x, int size_y)
{
	//コンテナ内に画像がなければ、画像を読み込む
	if (image_container.count(file_name) == NULL)
	{
		if (all_num == 1)
		{
			CreateImagesResource(file_name);
		}
		else
		{
			CreateImagesResource(file_name, all_num, num_x, num_y, size_x, size_y);
		}
	}

	//コンテナ内の画像データを返却
	return image_container[file_name];
}
//音源の取得
int  ResourceManager::GetSound(const std::string& file_name)
{
	//コンテナ内に音源がなければ、音源を読み込む
	if (sound_container.count(file_name) == NULL)
	{
		CreateSoundsResource(file_name);
	}
	return sound_container[file_name];
}

const std::vector<int>& ResourceManager::GetImages(const char* file_name,
	int all_num, int x_num, int y_num, int x_size, int y_size)
{
	return GetImages(std::string(file_name), all_num, x_num, y_num, x_size, y_size);
}
const std::vector<int>& ResourceManager::GetImages(MaterialParam element)
{
	return GetImages(element.file_path, element.all_num, element.num_x, element.num_y, element.size_x, element.size_y);
}
/*
すべての画像を削除する
@param material_handle 削除したい画像ハンドルのstd::vector配列
*/

void ResourceManager::UnloadResourcesALL()
{
	//コンテナ内に画像がなければ処理を終了する
	if (image_container.size() == NULL)
	{
		return;
	}

	//すべての画像を削除する
	for (std::pair<std::string, std::vector<int>>value : image_container)
	{
		DeleteSharingGraph(value.second[0]);
		value.second.clear();
	}
	//コンテナを開放
	image_container.clear();
}

/*
画像ハンドルを読み込みリソースを作成する
@param file_name ファイルパス
*/
void ResourceManager::CreateImagesResource(std::string file_name)
{
	//指定されたファイルを読み込む
	int handle = LoadGraph(file_name.c_str());

	//エラーチェック
	if (handle == -1)
	{
		throw(file_name + "がありません\n");
	}

	//コンテナに読み込んだ画像を追加する
	image_container[file_name].push_back(handle);
}

/*
音源ハンドルを読み込みリソースを作成する
@param file_name ファイルパス
*/
void ResourceManager::CreateSoundsResource(std::string file_name)
{
	//指定されたファイルを読み込む
	int handle = LoadSoundMem(file_name.c_str());

	//エラーチェック
	if (handle == -1)
	{
		throw(file_name + "がありません\n");
	}

	//コンテナに読み込んだ音源を追加する
	sound_container[file_name] = handle;
}

/*
	画像ハンドルを読み込みリソースを作成する
	@param file_name ファイルパス
	@param all_num　　画像の総数
	@param num_x	  横の総数
	@param num_y	　縦の総数
	@param size_x	　横のサイス(px)
	@param size_y	 縦のサイズ(px)
	*/

void ResourceManager::CreateImagesResource(std::string file_name,
	int all_num, int num_x, int num_y, int size_x, int size_y)
{
	//指定されたファイルを読み込む
	int* handle = new int[all_num];
	int err = LoadDivGraph(file_name.c_str(), all_num, num_x, num_y, size_x, size_y, handle);

	//エラーチェック
	if (err == -1)
	{
		throw(file_name + "がありません\n");
	}

	//コンテナに読み込んだ画像を追加する
	for (int i = 0; i < all_num; i++)
	{
		image_container[file_name].push_back(handle[i]);
	}

	//動的メモリの開放
	delete[] handle;
}

/*
音源を削除する
@param material_handle 削除したい音源ハンドルのint
*/
void ResourceManager::UnloadSoundResource()
{
	//コンテナ内に音源がなければ処理を終了する
	if (sound_container.size() == NULL)
	{
		return;
	}

	//すべての音源を削除する
	for (std::pair<std::string, int>value : sound_container)
	{
		DeleteSharingGraph(value.second);
	}
	//コンテナを開放
	sound_container.clear();
}