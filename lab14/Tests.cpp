#include "Tests.h"
#include <assert.h>
#include "Basket.h"
#include "CSVBasket.h"

void Tests::testRepo()
{
	Repo repo;

	Gowns g;
	assert(repo.findGownByPicture("www.google.com") == g);
	assert(repo.findGownSBySize(34).size()==0);

	Gowns g1(36, "blue", 1999, 12, "http://www.eliesaab.com/en/haute-couture/ss-2017/1/1");
	Gowns g2(38, "gold", 2999, 0, "http://www.eliesaab.com/en/haute-couture/ss-2017/14/1");
	Gowns g3(40, "red", 3500, 5, "http://www.eliesaab.com/en/haute-couture/fw-2017-2018/17/0");

	repo.addGown(g1);
	repo.addGown(g2);
	repo.addGown(g3);

	assert(repo.getGowns().size() == 3);

	Gowns g4(36, "red", 10000, 2, "www.google.com");
	repo.addGown(g4);
	assert(repo.getGowns().size() == 4);
	repo.removeGown(g3);
	assert(repo.getGowns().size() == 3);
	repo.updatePrice("www.google.com", 34);
	assert(repo.findGownByPicture("www.google.com") == g4);
	assert(repo.findGownByPicture("www.google.com").getPrice() == 34);
	repo.updateQuantity("www.google.com", 10);
	assert(repo.findGownByPicture("www.google.com").getQuantity() == 10);
	
	std::vector<Gowns> v = repo.findGownSBySize(36);
	assert(v.size() == 2);
}

void Tests::testController()
{
	Repo repo;
	Gowns g1(36, "blue", 1999, 12, "www.google.com");
	Gowns g2(38, "red", 1500, 0, "www.youtube.com");
	Gowns g3(34, "yellow", 5000, 40, "www.facebook.com");
	repo.addGown(g1);
	repo.addGown(g2);
	repo.addGown(g3);

	List list{};
	Basket* basket = new CSVBasket{ std::string("Basket.csv") };
	GownValidator v;
	Controller ctrl(repo, list, basket, v);

	assert(ctrl.getRepo().getGowns().size() == 3);
	ctrl.addGownC(36, "pink", 5500, 10, "www.pinterest.com");
	assert(ctrl.getRepo().getGowns().size() == 4);
	ctrl.removeGownC();
	assert(ctrl.getRepo().getGowns().size() == 3);
	ctrl.updatePriceC("www.google.com", 20);
	assert(ctrl.getRepo().getGowns()[0].getPrice() == 20);
	ctrl.updateQuantityC("www.google.com", 2);
	assert(ctrl.getRepo().getGowns()[0].getQuantity() == 2);

	ctrl.findGownsBySizeC(36);
	assert(ctrl.getList().isEmpty() == false);
	assert(ctrl.getList().getCurrentGown() == g1);
	ctrl.addGownToBasket(g1);
	assert(ctrl.getBasket().size() == 1);
	assert(ctrl.getBasket()[0] == g1);
	ctrl.addGownToBasket(g2);
	assert(ctrl.totalBasket() == 3499);


	Repo repo2;
	Gowns gg1(36, "blue", 1999, 12, "www.google.com");
	Gowns gg2(38, "red", 1500, 0, "www.youtube.com");
	Gowns gg3(34, "yellow", 5000, 40, "www.facebook.com");
	repo2.addGown(g1);
	repo2.addGown(g2);
	repo2.addGown(g3);

	List list2{};
	Basket* basket2 = new CSVBasket{ std::string("Basket.csv") };
	GownValidator v2;
	Controller ctrl2(repo2, list2, basket2, v2);
	ctrl2.findGownsBySizeC(0);
	assert(ctrl2.getList().isEmpty() == false);
	assert(ctrl2.getList().getCurrentGown() == gg1);
	ctrl2.startList();
	ctrl2.nextGown();
	assert(ctrl2.getList().getCurrentGown() == gg2);

}

void Tests::testList()
{
	List list;
	Gowns g1(36, "blue", 1999, 12, "www.google.com");
	Gowns g2(38, "red", 1500, 20, "www.youtube.com");
	Gowns g3(34, "yellow", 5000, 40, "www.facebook.com");

	assert(list.isEmpty() == true);
	assert(list.getCurrentGown() == Gowns{});
	Gowns g;
	assert(list.getCurrentGown() == g);
	list.add(g1);
	list.add(g2);
	list.add(g3);
	assert(list.isEmpty() == false);
	list.show();
	assert(list.getCurrentGown() == g1);
	list.next();
	assert(list.getCurrentGown() == g2);
}

void Tests::testGown()
{
	Gowns g(36, "blue", 1999, 12, "http://www.eliesaab.com/en/haute-couture/ss-2017/1/1");
	assert(g.getSize() == 36);
	assert(g.getColour() == "blue");
	assert(g.getPhoto() == "http://www.eliesaab.com/en/haute-couture/ss-2017/1/1");
	assert(g.getPrice() == 1999);
	assert(g.getQuantity() == 12);
	g.setColour("purple");
	assert(g.getColour() == "purple");
	g.setPhoto("www.google.com");
	assert(g.getPhoto() == "www.google.com");
	g.setPrice(20);
	assert(g.getPrice() == 20);
	g.setQuantity(10);
	assert(g.getQuantity() == 10);
	g.setSize(34);
	assert(g.getSize() == 34);
}

void Tests::testDynamicVector()
{
	DynamicVector<Gowns> v;
	Gowns g1(36, "blue", 1999, 12, "www.google.com");
	Gowns g2(38, "red", 1500, 20, "www.youtube.com");
	Gowns g3(34, "yellow", 5000, 40, "www.facebook.com");
	Gowns g11(40, "red", 3500, 5, "http://www.eliesaab.com/en/haute-couture/fw-2017-2018/17/0");
	Gowns g4(38, "black", 2000, 10, "http://www.eliesaab.com/en/haute-couture/fw-2017-2018/5/0");
	Gowns g5(40, "green", 999, 40, "http://www.eliesaab.com/en/haute-couture/fw-2017-2018/13/0");
	Gowns g6(36, "ochre", 4000, 17, "http://www.eliesaab.com/en/haute-couture/fw-2017-2018/22/0");
	Gowns g7(38, "red", 3000, 20, "http://www.eliesaab.com/en/haute-couture/fw-2017-2018/21/0");
	Gowns g8(36, "white", 10000, 1, "http://www.eliesaab.com/en/bridal/fw-2017/3/0");
	Gowns g9(36, "white", 9000, 5, "http://www.eliesaab.com/en/bridal/ss-2017/15/0");
	Gowns g10(38, "white", 8000, 0, "http://www.eliesaab.com/en/bridal/ss-2018/4/0");
	Gowns g20(38, "white", 8000, 0, "http://www.eliesaab.com/en/bridal/ss-2018/4/0");

	v.add(g1);
	v.add(g2);
	v.add(g3);
	assert(v.getSize() == 3);
	v.remove(g2);
	assert(v.getSize() == 2);
	assert(v.getAllElems()[0].getColour() == "blue");
	assert(v.getCapacity() == 10);
	
	v.add(g4);
	v.add(g11);
	v.add(g5);
	v.add(g6);
	v.add(g7);
	v.add(g8);
	v.add(g9);
	v.add(g10);
	v.add(g20);
	//assert(v.getCapacity() == 12);
}
