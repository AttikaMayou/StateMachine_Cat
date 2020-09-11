#pragma once
#include <iostream>
#include "Pet.h"
#include "House.h"

using namespace std;

class Transition
{
private:
	const bool(*comparison) (const Pet* const pet, const House* const house);
public:
	//Constructors
	Transition();
	Transition(const bool(*function)(const Pet* const pet, const House* const house));
	
	//Destructor
	~Transition();

	//Function
	bool process(const Pet* const pet, const House* const house) const;
};

