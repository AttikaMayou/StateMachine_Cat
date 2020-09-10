#include "StateMachine.h"
#include "Cat.h"
#include "Dog.h"
#include "World.h"

int main()
{
	World world;
	StateMachine state_machine;

	State* state_c = new State("C");
	State* state_b = new State("B");
	Transition* transition = new Transition();
	state_b->add_transition(transition, state_c);
	State* state_a = new State("A", transition, state_b);
	
	state_machine.add_state(state_a);
	state_machine.add_state(state_b);
	state_machine.add_state(state_c);
	state_machine.get_current()->add_transition(transition, state_a);
	
    return 0;
}