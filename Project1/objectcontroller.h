#ifndef OBJECTCONTROLLER_H
#define OBJECTCONTROLLER_H
#include "objectcontainer.h"

using namespace std;

class ObjectController{
	static const int OBJCONTROLSIZE = 7;
	static const string NORMAL;
	static const string CLASSIC;
	static const string CUSTOMER;

public:
	ObjectController();
	~ObjectController();
	bool insertIt(char ch, Object* toInsert);
	void print();

private:
	ObjectContainer* objController [OBJCONTROLSIZE];
	int hash(char ch);

};

#endif