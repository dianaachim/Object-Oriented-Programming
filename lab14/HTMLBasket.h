#pragma once
#include "Basket.h"
#include <string>

class HTMLBasket: public Basket
{
public:
	HTMLBasket(std::string filename) : Basket{ filename } {};
	void writeToFile() override;
	void showBasket() override;
};

