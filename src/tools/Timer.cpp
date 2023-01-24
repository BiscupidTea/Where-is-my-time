#include "Timer.h"

Timer::Timer(float timerValue)
{
	this->timerPass = timerValue;
	this->IsEnded = false;
	this->IsPaused = false;
}

Timer::~Timer()
{

}

void Timer::UpdateTimer()
{
	if (!IsPaused)
	{
		timerPass -= GetFrameTime();
	}

	if (timerPass <= 0)
	{
		if (!IsEnded)
		{
			IsEnded = true;
			timerPass = 0;
		}
	}
}

float Timer::GetTimer()
{
	return timerPass;
}

bool Timer::GetIsTimeEnd()
{
	return IsEnded;
}

void Timer::SetIsPaused(bool setPause)
{
	IsPaused = setPause;
}

bool Timer::GetIsPaused()
{
	return IsPaused;
}