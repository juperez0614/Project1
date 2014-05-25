#ifndef OBJECTCONTROLLER_H
#define OBJECTCONTROLLER_H
#include "objectcontainer.h"
#include "movieobjectcontainer.h"
#include "userobjectcontainer.h"
#include "classicobjcontainer.h"
#include "comedyobjcontainer.h"
#include "dramaobjcontainer.h"
#include "customerobjcontainer.h"

using namespace std;

class ObjectController{

	static const int FACTSIZE = 7;
public:
	ObjectController();
	~ObjectController();
	bool insertIt(char ch, Object* toInsert);
	void print(ostream & output);

private:
	ObjectContainer* objController[FACTSIZE];
	int hash(char ch);
};

#endif