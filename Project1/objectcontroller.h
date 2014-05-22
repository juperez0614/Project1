#ifndef OBJECTCONTROLLER_H
#define OBJECTCONTROLLER_H
#include "objectcontainer.h"

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