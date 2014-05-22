/*
This is a binary search tree that contains all the movies in a particular
genre. Each tree is sorted by the MovieObject's definition of < and ==.
*/
#ifndef MOVIEOBJECTCONTAINER_H
#define MOVIEOBJECTCONTAINER_H
#include "objectcontainer.h"
#include "movieobject.h"
#include "classicobj.h"
#include "comedyobj.h"
#include "dramaobj.h"


class MovieObjectContainer : public ObjectContainer{
public:
	MovieObjectContainer();
	//MovieObjectContainer(const MovieObjectContainer& current);
	virtual void print(ostream & output) = 0;
	virtual ~MovieObjectContainer();
	bool search(Object* toFind);

protected:
	ObjectContainer::containerNode* copyHelper(const containerNode* current);

};

#endif