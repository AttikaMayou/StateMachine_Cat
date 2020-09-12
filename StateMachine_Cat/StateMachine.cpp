#include "StateMachine.h"

StateMachine::StateMachine()
{
	m_begin = new State();
	m_current = m_begin;
	m_states.push_back(m_begin);
	m_transitions = vector<Transition*>();
	m_house = new House();
	m_pet = new Pet();
}

StateMachine::StateMachine(State* begin)
{
	m_begin = begin;
	m_current = m_begin;
	m_states = vector<State*>();
	m_states.push_back(m_begin);
	m_transitions = vector<Transition*>();
	m_house = new House();
	m_pet = new Pet();
}

StateMachine::StateMachine(State* begin, House* house, Pet* pet)
{
	m_begin = begin;
	m_current = m_begin;
	m_states = vector<State*>();
	m_states.push_back(m_begin);
	if(m_begin->get_transitions().empty())
	{
		m_transitions = vector<Transition*>();
	}
	else
	{
		m_transitions = m_begin->get_only_transitions();
	}
	m_house = house;
	m_pet = pet;
}

StateMachine::StateMachine(const StateMachine& s)
{
	m_begin = s.get_begin();
	m_current = m_begin;
	m_states = s.get_states();
	m_transitions = s.get_transitions();
	m_house = s.get_house();
	m_pet = s.get_pet();
}

StateMachine& StateMachine::operator=(const StateMachine& s)
{
	m_begin = s.get_begin();
	m_current = s.get_current();
	m_states = s.get_states();
	m_transitions = s.get_transitions();
	m_house = s.get_house();
	m_pet = s.get_pet();
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
	
	delete m_pet;
	delete m_house;
}

void StateMachine::set_begin(State* begin)
{
	m_begin = begin;
}

void StateMachine::set_current(State* const current)
{
	cout << "Change current state from " << this->get_current()->get_type() << " to " << current->get_type() << endl;
	m_current = current;
}

void StateMachine::set_house(House* house)
{
	m_house = house;
}

void StateMachine::set_pet(Pet* pet)
{
	m_pet = pet;
}

//Assert quand on essaie d'ajouter un state qui existe déjà
void StateMachine::add_state(State* state)
{
	//check if state machine already contains state
	m_states.push_back(state);

	vector<Transition*> state_tr = state->get_only_transitions();
	const size_t tr_size = state_tr.size();

	m_transitions.reserve(m_transitions.capacity() + tr_size + 2);
	
	if(tr_size > 0)
	{
		for(size_t i = 0; i < tr_size; ++i)
		{
			m_transitions.push_back(state_tr[i]);
		}
	}
}

void StateMachine::process_state()
{
	State* current_state = this->get_current();
	if(current_state == nullptr)
	{
		cout << "No current state !!!!!" << endl;
		return;
	}
	
	//cout << "Process current state : " << current_state->get_type() << endl;
	vector<pair<Transition*, State*>> transitions = current_state->get_transitions();
	size_t const transitions_size = transitions.size();

	if(transitions_size <= 0)
	{
		//cout << "No transition from state " << current_state->get_type() << endl;
		return;
	}
	
	for(size_t i = 0; i < transitions_size; ++i)
	{
		if(transitions[i].first->process(m_pet, m_house))
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