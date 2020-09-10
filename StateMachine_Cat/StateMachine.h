#pragma once
#include <vector>
#include"State.h"

using namespace std;

class StateMachine
{
private:
	State* m_idle;
	State* m_current;
	vector<State*> m_states;
	vector<Transition*> m_transitions;

public:
	//Constructors
	StateMachine();
	StateMachine(State* idle);
	StateMachine(const StateMachine& s);

	//Operator =
	StateMachine& operator=(const StateMachine& s);
	
	//Destructor
	~StateMachine();

	//Getter
	State* get_idle() const { return m_idle; }
	State* get_current() const { return m_current; }
	vector<State*> get_states() const { return m_states; }
	vector<Transition*> get_transitions() const { return m_transitions; }
	
	//Setter
	void set_idle(State* idle);
	void set_current(State* current);

	//Functions
	void add_state(State* state);
	void process_state();
	void change_state(State* state);
};

