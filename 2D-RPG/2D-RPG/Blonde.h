#pragma once
#include "Enemy.h"

class Blonde : public Enemy
{
public:
	Blonde();
	~Blonde();

	int Update(const float DT, const int TURN_ORDER);
	
private:
	int m_current_frame;
	const int M_TOTAL_FRAMES;

	const sf::Vector2i M_FRAME_SIZE;

	sf::Texture m_blonde_tex_idle;
};

