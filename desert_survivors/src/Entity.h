#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <map>
#include <string>
#include <typeinfo>

#include "Component.h"

class Entity
{
private:
	bool isActive = true;
	//std::vector<Component*> components;
	std::map<const std::type_info*, Component*> components;
	std::string name;
public:

	Entity(std::string name);

	void Update(float dt);
	void Render();
	void InitComponents();
	std::string GetName();
	//bool AddComponent(Component* comp);
	//bool RemoveComponent(Component* comp);


	template <typename T>
	bool AddComponent(T* comp)
	{
		//if (this->components.find(typeInfoPtr) != this->components.end()) {
		//	return false; // Component already exists
		//}
		
		comp->owner = this;

		this->components[&(typeid(T))] = comp;
		return true;
	}

	template<typename T>
	bool RemoveComponent()
	{
		if (this->components.empty() || this->components.find(typeid(T)) == this->components.end())
		{
			return false;
		}

		this->components.erase(typeid(T));
		return true;
	}

	template<typename T>
	T* GetComponent()
	{
		auto it = this->components.find(&typeid(T));
		if (it == this->components.end())
		{
			throw std::runtime_error(std::string("Couldnt find requested component"));
		}
		/*for (const auto pair : this->components)
		{
			if (pair.first == &typeid(T))
			{
				return dynamic_cast<T*>(pair.second);
			}
		}*/
		return dynamic_cast<T*>(it->second);
	}

	~Entity();
};


#endif // !ENTITY_H
