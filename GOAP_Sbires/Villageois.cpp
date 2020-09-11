#include "Villageois.h"

using namespace std;

Villageois::Villageois() : m_life(5)
{

}


Villageois::~Villageois()
{

}

//Fonction

void Villageois::getDammage(int nbDammages)
{
    m_life -= nbDammages;

    if (m_life < 0)
    {
        m_life = 0;
    }
}


void Villageois::doEat(int viande, int fire, int legumes) 
{

}

void Villageois::farmer() 
{

}

bool Villageois::isFree() 
{
    bool isFree(true);
}

bool Villageois::isFinishedHisWork() 
{

}
