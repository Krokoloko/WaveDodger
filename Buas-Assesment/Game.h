#pragma once
#include <SFML/Graphics.hpp>
#include "InputManager.h"
#include "Player.h"
class Game
{
public:
	Game(sf::RenderWindow*);

	void Start();
	void Draw();
	void Update();

	~Game();

protected:
	sf::RenderWindow* _window;
	Player player;
	InputManager inputManager;
};

