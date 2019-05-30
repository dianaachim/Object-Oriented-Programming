#include "Repo.h"
#include <string>
#include <iostream>
#include "Exceptions.h"

using namespace std;


Repo::Repo(const std::string& filename)
{
	this->filename = filename;
	this->readFromFile();
}

void Repo::addGown(const Gowns& new_gown)
{
	if (this->findGownByPicture(new_gown.getPhoto()) == new_gown)
		throw Exceptions("Gown already exists");
	this->gowns.push_back(new_gown);
	this->writeToFile();
}

/*
void Repo::removeGown(const Gowns& gown)
{
	this->gowns.remove(gown);
}
*/

void Repo::removeGown(const Gowns& gown)
{
	int i=0; //the index
	while (i < this->gowns.size())
	{
		if (this->gowns[i] == gown)
			break;
		else
			i++;
	}
	auto it = this->gowns.begin() + i;
	this->gowns.erase(it);
	this->writeToFile();
}

Gowns Repo::findGownByPicture(const std::string& photo)
{
	std::vector<Gowns> allGowns = this->gowns;
	if (allGowns.size() == 0)
		return Gowns{};

	for (int i = 0; i < this->gowns.size(); i++)
	{
		Gowns g = allGowns[i];
		if (g.getPhoto() == photo)
			return g;
	}

	return Gowns{};
}

std::vector<Gowns> Repo::findGownSBySize(int size)
{
	std::vector<Gowns> v;
	std::vector<Gowns> allGowns = this->gowns;
	if (allGowns.size() == 0) return v;

	for (int i = 0; i< this->gowns.size(); i++)
	{ 
		if (allGowns[i].getSize() == size)
			v.push_back(allGowns[i]);
	}
	return v;
}
void Repo::readFromFile()
{
	ifstream file(this->filename);

	if (!file.is_open())
		throw FileException("file could not be opened");

	Gowns g;
	while (file >> g)
		this->gowns.push_back(g);
	file.close();
}
void Repo::writeToFile()
{
	ofstream file(this->filename);
	if (!file.is_open())
		throw FileException("file could not be opened");

	for (auto g : this->gowns)
	{
		file << g;
	}
	file.close();
}
/*
void Repo::sortGowns()
{
	CompareDescendingByPrice<Gowns> cmp;
	this->gowns.sort(cmp);
}
*/
void Repo::updatePrice(const std::string& photo, int newPrice)
{
	//this->findGownByPicture(photo).setPrice(newPrice);
	//std::vector<Gowns> allGowns = this->gowns;

	if (this->findGownByPicture(photo) == Gowns{})
		throw Exceptions("This gown does not exist");

	for (int i = 0; i < this->gowns.size(); i++)
	{
		if (this->gowns[i].getPhoto() == photo)
			this->gowns[i].setPrice(newPrice);	
	}
	this->writeToFile();
}

void Repo::updateQuantity(const std::string& photo, int newQ)
{
	//this->findGownByPicture(photo).setQuantity(newQ);

	//std::vector<Gowns> allGowns = this->gowns;

	if (this->findGownByPicture(photo) == Gowns{})
		throw Exceptions("This gown does not exits");

	for (int i = 0; i < this->gowns.size(); i++)
	{
		if (this->gowns[i].getPhoto() == photo)
			this->gowns[i].setQuantity(newQ);
	}
	this->writeToFile();
}