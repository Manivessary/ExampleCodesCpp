#include <iostream>
#include <array>
#include <string>
#include <memory>
// #include "String.h"

class Entity
{
public:
	Entity() { std::cout << "Entity Created" << std::endl; }
	~Entity() { std::cout << "Entity Deleted" << std::endl; }
};

class ScopedPtr {
public:
	ScopedPtr(Entity* entity) 
		:m_Obj(entity)
	{
	}
	~ScopedPtr()	
	{
		delete m_Obj;
	}

private:
	Entity* m_Obj;;
};

int main() {

	{
		Entity* entity = new Entity();
	}

	std::cin.get();
}