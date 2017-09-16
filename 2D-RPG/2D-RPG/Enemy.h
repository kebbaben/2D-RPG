#pragma once
#include <iostream>

#include <SFML\Graphics.hpp>

#include "sol.hpp"

class Enemy
{
public:
	Enemy();
	virtual ~Enemy() = 0;

	virtual int Update(const float DT, const int TURN_ORDER) = 0;
	virtual void Draw(sf::RenderWindow& win);

	virtual void IsDamaged(const int DAMAGE);
	virtual int GetHp() const;
	virtual int GetDamage() const;

	bool IsTurn() const;
	sf::Sprite& GetSprite();
	
	static Enemy* NewEnemy(const std::string& TYPE);
	
protected:
	sol::state m_lua;

	int m_hp;
	int m_damage;

	bool m_is_turn;

	sf::Font m_font_arial;
	sf::Text m_enemy_hp;
	sf::Sprite m_enemy_sprite;

	sf::Vector2f m_enemy_pos;
	sf::Vector2f m_enemy_origin;
};