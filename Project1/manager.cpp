/*
This class is used to manage the interactions between external entities and the
manager class will in take all lines from the "txt' file and analyze the first
character of the line and send the command to the appropriate container.

*/
#include "manager.h"

	
void Manager::populateData(ifstream & intakeFile){
	char objectCode;
	objectCode = intakeFile.peek();
	emptyObject = factoryControl.selectFactory(objectCode); //new Obj
	emptyObject->setData(intakeFile);
	containerArray.insertIt(objectCode, emptyObject);
	emptyObject = NULL;
	while (!intakeFile.eof()){
		intakeFile.get();
		if (!intakeFile.eof()){
			populateData(intakeFile);
		}
	}
}

Manager::~Manager(){}


void Manager::printContainer(ostream & output, ObjectController & toPrint){
	toPrint.print(output);
}

void Manager::print(ostream & output){
	printContainer(output, containerArray);
}

	//peek and get line are from ifstream class itself