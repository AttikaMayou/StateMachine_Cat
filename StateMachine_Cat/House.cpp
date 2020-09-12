#include "House.h"

House::House(): water_glass_on_table(true), bowl_cat(false), bowl_dog(false), human_available(true)
{
}

House::House(const House& house)
{
	water_glass_on_table = house.get_water_status();
	bowl_cat = house.get_cat_bowl_status();
	bowl_dog = house.get_dog_bowl_status();
	human_available = house.get_human_status();
}

House& House::operator=(const House& house)
{
	water_glass_on_table = house.get_water_status();
	bowl_cat = house.get_cat_bowl_status();
	bowl_dog = house.get_dog_bowl_status();
	human_available = house.get_human_status();
	return *this;
}

House::~House()
{
}

void House::set_water_glass_status(bool value)
{
	water_glass_on_table = value;
}

void House::set_cat_bowl_status(bool value)
{
	bowl_cat = value;
}

void House::set_dog_bowl_status(bool value)
{
	bowl_dog = value;
}

void House::set_human_status(bool value)
{
	human_available = value;
}

void House::break_glass()
{
	set_water_glass_status(false);
}

void House::fill_cat_bowl()
{
	set_cat_bowl_status(true);
}

void House::empty_cat_bowl()
{
	set_cat_bowl_status(false);
}

void House::fill_dog_bowl()
{
	set_dog_bowl_status(true);
}

void House::empty_dog_bowl()
{
	set_dog_bowl_status(false);
}

void House::pet_cat()
{
	set_human_status(false);
}

void House::pet_dog()
{
	set_human_status(false);
}

void House::free_human()
{
	set_human_status(true);
}