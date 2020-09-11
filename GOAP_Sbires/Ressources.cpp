#include "Ressources.h"


using namespace std;


Ressources::Ressources() : m_wood(50), m_fire(15), m_canne(10), m_house(20), m_weapon(10)
{

}


Ressources::~Ressources() 
{

}


void Ressources::getWood()
{
	m_wood += 1;
}



void Ressources::doFire() 
{
	m_fire += 1;
}

void Ressources::doCanne() 
{
	m_canne += 1;
}

void Ressources::doHouse() 
{
	m_house += 1;
}

void Ressources::doWeapeon()
{
	m_weapon += 1;
}



