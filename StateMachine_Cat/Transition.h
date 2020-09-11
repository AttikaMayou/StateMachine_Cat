#pragma once
#include <functional>
#include <iostream>
#include "Pet.h"
#include "House.h"

using namespace std;

class Transition
{
private:
	function< bool(Pet*, House*)> comparison;
public:
	//Constructors
	Transition();
	Transition(function <bool(Pet*, House*)>f);
	
	//Destructor
	~Transition();

	//Function
	bool process(Pet* pet, House* house) const;
};

