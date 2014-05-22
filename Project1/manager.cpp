/*
This class is used to manage the interactions between external entities and the
manager class will in take all lines from the "txt' file and analyze the first
character of the line and send the command to the appropriate container.

*/
#include "manager.h"

	
void Manager::intakeDataFromFile(ifstream & intakeFile){
	char movieCode;
	intakeFile >> movieCode;
	emptyObject =  objFactory.createIt(movieCode);
	emptyObject->setData(intakeFile);
	containerArray.insertIt(movieCode, emptyObject);
	emptyObject = NULL;
}


	//peek and get line are from ifstream class itself