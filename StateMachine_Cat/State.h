#pragma once
#include <vector>
#include"Transition.h"
#include "World.h"

using namespace std;

class State
{
private:
	WorldState m_type;
	vector<pair<const Transition* const, State* const>> m_transitions;
	const void(*action)();
	
public:
	//Constructors
	State();
	State(const void(*function)());
	
	//Destructor
	~State();

	//Getter
	const WorldState get_type() const { return m_type; }
	const vector<pair<const Transition* const, State* const>> get_transitions() const { return m_transitions; }
	
	//Setter
	void set_type(WorldState type);
	void set_transitions(const vector<pair<const Transition* const, State* const>>& transitions);

	//Functions
	void add_transition(const Transition* const transition, State* const state);
	void perform_action() const;
};

