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
		DrawRectangle(this->transform->position.x, this->transform->position.y, this->transform->width, this->transform->height, RED);
		
	}
};


#endif // !SPRITE_COMPONENT
