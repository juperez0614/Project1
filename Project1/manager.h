/*
This class is used to manage the interactions between external entities and the
manager class will in take all lines from the "txt' file and analyze the first
character of the line and send the command to the appropriate container.

*/
#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <fstream>
#include "objectcontainer.h"
#include "factory.h"


using namespace std;

class Manager {

	static const int USER_TYPES = 1;
	static const int GENRE_TYPES = 3;

public:

	void intakeDataFromFile(ifstream & inputfile);
	//bool borrowDVD(ifstream input);
	//bool returnDVD(string dvdName, string custFullName);

protected:
	Object* emptyObject;
	ObjectContainer* containerArray [(USER_TYPES + GENRE_TYPES) * 2 + 1];
	Factory* objFactory;
};

#endif