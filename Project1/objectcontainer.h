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
	bool insert(Object* toInsert);
	virtual bool search(Object* toFind) = 0;
	bool isEmpty() const; 
	virtual void print(ostream & output) = 0;

protected:
	 struct containerNode{
			Object* data;
			containerNode* left;
			containerNode* right; 
		};	

	containerNode* root;
	containerNode* insertHelper(containerNode* current, containerNode* toInsert);
	void destructorHelper(containerNode* current);
	ostream& outputHelper(ostream& output, containerNode* toWrite);
	containerNode* copyHelper(const containerNode* current);
};
#endif