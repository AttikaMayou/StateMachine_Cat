#include "StateMachine.h"

StateMachine::StateMachine()
{
	m_begin = new State("Idle");
	m_current = m_begin;
	m_states.push_back(m_begin);
	m_transitions = vector<const Transition* const>();
}

StateMachine::StateMachine(State* const begin)
{
	m_begin = begin;
	m_current = m_begin;
	m_states = vector<const State*>();
	m_states.push_back(m_begin);
	m_transitions = vector<const Transition* const>();
}

StateMachine::StateMachine(const StateMachine& s)
{
	m_begin = s.get_begin();
	m_current = m_begin;
	m_states = s.get_states();
	m_transitions = s.get_transitions();
}

StateMachine& StateMachine::operator=(const StateMachine& s)
{
	m_begin = s.get_begin();
	m_current = s.get_current();
	m_states = s.get_states();
	m_transitions = s.get_transitions();
	return *this;
}

StateMachine::~StateMachine()
{
	for (size_t i = 0; i < m_states.size(); ++i)
	{
		delete m_states[i];
	}

	for(size_t i = 0; i < m_transitions.size(); ++i)
	{
		delete m_transitions[i];
	}
}

void StateMachine::set_current(State* const current)
{
	cout << "Change current state from " << this->get_current()->get_name() << " to " << current->get_name() << endl;
	m_current = current;
}

//Assert quand on essaie d'ajouter un state qui existe déjà
void StateMachine::add_state(State* const state)
{
	//check if state machine already contains state
	m_states.push_back(state);
}

void StateMachine::set_begin(State* const begin)
{
	m_begin = begin;
}

void StateMachine::process_state()
{
	const State* const current_state = this->get_current();
	if(current_state == nullptr)
	{
		cout << "No current state !!!!!" << endl;
		return;
	}
	cout << "Process current state : " << current_state->get_name() << endl;
	vector<pair<const Transition* const, State* const>> transitions = current_state->get_transitions();
	size_t const transitions_size = transitions.size();

	if(transitions_size <= 0)
	{
		cout << "No transition from state " << current_state->get_name() << endl;
		return;
	}
	
	for(size_t i = 0; i < transitions_size; ++i)
	{
		if(transitions[i].first->process())
		{
			this->change_state(transitions[i].second);
			break;
		}
	}
}

void StateMachine::change_state(State* const state)
{
	this->set_current(state);
}
