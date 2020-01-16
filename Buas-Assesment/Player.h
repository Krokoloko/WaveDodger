#pragma once
#include <SFML/Graphics.hpp>
#include "Collision.h"
class Player
{

public:
	Player();

	Player(sf::Vector2f, float);

	enum PlayerState {
		Grounded,
		Airborne
	};

	Collision collider;

	sf::Vector2f Position();
	sf::Vector2f Velocity();
	sf::Vector2f Accelleration();

	float Weight();

	void Jump();
	void Update();

	~Player();
private:
	sf::Vector2f _position;
	sf::Vector2f _velocity;
	sf::Vector2f _accelleration;

	sf::VertexArray _collisionBox;

	Player::PlayerState _state;
	int _jumpForce;
	
	float _weight;
};

