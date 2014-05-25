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
	virtual ~MovieObjectContainer();
	virtual void print(ostream & output)= 0;
	virtual bool search(Object* toFind);
	virtual bool isEmpty() const;


protected:
	virtual void destructorHelper(containerNode* current) = 0;
	virtual ostream& outputHelper(ostream& output, const containerNode* toWrite) = 0;
};

#endif