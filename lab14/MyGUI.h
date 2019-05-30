#pragma once
#include <qwidget.h>
#include <vector>
#include <string>
#include <qlistwidget.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qlabel.h>
#include "Controller.h"
#include <qcombobox.h>

class MyGUI: public QWidget
{
public:
	MyGUI(Controller controller);
	~MyGUI();

private:
	Controller ctrl;
	QListWidget *list;
	QComboBox *box;
	QLabel *size;
	QLabel *colour;
	QLabel *price;
	QLabel *quantity;
	QLabel *photo;
	QLabel *SUM;
	QLineEdit *sizeEdit;
	QLineEdit *colourEdit;
	QLineEdit *priceEdit;
	QLineEdit *quantityEdit;
	QLineEdit *photoEdit;
	QPushButton *Add;
	QPushButton *Delete;
	QPushButton *UpdatePrice;
	QPushButton *UpdateQ;
	QPushButton *findSize;
	//QPushButton *saveToFile;
	QPushButton *listAll;
	QListWidget *sizeList;
	QPushButton *Show;
	QPushButton *Next;
	QPushButton *addBasket;
	QListWidget *basket;
	QListWidget *totalSum;
	QPushButton *sum;
	QPushButton *saveCSV;
	QPushButton *saveHTML;
	QPushButton *showFileBasket;

	void initGUI();
	void populateList();
	void populateSizeList();
	//void populateBasket();
	void AddGown();
	void RemoveGown();
	void UpdateGownPrice();
	void UpdateGownQuantity();
	void findBySize();
	void listAllGowns();
//	void saveToFile();
	void ShowGowns();
	void NextGown();
	void addToBasket();
	void basketSum();
	void SAVECSV();
	void SAVEHTML();
	void drop();
	void showBasketGUI();
};

