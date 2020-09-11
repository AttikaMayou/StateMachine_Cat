#pragma once
#include <vector>
#include "Action.h"
#include "Precondition.h"
#include "Effect.h"

using namespace std;

class State
{
private:
	Action* m_action;
	vector<const Precondition* const> m_preconditions;
	vector<const Effect* const> m_effects;

public:
	//Constructors
	State();
	State(Action* action, const Precondition* const precondition, const Effect* const effect);
	State(Action* action, vector<const Precondition* const> preconditions, vector<const Effect* const> effects);
	State(const State& state);
	
	//Operator=
	State& operator=(const State& state);

	//Destructor
	~State();
	
	//Getter
	Action* const get_action() const { return m_action; }
	const vector<const Precondition* const>& get_preconditions() const { return m_preconditions; }
	const vector<const Effect* const>& get_effects() const { return m_effects; }

	//Setter
	void set_action(Action* const action);
	void set_preconditions(const vector<const Precondition* const>& preconditions);
	void set_effects(const vector<const Effect* const>& effects);

	//Functions
	void add_precondition(const Precondition* const precondition);
	void add_effect(const Effect* const effect);
};

