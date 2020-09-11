#include "State.h"

State::State()
{
	m_type = WorldState::NONE;
	m_transitions = vector<pair<const Transition* const, State* const>>();
	action = []() -> const void {};
}

State::State(const void(*function)()): action(function)
{
	m_type = WorldState::NONE;
	m_transitions = vector<pair<const Transition* const, State* const>>();
}

State::~State()
{
	m_transitions.clear();
}

void State::set_type(WorldState type)
{
	m_type = type;
}

void State::set_transitions(const vector<pair<const Transition* const, State* const>>& transitions)
{
	m_transitions = transitions;
}

void State::add_transition(const Transition* const transition, State* const state)
{
	//cout << "Add transition from " << this->get_name() << " to " << state->get_name() << endl;
	pair<const Transition* const, State* const> pair(transition, state);
	m_transitions.push_back(pair);
}

void State::perform_action() const
{
	cout << "Perform state action" << endl;
	action();
}

