#pragma once
#include "Enemy.h"

class Tree : public Enemy
{
public:
	Tree();
	~Tree();

	int Update(const float DT, const int TURN_ORDER);

private:
	int m_self_heal;
	sf::Texture m_tree_tex;
};

