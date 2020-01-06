//This is the code that runs the game, WaveDodger

//SFML graphics library to use it's graphical capabilities.
#include <SFML/Graphics.hpp>

//The math library from c++ to get access of the sine function.
#include <cmath>

//My custom classes for the project that will be put to use
#include "InputManager.h"

void Test() {
	printf("Hello World\n");
}

//Main program
int main()
{
	//The window where the grahpics is drawed on.
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

	InputManager inputManager;

	inputManager.SetEvent(InputManager::Jump, &Test);

	sf::VertexArray original_vertexes(sf::Triangles, 3);
	sf::VertexArray vertexes;



	original_vertexes[0].position = sf::Vector2f(10.f, 10.f);
	original_vertexes[1].position = sf::Vector2f(100.f, 10.f);
	original_vertexes[2].position = sf::Vector2f(100.f, 100.f);

	vertexes = original_vertexes;

	clock_t time;
	time = clock();


	while (window.isOpen())
	{
		vertexes[2] = sf::Vector2f(original_vertexes[2].position.x, sin(time - clock() / 50) * 20 + original_vertexes[2].position.y);


		sf::Event event;
		while (window.pollEvent(event))
		{
			inputManager.UpdateEvents(event);

			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(vertexes);
		window.display();
	}

	return 0;
}


