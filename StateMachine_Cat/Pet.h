#pragma once
class Pet
{
private:
	float m_hunger, m_thirst, m_needs;

public:
	//Constructors
	Pet(): m_hunger(0.0f), m_thirst (0.0f), m_needs(100.0f) {}
	Pet(float hunger, float thirst, float needs);
	Pet(const Pet& p);
	
	//Destructor
	~Pet();

	//Getter
	float get_hunger() const { return m_hunger; }
	float get_thirst() const { return m_thirst; }
	float get_needs() const { return m_needs; }

	//Setter
	void set_hunger(const float val);
	void set_thirst(const float val);
	void set_needs(const float val);
};

