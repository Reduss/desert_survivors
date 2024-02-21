#include "raylib.h"
#include <iostream>


#include "Game.h"
#include "Entity.h"
#include "Component.h"
#include "components/HUDComponent.h"
#include "components/SpriteComponent.h"
#include "components//TransformComponent.h"
#include "components//KeyboardControlComponent.h"


Game::Game(int w, int h)
{
	this->windowWidth = w;
	this->windowsHeight = h;
}

std::vector<Entity*> Game::GetWorld()
{
	return this->world;
}

void Game::SetupBasicEntities()
{
	Entity* HUD = new Entity("hud");
	Entity* player = new Entity("player");

	HUD->AddComponent<HUDComponent>(new HUDComponent(*this));
	player->AddComponent<TransformComponent>(new TransformComponent());
	player->AddComponent<KeyboardControlComponent>(new KeyboardControlComponent());
	player->AddComponent<SpriteComponent>(new SpriteComponent());


	this->world.push_back(HUD);
	this->world.push_back(player);

	for (auto* c : this->world)
	{
		c->InitComponents();
	}
}

void Game::Init()
{
	InitWindow(this->windowWidth, this->windowsHeight, "Desert Survivors 0.1");
	SetTargetFPS(60);
	this->SetupBasicEntities();
}

void Game::Update()
{
	float dt = GetFrameTime();


	for (Entity* e : world)
	{
		e->Update(dt);
	}
}

void Game::Render()
{
	BeginDrawing();

	ClearBackground(WHITE);


	for (Entity* e : world) 
	{
		e->Render();
	}

	EndDrawing();
}

void Game::Run()
{
	// call init
	// game loop
	//		get input
	//		call update
	//		call render
	// exit

	this->Init();
	
	while (!WindowShouldClose())
	{
		this->Update();
		this->Render();
	}


}