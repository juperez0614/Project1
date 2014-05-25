#ifndef CUSTOMEROBJCONTAINER_H
#define CUSTOMEROBJCONTAINER_H


#include "userobjectcontainer.h"
#include "customerobj.h"

class CustomerObjContainer : public UserObjectContainer {
	friend ostream& operator<<(ostream& output, const CustomerObjContainer& toWrite);

public:
	CustomerObjContainer();
	virtual ~CustomerObjContainer();
	virtual void print(ostream & output);
	//virtual bool search(Object* toFind);
	virtual bool isEmpty() const;

protected:
	virtual void destructorHelper(containerNode* current);
	virtual ostream& outputHelper(ostream& output, const containerNode* toWrite);
};






#endif