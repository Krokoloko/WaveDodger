#pragma once
class Wave
{
public:
	Wave();
	Wave(int, float, float);
	int Length();
	int UnitsTraveled();
	float MaxLength();
	float DistanceTraveled();
	float WavePower();

	//Returns an array of values that corespond the wave
	float* GetWaveValues();

	void UpdateWaves(float, float(*_waveFunction)(float, float));

	~Wave();
private:
	bool _autoUpdate; // Determines to update values when calling GetWaveValues

	int _length;
	int _unitsTraveled;
	float _maxLength; 
	float _distanceTraveled;
	float _wavePower;

	float* _waveValues;
};

