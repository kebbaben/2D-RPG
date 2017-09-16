#include "Enemy.h"
#include "Blonde.h"
#include "Tree.h"
#include "Rock.h"

Enemy::Enemy() :
	m_is_turn(false)
{
}

Enemy::~Enemy()
{
}

void Enemy::Draw(sf::RenderWindow& win)
{
	win.draw(m_enemy_sprite);
	win.draw(m_enemy_hp);
}

void Enemy::IsDamaged(const int DAMAGE)
{
	m_hp -= DAMAGE;
}

int Enemy::GetHp() const
{
	return m_hp;
}

int Enemy::GetDamage() const
{
	return m_damage;
}

bool Enemy::IsTurn() const
{
	return m_is_turn;
}

sf::Sprite & Enemy::GetSprite()
{
	return m_enemy_sprite;
}

Enemy * Enemy::NewEnemy(const std::string& TYPE)
{
	if (TYPE == "blonde")
		return new Blonde;
	else if (TYPE == "tree" || TYPE == "treestump")
		return new Tree;
	else if (TYPE == "rock")
		return new Rock;
	else
		return nullptr;
}