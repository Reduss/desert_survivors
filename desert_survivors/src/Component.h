#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>


class Entity;

class Component
{
protected:
	bool isActive = true;	// only update and render if the component is active
	bool isRenderable = true;	// only render if isRenderable = true
	std::string name = "basic_component";
public:
	Entity* owner = NULL;
	virtual void Init() { };
	virtual void Update(float dt) { };
	virtual void Render() { } ;
	void SetActive(bool isActive) { this->isActive = isActive; };
	void SetRenderable(bool isRenderable) { this->isRenderable = isRenderable; };
	
	bool IsActive() { return this->isActive; }
	bool IsRenderable() { return this->isRenderable; }

	std::string GetName() { return this->name; }
};

#endif