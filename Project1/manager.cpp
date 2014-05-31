/*
This class is used to manage the interactions between external entities and the
manager class will in take all lines from the "txt' file and analyze the first
character of the line and send the command to the appropriate container.

*/
#include "manager.h"

	
void Manager::populateData(ifstream & intakeFile){
	char objectCode;
        for (;;) {
	   objectCode = intakeFile.peek();
	  // cout << "peek " << objectCode << endl;
	   if (objectCode == EOF) break;
	   emptyObject = factoryControl.selectFactory(objectCode); //new Obj
	   emptyObject->setData(intakeFile);
	//emptyObject->display();
	   containerArray.insertIt(objectCode, emptyObject);
	   //emptyObject = NULL;
	}
}

void Manager::applyAction(ifstream & intakeFile){
	char objectCode;
	Object* custTemp;
	Object* movieTemp;
	for (;;) {
		objectCode = '\0';
		intakeFile >> objectCode;
		if (objectCode == EOF || objectCode == '\0') break;
		emptyAction = actionArray.selectAction(objectCode); 
		custTemp = factoryControl.selectFactory(1);//need to set partial data
		custTemp->setPartialData(intakeFile); // id to set
		custTemp = containerArray.find(1, custTemp);
		//customer is completely retireved
		emptyAction->setData(intakeFile); // needs to be after because of id
		
		movieTemp = factoryControl.selectFactory(emptyAction->getCode());
		movieTemp->setPartialData(intakeFile); //initial set
		movieTemp = containerArray.find(emptyAction->getCode(), movieTemp); //real set
		//customer is completely retreived
		emptyAction->customerSet(custTemp); // set to objects
		emptyAction->movieSet(movieTemp); //set
		//all attributes set, emptyAction is ready...
		emptyAction->performAct();
		//emptyObject = NULL;
	}
}


Manager::~Manager(){}


void Manager::printContainer(ObjectController & toPrint) const{
	toPrint.print();
}

void Manager::print(){
	printContainer(containerArray);
}

	//peek and get line are from ifstream class itself
//void Manager::borrowDVD(ifstream & intake) 