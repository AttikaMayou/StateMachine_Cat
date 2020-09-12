#include "Transition.h"

#include "CONST_VALUES.h"

Transition::Transition()
{
	comparison = [](Pet* pet, House* house) -> bool
	{
		return true;
	};
}

Transition::Transition(function <bool(Pet*, House*)> f): comparison(f)
{
}
	
Transition::~Transition()
{
}

bool Transition::process(Pet* pet, House* house) const
{
	return comparison(pet, house);
}
