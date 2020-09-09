#pragma once
#include"State.h"

class StateMachine
{
private:
	State* m_start;
	State* m_end;

public:
	//Constructors
	StateMachine();
	StateMachine(const State& start, const State& end);
	StateMachine(const StateMachine& s);

	//Operator =
	StateMachine& operator=(const StateMachine& s);
	
	//Destructor
	~StateMachine();

	//Getter
	State* get_start() const { return m_start; }
	State* get_end() const { return m_end; }
	
	//Setter
	void set_start(const State& start);
	void set_end(const State& end);
	void set_current(const State& current);

	//Functions
	void process_state();
	void change_state(const State& state);
	
};

