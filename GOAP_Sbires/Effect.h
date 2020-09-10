#pragma once
#include "EffectType.h"

using namespace std;

class Effect
{
private:
	EffectType m_type;

public:
	//Constructors
	Effect();
	Effect(const EffectType& effect_type);
	Effect(const Effect& effect);

	//Operator=
	Effect& operator=(const Effect& effect);

	//Destructor
	~Effect();
	
	//Getter
	const EffectType get_effect_type() const { return m_type; }

	//Setter
	void set_effect_type(const EffectType& effect_type);

	//Functions
};

