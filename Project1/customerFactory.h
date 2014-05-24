#ifndef CUSTOMERFACTORY_H
#define CUSTOMERFACTORY_H
#include "factory.h"
#include "customerobj.h"
#include "object.h"

class CustomerFactory : public Factory{
	static const int SIZE = 1;
public:
	CustomerFactory();
	virtual ~CustomerFactory();
	virtual Object* createIt(char ch);

private:
	Object* objFactory[SIZE];
	int hash(char ch);
};

#endif