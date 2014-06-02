//---------------------------------------------------------------------------
// MovieObjectContainer.cpp
// Derive class for all object containers, contains movie objects
// Authors: Julio Perez, Jeffrey Asmus
//---------------------------------------------------------------------------
// MovieObjectContainer class:  
//		includes  features:
//   -- find object
//   -- determines if container is empty
//
//---------------------------------------------------------------------------

#include "movieobjectcontainer.h"

MovieObjectContainer::MovieObjectContainer() :ObjectContainer(){
}



MovieObjectContainer::~MovieObjectContainer(){}


bool MovieObjectContainer::search(Object* toFind){
	return true;
}

bool MovieObjectContainer::isEmpty() const{
	if (root == NULL){
		return true;
	}
	else {
		return false;
	}
}
