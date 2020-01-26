#pragma once
#include <SFML/Graphics.hpp>
#include "Wave.h"

class SineWall
{
public:	
	SineWall();
	SineWall(int, int, float, float, sf::Vector2f, sf::Vector2f, float(*)(float, float));

	enum GenerateSide {Bottom, Surface};

	int CubeSideCount();
	float Width();
	float Length();
	sf::Vector2f Position();
	sf::Vector2f Direction();

	sf::VertexArray Wall();

	void GenerateWave();
	void Update();

	~SineWall();
private:
	int _cubeSideCount;
	float _width;
	float _length;
	sf::Vector2f _position;
	sf::Vector2f _direction;

	float (*_sineFunction)(float, float);

	bool _debug;

	int _waveCount;
	int _maxWaveAmount;
	Wave* _waves;

	sf::VertexArray _wallOrigin;
	sf::VertexArray _wall;
};

