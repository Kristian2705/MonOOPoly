#pragma once
#include <iostream>
#include "Constants.h"

template<typename T>
class PolymorphicContainer
{
	T** elements;
	int size;
	int capacity;
	void resize(int newCapacity);
	void copyFrom(const PolymorphicContainer& other);
	void free();
public:
	PolymorphicContainer();
	PolymorphicContainer(const PolymorphicContainer& other);
	PolymorphicContainer<T>& operator=(const PolymorphicContainer& other);
	~PolymorphicContainer();
	void addElement(const T& el);
	void addElement(T* el);
	void remove(int index);
	int getSize() const;
	const T* operator[](int index) const;
	T* operator[](int index);
	void swap(int i, int j);
};

template<class T>
PolymorphicContainer<T>::PolymorphicContainer()
{
	capacity = Utils::MIN_CAPACITY;
	elements = new T * [capacity] { nullptr };
	size = 0;

}

template<class T>
void PolymorphicContainer<T>::copyFrom(const PolymorphicContainer& other)
{
	size = other.size;
	capacity = other.capacity;
	elements = new T * [capacity] { nullptr };
	for (int i = 0; i < size; i++)
	{
		elements[i] = other.elements[i]->clone();
	}
}

template<class T>
void PolymorphicContainer<T>::resize(int newCapacity)
{
	T** temp = new T * [newCapacity] { nullptr };
	for (int i = 0; i < size; i++)
	{
		temp[i] = elements[i];
	}
	delete[] elements;
	elements = temp;
	capacity = newCapacity;
}

template<class T>
PolymorphicContainer<T>::PolymorphicContainer(const PolymorphicContainer& other)
{
	copyFrom(other);
}

template<class T>
PolymorphicContainer<T>& PolymorphicContainer<T>::operator=(const PolymorphicContainer& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template<class T>
void PolymorphicContainer<T>::free()
{
	for (int i = 0; i < size; i++)
	{
		delete elements[i];
	}
	delete[] elements;
}

template<class T>
PolymorphicContainer<T>::~PolymorphicContainer()
{
	free();
}

template<class T>
int PolymorphicContainer<T>::getSize() const
{
	return size;
}

template<class T>
void PolymorphicContainer<T>::addElement(const T& el)
{
	if (size == capacity) {
		resize(capacity * 2);
	}
	elements[size++] = el.clone();
}

template<class T>
void PolymorphicContainer<T>::addElement(T* el)
{
	if (!el) {
		return;
	}
	if (size == capacity) {
		resize(capacity * 2);
	}
	elements[size++] = el;
}

template<class T>
void PolymorphicContainer<T>::remove(int index)
{
	if (index >= size) {
		throw std::out_of_range("Error index out of range");
	}
	delete elements[index];
	for (int i = index; i < size - 1; i++)
	{
		elements[i] = elements[i + 1];
	}
	elements[size - 1] = nullptr;
	size--;
}

template<class T>
const T* PolymorphicContainer<T>::operator[](int index) const
{
	if (index >= size) {
		throw std::invalid_argument("Invalid index");
	}
	return elements[index];
}

template<class T>
T* PolymorphicContainer<T>::operator[](int index)
{
	if (index >= size) {
		throw std::invalid_argument("Invalid index");
	}
	return elements[index];
}

template<class T>
void PolymorphicContainer<T>::swap(int i, int j)
{
	std::swap(elements[i], elements[j]);
}