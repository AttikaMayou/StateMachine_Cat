#pragma once
class Pet
{
private:
	float hunger, thirst, needs;

public:
	Pet() : hunger(0.0f), thirst (0.0f), needs(100.0f) {}
	Pet(float hunger, float thirst, float needs);
};

