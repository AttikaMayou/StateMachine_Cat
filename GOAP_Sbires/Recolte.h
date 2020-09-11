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
		void doEat();
		void doHunt();
		void farmer();


};

