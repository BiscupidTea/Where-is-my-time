#pragma once
#include "raylib.h"

class Timer
{
private:
	float timerValue;
	float timerPass;
	bool IsEnded;
	bool IsPaused;

public:
	Timer(float timer);
	~Timer();

	void UpdateTimer();
	float GetTimer();

	bool GetIsTimeEnd();

	void SetIsPaused(bool setPause);
	bool GetIsPaused();
};

