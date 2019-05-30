#pragma once
#include "Repo.h"
#include "List.h"
#include <vector>
#include <algorithm>
#include "GownValidator.h"
#include "Basket.h"

class Controller
{
private:
	Repo repo;
	List gownsList;
	Basket* basket;
	GownValidator validator;

public:
	Controller(const Repo& r, const List& l, Basket* b, GownValidator v) : repo{ r }, gownsList{ l }, basket{ b }, validator{ v } {};
	Repo getRepo() const { return repo; }
	List getList () const { return gownsList; }
	std::vector<Gowns> getBasket() { return this->basket->getBasket(); }
	
	//adds a gown
	void addGownC(int size, const std::string& colour, int price, int quantity, const std::string& photo);
	//removes the gowns that are out of stock
	void removeGownC();
	//updates the price of the gown with the photograph photo
	void updatePriceC(const std::string& photo, int newPrice);
	//updates the quantity of the gown with the photograph photo
	void updateQuantityC(const std::string& photo, int newQuantity);
	//sorts the gowns from the repository descending by price
	//void sortGownsC();
	
	//adds a given gown to the shopping basket
	void addGownToBasket(Gowns gown);
	//adds the gowns with a given size to the controller list; if the size is NULL, the controller list will get all the gowns from the repository
	void findGownsBySizeC(int size);
	//starts showing the list
	void startList();
	//moves to the next gown
	void nextGown();
	//returns the total sum of the gowns from the controller basket
	int totalBasket();
	void saveBasket();
	void openBasket();

	void setCSV();
	void setHTML();
};