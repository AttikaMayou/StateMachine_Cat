#pragma once
#include "StateMachine.h"
#include <iostream>

using namespace std;

enum PetType
{
	ANY,
	CAT,
	DOG
};

class Pet
{
private:
	string m_name;
	float m_hunger, m_thirst, m_cared, m_thirst_factor, m_hunger_factor, m_cared_factor;
	PetType m_type;
	StateMachine* m_state_machine;

public:
	//Constructors
	Pet();
	Pet(string name, float hunger, float thirst, float cared, float thirst_factor, float hunger_factor, float cared_factor, PetType type, StateMachine* state_machine);
	Pet(const Pet& p);

	//Operator=
	Pet& operator=(const Pet& pet);
	
	//Destructor
	~Pet();

	//Getter
	string get_name() const { return m_name; }
	float get_hunger() const { return m_hunger; }
	float get_thirst() const { return m_thirst; }
	float get_cared() const { return m_cared; }
	float get_thirst_factor() const { return m_thirst_factor; }
	float get_hunger_factor() const { return m_hunger_factor; }
	float get_cared_factor() const { return m_cared_factor; }
	PetType get_type() const { return m_type; }
	StateMachine* get_state_machine() const { return m_state_machine; }
	
	//Setter
	void set_name(string name);
	void set_hunger(float val);
	void set_thirst(float val);
	void set_cared(float val);
	void set_thirst_factor(float val);
	void set_hunger_factor(float val);
	void set_cared_factor(float val);
	void set_type(PetType type);
	void set_state_machine(StateMachine* state_machine);

	//Functions
	void update_pet();
	void reset_needs();
	void being_cared();
};

