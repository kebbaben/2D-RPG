#pragma once
#include <SFML\Graphics.hpp>

class Player
{
public:
	Player();
	~Player();

	void Update(const float DT); //this is used when it's the players turn
	void Draw(sf::RenderWindow& win);
	
	void Damaged(const int DAMAGE);
	void Reset();

	int GetHp() const;

private:
	int m_hp;
	int m_current_frame;
	const int M_TOTAL_FRAMES;

	sf::Texture m_tex_p_idle;
	sf::Font m_font_arial;
	sf::Text m_text_hp;

	sf::Sprite m_player_sprite;

	const sf::Vector2i M_FRAME_SIZE;
	sf::Vector2f m_player_pos;
	sf::Vector2f m_player_origin;
};

