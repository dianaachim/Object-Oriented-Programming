#pragma once
#include "Basket.h"
#include <string>

class CSVBasket: public Basket
{
public:
	CSVBasket(std::string filename) : Basket{ filename } {};
	void writeToFile() override;
	void showBasket() override;
};

