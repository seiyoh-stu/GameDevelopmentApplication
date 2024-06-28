#pragma once

#include"../Utility/Vector2D.h"
#include"../Utility/ResourceManager.h"
class GameObject
{
protected:
	int image;			//�摜
	int sound;			//����
	int flip_flag;
	Vector2D location;	//���̏ꏊ
	Vector2D box_size;	//���̃T�C�Y
public:
	GameObject();			//�R���X�g���N�^
	virtual ~GameObject();	//�f�X�g���N�^

	virtual void Initialize();		//������
	virtual void Update();			//�X�V
	virtual void Draw() const;		//�`��
	virtual void Finalize();		//�I��

public:
	Vector2D GetLocation() const;		//�ꏊ�̏��擾
	Vector2D GetBoxSize() const;		//���̃T�C�Y�擾

	void SetLocation(Vector2D location);//�ꏊ�̐ݒ�

};

