#include "Wave.h"

Wave::Wave()
{
}

Wave::Wave(int aLength, float aWavePower, float aMaxLength) {
	_length = aLength;
	_waveValues = new float[_length];
	_wavePower = aWavePower;
	_maxLength = aMaxLength;
}

int Wave::Length() {
	return _length;
}

int Wave::UnitsTraveled() {
	return _unitsTraveled;
}

float Wave::MaxLength() {
	return _maxLength;
}

float Wave::DistanceTraveled() {
	return _distanceTraveled;
}

float Wave::WavePower() {
	return _wavePower;
}

float* Wave::GetWaveValues() {
	return _waveValues;
}

void Wave::UpdateWaves(float step, float(*_waveFunction)(float, float)) {
	_distanceTraveled += step;
	_unitsTraveled++;
	for (int i = 0; i < _length; i++) {
		_waveValues[i] = _waveFunction(_distanceTraveled + (float(i * step)), _wavePower);
	}
}

Wave::~Wave()
{
}
