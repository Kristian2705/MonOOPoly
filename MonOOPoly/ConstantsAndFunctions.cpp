#include "ConstantsAndFunctions.h"
#include "MyString.h"

namespace SaveFunctions {
	void SaveFunctions::saveMyStringToBinaryFile(std::ofstream& ofs, const MyString& str)
	{
		int size = str.getSize();
		ofs.write((const char*)(&size), sizeof(size));
		ofs.write(str.c_str(), sizeof(char) * size);
	}

	MyString SaveFunctions::loadMyStringFromBinaryFile(std::ifstream& ifs)
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
}
