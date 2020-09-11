#pragma once


class Ressources
{
	private:
		int m_wood;
		int m_fire;
		int m_canne;
		int m_house;
		int m_weapon;
		
	public:

		//Constructeur
		Ressources();

		//Destucteur
		~Ressources();

		//Fonction
		void getWood();
		void doFire();
		void doCanne();
		void doHouse();
		void doWeapeon();

		
};

