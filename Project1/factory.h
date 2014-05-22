#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>
#include <string>
#include "object.h"
#include "customerobj.h"
#include "classicobj.h"
#include "comedyobj.h"
#include "dramaobj.h"

using namespace std;

class Factory{
	static const int FACTSIZE = 7; 
public:
	Factory();
	~Factory();
	Object* createIt(char ch);

private:
	Object* objFactory[FACTSIZE];
	int hash(char ch);

};

#endif