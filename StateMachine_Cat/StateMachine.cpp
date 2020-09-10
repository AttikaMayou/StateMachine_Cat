#include "StateMachine.h"

StateMachine::StateMachine()
{
	m_idle = new State("Idle");
	m_current = m_idle;
	m_states.push_back(m_idle);
}

StateMachine::StateMachine(State* idle)
{
	m_idle = idle;
	m_current = m_idle;
	m_states.clear();
	m_states.push_back(m_idle);
}

StateMachine::StateMachine(const StateMachine& s)
{
	m_idle = s.get_idle();
	m_current = m_idle;
	m_states.clear();
	m_states = s.get_states();
}

StateMachine& StateMachine::operator=(const StateMachine& s)
{
	m_idle = s.get_idle();
	m_current = m_idle;
	m_states.clear();
	m_states.push_back(m_idle);
	return *this;
}

StateMachine::~StateMachine()
{
	m_states.clear();
	//delete m_current;
	delete m_idle;
}

void StateMachine::set_idle(State* idle)
{
	m_idle = idle;
}

void StateMachine::set_current(State* current)
{
	cout << "Change current state from " << this->get_current()->get_name() << " to " << current->get_name() << endl;
	m_current = current;
}

void StateMachine::add_state(State* state)
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
			break;
		}
	}
}

void StateMachine::change_state(State* state)
{
	this->set_current(state);
}
