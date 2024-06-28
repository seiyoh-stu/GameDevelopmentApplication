
#include "SceneBase.h"
class SceneManager
{
private:
	SceneBase* current_scene;

public:
	SceneManager();
	~SceneManager();

	//����������
	void Initialize();

	//�X�V����
	void Run();

	void Finalize();

private:
	//�`�揈��
	void Draw() const;

	//�V�[���̐؂�ւ�����
	void ChangeScene(eSceneType type);

	//�V�[����������
	SceneBase* CreateScene(eSceneType type);
};
