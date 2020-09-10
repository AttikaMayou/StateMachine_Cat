#pragma once
#include "Pet.h"
#include <iostream>
#include <vector>

using namespace std;

class World
{
private:
	//vector<Pet> m_pets;

public:
	//Constructors
	World();
	World(const World& world);

	//Operator=
	World& operator=(const World& world);
	
	//Destructor
	~World();

	//Getter
	//vector<Pet> get_pets() const { return m_pets; }
	
	//Setter
	//void set_pets(vector<Pet> pets);
	
	//Functions
};

