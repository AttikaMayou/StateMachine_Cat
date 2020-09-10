#pragma once
#include <iostream>
using namespace std;

//TODO : make child of Translation to handle different cases
	//(comparison between float, between bool...) 

class Transition
{
private:
	
public:
	//Constructors
	Transition();
	Transition(const Transition& transition);

	//Operator=
	Transition& operator=(const Transition & t);
	
	//Destructor
	~Transition();

	//Function
	bool process() const;
};

