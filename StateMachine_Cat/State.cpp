#include "State.h"

State::State(): m_name("State")
{
	m_transitions = vector<pair<Transition*, State*>>();
}

State::State(const string& name)
{
	m_name = name;
	m_transitions = vector<pair<Transition*, State*>>();
}

State::State(const string& name,Transition* transition, State* state)
{
	m_name = name;
	this->add_transition(transition, state);
}

State::State(const string& name, const 	vector<pair<Transition*, State*>>& transitions)
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
	m_transitions.clear();
}

void State::set_name(const string& name)
{
	m_name = name;
}

void State::set_transitions(const 	vector<pair<Transition*, State*>>& transitions)
{
	m_transitions = transitions;
}

void State::add_transition(Transition* transition, State* state)
{
	cout << "Add transition from " << this->get_name() << " to " << state->get_name() << endl;
	pair<Transition*, State*> pair(transition, state);
	m_transitions.push_back(pair);
}
