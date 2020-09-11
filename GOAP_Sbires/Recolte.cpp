#include "Recolte.h"

using namespace std;


Recolte::Recolte() : m_meal(15), m_fish(15), m_legume(15)
{

}
	

Recolte::~Recolte()
{

}



void Recolte::doEat()
{

}

void Recolte::doHunt() 
{
	m_meal += 1;
}

void Recolte::farmer() 
{

}