#include "HelperFunctions.h"

void HelperFunctions::saveMyStringToBinaryFile(std::ofstream& ofs, const MyString& str)
{
	int size = str.getSize();
	ofs.write((const char*)(&size), sizeof(size));
	ofs.write(str.c_str(), sizeof(char) * size);
}

MyString HelperFunctions::loadMyStringFromBinaryFile(std::ifstream& ifs)
{
	int size = 0;
	ifs.read((char*)(&size), sizeof(size));
	char* buffer = new char[size + 1];
	ifs.read(buffer, sizeof(char) * size);
	buffer[size] = '\0';
	MyString str(buffer);
	delete[] buffer;
	return str;
}

size_t HelperFunctions::getFileSize(std::ifstream& ifs)
{
	size_t currPos = ifs.tellg();
	ifs.seekg(0, std::ios::end);
	size_t size = ifs.tellg();
	ifs.seekg(currPos, std::ios::beg);
	return size;
}
