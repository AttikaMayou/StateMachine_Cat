#include <iostream>
#include <string>


class Villageois
{
    private:

        int life;
    


    public: 
        
        //Contstructeur
        Villageois();
        

        //Destructeur
        ~Villageois();

        //Fonction
        void getDammage(int nbDammages);
        void getWood();
        void goHunt();
        void goFishing();
        void doEat(int viande, int fire, int legumes);
        void farmer();
        bool isFree();
        bool isFinishedHisWork();
        

};






