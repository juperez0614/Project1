#include "objectcontainer.h"

ObjectContainer::ObjectContainer(){
	root = NULL; 
}

bool ObjectContainer::insert( Object* toInsert){
	containerNode* current = root; 
	return insert(current, toInsert);
}

bool ObjectContainer::insert(containerNode* current, Object* toInsert){
	if (current == NULL){
		containerNode * toAdd = new containerNode;
		*toAdd->data = *toInsert;
		toAdd->left = NULL;
		toAdd->right = NULL;
		current = toAdd;
		return true; 
	}
	else {
		if (*current->data < *toInsert){
			return insert(current->right, toInsert);
		}
		else if (*current->data == *toInsert){
			return false;
		}
		else{
			return insert(current->left, toInsert);
		}
	}

}
