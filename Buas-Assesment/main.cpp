//This is the code that runs the game, WaveDodger

//SFML graphics library to use it's graphical capabilities.
#include <SFML/Graphics.hpp>

//The math library from c++ to get access of the sine function.
#include <cmath>


//Main program
int main()
{
	//The window where the grahpics is drawed on.
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");


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
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed) {
				switch (event.key.code)
				{
				case sf::Keyboard::A:
					printf("move left \n");
					continue;

				case sf::Keyboard::D:
					printf("move right \n");
					continue;

				case sf::Keyboard::W:
					printf("move up \n");
					continue;

				case sf::Keyboard::S:
					printf("move down \n");
					continue; 

				default:
					printf("key pressed \n");
					break;
				}
			}
		}
		window.clear();
		window.draw(vertexes);
		window.display();
	}

	return 0;
}


