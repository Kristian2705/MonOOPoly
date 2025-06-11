#pragma once
#include<fstream>
#include "Constants.h"

class MyString {
    char* str;
    size_t size;
    size_t capacity;

    void free();

    void copyFrom(const MyString& other);

    void resizeCapacity(int newCapacity);

    void swap(char& a, char& b);

public:
    MyString();

    MyString(const char* other);

    MyString(const MyString& other);

    MyString& operator=(const MyString& other);

    ~MyString();

    size_t getSize() const;

    size_t getCapacity() const;

    const char* c_str() const;

    MyString substr(unsigned startIndex, unsigned len) const;

    int stoi() const;

    static MyString itos(int num);

    MyString reverse();

    void clear();

    void shrinkToFit();

    void resize(int size);

    void resize(int size, char ch);

    void reserve(size_t newCapacity);

    char& at(size_t pos);

    const char& at(size_t pos) const;

    char& back();

    const char& back() const;

    char& front();

    const char& front() const;

    bool empty() const;

    char& operator[](size_t index);

    const char& operator[](size_t index) const;

    MyString& operator+=(const MyString& other);

    MyString& assign(const MyString& str);

    MyString& insert(size_t pos, const MyString& str);

    MyString& erase(size_t pos, size_t len);

    friend std::ostream& operator<<(std::ostream& os, const MyString& obj);

    friend std::istream& operator>>(std::istream& is, MyString& ref);
};

MyString operator+(const MyString& lhs, const MyString& rhs);

bool operator==(const MyString& lhs, const MyString& rhs);

bool operator!=(const MyString& lhs, const MyString& rhs);

bool operator>(const MyString& lhs, const MyString& rhs);

bool operator>=(const MyString& lhs, const MyString& rhs);

bool operator<(const MyString& lhs, const MyString& rhs);

bool operator<=(const MyString& lhs, const MyString& rhs);
