#include "Scene.h"
#include"../Objects/Player/Player.h"
#include"../Utility/InputControl.h"
#include"../Objects/Enemy/Enemy.h"
#include"../Objects/Bullet/Bullet.h"
#include"DxLib.h"

#define D_PIVOT_CENTER
//�R���X�g���N�^
Scene::Scene() :objects()
{
}

//�f�X�g���N�^
Scene::~Scene()
{
	//�Y��h�~
	Finalize();
}

//����������
void Scene::Initialize()
{
	background_image = LoadGraph("Resouce/Images/BackGround.png");
	//�v���C���[�𐶐�����
	CreateObject<Player>(Vector2D(320.0f, 240.0f));
}

//�`�揈��
void Scene::Draw() const
{
	DrawGraph(0, 0, background_image, TRUE);
	//�V�[���ɑ��݂���I�u�W�F�N�g�̕`�揈��
	for (GameObject* obj : objects)
	{
		obj->Draw();
	}
}

//�X�V����
void Scene::Update()
{

	Draw();
	//�V�[���ɑ��݂���I�u�W�F�N�g�̍X�V����
	for (GameObject* obj : objects)
	{
		obj->Update();
	}

	//�I�u�W�F�N�g���m�̓����蔻��`�F�b�N
	for (int i = 0; i < objects.size(); i++)
	{
		for (int j = i + 1; j < objects.size(); j++)
		{
			//�����蔻��`�F�b�N����
			HitCheckObject(objects[i], objects[j]);
		}
	}
	//�����G�ɓ���������A�G�Ƌ���kesu
	
	//Z�L�[�𐄂�����A�G�𐶐�����
	if (InputControl::GetKeyDown(KEY_INPUT_Z))
	{
		CreateObject<Enemy>(Vector2D(100.0f, 480.0f));
	}
	//X�L�[����������A���𐶐�����
	if (InputControl::GetKeyDown(KEY_INPUT_X))
	{
		for (int i = 0; i < objects.size(); i++) 
		{
			if(!(dynamic_cast<Player*>(objects[i]) == nullptr))
			{
				CreateObject<Bullet>(objects[i]->GetLocation());
			}
		}
	}
}

#ifdef D_PIVOT_CENTER

//�����蔻��`�F�b�N����
void Scene::HitCheckObject(GameObject* a, GameObject* b)
{
	//�Q�̃I�u�W�F�N�g�̓����蔻��̑傫�����擾
	Vector2D diff = a->GetLocation() - b->GetLocation();

	//�Q�̃I�u�W�F�N�g�̓����蔻��̑傫�����擾
	Vector2D box_size = (a->GetBoxSize() + b->GetBoxSize()) / 2.0f;

	//�������傫�����傫���ꍇ�Ahit����Ƃ���
	if ((fabsf(diff.x) < box_size.x) && (fabsf(diff.y) < box_size.y))
	{
		//�����������Ƃ��I�u�W�F�N�g�ɒʒm����
		a->OnHitCollision(b);
		b->OnHitCollision(a);
	}
}
#else
�����蔻��`�F�b�N�����i���㒸�_�̍��W���瓖���蔻��v�Z���s���j
void Scene::HitCheckObject(GameObject* a, GameObject* b)
{
	//�E�㒸�_���W���擾����
	Vector2D a_lower_right = a->GetLocation() + a->GetBoxSize();
	Vector2D b_lower_riget = b->GetLocation() + b->GetBoxSize();

	//�P�nA�ƒP�nB�̈ʒu���𒲂ׂ�
	if ((a->GetLocation().x < b_lower_right.x) &&
		(a->GetLocation().x < b_lower_right.y) &&
		(b_lower_right.x > b->GetLocation().x) &&
		(b_lower_right.y > b->GetLocation().x))
	{
		//�I�u�W�F�N�g�ɑ΂���Hit�����ʒm����
		a->OnHitCollision(b);
		b->OnHitCollision(a);
	}
}
#endif // D_PIVOT_CENTER


//�I��������
void Scene::Finalize()
{
	//���I�z�񂪋�Ȃ珈�����I������
	if (objects.empty())
	{
		return;
	}

	//�e�I�u�W�F�N�g���폜����
	for (GameObject* obj : objects)
	{
		obj->Finalize();
		delete obj;
	}

	//���I�z��̉��
	objects.clear();
}


