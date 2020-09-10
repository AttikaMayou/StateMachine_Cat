#include "StateMachine.h"
#include "Cat.h"
#include "Dog.h"
#include "World.h"

void create_test_state_machine()
{
	StateMachine state_machine;

	//make a new function to create a state for a state machine 
	State* state_c = new State("C");
	State* state_b = new State("B");
	Transition* transition = new Transition();
	state_b->add_transition(transition, state_c);
	State* state_a = new State("A", transition, state_b);
	State* state_d = new State("D");

	state_machine.add_state(state_a);
	state_machine.add_state(state_b);
	state_machine.add_state(state_c);
	state_machine.get_current()->add_transition(transition, state_a);

	state_machine.process_state();

	state_b->add_transition(transition, state_d);

	state_machine.process_state();
	state_machine.process_state();
	state_machine.process_state();
}

int main()
{
	World world;

	create_test_state_machine();
	
    return 0;
}