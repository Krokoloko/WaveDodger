#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"
class Collision
{
public:
	Collision();
	Collision(sf::Vector2f*);
	Collision(Object *, sf::VertexArray);

	sf::VertexArray collision;

	bool OnHitStartWith(Collision);
	bool OnHitWith(Collision);
	bool OnHitReleaseWith(Collision);

	~Collision();
private:
	bool _isColliding(Collision);
	
	bool _colliding;

	bool _isInArea(sf::Vector2f, sf::Vector2f, sf::Vector2f, sf::Vector2f);
	float _areaTriangle(sf::Vector2f, sf::Vector2f, sf::Vector2f);
	
	Object* _transform;
};
