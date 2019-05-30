#include "MyGUI.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <qgridlayout.h>
#include <qlabel.h>
#include <string>

MyGUI::MyGUI(Controller controller) : ctrl{controller}
{
	this->initGUI();

	QObject::connect(this->box, &QComboBox::currentTextChanged, this, &MyGUI::drop);
	//QObject::connect(this->Show, &QPushButton::clicked, this, &MyGUI::populateList);
	QObject::connect(this->Add, &QPushButton::clicked, this, &MyGUI::AddGown);
	QObject::connect(this->Delete, &QPushButton::clicked, this, &MyGUI::RemoveGown);
	QObject::connect(this->UpdatePrice, &QPushButton::clicked, this, &MyGUI::UpdateGownPrice);
	QObject::connect(this->listAll, &QPushButton::clicked, this, &MyGUI::listAllGowns);
	QObject::connect(this->UpdateQ, &QPushButton::clicked, this, &MyGUI::UpdateGownQuantity);
	QObject::connect(this->findSize, &QPushButton::clicked, this, &MyGUI::findBySize);
	QObject::connect(this->Show, &QPushButton::clicked, this, &MyGUI::ShowGowns);
	QObject::connect(this->Next, &QPushButton::clicked, this, &MyGUI::NextGown);
	QObject::connect(this->addBasket, &QPushButton::clicked, this, &MyGUI::addToBasket);
	QObject::connect(this->saveCSV, &QPushButton::clicked, this, &MyGUI::SAVECSV);
	QObject::connect(this->saveHTML, &QPushButton::clicked, this, &MyGUI::SAVEHTML);
	QObject::connect(this->sum, &QPushButton::clicked, this, &MyGUI::basketSum);
	QObject::connect(this->showFileBasket, &QPushButton::clicked, this, &MyGUI::showBasketGUI);
}


MyGUI::~MyGUI()
{
}

void MyGUI::initGUI()
{
	QHBoxLayout *main = new QHBoxLayout(this);
	QVBoxLayout *left = new QVBoxLayout;
	
	QLabel * not = new QLabel("Admin mode: ");
	this->list = new QListWidget;
	
	left->addWidget(not);

	this->box = new QComboBox();
	this->box->addItem(QString::fromStdString(" "));
	this->box->addItem(QString::fromStdString("Short"));
	this->box->addItem(QString::fromStdString("Detailed"));
	left->addWidget(this->box);

	left->addWidget(this->list);


	QHBoxLayout *line1 = new QHBoxLayout;
	this->size = new QLabel("Size: ");
	this->sizeEdit = new QLineEdit;
	line1->addWidget(this->size);
	line1->addWidget(this->sizeEdit);
	left->addLayout(line1);

	QHBoxLayout *line2 = new QHBoxLayout;
	this->colour = new QLabel("Colour: ");
	this->colourEdit = new QLineEdit;
	line2->addWidget(this->colour);
	line2->addWidget(this->colourEdit);
	left->addLayout(line2);

	QHBoxLayout *line3 = new QHBoxLayout;
	this->price = new QLabel("Price: ");
	this->priceEdit = new QLineEdit;
	line3->addWidget(this->price);
	line3->addWidget(priceEdit);
	left->addLayout(line3);

	QHBoxLayout *line4 = new QHBoxLayout;
	this->quantity = new QLabel("Quantity: ");
	this->quantityEdit = new QLineEdit;
	line4->addWidget(quantity);
	line4->addWidget(quantityEdit);
	left->addLayout(line4);

	QHBoxLayout *line5 = new QHBoxLayout;
	this->photo = new QLabel("Photo: ");
	this->photoEdit = new QLineEdit;
	line5->addWidget(photo);
	line5->addWidget(photoEdit);
	left->addLayout(line5);

	QGridLayout *bottom_left = new QGridLayout;
	this->Add = new QPushButton("Add");
	bottom_left->addWidget(this->Add, 0, 1);

	this->Delete = new QPushButton("Delete");
	bottom_left->addWidget(this->Delete, 0, 0);

	this->UpdatePrice = new QPushButton("Update Price");
	bottom_left->addWidget(this->UpdatePrice, 1, 0);

	this->UpdateQ = new QPushButton("Update Quantity");
	bottom_left->addWidget(this->UpdateQ, 1, 1);

	this->findSize = new QPushButton("Find Size");
	bottom_left->addWidget(this->findSize, 1, 2);

	/*
	this->saveToFile = new QPushButton("Save To File");
	bottom_left->addWidget(this->saveToFile, 0, 2);
	*/
	
	this->listAll = new QPushButton("List All");
	bottom_left->addWidget(this->listAll, 0, 2);

	left->addLayout(bottom_left);

	QVBoxLayout *middle = new QVBoxLayout;
	QLabel * not2 = new QLabel("User mode: ");
	this->sizeList = new QListWidget;
	middle->addWidget(not2);
	middle->addWidget(this->sizeList);

	QGridLayout *bottom_middle = new QGridLayout;
	this->Show = new QPushButton("Show");
	bottom_middle->addWidget(this->Show, 0, 0);

	this->Next = new QPushButton("Next");
	bottom_middle->addWidget(this->Next, 0, 1);

	this->addBasket = new QPushButton("Add to Basket");
	bottom_middle->addWidget(this->addBasket, 0, 2);

	middle->addLayout(bottom_middle);

	QVBoxLayout *right = new QVBoxLayout;
	QLabel * not3 = new QLabel("Basket: ");
	this->basket = new QListWidget;
	right->addWidget(not3);
	right->addWidget(this->basket);

	QHBoxLayout *line = new QHBoxLayout;
	this->SUM = new QLabel("Sum: ");
	this->totalSum = new QListWidget;
	line->addWidget(SUM);
	right->addLayout(line);
	right->addWidget(this->totalSum);

	QGridLayout *bottom_right = new QGridLayout;
	this->sum = new QPushButton("Total Sum");
	bottom_right->addWidget(this->sum, 0, 0);

	this->saveCSV = new QPushButton("Save CSV");
	bottom_right->addWidget(this->saveCSV, 0, 1);

	this->saveHTML = new QPushButton("Save HTML");
	bottom_right->addWidget(this->saveHTML, 0, 2);

	this->showFileBasket = new QPushButton("Show Basket");
	bottom_right->addWidget(this->showFileBasket, 1, 1);


	right->addLayout(bottom_right);

	main->addLayout(left);
	main->addLayout(middle);
	main->addLayout(right);

}

void MyGUI::populateList()
{
	for (auto s : this->ctrl.getRepo().getGowns())
	{
		std::string string_ver = std::to_string(s.getSize()) + ", " + s.getColour() + ", " + std::to_string(s.getPrice())+", "+std::to_string(s.getQuantity())+", "+s.getPhoto();
		this->list->addItem(QString::fromStdString(string_ver));
	}
}

void MyGUI::populateSizeList()
{
	for (auto s : this->ctrl.getList().getGowns())
	{
		std::string gown = std::to_string(s.getSize()) + ", " + s.getColour() + ", " + std::to_string(s.getPrice()) + ", " + std::to_string(s.getQuantity()) + ", " + s.getPhoto();
		this->sizeList->addItem(QString::fromStdString(gown));
	}

}

void MyGUI::AddGown()
{
	QString content_size = this->sizeEdit->text();
	std::string size_s = content_size.toStdString();
	int size = stoi(size_s);

	QString content_colour = this->colourEdit->text();
	std::string colour = content_colour.toStdString();

	QString content_price = this->priceEdit->text();
	std::string price_s = content_price.toStdString();
	int price = stoi(price_s);

	QString content_quantity = this->quantityEdit->text();
	std::string quantity_s = content_quantity.toStdString();
	int quantity = stoi(quantity_s);


	QString content_photo = this->photoEdit->text();
	std::string photo = content_photo.toStdString();

	this->ctrl.addGownC(size,colour, price, quantity, photo);

	//this->populateList();
}

void MyGUI::RemoveGown()
{
	this->ctrl.removeGownC();
	//this->populateList();
}

void MyGUI::UpdateGownPrice()
{
	QString content_price = this->priceEdit->text();
	std::string price_s = content_price.toStdString();
	int new_price = stoi(price_s);

	QString content_photo = this->photoEdit->text();
	std::string photo = content_photo.toStdString();

	this->ctrl.updatePriceC(photo, new_price);
}

void MyGUI::UpdateGownQuantity()
{
	QString content_q = this->quantityEdit->text();
	std::string q_s = content_q.toStdString();
	int new_q = stoi(q_s);

	QString content_photo = this->photoEdit->text();
	std::string photo = content_photo.toStdString();

	this->ctrl.updateQuantityC(photo, new_q);
}

void MyGUI::findBySize()
{
	QString content_s = this->sizeEdit->text();
	std::string size_s = content_s.toStdString();
	int size = stoi(size_s);

	this->ctrl.findGownsBySizeC(size);
	this->populateSizeList();
}

void MyGUI::listAllGowns()
{
	this->populateList();
}

void MyGUI::ShowGowns()
{
	this->ctrl.startList();
}

void MyGUI::NextGown()
{
	this->ctrl.nextGown();
}

void MyGUI::addToBasket()
{
	Gowns s = this->ctrl.getList().getCurrentGown();
	this->ctrl.addGownToBasket(s);
	
	std::string gown = std::to_string(s.getSize()) + ", " + s.getColour() + ", " + std::to_string(s.getPrice()) + ", " + std::to_string(s.getQuantity()) + ", " + s.getPhoto();
	this->basket->addItem(QString::fromStdString(gown));
}

void MyGUI::basketSum()
{	
	std::string sum = std::to_string(this->ctrl.totalBasket());
	this->totalSum->addItem(QString::fromStdString(sum));
}

void MyGUI::SAVECSV()
{
	this->ctrl.setCSV();
}

void MyGUI::SAVEHTML()
{
	this->ctrl.setHTML();
}

void MyGUI::drop()
{
	QString current = this->box->currentText();
	std::string text = current.toStdString();

	if (text == "Short")
	{
		for (auto s : this->ctrl.getRepo().getGowns())
		{
			std::string g = std::to_string(s.getSize()) + ", " + s.getColour();
			this->list->addItem(QString::fromStdString(g));
		}
	}
	else
		if (text == "Detailed")
		{
			this->populateList();
		}
}

void MyGUI::showBasketGUI()
{
	this->ctrl.saveBasket();
}

