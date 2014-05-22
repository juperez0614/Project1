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
	
	bool search(Object* toFind);

protected:


};

#endif