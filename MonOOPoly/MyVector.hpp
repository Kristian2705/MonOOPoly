#pragma once
#include<iostream>
#include "Constants.h"

template <typename T>
class MyVector {
	T* elements;
	size_t size;
	size_t capacity;

	void copyFrom(const MyVector<T>& other);

	void free();

	void resize(int newCapacity);

public:
	MyVector();

	MyVector(size_t capacity);

	MyVector(size_t size, const T& initialValue);

	MyVector(const MyVector<T>& other);

	MyVector& operator=(const MyVector<T>& other);

	~MyVector();

	void push_back(const T& value);

	void pop_back();

	bool isEmpty() const;

	bool contains(const T& value) const;

	void insert(size_t index, const T& value);

	T* begin();

	const T* begin() const;

	T* end();

	const T* end() const;

	size_t getSize() const;

	size_t getCapacity() const;

	void reserve(size_t newCapacity);

	void shrink_to_fit();

	void clear();

	T& operator[](size_t index);

	const T& operator[](size_t index) const;

	T& at(size_t index);

	const T& at(size_t index) const;

	template<typename K>
	friend std::ostream& operator<<(std::ostream& os, const MyVector<K>& obj);
};

template <typename T>
bool operator==(const MyVector<T>& lhs, const MyVector<T>& rhs);

template <typename T>
bool operator!=(const MyVector<T>& lhs, const MyVector<T>& rhs);

static unsigned roundToPowerOfTwo(unsigned v)
{
	v--;
	v |= v >> 1;
	v |= v >> 2;
	v |= v >> 4;
	v |= v >> 8;
	v |= v >> 16;
	v++;
	return v;
}

template<typename T>
MyVector<T>::MyVector() {
	size = 0;
	capacity = GameConstants::MIN_CAPACITY;
	elements = new T[GameConstants::MIN_CAPACITY];
}

template<typename T>
MyVector<T>::MyVector(size_t capacity) {
	size = 0;
	this->capacity = capacity;
	elements = new T[this->capacity];
}
template<typename T>
MyVector<T>::MyVector<T>(size_t size, const T& initialValue) {
	this->size = size;
	capacity = roundToPowerOfTwo(this->size);
	elements = new T[capacity];

	for (int i = 0; i < this->size; i++) {
		elements[i] = initialValue;
	}
}

template<typename T>
void MyVector<T>::copyFrom(const MyVector<T>& other) {
	if (!other.elements) {
		return;
	}

	size = other.size;
	capacity = other.capacity;
	elements = new T[capacity];
	for (int i = 0; i < size; i++) {
		elements[i] = other[i];
	}
}

template<typename T>
void MyVector<T>::free() {
	delete[] elements;
	elements = nullptr;
}

template<typename T>
MyVector<T>::MyVector(const MyVector<T>& other) {
	copyFrom(other);
}

template<typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

template<typename T>
MyVector<T>::~MyVector() {
	delete[] elements;
}

template<typename T>
void MyVector<T>::resize(int newCapacity) {
	T* newElements = new T[newCapacity];
	for (int i = 0; i < size; i++) {
		newElements[i] = elements[i];
	}
	free();
	elements = newElements;
	capacity = newCapacity;
}

template<typename T>
void MyVector<T>::push_back(const T& value) {
	if (size == capacity) {
		resize(capacity * 2);
	}

	elements[size] = value;
	size++;
}

template<typename T>
void MyVector<T>::pop_back() {
	if (size == 0) {
		throw std::out_of_range("Vector is empty");
	}

	size--;
}

template<typename T>
bool MyVector<T>::isEmpty() const {
	return (size == 0);
}

template<typename T>
bool MyVector<T>::contains(const T& value) const {
	for (int i = 0; i < size; i++) {
		if (elements[i] == value) {
			return true;
		}
	}
	return false;
}

template<typename T>
void MyVector<T>::insert(size_t index, const T& value) {
	if (index < 0 || index > size) {
		throw std::out_of_range("Insert index out of range");
	}

	if (size == capacity) {
		resize(capacity * 2);
	}

	for (int i = size; i >= index; i--) {
		elements[i] = elements[i - 1];
	}

	elements[index] = value;
	size++;
}

template<typename T>
T* MyVector<T>::begin() {
	return elements;
}

template<typename T>
const T* MyVector<T>::begin() const {
	return elements;
}

template<typename T>
T* MyVector<T>::end() {
	return elements + size;
}

template<typename T>
const T* MyVector<T>::end() const {
	return elements + size;
}

template<typename T>
size_t MyVector<T>::getSize() const {
	return size;
}

template<typename T>
size_t MyVector<T>::getCapacity() const {
	return capacity;
}

template<typename T>
void MyVector<T>::reserve(size_t newCapacity) {
	if (newCapacity > capacity) {
		resize(newCapacity);
	}
}

template<typename T>
void MyVector<T>::shrink_to_fit() {
	if (size == 0) {
		return;
	}
	if (capacity > size) {
		resize(size);
	}
}

template<typename T>
void MyVector<T>::clear() {
	size = 0;
}

template<typename T>
T& MyVector<T>::operator[](size_t index) {
	return elements[index];
}

template<typename T>
const T& MyVector<T>::operator[](size_t index) const {
	return elements[index];
}

template<typename T>
T& MyVector<T>::at(size_t index) {
	if (index < 0 || index >= size) {
		throw std::out_of_range("Index out of range");
	}

	return elements[index];
}

template<typename T>
const T& MyVector<T>::at(size_t index) const {
	return this->at(index);
}

template<typename K>
std::ostream& operator<<(std::ostream& os, const MyVector<K>& obj) {
	int size = obj.getSize();
	for (int i = 0; i < size - 1; i++) {
		os << obj[i] << ' ';
	}
	os << obj[size - 1];
	return os;
}

template<typename T>
bool operator==(const MyVector<T>& lhs, const MyVector<T>& rhs) {
	if (lhs.getSize() != rhs.getSize()) {
		return false;
	}

	int size = lhs.getSize();

	for (int i = 0; i < size; i++) {
		if (lhs[i] != rhs[i]) {
			return false;
		}
	}
	return true;
}

template<typename T>
bool operator!=(const MyVector<T>& lhs, const MyVector<T>& rhs) {
	return !(lhs == rhs);
}
