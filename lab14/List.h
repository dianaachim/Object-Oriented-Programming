#pragma once
#include "DynamicVector.h"
#include "Gowns.h"
#include <vector>
#include <algorithm>

class List
{
private:
	std::vector<Gowns> gowns;
	int current;

public:
	List();
	
	//Adds a gown to the shopping List
	void add(Gowns& gown);

	//Gets the current gown from the list
	Gowns getCurrentGown();

	//Starts showing the gowns
	void show();

	//Moves to the next item in the list
	void next();

	//Checks if the shopping list is empty
	bool isEmpty();

	std::vector<Gowns> getGowns();
};

