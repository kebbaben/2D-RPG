#include "Rock.h"

Rock::Rock()
{
	m_lua.script_file("variables.lua");
	sol::table lua_rock = m_lua["rock"];
	m_hp = lua_rock["hp"];

	m_rock_tex1.loadFromFile("Pictures/rock.png");

	m_font_arial.loadFromFile("arial.ttf");

	m_enemy_sprite.setTexture(m_rock_tex1);
	m_enemy_origin = sf::Vector2f(m_enemy_sprite.getLocalBounds().width / 2, m_enemy_sprite.getLocalBounds().height / 2);
	m_enemy_sprite.setOrigin(sf::Vector2f(m_enemy_origin));
	m_enemy_sprite.setPosition(860 + m_enemy_origin.x, 580 + m_enemy_origin.y);
	m_enemy_pos = m_enemy_sprite.getPosition();

	m_enemy_hp.setFont(m_font_arial);
	m_enemy_hp.setCharacterSize(52);
	m_enemy_hp.setPosition(sf::Vector2f(m_enemy_pos.x - m_enemy_origin.x / 2, 430));
}

Rock::~Rock()
{
	std::cout << "Rock was destroyed!" << std::endl;
}

int Rock::Update(const float DT, const int TURN_ORDER)
{
	m_lua.script_file("variables.lua");
	sol::table lua_rock = m_lua["rock"];
	m_damage = lua_rock["dmg"];

	m_enemy_hp.setString(std::to_string(m_hp));

	if(TURN_ORDER == 2)
	{
		return m_damage;
	}
	return 0;
}
