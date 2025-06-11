#include "MyString.h"
#include <exception>
#pragma warning(disable:4996)

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

MyString::MyString() {
    size = 0;
    capacity = Utils::MIN_CAPACITY;
    str = new char[capacity + 1];
    str[capacity] = '\0';
}

MyString::MyString(const char* other) {
    size = strlen(other);
    capacity = roundToPowerOfTwo(size);
    str = new char[capacity + 1];
    strcpy(str, other);
}

MyString::MyString(const MyString& other) {
    copyFrom(other);
}

MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }

    return *this;
}

MyString::~MyString() {
    delete[] str;
}

void MyString::copyFrom(const MyString& other) {
    if (!other.str) {
        return;
    }
    this->str = new char[other.capacity + 1];
    this->size = other.size;
    this->capacity = other.capacity;
    strcpy(this->str, other.str);
}

void MyString::free() {
    delete[] str;
    str = nullptr;
}

size_t MyString::getSize() const {
    return this->size;
}

size_t MyString::getCapacity() const {
    return this->capacity;
}

const char* MyString::c_str() const {
    return str ? str : "";
}

void MyString::clear() {
    free();
    str = new char[1];
    str[0] = '\0';
    size = 0;
    capacity = 0;
}

void MyString::shrinkToFit() {
    if (size == 0) {
        return;
    }
    if (capacity > size) {
        resizeCapacity(size);
    }
}

void MyString::resize(int size) {
    if (size < 0) {
        throw std::out_of_range("Size is out of range");
    }

    if (size > this->size) {
        resizeCapacity(size);
        return;
    }

    this->size = size;
    str[this->size] = '\0';
}

void MyString::resize(int size, char ch) {
    if (size < 0) {
        throw std::out_of_range("Size is out of range");
    }

    if (size > this->size) {
        resizeCapacity(size);
        for (int i = this->size; i < size; i++) {
            str[i] = ch;
        }
    }

    this->size = size;
    str[this->size] = '\0';
}

void MyString::reserve(size_t newCapacity) {
    if (newCapacity > capacity) {
        resizeCapacity(newCapacity);
    }
}

char& MyString::at(size_t pos) {
    if (pos < 0 || pos >= size) {
        throw std::out_of_range("Index out of range");
    }
    return str[pos];
}

const char& MyString::at(size_t pos) const {
    if (pos < 0 || pos >= size) {
        throw std::out_of_range("Index out of range");
    }
    return str[pos];
}

char& MyString::back() {
    return str[size - 1];
}

const char& MyString::back() const {
    return str[size - 1];
}

char& MyString::front() {
    return str[0];
}

const char& MyString::front() const {
    return str[0];
}

bool MyString::empty() const {
    return (size == 0);
}

MyString MyString::substr(unsigned startIndex, unsigned len) const {
    if (startIndex < 0 || startIndex >= size
        || len < 0 || (startIndex - 1 + len > size && startIndex + len != 0)) {
        throw std::out_of_range("Index is out of range");
    }

    char* newStr = new char[len + 1];
    for (int i = startIndex; i < startIndex + len; i++) {
        newStr[i - startIndex] = str[i];
    }

    newStr[len] = '\0';

    MyString substr(newStr);
    delete[] newStr;

    return substr;
}

int MyString::stoi() const
{
    int power = size - 1;
    int ind = 0;
    int num = 0;
    while (str[ind] != '\0') {
        int digit = str[ind++] - '0';
        num += digit * pow(10, power);
        power--;
    }
    return num;
}

MyString MyString::itos(int num)
{
    char res[Utils::BUFFER_CAPACITY];
    int i = 0;

    if (num == 0) {
        res[i++] = '0';
        res[i] = '\0';
        return MyString(res);
    }

    while (num > 0) {
        int digit = num % 10;
        res[i++] = digit + '0';
        num /= 10;
    }

    res[i] = '\0';
    MyString resStr(res);

    return resStr.reverse();
}

MyString MyString::reverse()
{
    for (int i = 0; i < size / 2; i++) {
        swap(str[i], str[size - 1 - i]);
    }
    return MyString(str);
}

char& MyString::operator[](size_t index) {
    return this->str[index];
}

const char& MyString::operator[](size_t index) const {
    return this->str[index];
}

MyString& MyString::operator+=(const MyString& other) {
    if (other.size == 0) {
        return *this;
    }

    int combinedSize = size + other.size;
    if (combinedSize > capacity) {
        resizeCapacity(combinedSize * 2);
    }

    for (int i = size; i < combinedSize; i++) {
        str[i] = other[i - size];
    }

    str[combinedSize] = '\0';
    size = combinedSize;

    return *this;
}

MyString& MyString::assign(const MyString& str) {
    clear();
    return (*this += str);
}

MyString& MyString::insert(size_t pos, const MyString& str) {
    if (pos < 0 || pos > size) {
        throw std::out_of_range("Index is out of range");
    }
    MyString lhs = substr(0, pos);
    lhs += str;
    if (pos != size) {
        MyString rhs = substr(pos, size - pos + 1);
        lhs += rhs;
    }
    return (*this = lhs);
}

MyString& MyString::erase(size_t pos, size_t len) {
    if (pos < 0 || pos >= size
        || len < 0 || pos - 1 + len > size) {
        throw std::out_of_range("Index is out of range");
    }
    MyString lhs = substr(0, pos);
    if (pos + len != size) {
        MyString rhs = substr(pos + len, size - pos - len + 1);
        lhs += rhs;
    }
    return (*this = lhs);
}

void MyString::resizeCapacity(int newCapacity) {
    char* newStr = new char[newCapacity + 1];
    for (int i = 0; i < size; i++) {
        newStr[i] = str[i];
    }
    newStr[size] = '\0';
    free();
    str = newStr;
    capacity = newCapacity;
}

void MyString::swap(char& a, char& b)
{
    char temp = a;
    a = b;
    b = temp;
}

std::ostream& operator<<(std::ostream& os, const MyString& obj) {
    os << obj.c_str();
    return os;
}

std::istream& operator>>(std::istream& is, MyString& ref) {
    ref.clear();

    char buffer[Utils::BUFFER_CAPACITY];
    is >> buffer;
    ref.size = strlen(buffer);
    ref.capacity = roundToPowerOfTwo(ref.size);
    ref.str = new char[ref.capacity + 1];
    strcpy(ref.str, buffer);
    return is;
}

MyString operator+(const MyString& lhs, const MyString& rhs) {
    MyString result(lhs);
    result += rhs;
    return result;
}

bool operator==(const MyString& lhs, const MyString& rhs) {
    return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

bool operator!=(const MyString& lhs, const MyString& rhs) {
    return !(lhs == rhs);
}

bool operator>(const MyString& lhs, const MyString& rhs) {
    return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}

bool operator<(const MyString& lhs, const MyString& rhs) {
    return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator>=(const MyString& lhs, const MyString& rhs) {
    return !(lhs < rhs);
}

bool operator<=(const MyString& lhs, const MyString& rhs) {
    return !(lhs > rhs);
}