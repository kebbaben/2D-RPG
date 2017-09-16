#include "Enemies.h"
#include "Blonde.h"
#include "Tree.h"
#include "Rock.h"

#include <iostream>

Enemies::Enemies()
{
}

Enemies::~Enemies()
{
}

void Enemies::Update(Player& player, const float DT, const int TURN_ORDER)
{
	if (m_enemy_vector.size() > 0)
	{
		for (int i = 0; i < m_enemy_vector.size(); i++)
		{
			if (m_enemy_vector[i]->GetHp() <= 0)
			{
				delete m_enemy_vector[i];
				m_enemy_vector.erase(m_enemy_vector.begin() + i);

				if (m_enemy_vector.size() <= 0)
					std::cout << "You Won!" << std::endl;
				continue;
			}
			m_damage = m_enemy_vector[i]->Update(DT, TURN_ORDER);
			player.Damaged(m_damage);
		}
	}
}

void Enemies::Draw(sf::RenderWindow & win)
{
	if (m_enemy_vector.size() > 0)
	{
		for (int i = 0; i < m_enemy_vector.size(); i++)
		{
			m_enemy_vector[i]->Draw(win);
		}
	}
}

void Enemies::PunchEnemy(const int DAMAGE)
{
	if (m_enemy_vector.size() > 0)
	{
		m_enemy_vector[0]->IsDamaged(DAMAGE);
	}
}

void Enemies::ShootEnemy(const int DAMAGE)
{
	if (m_enemy_vector.size() > 0)
	{
		m_enemy_vector.back()->IsDamaged(DAMAGE);
	}
}

void Enemies::NewEnemy(const std::string& TYPE)
{
	if (TYPE == "blonde")
		m_enemy_vector.push_back(new Blonde);
	else if (TYPE == "tree")
		m_enemy_vector.push_back(new Tree);
	else if (TYPE == "rock")
		m_enemy_vector.push_back(new Rock);
	else
		std::cout << "The enemy type: " << TYPE << " doesn't exist" << std::endl;
}

int Enemies::GetTotalEnemies() const
{
	return m_enemy_vector.size();
}

void Enemies::ClearVector()
{
	for (int i = 0; i < m_enemy_vector.size(); i++)
	{
		delete m_enemy_vector[i];
	}
	m_enemy_vector.clear();
}
