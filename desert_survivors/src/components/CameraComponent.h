#ifndef CAMERA_COMPONENT
#define CAMERA_COMPONENT

#include "raylib.h"

#include "../Component.h"
#include "TransformComponent.h"
#include "../Entity.h"

class CameraComponent : public Component
{
private:
	Camera2D camera;
	TransformComponent* transfrom;
public:
	void Init()
	{
		this->transfrom = this->owner->GetComponent<TransformComponent>();

		this->camera.zoom = 1.0;
		this->camera.offset = 
		{ 
			(float)Constants::windowWidth / 2 ,
			(float)Constants::windowHeight / 2 ,
		};
		this->camera.rotation = 0.0;

	}

	void Update(float df)
	{
		this->camera.target = {
			this->transfrom->position.x + this->transfrom->width / 2,
			this->transfrom->position.y + this->transfrom->height / 2,
		};

	}

	void Render()
	{
		std::string cam_line = "Camera target:" + std::to_string(this->camera.target.x)
			+ std::string("; ")
			+ std::to_string(this->camera.target.y);
		DrawText(cam_line.c_str(), this->transfrom->position.x, this->transfrom->position.y  - 50, Constants::fontSize / 1.5, BLUE);
	}
	
	Camera2D* GetCamera()
	{
		return &this->camera;
	}
};


#endif // !CAMERA_COMPONENT
