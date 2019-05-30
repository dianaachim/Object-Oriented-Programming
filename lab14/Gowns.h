#pragma once
#include <string>
class Gowns
{
private:
	int size;
	std::string colour;
	int price;
	int quantity;
	std::string photo;
public:
	Gowns();
	//constructor with parameters
	Gowns(int size, const std::string& colour, int price, int quantity, const std::string& photo);
	
	// overload operator ==
	bool operator==(const Gowns& gown);
	
	// getters
	int getSize() { return size;  }
	std::string getColour() const { return colour; }
	int getPrice() { return price; }
	int getQuantity() { return quantity; }
	std::string getPhoto() const { return photo; }

	// setters
	void setSize(int new_size) { size = new_size; }
	void setColour(const std::string new_colour) { colour = new_colour; }
	void setPrice(int new_price) { price = new_price; }
	void setQuantity(int new_quantity) { quantity = new_quantity; }
	void setPhoto(const std::string new_photo) { photo = new_photo; }

	void show();

	friend std::istream& operator>>(std::istream& is, Gowns& g);
	friend std::ostream& operator<<(std::ostream& os, const Gowns& g);

	~Gowns();
};

