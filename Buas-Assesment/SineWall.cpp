#include "SineWall.h"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

# define M_PI           3.14159265358979323846  /* pi */


SineWall::SineWall()
{
}

SineWall::SineWall(int aCubeSideCount, int aMaxWaveAmount, float aWidth, float aLength,sf::Vector2f aPosition, 
	sf::Vector2f aDirection, float(*aWaveFunction)(float, float)) {
	
	_cubeSideCount = aCubeSideCount;
	_maxWaveAmount = aMaxWaveAmount;
	_width = aWidth;
	_length = aLength;
	_position = aPosition;
	_direction = aDirection;
	_sineFunction = aWaveFunction;
	_waveCount = 0;

	_debug = true;

	_waves = new Wave[_maxWaveAmount];
	_wall = sf::VertexArray(sf::Quads, _cubeSideCount * 4);

	for (int i = 0; i < _cubeSideCount; i++) {
		_wall[(i * 4)].position = sf::Vector2f(
			_width / 2 + (_width/_cubeSideCount)*i,
			-_length / 2
		) + _position;
		_wall[(i * 4) + 1].position = sf::Vector2f(
			_width / 2 + (_width / _cubeSideCount)*(i + 1),
			-_length / 2
		) + _position;
		_wall[(i * 4) + 2].position = sf::Vector2f(
			_width / 2 + (_width / _cubeSideCount )*(i + 1),
			_length / 2
		) + _position;
		_wall[(i * 4) + 3].position = sf::Vector2f(
			_width / 2 + (_width / _cubeSideCount)*i,
			_length / 2
		) + _position;

		_wallOrigin = _wall;

		//std::cout << "Cube( (" << _wall[(i * 4)].position.x << "," << _wall[(i * 4)].position.y << ") , (" << _wall[(i * 4) + 1].position.x << "," << _wall[(i * 4) + 1].position.y << ") , ("
		//	<< _wall[(i * 4) + 2].position.x << "," << _wall[(i * 4) + 2].position.y << ") , (" << _wall[(i * 4) + 3].position.x << "," << _wall[(i * 4) + 3].position.y << ") );\n";

		if (i == 0) {
			for (int j = 0; j < 4; j++) {
				_wall[(i*4 + j)].color = sf::Color::Green;
			}
		}
		else {
			if (i % 2 == 0) {
				for (int j = 0; j < 4; j++) {
					_wall[(i * 4 + j)].color = sf::Color::Green;
				}
			}
			else {
				for (int j = 0; j < 4; j++) {
					_wall[(i * 4 + j)].color = sf::Color::Yellow;
				}
			}
		}
	}
}

void SineWall::GenerateWave() {
	if (_waveCount < _maxWaveAmount) {
		
		Wave wave(_cubeSideCount, 25, M_PI*6);
		
		_waves[_waveCount] = wave;

		_waveCount++;
	}
}

void SineWall::Update() {
	for (int i = 0; i < _waveCount; i++) {
		
		_waves[i].UpdateWaves(0.314,_sineFunction);

		float* waveVals = _waves[i].GetWaveValues();
		for (int j = 0; j < _waves[i].Length(); j++) {
			int modulo;

			if ((_waves[i].UnitsTraveled()) - (j+1*4) != 0) {
				modulo = ((_waves[i].UnitsTraveled()) - (j+1*4)) % 4;
			}
			else modulo = 0;

			//Is it within the wall
			if (modulo == 0) {

				if (_waves[i].UnitsTraveled() - (j*4) > (j*4) + _waves[i].MaxLength() && _waves[i].UnitsTraveled() - (j*4) < _waves[i].UnitsTraveled() + _waves[i].MaxLength()) {
					_wall[(j * 4)].position = _wallOrigin[(j * 4)].position + sf::Vector2f(0, waveVals[j]);
					_wall[(j * 4) + 1].position = _wallOrigin[(j * 4) + 1].position + sf::Vector2f(0, waveVals[j]);
				}
				
			}
		}
		/*if (_waves[i].DistanceTraveled() + _waves[i].UnitsTraveled() - _waves[i].MaxLength()) {
			std::cout << "Delete";
		}*/
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
