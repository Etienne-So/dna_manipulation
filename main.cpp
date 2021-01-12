#include <iostream>
#include <vector>
#include "acgtstring.h"


bool isAcgtString(std::string chars);
/*
 * Compilation: g++ main.cpp acgtstring.cpp -o solution
 *
 * Example:
 * solution "ACGATGTG" insertion GT 1
 * solution "ACGATGTG" deletion 2 4
 */

int main(int argc, char* argv[])
{
	std::string originalString = argv[1];

	ACGTString myObj = ACGTString();

	if (argc == 2 && originalString == "HELP") {
		std::cout << "Usage : ACGTSTRING + ACTION + PARAM1 + PARAM2\n" << std::endl;
		std::cout << "ACGTSTRING is a string composed uniquely of A C G and T letters \nACTION can be insertion or deletion \n" << std::endl;
		std::cout << "If action = insertion, PARAM1 is the string to insert, PARAM2 is the index where to insert PARAM1 into the string \n" << std::endl;
		std::cout << "If action = deletion, PARAM1 is the number of characters to be deleted, PARAM2 is the index where to start the deletion \n" << std::endl;
	}


	if (argc == 5) 
	{
		std::string action = argv[2];
		int index = atoi(argv[4]);

		if (isAcgtString(originalString) == true)
		{
			//std::cout << "The Original String IS a ACGT String \n" << std::endl;
			myObj.setAcgtString(originalString);

			if (action == "insertion")
			{
				std::cout << "The action is an insertion starting at index " << index << "\n" << std::endl;

				std::string stringToInsert = argv[3];
				if (isAcgtString(stringToInsert) == true)
				{
					if (-1 <= index < int(myObj.getAcgtString().length())) // La comparaison à -1 permet d'inserer une acgtString à la position 0 de la acgtString originale
					{
						//myObj.insertChars(stringToInsert, index);
						std::vector<std::string> result = myObj.insertCharsV2(stringToInsert, index);
						std::cout << "The new string is : " << myObj.acgtString << "\n" << std::endl;
						std::cout << "The insertion was performed at index " << myObj.getIndexActionPerformed() << "\n" << std::endl;
						for (int j = 0; j < result.size(); j++)
						{
							std::cout << result[j] << "\n" << std::endl;
						}
					}
					else 
						std::cout << "The index to insert into the string is out of range !  \n" << std::endl;
				}
				else
					std::cout << "The String to insert is not a ACGT String \n" << std::endl;
			}
			else if(action == "deletion")
			{
				int elementsToDel = atoi(argv[3]);
				int span = index + elementsToDel;
				//std::cout << "index = " << index << "| number of elements to delete : " << elementsToDel << "| span : " << span << std::endl;
				if (span < myObj.getAcgtString().length())
				{
					std::cout << "The action is a deletion starting at index " << index << "\n" << std::endl;
					std::vector<std::string> result = myObj.deleteCharsV2(elementsToDel, index);
					std::cout << "The new string is : " << myObj.acgtString << "\n" << std::endl;
					std::cout << "The deletion was performed at index " << myObj.getIndexActionPerformed() << "\n" << std::endl;
					for (int j = 0; j < result.size(); j++)
					{
						std::cout << result[j] << "\n" << std::endl;
					}
				}
				else
					std::cout << "The action could not be performed as it goes out of range \n" << std::endl;
			}
			else
				std::cout << "The action was not recognized \n" << std::endl;
		}
		else {
			std::cout << "The String is not a ACGT String \n" << std::endl;
			return 0;
		}
	}
	else if(argc != 5 && originalString != "HELP")
		std::cout << "Error, wrong syntax ! \nExample : " << argv[0] << "ACGTSTRING + ACTION + PARAM1 + PARAM2 \nType 'Solution HELP' for more information.'" << std::endl;
	
}


bool isAcgtString(std::string chars)
{
	bool compteur = true;
	for (int i = 0; i < chars.length(); i++)
	{
		if (chars[i] != 'C' && chars[i] != 'G' && chars[i] != 'A' && chars[i] != 'T')
		{
			compteur = false;
			break;
		}
	}
	return compteur;
}
