#include "StateMachine.h"

//TODO : complete functions

StateMachine::StateMachine()
{
	m_start = new State();
}

StateMachine::StateMachine(const State& start, const State& end, const Transition& transition)
{
}

StateMachine::StateMachine(const StateMachine& s)
{
}

StateMachine::~StateMachine()
{
	delete m_start;
	delete m_end;
	delete m_transition;
}

void StateMachine::set_start(const State& start)
{
}

void StateMachine::set_end(const State& end)
{
}

void StateMachine::set_current(const State& current)
{
}

void StateMachine::set_transition(const Transition& transition)
{
}

void StateMachine::process_state()
{
}
