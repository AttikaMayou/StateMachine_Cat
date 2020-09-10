#include "State.h"

State::State(): m_name("State")
{
	m_transitions = new vector<pair<Transition, State>>();
}

State::State(const string& name, const 	vector<pair<Transition, State>>& transitions)
{
	m_name = name;
	m_transitions = transitions;
}

State::State(const State& s)
{
	m_name = s.get_name();
	m_transitions = s.get_transitions();
}

State& State::operator=(const State& s)
{
	m_name = s.get_name();
	m_transitions = s.get_transitions();
	return *this;
}

State::~State()
{
}

void State::set_name(const string& name)
{
	m_name = name;
}

void State::set_transitions(const 	vector<pair<Transition, State>>& transitions)
{
	m_transitions = transitions;
}

int State::get_transitions_size() const
{
	return m_transitions.size();
}

void State::add_transition(const Transition& transition, const State& state)
{
	m_transitions.push_back(pair<Transition, State>(transition, state));
}

State State::get_next_state(const Transition& transition) const
{
	return State();
}
