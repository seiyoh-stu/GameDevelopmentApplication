#pragma once

#include"../Utility/Vector2D.h"
class GameObject
{
protected:

	Vector2D location;	//���̏ꏊ
	Vector2D box_size;	//���̃T�C�Y
	int image;
	int flip_flag;

public:
	GameObject();
	virtual ~GameObject();

	virtual void Initialize();		//������
	virtual void Update();			//�X�V
	virtual void Draw() const;		//�`��
	virtual void Finalize();		//�I��

public:
	Vector2D GetLocation() const;		//�ꏊ�̏��擾
	Vector2D GetBoxSize() const;		//���̃T�C�Y�擾

	void SetLocation(Vector2D location);//�ꏊ�̐ݒ�
};

