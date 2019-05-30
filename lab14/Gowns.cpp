#include "Gowns.h"
#include <Windows.h>
#include <shellapi.h>
#include <string>
#include <iostream>
#include "Utils.h"
#include <vector>

using namespace std;


Gowns::Gowns() : size(0), colour(""), price(0), quantity(0), photo("") {}


Gowns::Gowns(int size, const std::string & colour, int price, int quantity, const std::string & photo)
{
	this->size = size;
	this->colour = colour;
	this->price = price;
	this->quantity = quantity;
	this->photo = photo;
}

bool Gowns::operator==(const Gowns & gown)
{
	if (this->photo == gown.getPhoto())
		return true;
	return false;
}

void Gowns::show()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getPhoto().c_str(), NULL, SW_SHOWMAXIMIZED);
}

Gowns::~Gowns()
{
}

std::istream & operator>>(std::istream & is, Gowns & g)
{
	string line;
	getline(is, line);

	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 5)
		return is;

	g.size = stoi(tokens[0]);
	g.colour = tokens[1];
	g.price = stoi(tokens[2]);
	g.quantity = stoi(tokens[3]);
	g.photo = tokens[4];

	return is;
}

std::ostream & operator<<(std::ostream & os, const Gowns & g)
{
	os << g.size << "," << g.colour << "," << g.price << "," << g.quantity << "," << g.photo << endl;
	return os;
}
