//---------------------------------------------------------------------------
// customerFactory.h
// derived class for factorys, stores movie objects
// Authors: Julio Perez, Jeffrey Asmus
//---------------------------------------------------------------------------
// customerfactor class:  
//		includes  features:
//   -- creates new customer types
//   -- hash objects at apporiate location
//
// Assumptions:
//   -- customer types will be stored in the apporiate location
//   -- invalid types are ignored
//---------------------------------------------------------------------------
#ifndef CUSTOMERFACTORY_H
#define CUSTOMERFACTORY_H
#include "factory.h"
#include "customerobj.h"
#include "object.h"

class CustomerFactory : public Factory{
	static const int SIZE = 1; //size of factory
public:
	CustomerFactory();
	virtual ~CustomerFactory();
	virtual Object* createIt(char ch);

private:
	Object* objFactory[SIZE];
	int hash(char ch);
};

#endif
