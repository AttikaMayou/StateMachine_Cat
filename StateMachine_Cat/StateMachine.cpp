#include "StateMachine.h"

StateMachine::StateMachine()
{
	m_begin = new State();
	m_current = m_begin;
	m_states.push_back(m_begin);
	m_transitions = vector<Transition*>();
}

StateMachine::StateMachine(State* begin)
{
	m_begin = begin;
	m_current = m_begin;
	m_states = vector<State*>();
	m_states.push_back(m_begin);
	m_transitions = vector<Transition*>();
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
	cout << "Change current state from " << this->get_current()->get_type() << " to " << current->get_type() << endl;
	m_current = current;
}

//Assert quand on essaie d'ajouter un state qui existe déjà
void StateMachine::add_state(State* state)
{
	//check if state machine already contains state
	m_states.push_back(state);
}

void StateMachine::set_begin(State* begin)
{
	m_begin = begin;
}

void StateMachine::process_state()
{
	State* current_state = this->get_current();
	if(current_state == nullptr)
	{
		cout << "No current state !!!!!" << endl;
		return;
	}
	cout << "Process current state : " << current_state->get_type() << endl;
	vector<pair<Transition*, State*>> transitions = current_state->get_transitions();
	size_t const transitions_size = transitions.size();

	if(transitions_size <= 0)
	{
		cout << "No transition from state " << current_state->get_type() << endl;
		return;
	}
	
	for(size_t i = 0; i < transitions_size; ++i)
	{
		Transition* curr_transition = transitions[i].first;
		if(curr_transition->process())
		{
			this->change_state(transitions[i].second);
			break;
		}
	}
}

void StateMachine::change_state(State* state)
{
	this->set_current(state);
}
