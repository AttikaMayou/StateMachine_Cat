#pragma once
#include "StateMachine.h"

class House
{
private:
	bool water_glass_on_table, bowl_cat, bowl_dog, human_available;
	StateMachine* m_state_machine;
	
public:
	//Constructors
	House();
	House(const House& house);

	//Operator=
	House& operator=(const House& house);

	//Destructor
	~House();

	//Getter
	bool get_water_status() const { return water_glass_on_table; }
	bool get_cat_bowl_status() const { return bowl_cat; }
	bool get_dog_bowl_status() const { return bowl_dog; }
	bool get_human_status() const { return human_available; }
	StateMachine* get_state_machine() const { return m_state_machine; }
	
	//Setter
	void set_water_glass_status(bool value);
	void set_cat_bowl_status(bool value);
	void set_dog_bowl_status(bool value);
	void set_human_status(bool value);
	void set_state_machine(StateMachine* state_machine);
	
	//Functions
	void break_glass();
	void fill_cat_bowl();
	void empty_cat_bowl();
	void fill_dog_bowl();
	void empty_dog_bowl();
	void pet_cat();
	void pet_dog();
	void free_human();
};

