//---------------------------------------------------------------------------
// userFactory.h
// derived class for factorys, stores user objects
// Authors: Julio Perez, Jeffrey Asmus
//---------------------------------------------------------------------------
// userObject class:  
//		includes  features:
//   -- creates new user types
//   -- hash objects at apporiate location
//
// Assumptions:
//   -- Genre types will be stored in the apporiate location
//   -- invalid types are ignored
//---------------------------------------------------------------------------
#ifndef USERFACTORY_H
#define USERFACTORY_H

#include "factory.h"
#include "customerobj.h"

class UserFactory : public Factory{
	static const int SIZE = 1;
public:
	UserFactory();
	virtual ~UserFactory();
	virtual Object* createIt(char ch);

private:
	Object* objFactory[SIZE];
	int hash(char ch);
};
#endif
