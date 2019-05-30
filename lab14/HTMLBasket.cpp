#include "HTMLBasket.h"
#include <fstream>
#include <Windows.h>
#include "Exceptions.h"

using namespace std;


void HTMLBasket::writeToFile()
{
	ofstream f(this->filename);

	if (!f.is_open())
		throw FileException("The file could not be opened!");

	f << "!DOCTYPE html";
	f << "<html>";
	f << "<head>";
	f << "<title>Basket</title>";
	f << "</head>";
	f << "<body>";
	f << "<table border=\"1\">";
	f << "<tr>";
	f << "<td>Size</td>";
	f << "<td>Color</td>";
	f << "<td>Price</td>";
	f << "<td>Quantity</td>";
	f << "<td>Photo</td>";
	f << "</tr>";
	for (auto s : this->gowns)
	{
		f << "<tr>";
		f << "<td>" << std::to_string(s.getSize()) << "</td>";
		f << "<td>" << s.getColour() << "</td>";
		f << "<td>" << std::to_string(s.getPrice()) << "</td>";
		f << "<td>" << std::to_string(s.getQuantity()) << "</td>";
		f << "<td>" <<"<a href ="<< s.getPhoto() << ">Link</a></td>";
		f << "</tr>";
	}
	f << "</table>";
	f << "</body>";
	f << "</html>";
}

void HTMLBasket::showBasket()
{
	string aux = "\"" + this->filename + "\"";
	ShellExecuteA(NULL, NULL, "Chrome.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}
