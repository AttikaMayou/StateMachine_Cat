#pragma once
#include "Pet.h"
class Cat :
    public Pet
{
private:
	float m_cared;

public:
	//Constructors
	Cat(): m_cared(100) {}
	Cat(float cared);
	Cat(const Cat& c);

	//Destructor
	~Cat();

	//Getter
	float get_cared() const { return m_cared; }
	
	//Setter
	void set_cared(float const val);
};

