#pragma once
#include <vector>
#include"State.h"

using namespace std;

class StateMachine
{
private:
	State* m_start;
	State* m_end;
	State* m_current;
	vector<State*> m_states;

public:
	//Constructors
	StateMachine();
	StateMachine(State* start, State* end);
	StateMachine(const StateMachine& s);

	//Operator =
	StateMachine& operator=(const StateMachine& s);
	
	//Destructor
	~StateMachine();

	//Getter
	State* get_start() const { return m_start; }
	State* get_end() const { return m_end; }
	State* get_current() const { return m_current; }
	vector<State*> get_states() const { return m_states; }
	
	//Setter
	void set_start(State* start);
	void set_end(State* end);
	void set_current(State* current);

	//Functions
	void add_state(State* state);
	void process_state();
	void change_state(State* state);
	
};

