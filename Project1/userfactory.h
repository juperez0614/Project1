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