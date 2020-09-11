#pragma once
#include <vector>
#include "State.h"
#include "Transition.h"

using namespace std;

class StateMachine
{
private:
	State* m_begin;
	State* m_current;
	vector<State*> m_states;
	vector<Transition*> m_transitions;

public:
	//Constructors
	StateMachine();
	StateMachine(State* begin);
	StateMachine(const StateMachine& s);

	//Operator =
	StateMachine& operator=(const StateMachine& s);
	
	//Destructor
	~StateMachine();

	//Getter
	State* get_begin() const { return m_begin; }
	State* get_current() const { return m_current; }
	const vector<State*>& get_states() const { return m_states; }
	const vector<Transition*>& get_transitions() const { return m_transitions; }
	
	//Setter
	void set_begin(State* begin);
	void set_current(State* current);

	//Functions
	void add_state(State* state);
	void process_state();
	void change_state(State* state);
};

