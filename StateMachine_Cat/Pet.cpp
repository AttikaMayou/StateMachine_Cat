#include "Pet.h"

Pet::Pet(float hunger, float thirst, float needs):
	m_hunger(hunger), m_thirst(thirst), m_needs(needs)
{
}

Pet::Pet(const Pet& p):
	m_hunger(p.get_hunger()), m_thirst(p.get_thirst()), m_needs(p.get_needs())
{
}

Pet::~Pet()
{
}

void Pet::set_hunger(const float val)
{
	m_hunger = val;
}

void Pet::set_thirst(const float val)
{
	m_thirst = val;
}

void Pet::set_needs(const float val)
{
	m_needs = val;
}
