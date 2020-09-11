#include "World.h"

World::World()
{
	cout << "Hello World !" << endl;
	m_pets = vector<Pet*>();
}

World::World(const World& world)
{
	m_pets = world.get_pets();
}

World& World::operator=(const World& world)
{
	m_pets = world.get_pets();
	return *this;
}

World::~World()
{
	for(size_t i = 0; i < m_pets.size(); ++i)
	{
		delete m_pets[i];
	}
	cout << "Goodbye World." << endl;
}

void World::set_pets(vector<Pet*> pets)
{
	m_pets = pets;
}

void World::update_world()
{
	for (size_t i = 0; i < m_pets.size(); ++i)
	{
		m_pets[i]->update_pet();
	}
}


