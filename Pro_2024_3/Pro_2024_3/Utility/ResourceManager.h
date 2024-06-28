#pragma once

#include <map>
#include <string>
#include <vector>

struct MaterialParam
{
	std::string file_path;
	int all_num;
	int num_x;
	int num_y;
	int size_x;
	int size_y;
};
class ResourceManager
{
private:
	//自クラスのポインタ（アドレス先にインスタンスを生成する）
	static ResourceManager* instance;
	//画像格納コンテナ
	std::map<std::string, std::vector<int>> image_container;

private:
	//コンストラクタをprivateにすることで、
	//自クラスのメンバ関数でしかインスタンスを生成できないようにする
	ResourceManager() = default;

	//コピーガード
	//クラス外でインスタンスを生成して渡すことができないようにする
	ResourceManager(ResourceManager& v) = delete;
	ResourceManager& operator=(const ResourceManager& v) = delete;
	//コピーガード
public:
	~ResourceManager() = default;

public:
	//インスタンスを取得する処理
	static ResourceManager* GetInstance();
	//インスタンス削除する処理
	static void DeleteInstance();

public:
	/// <summary>
	/// 画像取得処理
	/// </summary>
	/// <param name="file_path">画像のファイルパス</param>
	/// <returns>画像分割の配分データ</returns>
	const std::vector<int>& GetImages(std::string file_name, int all_num = 1, 
		int num_x = 1, int num_y = 1, int size_x = 0, int size_y = 0);
	const std::vector<int>& GetImages(const char* file_name, int all_num = 1,
		int num_x = 1, int num_y = 1, int size_x = 0, int size_y = 0);
	const std::vector<int>& GetImages(MaterialParam element);

	/*
	すべての画像を削除する
	*/
	void UnloadResourcesALL();

private:

	void CreateImagesResource(std::string file_name);
	/// <summary>
	/// 画像取得処理
	/// </summary>
	/// <param name="flie_path">画像のファイルパス</param>
	/// <param name="all_num">分割総枚数</param>
	/// <param name="x_num">横方向の分割数</param>
	/// <param name="y_num">縦方向の分割数</param>
	/// <param name="x_size">分割画像１枚当たりのピクセル数（横）</param>
	/// <param name="y_size">分割画像１枚当たりのピクセル数（盾）</param>
	/// <returns>分割画像の配列データ</returns>
	void CreateImagesResource(std::string file_name, 
		int all_num, int num_x, int num_y, int size_x, int size_y);
};