#ifndef GAME_H
#define GAME_H

#include <vector>
#include "raylib.h"
#include "Entity.h"
#include "Constants.h"


class Game
{
private:
	int windowWidth = Constants::windowWidth;
	int windowsHeight = Constants::windowHeight;
	
	Entity* player = NULL;
	Entity* HUD = NULL;
	Camera2D* camera = NULL;
	std::vector<Entity*> world;

	void SetupBasicEntities();
	void Init();
	void Update();
	void Render();
public:
	Game(int width, int height);
	std::vector<Entity*> GetWorld();
	void Run();
	void Exit();
};

#endif 
