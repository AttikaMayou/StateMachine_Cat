#pragma once



class Besoins
{
	private :
		int m_heal;
		

	public :

		//Constructeur
		Besoins();

		//Destructeur
		~Besoins();


		//Fonction

		void takeShower();
		void doEat();
		
		//Getter
		int getHeal();
};

