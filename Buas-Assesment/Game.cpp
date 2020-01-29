#include "Game.h"

#include "InputManager.h"
#include "Collision.h"
#include "SineWall.h"
#include "Player.h"

# define M_PI           3.14159265358979323846  /* pi */

#include <cmath>
#include <iostream>
#include <SFML/Graphics.hpp>

Game::Game(sf::RenderWindow *window)
{
	_window = window;
	_window->setFramerateLimit(60);
}

void Game::Start() {
	inputManager = InputManager();

	sf::VertexArray square(sf::Quads, 4);

	square[0].position = sf::Vector2f(-5, 0);
	square[1].position = sf::Vector2f(5, 0);
	square[2].position = sf::Vector2f(5, -10);
	square[3].position = sf::Vector2f(-5, -10);

	Collision playerCol(&(player), square);
	sf::Vector2f position = sf::Vector2f(-400, 500);

	auto sineFunction = [](float x, float m) {return float(fmin(0,(sin((x / 6) - M_PI * 6))*m)); };

	wall = SineWall(400,1,800,50, position,sf::Vector2f(0.4,0.6),sineFunction);
	player = Player(sf::Vector2f(400.f, 300.f), 10.f, 2.f, playerCol);

	generatedWalls = false;
}

void Game::Draw() {
	_window->draw(player.CollisionBox().collision);
	_window->draw(wall.Wall());
}



void Game::UpdateEvent(TriggerEvents e) {
	switch (e) {
		case TriggerEvents::GenerateWave:
			//std::cout << "Generate waves\n";
			wall.GenerateWave();
			generatedWalls = true;
			break;
		case TriggerEvents::Jump:
			player.Jump();
			//std::cout << "jump";
			break;
	}
}

void Game::CollisionUpdate() {
	if (player.CollisionBox().OnHitWith(wall.Wall())) {
		//std::cout << "Hit";
	}
}

void Game::Update() {
	if (player.State() == Player::Grounded) {
		if (!generatedWalls) {
			UpdateEvent(TriggerEvents::GenerateWave);
		}
	}
	player.UpdatePhysics();
	player.Update(wall);
	wall.Update();
}

Game::~Game()
{
}
