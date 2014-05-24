#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>
#include <string>
#include "object.h"


using namespace std;

class Factory{

public:
	Factory();
	virtual ~Factory();
	virtual Object* createIt(char ch) = 0;

protected:
	virtual int hash(char ch) = 0;
};

#endif