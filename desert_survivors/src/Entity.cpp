#include <iostream>
#include <stdexcept>
#include <string>
#include <typeinfo>

#include "Entity.h"

Entity::Entity(std::string name)
{
	this->name = name;
}

void Entity::Update(float dt)
{
	std::cout << "IN ENTITY UPDATE" << std::endl;
	for (const auto& pair: this->components)
	{
		pair.second->Update(dt);
	}
}

void Entity::Render()
{
	for (const auto& pair : this->components)
	{
		pair.second->Render();
	}
}

void Entity::InitComponents()
{
	for (const auto& pair : this->components)
	{
		pair.second->Init();
	}
}


std::string Entity::GetName()
{
	return this->name;
}

Entity::~Entity()
{
	// TODO: delete components?
	// enity is not the owner of its components?
	// Should there be a manager that will do that? EntityManager?

	for (const auto& pair : this->components)
	{
		delete pair.second;
	}
	this->components.clear();
}