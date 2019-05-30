#include "List.h"

List::List()
{
	this->current = 0;
}

void List ::add(Gowns& gown)
{
	this->gowns.push_back(gown);
}

Gowns List::getCurrentGown()
{
	if (this->current == this->gowns.size())
		this->current = 0;
	std::vector<Gowns> elems = this->gowns;
	if (elems.size() != 0)
		return elems[this->current]; 
	return Gowns{};
}

void List::show()
{
	if (this->gowns.size() == 0) return;
	this->current = 0;
	Gowns currentGown = this->getCurrentGown();
	currentGown.show();
}

void List::next()
{
	if (this->gowns.size() == 0) return;
	this->current++;
	Gowns currentGown = this->getCurrentGown();
	currentGown.show();
}

bool List::isEmpty()
{
	return this->gowns.size() == 0;
}

std::vector<Gowns> List::getGowns()
{
	return this->gowns;
}
