#pragma once

#include"GameObject.h"
class Player:public GameObject

{
private:

public:
	Player();
	~Player();

	void Initialize();
	void Update();
	void Draw() const;
	void Finalize();

private:
	void Movement();
};

