#include "Pet.h"
#include "House.h"
#include "StateMachine.h"
#include "State.h"
#include "Transition.h"
#include "World.h"
#include "CONST_VALUES.h"

StateMachine* init_cat_state_machine(World* world)
{
	StateMachine* st = new StateMachine();

	State* cat_idle_state = new State();
	
	auto check_thirsty = [](Pet* pet, House* house) -> bool
	{
		return pet->get_thirst() >= CONST_VALUES::THIRST_THRESHOLD
		   && house->get_cat_bowl_status();
	};
	Transition* to_thirst = new Transition(check_thirsty);
	State* cat_thirst_state = new State(world->get_house()->fill_cat_bowl());

	cat_idle_state->add_transition(to_thirst, cat_thirst_state);

	
	return st;
}

void initWorld()
{
	//House initialized with world initialization => one house per world
	World* my_world = new World();

	StateMachine* cat_state_machine = init_cat_state_machine(my_world);
	
	Pet* first_cat = new Pet("Little Cato", 20.0f, 20.0f, 70.0f, 1.0f, 1.0f, 5.0f, PetType::CAT, cat_state_machine);
	Pet* first_dog = new Pet();
	
	my_world->add_pet(first_cat);
	my_world->add_pet(first_dog);
}


int main()
{
	initWorld();
	
    return 0;
}