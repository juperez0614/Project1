#ifndef OBJECTCONTAINER_H
#define OBJECTCONTAINER_H
#include <iostream>
#include <string>
#include "object.h"

using namespace std;

class ObjectContainer {
	friend ostream& operator<<(ostream& output, const ObjectContainer& toWrite);
public:
	ObjectContainer();
	//ObjectContainer(const ObjectContainer& current);
	virtual ~ObjectContainer();
	virtual bool insert(Object* toInsert);
	virtual bool search(Object* toFind) = 0;
	virtual bool isEmpty() const; 
	virtual void print(ostream & output) = 0;

protected:
	 struct containerNode{
			Object* data;
			containerNode* left;
			containerNode* right; 
		};	

	containerNode* root;
	containerNode* insertHelper(containerNode* current, containerNode* toInsert);
	virtual void destructorHelper(containerNode* current);
	virtual ostream& outputHelper(ostream& output, const containerNode* toWrite) = 0;
};
#endif