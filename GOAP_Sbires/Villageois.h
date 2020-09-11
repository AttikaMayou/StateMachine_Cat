#include <iostream>
#include <string>
#include "Ressources.h"
#include "Besoins.h"
#include "Recolte.h"

class Villageois
{
    private:

        int m_life;

    public: 
        
        //Contstructeur
        Villageois();
        

        //Destructeur
        ~Villageois();

        //Fonction
        void heal(int m_heal);
        void dommage(int m_dommage);
        void farmer();
        bool isFree();
        bool isPossibleToAssignedNewAction();
        

       

};






