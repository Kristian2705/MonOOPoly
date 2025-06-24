#pragma once
#include "MyString.h"

class HelperFunctions
{
public:
	static void saveMyStringToBinaryFile(std::ofstream& ofs, const MyString& str);
	static MyString loadMyStringFromBinaryFile(std::ifstream& ifs);
	static size_t getFileSize(std::ifstream& ifs);
};

