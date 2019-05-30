#include "CSVBasket.h"
#include <fstream>
#include <Windows.h>
#include "Exceptions.h"

using namespace std;



void CSVBasket::writeToFile()
{
	ofstream f(this->filename);

	if (!f.is_open())
		throw FileException("The file could not be opened!");

	for (auto s : this->gowns)
		f << s;
	f.close();
}

void CSVBasket::showBasket()
{
	string aux = "\"" + this->filename + "\"";
	ShellExecuteA(NULL, NULL, "c:\\Program Files\\Microsoft Office\\Office15\\EXCEL.EXE", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}
