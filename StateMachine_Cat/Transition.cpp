#include "Transition.h"

#include "CONST_VALUES.h"

Transition::Transition()
{
	//auto 
	//comparison = std::function<bool(Pet*, House*)>;
	comparison = [](Pet* pet, House* house) -> bool
	{
		return pet->get_thirst() >= CONST_VALUES::THIRST_THRESHOLD
			&& house->get_cat_bowl_status();
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
	cout << "Process transition" << endl;
	//auto comparison = [](auto value, auto threshold) -> bool {return value <= threshold; };
	return comparison(pet, house);
}
