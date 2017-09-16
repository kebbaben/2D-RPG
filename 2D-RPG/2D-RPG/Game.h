#pragma once
#include <iostream>

#include <SFML\Graphics.hpp>

#include "Player.h"
#include "Enemies.h"
#include "Blonde.h"
#include "Tree.h"
#include "Rock.h"

class Game
{
public:
	Game();
	~Game();

	void Update();
	
private:
	int m_turn_order; // 1 == player, 2 == treestump or rock, 3 == blonde
	bool m_turn_over; // this is for the player
	sf::Vector2f m_mouse_pos;

	sf::Texture m_bg_tex1;
	sf::Texture m_bg_tex2;
	sf::Texture m_ui_bg_tex;
	sf::Texture m_arrow_keys_tex;

	sf::Sprite m_bg_sprite; // scene background
	sf::Sprite m_ui_bg_sprite; // UI background
	sf::Sprite m_arrow_keys_sprite;

	sf::Font m_font_arial;
	sf::Text m_text_punch;
	sf::Text m_text_shoot;
	sf::Text m_text_arrows;
};