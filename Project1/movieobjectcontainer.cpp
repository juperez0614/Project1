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