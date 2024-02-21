#ifndef SPRITE_COMPONENT
#define SPRITE_COMPONENT

#include <typeinfo>

#include "../Component.h"
#include "TransformComponent.h"
#include "../Entity.h"

class SpriteComponent : public Component
{
private:
	TransformComponent* transform = NULL;
public:

	void Init()
	{
		this->transform = this->owner->GetComponent<TransformComponent>();
	}

	void Update(float dt)
	{

	}

	void Render()
	{
		DrawRectangle(this->transform->position.x, this->transform->position.y, 50, 50, RED);
		std::string vel_line = "Velocity:" + std::to_string(this->owner->GetComponent<TransformComponent>()->velocity.x)
			+ std::string("; ")
			+ std::to_string(this->owner->GetComponent<TransformComponent>()->velocity.y);
		std::string pos_line = "Position:" + std::to_string(this->owner->GetComponent<TransformComponent>()->position.x)
			+ std::string("; ")
			+ std::to_string(this->owner->GetComponent<TransformComponent>()->position.y);
		DrawText(pos_line.c_str(), 500, 0, Constants::fontSize, BLUE);
		DrawText(vel_line.c_str(), 500, Constants::fontSize + 5, Constants::fontSize, BLUE);
	}
};


#endif // !SPRITE_COMPONENT
