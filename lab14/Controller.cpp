#include "Controller.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include "CSVBasket.h"
#include "HTMLBasket.h"

void Controller::addGownC(int size, const std::string& colour, int price, int quantity, const std::string& photo)
{
	Gowns new_gown = { size, colour, price, quantity, photo };
	this->validator.validate(new_gown);
	this->repo.addGown(new_gown);
}

void Controller::removeGownC()
{
	std::vector<Gowns> allGowns = this->repo.getGowns();

	for (int i = 0; i < allGowns.size(); i++)
	{
		if (allGowns[i].getQuantity() == 0)
		{
			this->repo.removeGown(allGowns[i]);
		}
	}
}

void Controller::updatePriceC(const std::string& photo, int newPrice)
{
	this->repo.updatePrice(photo, newPrice);
}

void Controller::updateQuantityC(const std::string& photo, int newQ)
{
	this->repo.updateQuantity(photo, newQ);
}

/*
void Controller::sortGownsC()
{
	this->repo.sortGowns();
}
*/

void Controller::addGownToBasket(Gowns gown)
{
	this->basket->add(gown);
	int q = gown.getQuantity();
	this->repo.updateQuantity(gown.getPhoto(), q - 1);
	//this->repo.findGownByPicture(gown.getPhoto()).setQuantity(q - 1);
}

void Controller::findGownsBySizeC(int size)
{
	if (size != NULL)
	{
		std::vector<Gowns> v = this->repo.findGownSBySize(size);
		for (int i = 0; i < v.size(); i++)
			this->gownsList.add(v[i]);
	}
	else
	{
		std::vector<Gowns> v = this->repo.getGowns();
		for (int i = 0; i < v.size(); i++)
			this->gownsList.add(v[i]);
	}
}

void Controller::startList()
{
	this->gownsList.show();
}

void Controller::nextGown()
{
	this->gownsList.next();
}

int Controller::totalBasket()
{
	int total = 0;
	std::vector<Gowns> b = this->basket->getBasket();
	for (int i = 0; i < b.size(); i++)
		total = total + b[i].getPrice();
	return total;
}

void Controller::saveBasket()
{
	if (this->basket == nullptr)
		return;
	this->basket->writeToFile();
}

void Controller::openBasket()
{
	if (this->basket == nullptr)
		return;
	this->basket->showBasket();
}

void Controller::setCSV()
{
	this->basket = new CSVBasket{ "gowns.csv" };
}

void Controller::setHTML()
{
	this->basket = new HTMLBasket{ "gowns.html" };
}
