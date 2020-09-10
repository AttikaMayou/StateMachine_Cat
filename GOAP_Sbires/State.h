#pragma once
#include <vector>
#include "Action.h"
#include "Precondition.h"
#include "Effect.h"

using namespace std;

class State
{
private:
	const Action* const m_action;
	vector<const Precondition* const> m_preconditions;
	vector<const Effect* const> m_effects;

public:
	//Constructors
	State();
	State(const Action* const action, const Precondition* const precondition, const Effect* const effect);
	State(const State& state);
	
	//Operator=
	State& operator=(const State& state);

	//Destructor
	~State();
	
	//Getter
	const Action* const get_action() const { return m_action; }
	const vector<const Precondition* const>& get_precondition() const { return m_preconditions; }
	const vector<const Effect* const>& get_effect() const { return m_effects; }

	//Setter
	void set_action(const Action* const action);
	void set_precondition(const vector<const Precondition* const> precondition);
	void set_effect(const vector<const Effect* const> effect);

	//Functions
	void add_precondition(const Precondition* const precondition);
	void add_effect(const Effect* const effect);
};

