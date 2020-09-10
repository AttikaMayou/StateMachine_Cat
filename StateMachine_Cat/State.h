#pragma once
#include <vector>
#include <string>

#include"Transition.h"
using namespace std;

class State
{
private:
	string m_name;
	vector<pair<Transition, State>> m_transitions;
	
public:
	//Constructors
	State();
	State(const string& name, const vector<pair<Transition, State>>& transitions);
	State(const State& s);

	//Operator =
	State& operator=(const State& s);

	//Destructor
	~State();

	//Getter
	string get_name() const { return m_name; }
	vector<pair<Transition, State>> get_transitions() const { return m_transitions; }
	
	//Setter
	void set_name(const string& name);
	void set_transitions(const vector<pair<Transition, State>>& transitions);

	//Functions
	int get_transitions_size() const;
	void add_transition(const Transition& transition, const State& state);
	State get_next_state(const Transition& transition) const;
};

