#ifndef KEYBOARD_CONTROL_COMPONENT
#define KEYBOARD_CONTROL_COMPONENT

#include "raylib.h"

#include "../Component.h"
#include "../Entity.h"
#include "TransformComponent.h"
#include "../Constants.h"

class KeyboardControlComponent : public Component
{
	TransformComponent* transform = NULL;
public:

	void Init()
	{
		this->transform = this->owner->GetComponent<TransformComponent>();

	}

	void Update(float dt)
	{

		this->transform->velocity.x = 0;
		this->transform->velocity.y = 0;
		if (IsKeyDown(KEY_A) && !IsKeyDown(KEY_D)) {
			this->transform->velocity.x = -Constants::baseSpeed;
		}
		if (IsKeyDown(KEY_D) && !IsKeyDown(KEY_A)) {
			this->transform->velocity.x = Constants::baseSpeed;
		}
		if (IsKeyDown(KEY_W) && !IsKeyDown(KEY_S)) {
			this->transform->velocity.y = -Constants::baseSpeed;
		}
		if (IsKeyDown(KEY_S) && !IsKeyDown(KEY_W)) {
			this->transform->velocity.y = Constants::baseSpeed;
		}
	}

	void Render()
	{

	}
};


#endif