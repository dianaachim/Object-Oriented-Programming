#pragma once
#include <vector>
#include "Gowns.h"

class Basket
{
protected:
	std::string filename;
	std::vector<Gowns> gowns;

public:
	Basket(std::string filename);
	std::vector<Gowns> getBasket();
	void add(Gowns g);
	virtual void showBasket()=0;
	virtual  void writeToFile()=0;
};

