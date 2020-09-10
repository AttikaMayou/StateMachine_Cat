#include "StateMachine.h"

StateMachine::StateMachine()
{
	m_start = new State();
	m_end = new State();
	m_current = m_start;
	m_states.push_back(*m_start);
	m_states.push_back(*m_end);
}

StateMachine::StateMachine(State* start, State* end)
{
	m_start = start;
	m_end = end;
	m_current = m_start;
	m_states.clear();
	m_states.push_back(*m_start);
	m_states.push_back(*m_end);
}

StateMachine::StateMachine(const StateMachine& s)
{
	m_start = s.get_start();
	m_end = s.get_end();
	m_current = m_start;
	m_states.clear();
	m_states.push_back(*m_start);
	m_states.push_back(*m_end);
}

StateMachine& StateMachine::operator=(const StateMachine& s)
{
	m_start = s.get_start();
	m_end = s.get_end();
	m_current = m_start;
	m_states.clear();
	m_states.push_back(*m_start);
	m_states.push_back(*m_end);
	return *this;
}

StateMachine::~StateMachine()
{
	m_states.clear();
	//delete m_current;
	delete m_start;
	delete m_end;
}

void StateMachine::set_start(State* start)
{
	m_start = start;
}

void StateMachine::set_end(State* end)
{
	m_end = end;
}

void StateMachine::set_current(State* current)
{
	m_current = current;
}

void StateMachine::add_state(const State& state)
{
	m_states.push_back(state);
}

void StateMachine::process_state()
{
	State* current_state = this->get_current();
	vector<pair<Transition, State>> transitions = current_state->get_transitions();
	int const transitions_size = transitions.size();

	for(int i = 0; i < transitions_size; ++i)
	{
		if(transitions[i].first.process())
		{
			this->change_state(&(transitions[i].second));
		}
	}
}

void StateMachine::change_state(State* state)
{
	this->set_current(state);
}
