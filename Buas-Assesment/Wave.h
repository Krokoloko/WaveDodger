#pragma once
class Wave
{
public:
	Wave();
	Wave(int);
	int Length();
	int UnitsTraveled();
	float DistanceTraveled();

	//Returns an array of values that corespond the wave
	int* GetWaveValues();

	void UpdateWaves(float, float(*_waveFunction)(float));

	~Wave();
private:
	bool _autoUpdate; // Determines to update values when calling GetWaveValues

	int _length;
	int _unitsTraveled;
	float _distanceTraveled;

	int* _waveValues;
};

