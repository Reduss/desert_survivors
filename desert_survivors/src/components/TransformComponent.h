#ifndef TRANSORM_COMPONENT
#define TRANSORM_COMPONENT

#include "../Component.h"
#include "raylib.h"


class TransformComponent : public Component
{
public:
	Vector2 position = { 100, 100 };
	Vector2 velocity = { 0, 0 };


	void Update(float dt)
	{
		position.x += velocity.x * dt;
		position.y += velocity.y * dt;
	}

	void Render()
	{

	}
};

#endif
