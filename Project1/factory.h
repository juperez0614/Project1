//---------------------------------------------------------------------------
// Factory.h
// stores customers, movies, and actions
// Authors: Julio Perez, Jeffrey Asmus
//---------------------------------------------------------------------------
// factory class:  
//		includes  features:
//   -- creates objects
//
//---------------------------------------------------------------------------
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
