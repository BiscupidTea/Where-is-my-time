#pragma once
#include "Entity.h"
#include "raylib.h"
#include "tools/Timer.h"

namespace Game
{
	class TimerItem : public Entity
	{
	private:
		float timeAdd;
		float timeToSpawn;
		float initPosition;
		float minSpace;
		float maxSpace;

		bool goingUp;

		Texture2D textureTimer;

	public:
		Timer* holdTimer;

		TimerItem(
			Vector2 position, Vector2 velocity,
			int width, int height,
			float timeAdd, float initPosition,
			float timeToSpawn,
			Texture2D textureTimer);
		~TimerItem();

		void Draw();

		void UpdateItem();

		float GettimeAdd();

		void ResetRandPosition();

		float GetTimeToSpawn();

		bool OutOfLimits();
	};
}