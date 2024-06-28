
#include "SceneBase.h"
class SceneManager
{
private:
	SceneBase* current_scene;

public:
	SceneManager();
	~SceneManager();

	//初期化処理
	void Initialize();

	//更新処理
	void Run();

	void Finalize();

private:
	//描画処理
	void Draw() const;

	//シーンの切り替え処理
	void ChangeScene(eSceneType type);

	//シーン生成処理
	SceneBase* CreateScene(eSceneType type);
};
