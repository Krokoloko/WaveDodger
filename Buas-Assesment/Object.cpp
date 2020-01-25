#include "Object.h"
#include <SFML/Graphics.hpp>


Object::Object()
{
}

sf::Vector2f Object::Position() {
	return position;
}

sf::Vector2f Object::Rotation() {
	return rotation;
}

Object::~Object()
{
}
