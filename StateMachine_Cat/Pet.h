#pragma once
#include "World.h"
#include <iostream>

using namespace std;

enum PetType
{
	ANY,
	CAT,
	DOG
};

class Pet
{
private:
	string m_name;
	float m_hunger, m_thirst, m_cared, m_thirst_factor, m_hunger_factor, m_cared_factor;
	PetType m_type;

public:
	//Constructors
	Pet(): m_name("Pet"), m_hunger(0.0f), m_thirst (0.0f), m_cared(100.0f), m_thirst_factor(1.0f), m_hunger_factor(1.0f), m_cared_factor(1.0f), m_type(PetType::ANY) {}
	Pet(string name, float hunger, float thirst, float needs, float cared, float thirst_factor, float hunger_factor, float cared_factor, PetType type);
	Pet(const Pet& p);

	//Operator=
	Pet& operator=(const Pet& pet);
	
	//Destructor
	~Pet();

	//Getter
	string get_name() const { return m_name; }
	float get_hunger() const { return m_hunger; }
	float get_thirst() const { return m_thirst; }
	float get_cared() const { return m_cared; }
	float get_thirst_factor() const { return m_thirst_factor; }
	float get_hunger_factor() const { return m_hunger_factor; }
	float get_cared_factor() const { return m_cared_factor; }
	PetType get_type() const { return m_type; }
	
	//Setter
	void set_name(string name);
	void set_hunger(float val);
	void set_thirst(float val);
	void set_cared(float val);
	void set_thirst_factor(float val);
	void set_hunger_factor(float val);
	void set_cared_factor(float val);
	void set_type(PetType type);

	//Functions
	void update_pet();
};

