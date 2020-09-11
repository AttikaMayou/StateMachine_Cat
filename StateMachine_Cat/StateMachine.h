#pragma once
#include <vector>
#include"State.h"
#include "Transition.h"

using namespace std;

class StateMachine
{
private:
	State* m_begin;
	State* m_current;
	vector<const State*> m_states;
	vector<const Transition* const> m_transitions;

public:
	//Constructors
	StateMachine();
	StateMachine(State* const begin);
	StateMachine(const StateMachine& s);

	//Operator =
	StateMachine& operator=(const StateMachine& s);
	
	//Destructor
	~StateMachine();

	//Getter
	State* get_begin() const { return m_begin; }
	State* get_current() const { return m_current; }
	const vector<const State*>& get_states() const { return m_states; }
	const vector<const Transition* const>& get_transitions() const { return m_transitions; }
	
	//Setter
	void set_begin(State* const begin);
	void set_current(State* const current);

	//Functions
	void add_state(State* const state);
	void process_state();
	void change_state(State* const state);
};

