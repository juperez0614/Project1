#ifndef OBJECTCONTAINER_H
#define OBJECTCONTAINER_H
#include <iostream>
#include <string>
#include "object.h"

using namespace std;

class ObjectContainer {
public:
	ObjectContainer();
	//ObjectContainer(const ObjectContainer& current);
	virtual ~ObjectContainer();
	virtual bool insert(Object* toInsert);
	virtual Object* find(Object* target);
	virtual bool isEmpty() const; 
	virtual void print();
	void setOverhead(string setTo);

protected:
	string inOutHeading;
	string heading; 
	 struct containerNode{
			Object* data;
			containerNode* left;
			containerNode* right; 
		};	

	containerNode* root;
	containerNode* insertHelper(containerNode* current, containerNode* toInsert);
	virtual void destructorHelper(containerNode* current);
	virtual void print(const containerNode* toWrite);
	Object* find(containerNode* toCheck, Object* target);
};
#endif