/*
This class is used to manage the interactions between external entities and the
manager class will in take all lines from the "txt' file and analyze the first
character of the line and send the command to the appropriate container.

*/
#include "manager.h"

	
void Manager::populateData(ifstream & intakeFile){
/*
	char objectCode;
	objectCode = intakeFile.peek();
	emptyObject = factoryControl.selectFactory(objectCode); //new Obj
	emptyObject->setData(intakeFile);
emptyObject->display();
	containerArray.insertIt(objectCode, emptyObject);
	emptyObject = NULL;
	while (!intakeFile.eof()){
		intakeFile.get();
		if (!intakeFile.eof()){
			populateData(intakeFile);
		}
	}
*/
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

Manager::~Manager(){}


void Manager::printContainer(ObjectController & toPrint) const{
	toPrint.print();
}

void Manager::print(){
	printContainer(containerArray);
}

	//peek and get line are from ifstream class itself
