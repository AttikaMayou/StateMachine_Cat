#include "StateMachine.h"

StateMachine::StateMachine()
{
	m_idle = new State("Idle");
	m_current = m_idle;
	m_states.push_back(m_idle);
	m_transitions = vector<Transition*>();
}

StateMachine::StateMachine(State* idle)
{
	m_idle = idle;
	m_current = m_idle;
	m_states = vector<State*>();
	m_states.push_back(m_idle);
	m_transitions = vector<Transition*>();
}

StateMachine::StateMachine(const StateMachine& s)
{
	m_idle = s.get_idle();
	m_current = m_idle;
	m_states = s.get_states();
	m_transitions = s.get_transitions();
}

StateMachine& StateMachine::operator=(const StateMachine& s)
{
	m_idle = s.get_idle();
	m_current = s.get_current();
	m_states = s.get_states();
	m_transitions = s.get_transitions();
	return *this;
}

StateMachine::~StateMachine()
{
	for (unsigned int i = 0; i < m_states.size(); ++i)
	{
		delete m_states[i];
	}

	for(unsigned int i = 0; i < m_transitions.size(); ++i)
	{
		delete m_transitions[i];
	}
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

//Assert quand on essaie d'ajouter un state qui existe déjà
void StateMachine::add_state(State* state)
{
	//check if state machine already contains state
	m_states.push_back(state);
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
	vector<pair<Transition*, State*>> transitions = current_state->get_transitions();
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

void StateMachine::change_state(State* state)
{
	this->set_current(state);
}
