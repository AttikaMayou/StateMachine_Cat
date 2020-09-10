#include "Transition.h"


Transition::Transition()
{
}

Transition::Transition(const Transition& transition)
{
}

Transition& Transition::operator=(const Transition& t)
{
	return *this;
}

Transition::~Transition()
{
}

bool Transition::process() const
{
	cout << "Process transition" << endl;
	return true;
}
