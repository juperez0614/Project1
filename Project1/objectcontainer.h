#ifndef OBJECTCONTAINER_H
#define OBJECTCONTAINER_H
#include <iostream>
#include <string>
#include "object.h"

using namespace std;

class ObjectContainer {
public:
	ObjectContainer();
	bool insert(Object* toInsert);
	virtual bool search(Object* toFind) = 0;

protected:
	struct containerNode{
		Object* data;
		containerNode* left;
		containerNode* right; 
	};
	containerNode* root;
	bool insert(containerNode* current, Object* toInsert);
};
#endif