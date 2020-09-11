#include "Pet.h"
#include "House.h"
#include "StateMachine.h"
#include "State.h"
#include "Transition.h"
#include "World.h"

void initWorld()
{
	//House initialized with world initialization => one house per world
	World* world = new World();

	Pet* first_cat = new Pet();
	world->add_pet(first_cat);
}


int main()
{
	initWorld();
	
    return 0;
}