#pragma once
#include <vector>
#include "State.h"
#include "Transition.h"
#include "Pet.h"
#include "House.h"

using namespace std;

class StateMachine
{
private:
	State* m_begin;
	State* m_current;
	vector<State*> m_states;
	vector<Transition*> m_transitions;
	House* m_house;
	Pet* m_pet;

public:
	//Constructors
	StateMachine();
	StateMachine(State* begin);
	StateMachine(State* begin, House* house, Pet* pet);
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
	House* get_house() const { return m_house; }
	Pet* get_pet() const { return m_pet; }
	
	//Setter
	void set_begin(State* begin);
	void set_current(State* current);
	void set_house(House* house);
	void set_pet(Pet* pet);

	//Functions
	void add_state(State* state);
	void process_state();
	void change_state(State* state);
};

