#include "State.h"

State::State()
{
	m_action = new Action();
	m_preconditions = vector<const Precondition* const>();
	m_effects = vector<const Effect* const>();
}

State::State(Action* action, const Precondition* const precondition, const Effect* const effect)
{
	m_action = action;
	m_preconditions = vector<const Precondition* const>();
	m_preconditions.push_back(precondition);
	m_effects = vector<const Effect* const>();
	m_effects.push_back(effect);
}

State::State(Action* action, vector<const Precondition* const> preconditions, vector<const Effect* const> effects)
{
	m_action = action;
	m_preconditions = preconditions;
	m_effects = effects;
}

State::State(const State& state)
{
	m_action = state.get_action();
	m_preconditions = state.get_preconditions();
	m_effects = state.get_effects();
}

State& State::operator=(const State& state)
{
	m_action = state.get_action();
	m_preconditions = state.get_preconditions();
	m_effects = state.get_effects();
	return *this;
}

State::~State()
{
	delete m_action;
	
	for(size_t i = 0; i < m_preconditions.size(); ++i)
	{
		delete m_preconditions[i];
	}
	
	for(size_t i = 0; i < m_effects.size(); ++i)
	{
		delete m_effects[i];
	}
}

void State::set_action(Action* const action)
{
	m_action = action;
}

void State::set_preconditions(const vector<const Precondition* const>& preconditions)
{
	m_preconditions = preconditions;
}

void State::set_effects(const vector<const Effect* const>& effects)
{
	m_effects = effects;
}

void State::add_precondition(const Precondition* const precondition)
{
	m_preconditions.push_back(precondition);
}

void State::add_effect(const Effect* const effect)
{
	m_effects.push_back(effect);
}





