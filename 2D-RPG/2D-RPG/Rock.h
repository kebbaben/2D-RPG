#pragma once
#include "Enemy.h"

class Rock : public Enemy
{
public:
	Rock();
	~Rock();

	int Update(const float DT, const int TURN_ORDER);

private:
	sf::Texture m_rock_tex1;
};

