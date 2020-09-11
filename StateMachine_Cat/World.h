#pragma once
#include "Pet.h"
#include <iostream>
#include <vector>

using namespace std;

enum WorldState
{
	NONE,
	BREAK_GLASS,
	PET_CAT,
	PET_DOG,
	FILL_CAT_BOWL,
	FILL_DOG_BOWL,
	DOG_DRINKING_WATER_ON_GROUND,
	CAT_EATING,
	DOG_EATING,
	CAT_DRINKING,
	DOG_DRINKING
};

class World
{
private:
	vector<Pet*> m_pets;

public:
	//Constructors
	World();
	World(const World& world);

	//Operator=
	World& operator=(const World& world);
	
	//Destructor
	~World();

	//Getter
	vector<Pet*> get_pets() const { return m_pets; }
	
	//Setter
	void set_pets(vector<Pet*> pets);
	
	//Functions
	void update_world();
};

