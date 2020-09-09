#pragma once

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

	//Getter

	//Setter

	//Function
	void process();
};

