//This is the code that runs the game, WaveDodger

//SFML graphics library to use it's graphical capabilities.
#include <SFML/Graphics.hpp>

//The math library from c++ to get access of the sine function.
#include <cmath>

//My custom classes for the project that will be put to use
#include "Game.h"

//Main program
int main()
{
	//The window where the grahpics is drawed on.
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

	clock_t time;
	time = clock();

	Game game(&window);

	game.Start();
	game.Draw();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		game.Draw();
		window.display();
	}

	return 0;
}

