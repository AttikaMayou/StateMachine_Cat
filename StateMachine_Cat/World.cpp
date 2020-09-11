#include "World.h"

World::World()
{
	cout << "Hello World !" << endl;
	m_house = new House();
	m_pets = vector<Pet*>();
}

World::World(const World& world)
{
	m_house = world.get_house();
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
	delete m_house;
	cout << "Goodbye World." << endl;
}

void World::set_house(House* house)
{
	m_house = house;
}

void World::set_pets(vector<Pet*> pets)
{
	m_pets = pets;
}

void World::add_pet(Pet* pet)
{
	m_pets.push_back(pet);
}

void World::update_world()
{
	const size_t pets_nb = m_pets.size();
	for (size_t i = 0; i < pets_nb; ++i)
	{
		m_pets[i]->update_pet();
	}
}


