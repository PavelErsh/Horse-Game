#include <SFML/Graphics.hpp>
#include <iostream>
#include "map.h"
#include "view.h"
#include "player.h"
#include <ctime>

#include <cstdlib>
using namespace sf;
int main()
{
	srand(time(NULL));
	Font font;
	font.loadFromFile("20016.ttf");
	Text text("", font, 20);
	text.setFillColor(sf::Color::Black);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	Text textGameOver("", font, 40);
	textGameOver.setFillColor(Color::Red);
	textGameOver.setStyle(sf::Text::Bold | sf::Text::Underlined);
	Image map_image;
	map_image.loadFromFile("images/map.png");//Создаем объект текстуры, грузим туда изображение:
	Texture map_texture;
	map_texture.loadFromImage(map_image);
	Sprite map_sprite;
	map_sprite.setTexture(map_texture);
	Player player1("images/horse.png", 100, 100, 80, 80);
	//player1.x = 50;
	//player1.direction = 1;
	//std::cout << player1.x << "\n";
	//std::cout << player1.direction << "\n";
	RenderWindow window(VideoMode(640, 480), "The Game!");
	view.reset(sf::FloatRect(0, 0, 400, 300));
	Clock clock;
	Clock gameTimeClock;
	int gameTime = 0;
	float hero_time = 0;
	float current_rec = 0;
	while (window.isOpen())

	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		//std::cout << time << "\n";
		time = time / 1000;
		Event event;

		while (window.pollEvent(event))

		{
			if (event.type == Event::Closed)
				window.close();
		}
		if (player1.lives > 0)

		{
			gameTime = gameTimeClock.getElapsedTime().asSeconds();
			if (Keyboard::isKeyPressed(Keyboard::Right))

			{

				player1.direction = 0;

				player1.speed = 0.1;

				current_rec += time * 0.005;

				if (current_rec > 4)

					current_rec -= 4;

				// hero_sprite.move( -0.1*time, 0 ); - заменим на update 

				player1.sprite.setTextureRect(IntRect(80 * int(current_rec), 160, 80, 80));
			}

			if (Keyboard::isKeyPressed(Keyboard::Left))

			{

				player1.direction = 1;

				player1.speed = 0.1;

				current_rec += time * 0.005;

				if (current_rec > 4)

					current_rec -= 4;

				player1.sprite.setTextureRect(IntRect(80 * int(current_rec), 80, 80, 80));
			}

			if (Keyboard::isKeyPressed(Keyboard::Up))

			{

				player1.direction = 3;

				player1.speed = 0.1;

				current_rec += time * 0.005;

				if (current_rec > 4)

					current_rec -= 4;

				player1.sprite.setTextureRect(IntRect(80 * int(current_rec), 240, 80, 80));
			}
			if (Keyboard::isKeyPressed(Keyboard::Down))

			{

				player1.direction = 2;

				player1.speed = 0.1;

				current_rec += time * 0.005;

				if (current_rec > 4)

					current_rec -= 4;

				player1.sprite.setTextureRect(IntRect(80 * int(current_rec), 0, 80, 80));
			}
			getPlayerCoordinateForView(player1.getPlayerX(), player1.getPlayerY());
		}
		else

		{

			textGameOver.setString("Game over");//задает строку тексту

			textGameOver.setPosition(view.getCenter().x, view.getCenter().y);
			view.move(0.1, 0);

			view.rotate(0.01);

		}
		player1.update(time);
		//view_map(time);
		window.setView(view);
		window.clear(Color(213, 186, 139));
		for (int i = 0; i < HEIGHT_MAP; i++)

			for (int j = 0; j < WIDTH_MAP; j++)

			{

				if (TileMap[i][j] == 'h')

					map_sprite.setTextureRect(IntRect(64 * 0, 0, 64, 64));

				if (TileMap[i][j] == 'g')

					map_sprite.setTextureRect(IntRect(64 * 1, 0, 64, 64));

				if (TileMap[i][j] == 'l')

					map_sprite.setTextureRect(IntRect(64 * 2, 0, 64, 64));

				if (TileMap[i][j] == 's')

					map_sprite.setTextureRect(IntRect(64 * 3, 0, 64, 64));
				map_sprite.setPosition(j * 64, i * 64);
				window.draw(map_sprite);
			};
		text.setString("Score: " + std::to_string(player1.playerScore) + "\nLives: " + std::to_string(player1.lives) +

			"\nTime: " + std::to_string(gameTime));//задает строку тексту

		text.setPosition(view.getCenter().x +120, view.getCenter().y - 150); 
		window.draw(text);
		window.draw(player1.sprite);
		window.draw(textGameOver);
		window.display();
	}
	return 0;
}