#pragma once
#include "DynamicVector.h"
#include "Gowns.h"
#include "Comparator.h"
#include <vector>
#include <algorithm>
#include <string>
#include "Utils.h"
#include <fstream>

class Repo
{
private:

	std::vector<Gowns> gowns;
	std::string filename;

public:
	Repo() {}
	Repo(const std::string& filename);
	//ads a new gown to the repository
	void addGown(const Gowns& new_gown);
	//removes a gown from the repository
	void removeGown(const Gowns& gown);
	//uptades the price of the gown with the photo photo with the new price newPrice
	void updatePrice(const std::string& photo, int newPrice);
	//updates the quantity of the gown with the photo photo with the new quantity new_quantity
	void updateQuantity(const std::string& photo, int new_quantity);
	
	//finds a gown by a given picture and returns it
	Gowns findGownByPicture(const std::string& photo);
	//finds all the gowns with a given size, and then returns the vector containing them
	std::vector<Gowns> findGownSBySize(int size);
	//returns all the gowns from the repository
	std::vector<Gowns> getGowns() const { return gowns; }
	//sorts descending by price
	//void sortGowns();

private:
	void readFromFile();
	void writeToFile();
};

