#pragma once

class Recolte
{

	private :

		int m_meal;
		int m_fish;
		int m_legume;

	public : 
		
		//Constructeur 
		Recolte();

		//Destructeur
		~Recolte();


		//Fonction
		void doEat(int viande, int fire, int legumes);
		void doHunt();
		void farmer();


};

