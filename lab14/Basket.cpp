#include "Basket.h"



Basket::Basket(std::string filename)
{
	this->filename = filename;
}

std::vector<Gowns> Basket::getBasket()
{
	return this->gowns;
}

void Basket::add(Gowns g)
{
	this->gowns.push_back(g);
}

