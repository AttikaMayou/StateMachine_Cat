#include "Pet.h"
#include "House.h"
#include "StateMachine.h"
#include "State.h"
#include "Transition.h"
#include "World.h"
#include "CONST_VALUES.h"

House* init_house()
{
	return new House();
}

StateMachine* init_cat_state_machine(Pet* cat, House* house)
{
	State* idle_state = new State(StateType::IDLE, [](Pet* pet, House* hs) {});

	StateMachine* st = new StateMachine(idle_state, house, cat);

	//-------------------- Create all states for cat --------------------//

	//=> cat become thirsty
	auto check_thirsty = [](Pet* pet, House* hs) -> bool
	{
		cout << "Cat is thirsty"  << endl;
		return pet->get_thirst() >= CONST_VALUES::THIRST_THRESHOLD
		   && !hs->get_cat_bowl_status();
	};
	Transition* to_thirst = new Transition(check_thirsty);
	auto cat_break_glass = [](Pet* pet, House* hs)
	{
		cout << "Cat broke glass !" << endl;
		if(hs->get_water_status())
			hs->break_glass();
	};
	State* cat_thirst_state = new State(StateType::CAT_THIRSTY, cat_break_glass);
	st->add_state(cat_thirst_state);
	idle_state->add_transition(to_thirst, cat_thirst_state);

	//=> cat become hungry
	auto check_hunger = [](Pet* pet, House* hs) -> bool
	{
		cout << "Cat is hungry" << endl;
		return pet->get_hunger() >= CONST_VALUES::HUNGER_THRESHOLD
			&& !hs->get_cat_bowl_status();
	};
	Transition* to_hunger = new Transition(check_hunger);
	State* cat_hunger_state = new State(StateType::CAT_HUNGRY, [](Pet* pet, House* hs){});
	st->add_state(cat_hunger_state);
	idle_state->add_transition(to_hunger, cat_hunger_state);

	//=> reset cat needs
	auto can_drink_or_eat = [](Pet* pet, House* hs) -> bool
	{
		return hs->get_cat_bowl_status();
	};
	Transition* to_idle = new Transition(can_drink_or_eat);
	auto reset_cat = [](Pet* pet, House* hs)
	{
		pet->reset_needs();
		hs->empty_cat_bowl();
	};
	State* cat_idle = new State(StateType::IDLE, reset_cat);
	cat_thirst_state->add_transition(to_idle, cat_idle);
	cat_hunger_state->add_transition(to_idle, cat_idle);
	
	//-------------------- Create all states for house --------------------//
	
	//=> house fill cat bowl if necessary
	auto check_cat_bowl = [check_thirsty, check_hunger](Pet* pet, House* hs) -> bool
	{
		return check_thirsty(pet, hs) && check_hunger(pet, hs) && hs->get_human_status();
	};
	Transition* to_fill_cat_bowl = new Transition(check_cat_bowl);
	auto fill_cat_cowl = [](Pet* pet, House* hs)
	{
		cout << "Cat bowls are now filled" << endl;
		hs->set_human_status(false);
		hs->fill_cat_bowl();
	};
	State* house_fill_cat_bowl = new State(StateType::FILL_CAT_BOWL, fill_cat_cowl);
	st->add_state(house_fill_cat_bowl);

	return st;
}

void create_and_play_house()
{
	House* const house = init_house();
	
	Pet* const first_cat = new Pet("Little Cato", 1.0f, 1.0f, 5.0f, PetType::CAT);

	StateMachine* const state_machine = init_cat_state_machine(first_cat, house);

	while(first_cat->get_thirst() < 100.0f || first_cat->get_hunger() < 100.0f)
	{
		first_cat->update_pet();
		state_machine->process_state();
	}
}

int main()
{
	create_and_play_house();
	
    return 0;
}