#include "Villageois.h"
#include "Besoins.h"

using namespace std;

Villageois::Villageois() : m_life(5)
{

}


Villageois::~Villageois()
{

}



void Villageois::dommage(int m_dommage)
{
    m_life -= m_dommage;

    if (m_life < 0)
    {
        m_life = 0;
    }
    
}


void Villageois::heal(int m_heal)
{
    m_life += m_heal;

    if (m_life > 50)
    {
        m_life = 50;
    }
}

void Villageois::farmer() 
{

}

bool Villageois::isFree() 
{
    bool isFree(true);
}

bool Villageois::isPossibleToAssignedNewAction()
{

}


