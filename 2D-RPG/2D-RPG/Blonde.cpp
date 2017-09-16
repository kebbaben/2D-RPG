#include "Blonde.h"
#include <iostream>

Blonde::Blonde() :
	M_FRAME_SIZE(165, 192), M_TOTAL_FRAMES(3), m_current_frame(0)
{
	m_lua.script_file("variables.lua");
	sol::table lua_blonde = m_lua["blonde"];
	m_hp = lua_blonde["hp"];

	m_blonde_tex_idle.loadFromFile("Pictures/e1_idle.png");

	m_font_arial.loadFromFile("arial.ttf");

	m_enemy_sprite.setTexture(m_blonde_tex_idle);
	m_enemy_sprite.setTextureRect(sf::IntRect(M_FRAME_SIZE.x * m_current_frame, 0, M_FRAME_SIZE.x, M_FRAME_SIZE.y));
	m_enemy_origin = sf::Vector2f(m_enemy_sprite.getLocalBounds().width / 2, m_enemy_sprite.getLocalBounds().height / 2);
	m_enemy_sprite.setOrigin(sf::Vector2f(m_enemy_origin));
	m_enemy_sprite.setPosition(1060 + m_enemy_origin.x, 500 + m_enemy_origin.y);
	m_enemy_pos = m_enemy_sprite.getPosition();

	m_enemy_hp.setFont(m_font_arial);
	m_enemy_hp.setCharacterSize(52);
	m_enemy_hp.setPosition(sf::Vector2f(m_enemy_pos.x - (m_enemy_origin.x) + 30, 430));
}

Blonde::~Blonde()
{
	std::cout << "Blonde has fainted!" << std::endl;
}

int Blonde::Update(const float DT, const int TURN_ORDER)
{
	m_lua.script_file("variables.lua");
	sol::table lua_blonde = m_lua["blonde"];
	m_damage = lua_blonde["dmg"];

	static const float FPS = 5.0f;
	static const float FIXED_FRAME_STEP = 1.0f / FPS;
	static float frame_time = 0.0f;

	frame_time += DT;
	if (frame_time > FIXED_FRAME_STEP)
	{
		m_enemy_sprite.setTextureRect(sf::IntRect(M_FRAME_SIZE.x * m_current_frame, 0, M_FRAME_SIZE.x, M_FRAME_SIZE.y));
		m_current_frame = (m_current_frame + 1) % M_TOTAL_FRAMES;

		frame_time -= FIXED_FRAME_STEP;
	}

	m_enemy_hp.setString(std::to_string(m_hp));

	if (TURN_ORDER == 3)
		return m_damage;
	else
		return 0;
}
