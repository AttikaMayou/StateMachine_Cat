#pragma once
#include"State.h"

//TODO : complete class (operator=)

class StateMachine
{
private:
	State* m_start;
	State* m_end;
	//Transition* m_transition;

public:
	//Constructors
	StateMachine();
	StateMachine(const State& start, const State& end, const Transition& transition);
	StateMachine(const StateMachine& s);

	//Destructor
	~StateMachine();

	//Getter
	State* get_start() const { return m_start; }
	State* get_end() const { return m_end; }
	Transition* get_transition() const { return m_transition; }
	
	//Setter
	void set_start(const State& start);
	void set_end(const State& end);
	void set_current(const State& current);
	void set_transition(const Transition& transition);

	//Functions
	void process_state();
	
};

