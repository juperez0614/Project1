#include "userobjectcontainer.h"

UserObjectContainer::UserObjectContainer() :ObjectContainer(){}



UserObjectContainer::~UserObjectContainer(){}


bool UserObjectContainer::search(Object * toFind){
	return true;
}

bool UserObjectContainer::isEmpty() const{
	if (root == NULL){
		return true;
	}
	else {
		return false;
	}
}