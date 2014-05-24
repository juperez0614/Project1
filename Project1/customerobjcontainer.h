#ifndef CUSTOMEROBJCONTAINER_H
#define CUSTOMEROBJCONTAINER_H


#include "userobjectcontainer.h"
#include "customerobj.h"

class CustomerObjContainer : public UserObjectContainer {
	friend ostream& operator<<(ostream& output, const CustomerObjContainer& toWrite);

public:
	CustomerObjContainer();
	virtual void print(ostream & output);

protected:
	ostream& outputHelper(ostream& output, const containerNode* toWrite);
};






#endif