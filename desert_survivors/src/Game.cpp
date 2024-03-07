#include "raylib.h"
#include <iostream>


#include "Game.h"
#include "Entity.h"
#include "Component.h"
#include "components/HUDComponent.h"
#include "components/SpriteComponent.h"
#include "components/TransformComponent.h"
#include "components/KeyboardControlComponent.h"
#include "components/CameraComponent.h"

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
	this->HUD = new Entity("hud");
	this->player = new Entity("player");

	HUD->AddComponent<HUDComponent>(new HUDComponent(*this));
	player->AddComponent<KeyboardControlComponent>(new KeyboardControlComponent());
	player->AddComponent<TransformComponent>(new TransformComponent(50, 50, {200, 200}));
	player->AddComponent<SpriteComponent>(new SpriteComponent());
	player->AddComponent<CameraComponent>(new CameraComponent());

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
	SetTargetFPS(Constants::targetFPS);
	
	this->SetupBasicEntities();
	this->camera = this->player->GetComponent<CameraComponent>()->GetCamera();

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

	// TODO: fix render lag


	BeginDrawing();
	
	ClearBackground(WHITE);


	BeginMode2D(*this->camera);

	DrawRectangle(0, 0, 100, 100, GREEN);
	DrawRectangle(500, 0, 100, 100, GREEN);
	DrawRectangle(500, 600, 100, 100, GREEN);
	DrawRectangle(0, 600, 100, 100, GREEN);
	
	for (Entity* e : world)
	{
		if (e->GetName() == "hud") { continue; }

		e->Render();
	}


	EndMode2D();
	this->HUD->Render();
	EndDrawing();
}

void Game::Run()
{
	this->Init();
	
	while (!WindowShouldClose())
	{
		this->Update();
		this->Render();
	}


}