#pragma once
#include "Gowns.h"

template <typename T>
class Comparator
{
public:
	Comparator();
	virtual bool compare(T& e1, T& e2)=0;
	~Comparator();
};

template <typename T>
Comparator<T>::Comparator()
{
}

template <typename T>
Comparator<T>::~Comparator()
{
}

template <typename T>
class CompareAscendingBySize :public Comparator<T>
{
public:
	CompareAscendingBySize();
	bool compare(T& g1, T& g2) override;
	~CompareAscendingBySize();
};

template <typename T>
class CompareDescendingByPrice : public Comparator<T>
{
public:
	CompareDescendingByPrice();
	bool compare(T& e1, T& e2);
	~CompareDescendingByPrice();
};

template <typename T>
CompareAscendingBySize<T>::CompareAscendingBySize()
{
}

template <typename T>
CompareAscendingBySize<T>::~CompareAscendingBySize()
{
}

template <typename T>
bool CompareAscendingBySize<T>::compare(T& g1, T& g2)
{
	if (g1.getSize() < g2.getSize())
		return true;
	else
		return false;
}

template <typename T>
CompareDescendingByPrice<T>::CompareDescendingByPrice()
{
}

template <typename T>
CompareDescendingByPrice<T>::~CompareDescendingByPrice()
{
}

template <typename T>
bool CompareDescendingByPrice<T>::compare(T& e1, T& e2)
{
	if (e1.getPrice() > e2.getPrice())
		return true;
	else
		return false;
}