#pragma once
#include <SFML/Graphics.hpp>
#include "InputManager.h"
#include "Player.h"
#include "SineWall.h"
class Game
{
public:
	Game(sf::RenderWindow*);

	void Start();
	void Draw();
	void Update();

	~Game();

private:
	sf::RenderWindow* _window;
	SineWall wall;
	Player player;
	InputManager inputManager;
};

