#include "State.h"

State::State()
{
	m_type = StateType::NONE;
	m_transitions = vector<pair<Transition*, State*>>();
	action = []() -> const void {};
}

State::State(const void(*function)()): action(function)
{
	m_type = StateType::NONE;
	m_transitions = vector<pair<Transition*, State*>>();
}

State::~State()
{
	m_transitions.clear();
}

void State::set_type(StateType type)
{
	m_type = type;
}

void State::set_transitions(const vector<pair<Transition*, State*>>& transitions)
{
	m_transitions = transitions;
}

void State::add_transition(Transition* transition, State* state)
{
	cout << "Add transition from " << this->get_type() << " to " << state->get_type() << endl;
	const pair<Transition*, State*> pair(transition, state);
	m_transitions.push_back(pair);
}

void State::perform_action() const
{
	cout << "Perform state action" << endl;
	action();
}

