#include "Tree.h"

Tree::Tree() :
	m_self_heal(1)
{
	m_lua.script_file("variables.lua");
	sol::table lua_tree = m_lua["tree"];
	m_hp = lua_tree["hp"];

	m_tree_tex.loadFromFile("Pictures/tree.png");	

	m_font_arial.loadFromFile("arial.ttf");

	m_enemy_sprite.setTexture(m_tree_tex);
	m_enemy_origin = sf::Vector2f(m_enemy_sprite.getLocalBounds().width / 2, m_enemy_sprite.getLocalBounds().height / 2);
	m_enemy_sprite.setOrigin(sf::Vector2f(m_enemy_origin));
	m_enemy_sprite.setPosition(900 + m_enemy_origin.x, 520 + m_enemy_origin.y);
	m_enemy_pos = m_enemy_sprite.getPosition();

	m_enemy_hp.setFont(m_font_arial);
	m_enemy_hp.setCharacterSize(52);
	m_enemy_hp.setPosition(sf::Vector2f(m_enemy_pos.x - m_enemy_origin.x / 2 - 20, 430));
}

Tree::~Tree()
{
	std::cout << "Tree was destroyed!" << std::endl;
}

int Tree::Update(const float DT, const int TURN_ORDER)
{
	m_lua.script_file("variables.lua");
	sol::table lua_tree = m_lua["tree"];
	m_damage = lua_tree["dmg"];

	m_enemy_hp.setString(std::to_string(m_hp));
	if (TURN_ORDER == 2)
	{
		if (m_hp <= 50 && m_self_heal > 0)
		{
			m_hp += 50;
			std::cout << "Tree stump skipped a turn and used self heal and healed " << 50 << " hp!" << std::endl;
			m_self_heal--;

			return 0;
		}
	}
	return m_damage;
}
