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

//リソース管理クラス
class ResourceManager
{
private:
	//自クラスのポインタ（アドレスの先にインスタンスを生成する）
	static ResourceManager* instance;

	//画像格納コンテナ
	std::map<std::string, std::vector<int>> image_container;

	//音源格納コンテナ
	std::map<std::string,int> sound_container;



private:
	//コンストラクタをprivateにすることで、
	//自クラスのメンバ関数でしたインスタンスを生成できないようにする
	ResourceManager() = default;;	

	//コピーガード
	//クラス外でインスタンスを生成して渡すことができないようにする
	ResourceManager(ResourceManager& v) = delete;
	ResourceManager& operator=(const ResourceManager& v) = delete;
	//~コピーガード

public:
	~ResourceManager() = default;

public:
	//インスタンス取得する処理
	static ResourceManager* GetInstance();
	//インスタンス削除する処理
	static void DeleteInstance();

public:
	///<summary>
	///画像取得処理
	///</summary>
	///<param name="file_path">画像のfileパス</param>
	///<returns>分割画像の配列データ</returns>
	const std::vector<int>& GetImages(MaterialParam element);//画像

	///<summary>
	///画像取得処理
	///</summary>
	///<param name="file_path">画像のfileパス</param>
	///<param name="all_num">分割総枚数</param>
	///<param name="X_num">横方向の分割数</param>
	///<param name="Y_num">縦方向の分割数</param>
	///<param name="X_size">分割画像1枚当たりのピクセル数（横）</param>
	///<param name="Y_size">分割画像1枚当たりのピクセル数（縦）</param>
	const std::vector<int>& GetImages(std::string file_name, int all_num = 1,
		int num_x = 1, int num_y = 1, int size_x = 0, int size_y = 0);		//横に画像を移動させる
	const std::vector<int>& GetImages(const char* file_name, int all_num = 1,
		int num_x = 1, int num_y = 1, int size_x = 0, int size_y = 0);
	int GetSound(const std::string& file_name);

	void UnloadResourcesALL();
	void UnloadSoundResource();

private:
	/*
	*画像ハンドルを読み込みリソースを作成する
	* @param file_name fileパス
	*/
	void CreateImagesResource(std::string file_name);

	void CreateSoundsResource(std::string file_name);

	/*
	*画像ハンドルを読み込みリソースを作成する
	* @param file_name ファイルパス
	* @param all_num　画像の総数
	* @param num_x　横の総数
	* @param num_y　縦の総数
	* @param size_x　横のサイズ(px)
	* @param size_y　縦のサイズ(px)
	*/
	void CreateImagesResource(std::string file_name, int all_num,
		int num_x, int num_y, int size_x, int size_y);
};

