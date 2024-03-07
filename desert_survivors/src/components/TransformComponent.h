#ifndef TRANSORM_COMPONENT
#define TRANSORM_COMPONENT

#include "../Component.h"
#include "raylib.h"


class TransformComponent : public Component
{
public:
	Vector2 position = { 0, 0};
	Vector2 velocity = { 0, 0 };
	int width = 0;
	int height = 0;

	TransformComponent(int w, int h, Vector2 pos)
	{
		this->width = w;
		this->height = h;
		this->position = pos;
	}

	void Update(float dt)
	{
		position.x += velocity.x * dt;
		position.y += velocity.y * dt;
	}

	void Render()
	{
		std::string vel_line = "Velocity:" + std::to_string(this->velocity.x)
			+ std::string("; ")
			+ std::to_string(this->velocity.y);
		std::string pos_line = "Position:" + std::to_string(this->position.x)
			+ std::string("; ")
			+ std::to_string(this->position.y);
		DrawText(pos_line.c_str(), this->position.x, this->position.y - Constants::fontSize/ 1.5 * 2, Constants::fontSize / 1.5, BLUE);
		DrawText(vel_line.c_str(), this->position.x, this->position.y - Constants::fontSize / 1.5, Constants::fontSize / 1.5, BLUE);
	}
};

#endif
