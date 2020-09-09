#include "State.h"

//TODO : complete functions

State::State(): m_name("State")
{
}

State::State(const string& name, const Transition& transition)
{
	m_name = name;
}

State::State(const State& s)
{
	
}

State& State::operator=(const State& s)
{
}

State::~State()
{
}

void State::set_name(const string& name)
{
}

void State::set_transitions(const map<Transition, State>& transitions)
{
}

void State::add_transition(const Transition& transition, const State& state)
{
}

State State::get_next_state(const Transition& transition) const
{
}
