#include "Game.h"

#include "InputManager.h"
#include "Collision.h"
#include "SineWall.h"
#include "Player.h"

# define M_PI           3.14159265358979323846  /* pi */

#include <cmath>
#include <SFML/Graphics.hpp>

Game::Game(sf::RenderWindow *window)
{
	_window = window;
	_window->setFramerateLimit(60);
}

float SineFunction(float x) {
	return (sin(x/2)-M_PI*2)*4;
}

void Game::Start() {
	inputManager = InputManager();

	sf::VertexArray square(sf::Quads, 4);

	square[0].position = sf::Vector2f(-5, 5);
	square[1].position = sf::Vector2f(5, 5);
	square[2].position = sf::Vector2f(5, -5);
	square[3].position = sf::Vector2f(-5, -5);

	Collision playerCol(&(player), square);
	sf::Vector2f position = sf::Vector2f(150, 400);

	wall = SineWall(50,2,100,50, position,sf::Vector2f(0.4,0.6),(*SineFunction));
	player = Player(sf::Vector2f(400.f, 300.f), 5.f, playerCol);
}

void Game::Draw() {
	_window->draw(player.CollisionBox().collision);
	_window->draw(wall.Wall());
}

void Game::Update() {
	player.Update();
	wall.Update();
}

Game::~Game()
{
}
