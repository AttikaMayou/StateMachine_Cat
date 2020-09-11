#include "Transition.h"


Transition::Transition()
{
	comparison = [](const Pet* const pet, const House* const house) -> const bool { return true; };
}

Transition::Transition(const bool(* function)(const Pet* const pet, const House* const house)): comparison(function)
{
}
	
Transition::~Transition()
{
}

bool Transition::process(const Pet* const pet, const House* const house) const
{
	cout << "Process transition" << endl;
	//auto comparison = [](auto value, auto threshold) -> bool {return value <= threshold; };
	return comparison(pet, house);
}
