#pragma once
#include <SFML\Graphics.hpp>
#include "Player.h"
#include "Enemy.h"

class Enemies
{
public:
	Enemies();
	~Enemies();

	void Update(Player& player, const float DT, const int TURN_ORDER);
	void Draw(sf::RenderWindow& win);

	void PunchEnemy(const int DAMAGE); // players punch ability
	void ShootEnemy(const int DAMAGE); // players shoot ability
	void NewEnemy(const std::string& TYPE);

	int GetTotalEnemies() const;

	void ClearVector();

private:
	int m_damage;

	std::vector<Enemy*> m_enemy_vector;
};