#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
sf::View view;
void getPlayerCoordinateForView(float x, float y)

{


	if (x < 200)

		x = 200;//????? ???????

		//????????? ??? ??? ????????? 

	if (x > 975)
		x = 975;//?????? ???????
	if (y < 150)

		y = 150;//??????? ???????

	if (y > 350)

		y = 350;//?????? ???????
	view.setCenter(x + 10, y + 10);

}
// ??????? ??????????? ??????

void view_map(float time)

{

	if (Keyboard::isKeyPressed(Keyboard::D))

		view.move(0.1*time, 0);
	if (Keyboard::isKeyPressed(Keyboard::S))

		view.move(0, 0.1*time);
	if (Keyboard::isKeyPressed(Keyboard::A))

		view.move(-0.1*time, 0);
	if (Keyboard::isKeyPressed(Keyboard::W))

		view.move(0, -0.1*time);
	if (Keyboard::isKeyPressed(Keyboard::R))

		view.setRotation(90);
	if (Keyboard::isKeyPressed(Keyboard::U))

		view.zoom(1.0001f);
	if (Keyboard::isKeyPressed(Keyboard::Y))

		view.zoom(0.9999f);
	if (Keyboard::isKeyPressed(Keyboard::I))

		view.setSize(640, 480);
	if (Keyboard::isKeyPressed(Keyboard::Q))

		view.setViewport(sf::FloatRect(0, 0, 0.5f, 1));
}