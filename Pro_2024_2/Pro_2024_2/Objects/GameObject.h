#pragma once

#include"../Utility/Vector2D.h"
class GameObject
{
protected:
	unsigned int color;	//���̐F
	Vector2D location;	//���̏ꏊ
	Vector2D box_size;	//���̃T�C�Y
public:
	GameObject();			
	virtual ~GameObject();	

	void Initialize();		//������
	void Update();			//�X�V
	void Draw() const;		//�`��
	void Finalize();		//�I��

public:
	void SetLocation(Vector2D location);//�ꏊ�̐ݒ�
	Vector2D GetLocation() const;		//�ꏊ�̏��擾
	Vector2D GetBoxSize() const;		//���̃T�C�Y�擾
};

