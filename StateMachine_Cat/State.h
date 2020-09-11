#pragma once
#include <vector>
#include "Transition.h"

using namespace std;

enum StateType
{
	NONE,
	BREAK_GLASS,
	PET_CAT,
	PET_DOG,
	FILL_CAT_BOWL,
	FILL_DOG_BOWL,
	DOG_DRINKING_WATER_ON_GROUND,
	CAT_EATING,
	DOG_EATING,
	CAT_DRINKING,
	DOG_DRINKING
};

class State
{
private:
	StateType m_type;
	vector<pair<Transition*, State*>> m_transitions;
	void(*action)();
	
public:
	//Constructors
	State();
	State(void(*function)());
	
	//Destructor
	~State();

	//Getter
	StateType get_type() const { return m_type; }
	vector<pair<Transition*, State*>> get_transitions() const { return m_transitions; }
	
	//Setter
	void set_type(StateType type);
	void set_transitions(const vector<pair<Transition*, State*>>& transitions);

	//Functions
	void add_transition(Transition* transition, State* state);
	void perform_action() const;
};

