#include "Transition.h"


Transition::Transition()
{
	comparison = [](const Pet* const pet, const World* const world) -> const bool { return true; };
}

Transition::Transition(const bool(* function)(const Pet* const pet, const World* const world)): comparison(function)
{
}
	
Transition::~Transition()
{
}

bool Transition::process(const Pet* const pet, const World* const world) const
{
	cout << "Process transition" << endl;
	//auto comparison = [](auto value, auto threshold) -> bool {return value <= threshold; };
	return comparison(pet, world);
}
