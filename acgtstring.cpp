#include <iostream>
#include <vector>
#include "acgtstring.h"

ACGTString::ACGTString(std::string chars)
{
	this->acgtString = chars;
}

int ACGTString::insertChars(std::string str, int i)
{
	this->acgtString.insert(i+1, str);
    return 0;
}

std::vector<std::string> ACGTString::insertCharsV2(std::string str, int i)
{
	std::vector<std::string> result;
	std::string equivalentInsert;
	std::string originalString = this->acgtString;
	std::string subString = str;
	int index = i;
	while (index < originalString.length())
	{
		if (subString[0] == originalString[index + 1])
		{
			subString = modifSubstring(subString);
			equivalentInsert = "Equivalent insertion " + subString + " at index " + std::to_string(index+1);
			result.push_back(equivalentInsert);
		}
		else
			break;
		index++;
	}
	this->indexActionPerformed = index;
	this->acgtString.insert(index+1, subString);
	//std::cout << "Substring : " << subString << " | index  = " << index  << std::endl;
	return result;
}

int ACGTString::deleteChars(int nbChars, int i)
{
	this->acgtString.erase(i, nbChars);
    return 0;
}

std::vector<std::string> ACGTString::deleteCharsV2(int nbChars, int i)
{
	std::vector<std::string> result;
	std::string equivalentInsert;
	std::string originalString = this->acgtString;
	std::string subString = originalString.substr(i, nbChars);
	//std::cout << "SubString Deletion = " << subString << std::endl;
	int index = i;
	//std::cout << "Index = " << index << std::endl;
	while (index < originalString.length())
	{
		if (subString[0] == originalString[int(subString.length()) + index])
		{
			subString = modifSubstring(subString);
			equivalentInsert = "Equivalent deletion " + subString + " at index " + std::to_string(index + 1);
			result.push_back(equivalentInsert);
		}
		else
			break;
		index++;
	}
	this->indexActionPerformed = index;
	this->acgtString.erase(index, nbChars);
	//std::cout << "Substring : " << subString << " | index  = " << index  << std::endl;
	return result;
}

std::string ACGTString::modifSubstring(std::string str)
{
	std::string tmp = str;
	tmp.insert(tmp.end(), tmp[0]);
	tmp.erase(0, 1);
	//std::cout << "tmp = " << tmp << std::endl;
	return tmp;
}


std::string ACGTString::getAcgtString() {
	return this->acgtString;
}

void ACGTString::setAcgtString(std::string chars) {
	this->acgtString = chars;
}

int ACGTString::getIndexActionPerformed()
{
	return this->indexActionPerformed;
}

ACGTString::ACGTString() {

}
