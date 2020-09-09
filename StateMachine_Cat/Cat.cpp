#include "Cat.h"

Cat::Cat(float cared): m_cared(cared)
{
	Pet();
}

Cat::Cat(const Cat& c): m_cared(c.get_cared())
{
	Pet();
}

Cat::~Cat()
{
}

void Cat::set_cared(float const val)
{
	m_cared = val;
}
