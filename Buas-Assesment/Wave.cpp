#include "Wave.h"

Wave::Wave()
{
}

Wave::Wave(int aLength) {
	_length = aLength;
}

int Wave::Length() {
	return _length;
}

int Wave::UnitsTraveled() {
	return _unitsTraveled;
}

float Wave::DistanceTraveled() {
	return _distanceTraveled;
}

int* Wave::GetWaveValues() {
	return _waveValues;
}

void Wave::UpdateWaves(float step, float(*_waveFunction)(float)) {
	_distanceTraveled += step;
	_unitsTraveled++;
	for (int i = 0; i < _length; i++) {
		_waveValues[i] = _waveFunction(_distanceTraveled +(i*step));
	}
}

Wave::~Wave()
{
}
