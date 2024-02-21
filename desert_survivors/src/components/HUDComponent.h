#ifndef HUD_COMPONENT
#define HUD_COMPONENT

#include "raylib.h"
#include <iostream>

#include "../Component.h"
#include "../Game.h"
#include "../Constants.h"

class HUDComponent : public Component
{
private:
	Game* game = NULL;

public:
	HUDComponent(Game& game)
	{
		this->name = "hud_component";
		this->game = &game;
	}
	void Update(float dt)
	{

	}
	void Render()
	{
		auto world = game->GetWorld();
		int offset = Constants::fontSize * 2.5;
		float elapseTime = GetTime();
		std::string time_str = "Elapsed time: " + std::to_string(elapseTime);

		DrawFPS(0, 0);
		DrawText(time_str.c_str(), 0, offset, Constants::fontSize, RED);
		
		std::string line = "Entities(" + std::to_string(world.size()) + "):";
		DrawText(line.c_str(), 0, offset + 20, Constants::fontSize * 1.25, RED);


		for (Entity* e : world)
		{
			offset += Constants::fontSize;
			DrawText(e->GetName().c_str(), 0, offset, Constants::fontSize, RED);
		}
		offset = Constants::fontSize * 2;

	}
};

#endif // !HUD_COMPONENT
