#pragma once
#include <vector>
#include "Transition.h"
#include "Pet.h"
#include "House.h"

using namespace std;

enum StateType
{
	IDLE,
	CAT_NEED_ATTENTION,
	DOG_NEED_ATTENTION,
	BREAK_GLASS,
	PET_CAT,
	PET_DOG,
	CAT_THIRSTY,
	CAT_HUNGRY,
	DOG_THIRSTY,
	DOG_HUNGRY,
	FILL_CAT_BOWL,
	FILL_DOG_BOWL,
	DOG_DRINKING_WATER_ON_GROUND,
	CAT_EATING_OR_DRINKING,
	DOG_EATING_OR_DRINKING
};

class State
{
private:
	StateType m_type;
	vector<pair<Transition*, State*>> m_transitions;
	function<void(Pet*, House*)> m_action;
	
public:
	//Constructors
	State();
	State(StateType type, function<void(Pet*, House*)>f);
	
	//Destructor
	~State();

	//Getter
	const StateType get_type() const { return m_type; }
	const vector<Transition*> get_only_transitions() const;
	const vector<pair<Transition*, State*>> get_transitions() const { return m_transitions; }
	
	//Setter
	void set_type(StateType type);
	void set_transitions(const vector<pair<Transition*, State*>>& transitions);

	//Functions
	void add_transition(Transition* transition, State* state);
	void perform_action(Pet* pet, House* house) const;
};

