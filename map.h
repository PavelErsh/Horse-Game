#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
const int HEIGHT_MAP = 8;//размер карты высота

const int WIDTH_MAP = 20;//размер карты ширина

const int WIDTH_MAP_TILE = 64;

const int HEIGHT_MAP_TILE = 64;

sf::String TileMap[HEIGHT_MAP] = {

"ssssssssssssssssssss",

"sgggghglggggggghglgs",

"sggggggggggggggggggs",

"slllghglggglgggggggs",

"sglgggllggglgggggggs",

"sghlgghlghglgggggggs",

"sgghggllgggggglggggs",

"ssssssssssssssssssss"

};
