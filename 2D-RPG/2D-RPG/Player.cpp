#include <iostream>

#include "Player.h"

Player::Player() :
	m_hp(200), M_FRAME_SIZE(165, 192), M_TOTAL_FRAMES(3), m_current_frame(0)
{
	m_tex_p_idle.loadFromFile("Pictures/idle.png");

	m_font_arial.loadFromFile("arial.ttf");

	m_player_sprite.setPosition(sf::Vector2f(450, 500));
	m_player_sprite.setTexture(m_tex_p_idle);
	m_player_sprite.setTextureRect(sf::IntRect(M_FRAME_SIZE.x * m_current_frame, 0, M_FRAME_SIZE.x, M_FRAME_SIZE.y));
	m_player_origin = sf::Vector2f(m_player_sprite.getLocalBounds().width / 2, m_player_sprite.getLocalBounds().height / 2);
	m_player_pos = m_player_sprite.getPosition();

	m_text_hp.setFont(m_font_arial);
	m_text_hp.setCharacterSize(52);
	m_text_hp.setPosition(sf::Vector2f(m_player_pos.x + 40 , 430));
}

Player::~Player()
{
}

void Player::Update(const float DT)
{
	m_text_hp.setString(std::to_string(m_hp));

	static const float FPS = 5.0f;
	static const float FIXED_FRAME_STEP = 1.0f / FPS;
	static float frame_time = 0.0f;

	frame_time += DT;
	if (frame_time > FIXED_FRAME_STEP)
	{
		m_player_sprite.setTextureRect(sf::IntRect(M_FRAME_SIZE.x * m_current_frame, 0, M_FRAME_SIZE.x, M_FRAME_SIZE.y));
		m_current_frame = (m_current_frame + 1) % M_TOTAL_FRAMES;
		
		frame_time -= FIXED_FRAME_STEP;
	}
}

void Player::Draw(sf::RenderWindow& win)
{
	win.draw(m_player_sprite);
	win.draw(m_text_hp);
}

void Player::Damaged(const int DAMAGE)
{
	m_hp -= DAMAGE;
}

void Player::Reset()
{
	m_hp = 200;
	m_current_frame = 0;
}

int Player::GetHp() const
{
	return m_hp;
}