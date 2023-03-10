#include "TimerItem.h"

#include "raymath.h"
#include "tools/Tools.h"

namespace Game
{
	TimerItem::TimerItem(Vector2 position, Vector2 velocity, int width, int height, float timeAdd, float initPosition, float timeToSpawn, Texture2D textureTimer) : Entity(position, velocity, width, height)
	{
		this->position = position;
		this->velocity = velocity;

		this->textureTimer = textureTimer;
		this->width = textureTimer.width;
		this->height = textureTimer.height;

		this->timeAdd = timeAdd;
		this->initPosition = initPosition;

		this->maxSpace = 0;
		this->minSpace = 0;

		this->goingUp = true;

		this->timeToSpawn = timeToSpawn;
		this->holdTimer = new Timer(timeToSpawn);

	}

	TimerItem::~TimerItem()
	{

	}

	void TimerItem::Draw()
	{
		//DrawRectangle(static_cast<int>(position.x),static_cast<int>(position.y),width, height, YELLOW);
		DrawTexturePro(textureTimer,
			{ 0, 0, 64, 64 },
			{ position.x,position.y, 64, 64 },
			{ 0,	0, },
			0, WHITE);
	}

	void TimerItem::UpdateItem()
	{
		position.x -= velocity.x * GetFrameTime();

		if (goingUp)
		{
			position.y -= velocity.y * GetFrameTime();
		}
		else
		{
			position.y += velocity.y * GetFrameTime();
		}

		if (position.y < minSpace && goingUp)
		{
			goingUp = false;
		}
		else if (position.y + height > maxSpace && !goingUp)
		{
			goingUp = true;
		}

		if (position.x + width < 0)
		{
			ResetRandPosition();
		}
	}

	float TimerItem::GettimeAdd()
	{
		return timeAdd;
	}

	void TimerItem::ResetRandPosition()
	{
		float midPlayableScreen = GetPercentageScreenHeight(42.5);

		position.y = initPosition;
		minSpace = midPlayableScreen - midPlayableScreen / 2;
		maxSpace = midPlayableScreen + midPlayableScreen / 2;

		if (GetRandomValue(1, 2) == 1)
		{
			goingUp = true;
		}
		else
		{
			goingUp = false;
		}

		position.x = static_cast<float>(GetScreenWidth());
		holdTimer->ResetTime();
	}

	float TimerItem::GetTimeToSpawn()
	{
		return timeToSpawn;
	}

	bool TimerItem::OutOfLimits()
	{
		if (GetX() + width < 0)
		{
			return true;
		}

		return false;
	}
}