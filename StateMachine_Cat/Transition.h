#pragma once
#include <iostream>
#include "Pet.h"
#include "World.h"

using namespace std;

class Transition
{
private:
	const bool(*comparison) (const Pet* const pet, const World* const world);
public:
	//Constructors
	Transition();
	Transition(const bool(*function)(const Pet* const pet, const World* const world));
	
	//Destructor
	~Transition();

	//Function
	bool process(const Pet* const pet, const World* const world) const;
};

