#include "Game.h"

enum SCENETYPE
{
	FOREST,
	DESERT
};

Game::Game() :
	m_turn_order(1), m_turn_over(false)
{
	m_bg_tex1.loadFromFile("Pictures/forest.png");
	m_bg_tex2.loadFromFile("Pictures/desert.png");
	m_ui_bg_tex.loadFromFile("Pictures/ui_bg.png");
	m_arrow_keys_tex.loadFromFile("Pictures/arrow_keys.png");
	m_font_arial.loadFromFile("arial.ttf");

	m_bg_sprite.setTexture(m_bg_tex1);

	m_text_punch.setFont(m_font_arial);
	m_text_punch.setString("Punch");
	m_text_punch.setCharacterSize(72);
	m_text_punch.setPosition(350, 750);

	m_text_shoot.setFont(m_font_arial);
	m_text_shoot.setString("Shoot");
	m_text_shoot.setCharacterSize(72);
	m_text_shoot.setPosition(900, 750);

	m_text_arrows.setFont(m_font_arial);
	m_text_arrows.setString("Switch Scenes");
	m_text_arrows.setCharacterSize(32);
	m_text_arrows.setPosition(40, 825);

	m_ui_bg_sprite.setTexture(m_ui_bg_tex);
	m_ui_bg_sprite.setPosition(sf::Vector2f(300, 710));

	m_arrow_keys_sprite.setTexture(m_arrow_keys_tex);
	m_arrow_keys_sprite.setPosition(sf::Vector2f(20, 720));
}

Game::~Game()
{
}

void Game::Update()
{
	sf::Clock clock;

	Player player;
	Enemies enemies;

	sf::RenderWindow window(sf::VideoMode(1600, 900), "2D-RPG");
	SCENETYPE scene = FOREST;

	enemies.NewEnemy("tree");
	enemies.NewEnemy("blonde");

	int is_pressed = 0; // for mouse clicks

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (player.GetHp() <= 0)
				window.close();
		}

		// Makes it possible to switch between scenes
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			if (scene == DESERT)
			{
				scene = FOREST;

				player.Reset();
				enemies.ClearVector();

				enemies.NewEnemy("tree");
				enemies.NewEnemy("blonde");

				m_bg_sprite.setTexture(m_bg_tex1);
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if (scene == FOREST)
			{
				scene = DESERT;

				player.Reset();
				enemies.ClearVector();

				enemies.NewEnemy("rock");
				enemies.NewEnemy("blonde");

				m_bg_sprite.setTexture(m_bg_tex2);
			}
		}

		float delta_time = clock.restart().asSeconds();
		m_mouse_pos = sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y); // Current mouse position

		if (m_text_punch.getGlobalBounds().contains(m_mouse_pos)) // If mouse hovers over text_punch
		{
			m_text_punch.setFillColor(sf::Color::Red);
			if (event.mouseButton.button == sf::Mouse::Left) // And if LMB is pressed
			{
				if (event.type == sf::Event::MouseButtonPressed)
				{
					is_pressed = 0;
				}
				else if (event.type == sf::Event::MouseButtonReleased && is_pressed == 0) // Then when released
				{
					enemies.PunchEnemy(30); // Damages front enemy 30hp
					m_turn_over = true;
					is_pressed++;
				}
			}
		}
		else
			m_text_punch.setFillColor(sf::Color::White);

		if (m_text_shoot.getGlobalBounds().contains(m_mouse_pos)) // If mouse hovers over text_punch
		{
			m_text_shoot.setFillColor(sf::Color::Red);
			if (event.mouseButton.button == sf::Mouse::Left) // And if LMB is pressed
			{
				if (event.type == sf::Event::MouseButtonPressed)
				{
					is_pressed = 0;
				}
				else if (event.type == sf::Event::MouseButtonReleased && is_pressed == 0) // Then when released
				{
					enemies.ShootEnemy(15);
					m_turn_over = true;
					is_pressed++;
				}
			}
		}
		else
			m_text_shoot.setFillColor(sf::Color::White);

		window.clear();

		player.Update(delta_time);
		enemies.Update(player, delta_time, m_turn_order);

		window.draw(m_bg_sprite);
		window.draw(m_ui_bg_sprite);
		player.Draw(window);
		enemies.Draw(window);
		window.draw(m_text_punch);
		window.draw(m_text_shoot);
		window.draw(m_text_arrows);
		window.draw(m_arrow_keys_sprite);

		window.display();

		if (m_turn_order == 1) // if player's turn
		{
			if (m_turn_over == true) // and player has made it's move
			{
				m_turn_order++;
				m_turn_over = false;
			}
		}
		else
		{
			if (m_turn_order >= 3)
				m_turn_order = 1;
			else
				m_turn_order++;
		}
	}
}