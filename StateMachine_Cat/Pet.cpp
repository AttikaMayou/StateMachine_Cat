#include "Pet.h"

//Add ASSERT => NEVER has 1.0f > factor > 5.0f and needs etc 0.0f > values > 100.0f
Pet::Pet(string name, float hunger, float thirst, float needs, float cared, float thirst_factor, float hunger_factor, float cared_factor, PetType type, StateMachine* state_machine) :
	m_name(name), m_hunger(hunger), m_thirst(thirst), m_cared(cared), m_thirst_factor(thirst_factor), m_hunger_factor(hunger_factor), m_cared_factor(cared_factor), m_type(type), m_state_machine(state_machine)
{
}

Pet::Pet(const Pet& p):
	m_name(p.get_name()), m_hunger(p.get_hunger()), m_thirst(p.get_thirst()), m_cared(p.get_cared()), m_type(p.get_type()), m_state_machine(p.get_state_machine())
{
}

Pet& Pet::operator=(const Pet& pet)
{
	m_name = pet.get_name();
	m_hunger = pet.get_hunger();
	m_thirst = pet.get_thirst();
	m_cared = pet.get_cared();
	m_thirst_factor = pet.get_thirst_factor();
	m_hunger_factor = pet.get_hunger_factor();
	m_cared_factor = pet.get_cared_factor();
	m_type = pet.get_type();
	m_state_machine = pet.get_state_machine();
	return *this;
}

Pet::~Pet()
{
	delete m_state_machine;
}

void Pet::set_name(string name)
{
	m_name = name;
}

void Pet::set_hunger(float val)
{
	m_hunger = val;
}

void Pet::set_thirst(float val)
{
	m_thirst = val;
}

void Pet::set_cared(float val)
{
	m_cared = val;
}

void Pet::set_thirst_factor(float val)
{
	m_thirst_factor = val;
}

void Pet::set_hunger_factor(float val)
{
	m_hunger_factor = val;
}

void Pet::set_cared_factor(float val)
{
	m_cared_factor = val;
}

void Pet::set_type(PetType type)
{
	m_type = type;
}

void Pet::set_state_machine(StateMachine* state_machine)
{
	m_state_machine = state_machine;
}

void Pet::update_pet()
{
	m_thirst -= 1.0f * m_thirst_factor;
	m_hunger -= 1.0f * m_hunger_factor;
	m_cared -= 1.0f * m_cared_factor;

	m_state_machine->process_state();
}

void Pet::reset_needs()
{
	m_thirst = 0.0f;
	m_hunger = 0.0f;
}

void Pet::being_cared()
{
	m_cared = 100.0f;
}
