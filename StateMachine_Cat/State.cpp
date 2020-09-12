#include "State.h"

State::State()
{
	m_type = StateType::IDLE;
	m_transitions = vector<pair<Transition*, State*>>();
	m_action = [](Pet*, House*) -> void {};
}

State::State(StateType type, function<void(Pet*, House*)> f): m_action(f)
{
	m_type = StateType::IDLE;
	m_transitions = vector<pair<Transition*, State*>>();
}

State::~State()
{
	m_transitions.clear();
}

const vector<Transition*> State::get_only_transitions() const
{
	vector<Transition*> tr;

	size_t size_tr = m_transitions.size();
	tr.reserve(size_tr + 2);

	for(size_t i = 0; i < size_tr; ++i)
	{
		tr.push_back(m_transitions[i].first);
	}

	return tr;
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
	//cout << "Add transition from " << this->get_type() << " to " << state->get_type() << endl;
	const pair<Transition*, State*> pair(transition, state);
	m_transitions.push_back(pair);
}

void State::perform_action(Pet* pet, House* house) const
{
	//cout << "Perform state action" << endl;
	m_action(pet, house);
}

