#include "Besoins.h"

using namespace std;

Besoins::Besoins() 
{

}


Besoins::~Besoins() 
{

}


void Besoins::takeShower() 
{
	m_heal += 1;
}

void Besoins::doEat() 
{
	
}



int Besoins::getHeal()
{
	return m_heal;
}