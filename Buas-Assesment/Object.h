#pragma once
#include <SFML/Graphics.hpp>
class Object
{
public:
	Object();
	
	sf::Vector2f Position();
	sf::Vector2f Rotation();

	~Object();

protected:
	sf::Vector2f position;
	sf::Vector2f rotation;
};

