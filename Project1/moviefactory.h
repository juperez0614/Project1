#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H

#include "factory.h"
#include "classicobj.h"
#include "comedyobj.h"
#include "dramaobj.h"

class MovieFactory : public Factory{
	static const int SIZE = 5;
public:
	MovieFactory();
	virtual ~MovieFactory();
	virtual Object* createIt(char ch);

private:
	Object* objFactory[SIZE];
	int hash(char ch);

};

#endif