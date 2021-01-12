#include <string>
#include <vector>

/**
 * Class that encapsulated the string.
 * Provides the insert and delete method to be implemented.
 */
class ACGTString
{
public:
    enum Action
    {
        Insertion,
        Deletion
    };

	ACGTString();
	ACGTString(std::string chars);

	std::string acgtString;
	std::string getAcgtString();
	void setAcgtString(std::string chars);

    
	int indexActionPerformed;
	int getIndexActionPerformed();
    

    int insertChars(std::string str, int i);

	std::vector<std::string> insertCharsV2(std::string str, int i);
    
    int deleteChars(int i, int nbChars);

	std::vector<std::string> deleteCharsV2(int i, int nbChars);

	
private:
	std::string modifSubstring(std::string str);
};