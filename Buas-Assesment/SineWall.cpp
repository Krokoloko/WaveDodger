#include "SineWall.h"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

SineWall::SineWall()
{
}

SineWall::SineWall(int aCubeSideCount, int aMaxWaveAmount, float aWidth, float aLength,sf::Vector2f aPosition, 
	sf::Vector2f aDirection, float(*aWaveFunction)(float)) {
	
	_cubeSideCount = aCubeSideCount;
	_maxWaveAmount = aMaxWaveAmount;
	_width = aWidth;
	_length = aLength;
	_position = aPosition;
	_direction = aDirection;
	_sineFunction = aWaveFunction;

	_waves = new Wave[_maxWaveAmount];
	_wall = sf::VertexArray(sf::Quads, _cubeSideCount * 5);

	for (int i = 0; i < _cubeSideCount; i++) {
		_wall[(i*5)].position = sf::Vector2f(
			-_width / 2 + i * (_width/_cubeSideCount),
			_length / 2
		) + _position;
		std::cout << _wall[i].position.x << ", " << _wall[i].position.y << "\n";
	}
}

void SineWall::GenerateWave() {
	if (_waveCount < _maxWaveAmount) {
		
		Wave wave(_cubeSideCount);
		
		_waves[_waveCount] = wave;

		_waveCount++;
	}
}

void SineWall::Update() {
	for (int i = 0; i < _waveCount; i++) {
		
		_waves[i].UpdateWaves(0.314,_sineFunction);

		int* waveVals = _waves[i].GetWaveValues();
		for (int j = 0; j < _waves[i].Length(); j++) {
			if (j-_waves[i].UnitsTraveled() >= 0 && j-_waves[i].UnitsTraveled() < _wall.getVertexCount()) {
				sf::Vector2f waveFrequent(_wall[j].position.x, waveVals[j]);
				_wall[j - _waves[i].UnitsTraveled()].position = waveFrequent;
			}
		}
	}
	
}

int SineWall::CubeSideCount() {
	return _cubeSideCount;
}

float SineWall::Width() {
	return _width;
}

float SineWall::Length() {
	return _length;
}

sf::Vector2f SineWall::Position() {
	return _position;
}

sf::Vector2f SineWall::Direction() {
	return _direction;
}

sf::VertexArray SineWall::Wall() {
	return _wall;
}

SineWall::~SineWall()
{
}
