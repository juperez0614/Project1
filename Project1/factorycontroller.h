#ifndef FACTORYCONTROLLER_H
#define FACTORYCONTROLLER_H

#include "object.h"
#include "factory.h"
#include "moviefactory.h"
#include "userfactory.h"


class FactoryController {
	const static int FACTORIES = 2;
public:
	FactoryController();
	~FactoryController();
	Object* selectFactory(char ch);

private:
	Factory* factArray[FACTORIES];

};

#endif