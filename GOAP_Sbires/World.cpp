#include "World.h"

World::World()
{
	cout << "Hello GOAP World !" << endl;
}

World::World(const World& world)
{
}

World& World::operator=(const World& world)
{
	return *this;
}

World::~World()
{
	cout << "Goodbye GOAP World." << endl;
}