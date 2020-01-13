#pragma once
#include <SFML/Graphics.hpp>
class Collision
{
public:
	Collision(sf::Vector2f*);
	Collision(sf::Vector2f*, sf::VertexArray);

	sf::VertexArray collision;

	bool OnHitStart(Collision);
	bool OnHit(Collision);
	bool OnHitRelease(Collision);

	~Collision();
private:
	bool _isColliding(Collision);
	
	bool _isInArea(sf::Vector2f, sf::Vector2f, sf::Vector2f, sf::Vector2f);
	float _areaTriangle(sf::Vector2f, sf::Vector2f, sf::Vector2f);
	
	sf::Vector2f* _position;
};

