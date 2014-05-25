/*
This is a binary search tree that contains all the customers. the tree is 
sorted by the UserObject's definition of < and ==.
*/
#ifndef USEROBJECTCONTAINER_H
#define USEROBJECTCONTAINER_H
#include "objectcontainer.h"
#include "userobject.h"
#include "object.h"




class UserObjectContainer : public ObjectContainer{
public:
	UserObjectContainer();
	virtual ~UserObjectContainer();
	virtual void print(ostream & output) = 0;
	virtual bool search(Object* toFind);
	virtual bool isEmpty() const;


protected:
	virtual void destructorHelper(containerNode* current) = 0;
	virtual ostream& outputHelper(ostream& output, const containerNode* toWrite) = 0;

};

#endif