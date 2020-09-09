#pragma once
#include <string>
#include"Transition.h"
using namespace std;

//TODO : complete class (operator=)

class State
{
private:
	string m_name;
	Transition* m_transition;

public:
	//Constructors
	State();
	State(const string& name, const Transition& transition);
	State(const State& s);

	//Destructor
	~State();

	//Getter
	string get_name() const { return m_name; }
	Transition* get_transition() const { return m_transition; }
	
	//Setter
	void set_name(const string& name);
	void set_transition(const Transition& transition);

	//Functions
	void add_transition(const Transition& transition, const State& sate);
};

