#include "Game.h"

#include "InputManager.h"
#include "Player.h"
#include <SFML/Graphics.hpp>

Game::Game(sf::RenderWindow *window)
{
	_window = window;
	_window->setFramerateLimit(60);
}

void Game::Start() {
	inputManager = InputManager();

	sf::VertexArray square(sf::Quads, 4);

	square[0].position = sf::Vector2f(-5, 5);
	square[1].position = sf::Vector2f(5, 5);
	square[2].position = sf::Vector2f(5, -5);
	square[3].position = sf::Vector2f(-5, -5);

	player = Player(sf::Vector2f(400.f, 300.f), 5.f, square);
}

void Game::Draw() {
	_window->draw(player.CollisionBox());
}

void Game::Update() {
	player.Update();
}

Game::~Game()
{
}
