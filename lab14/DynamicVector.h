#pragma once
#include "Comparator.h"

template <typename T>
class DynamicVector
{
private:
	T * elems;
	int size;
	int capacity;

public:
	DynamicVector<T>(int capacity = 10);

	//copy constructor for a DynamicVector
	DynamicVector<T>(const DynamicVector& v);
	~DynamicVector<T>();

	//overload the operator -
	DynamicVector<T>& operator-(const T& e);
	
	//adds an element to the current DynamicVector
	void add(const T& e);
	//removes and element from the current DynamicVector
	void remove(const T& e);

	int getSize() const;
	T* getAllElems() const;
	int getCapacity() const;
	void sort(Comparator<T>& cmp);

private:
	//Resizes the current DynamicVector, multiplying its capacity by a given factor (real number).
	void resize(double factor = 2);
};

template <typename T>
DynamicVector<T>::DynamicVector(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	this->elems = new T[capacity];
}

template <typename T>
DynamicVector<T>::DynamicVector(const DynamicVector<T>& v)
{
	this->size = v.size;
	this->capacity = v.capacity;
	this->elems = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];
}

template <typename T>
DynamicVector<T>::~DynamicVector()
{
	delete[] this->elems;
}


template <typename T>
void DynamicVector<T>::add(const T& e)
{
	if (this->size == this->capacity)
		this->resize();
	this->elems[this->size] = e;
	this->size++;
}

template <typename T>
void DynamicVector<T>::remove(const T & e)
{ 
	int index;
	for (int i = 0; i < this->getSize(); i++)
		if (this->elems[i] == e)
			index = i;
	for (int i = index; i < (this->getSize() - 1); i++)
		this->elems[i] = this->elems[i + 1];
	this->size--;
}

template <typename T>
DynamicVector<T> &DynamicVector<T>::operator-(const T& e)
{
	this->remove(e);
	return *this;
}

template <typename T>
void DynamicVector<T>::resize(double factor)
{
	this->capacity *= static_cast<int>(factor);

	T* els = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		els[i] = this->elems[i];

	delete[] this->elems;
	this->elems = els;
}

template <typename T>
T* DynamicVector<T>::getAllElems() const
{
	return this->elems;
}

template <typename T>
int DynamicVector<T>::getSize() const
{
	return this->size;
}

template <typename T>
int DynamicVector<T>::getCapacity() const
{
	return this->capacity;
}

template <typename T>
void DynamicVector<T>::sort(Comparator<T>& cmp)
{
	int i, j;
	Gowns aux;
	//CompareDescendingByPrice <Gowns> cmp;
	for (i = 0; i < this->getSize()-1; i++)
	{
		for (j = i+1; j < this->getSize(); j++)
		{
			if (cmp.compare(this->elems[i], this->elems[j]) == false)
			{
				aux = this->elems[i];
				this->elems[i] = this->elems[j];
				this->elems[j] = aux;
			}
		}
	}
}