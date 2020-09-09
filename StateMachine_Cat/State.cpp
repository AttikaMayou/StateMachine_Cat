#include "State.h"

//TODO : complete functions

State::State(): m_name("State")
{
	m_transition = new Transition();
}

State::State(const string& name, const Transition& transition)
{
	m_name = name;
	m_transition = new Transition(transition);
}

State::State(const State& s)
{
	
}

State::~State()
{
	delete m_transition;
}

void State::set_name(const string& name)
{
}

void State::set_transition(const Transition& transition)
{
}

void State::add_transition(const Transition& transition, const State& sate)
{
}
