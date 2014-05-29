/*
This class is used to manage the interactions between external entities and the
manager class will in take all lines from the "txt' file and analyze the first
character of the line and send the command to the appropriate container.

*/
#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <fstream>
#include "objectcontroller.h"
#include "factorycontroller.h"


using namespace std;

class Manager {


public:
	~Manager();
	void print();
	void printContainer(ObjectController &) const;
	void populateData(ifstream & inputfile);
	//bool borrowDVD(ifstream input);
	//bool returnDVD(string dvdName, string custFullName);

protected:
	Object* emptyObject;
	ObjectController containerArray;
	FactoryController factoryControl;
};

#endif

/*
TODO:
check for const
check for bad input and how to mitigate it
*/