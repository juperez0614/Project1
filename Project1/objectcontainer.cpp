#include "objectcontainer.h"

ObjectContainer::ObjectContainer(){
	root = NULL; 
}


bool ObjectContainer::insert( Object* toInsert){
	if (toInsert == NULL){
		return false;
	}
	containerNode * insertNode = new containerNode;
	insertNode->data = toInsert;
	insertNode->left = NULL;
	insertNode->right = NULL;
	containerNode * duplicate = insertHelper(root, insertNode);
	if (duplicate != NULL){
		root = duplicate;
		return true;
	}
	else {
		return false;
	}
}

ObjectContainer::containerNode* ObjectContainer::insertHelper(containerNode* current, containerNode* toInsert) {
	if (current == NULL){
		return toInsert;
	} 
	else {
		if (*current->data == *toInsert->data){
			delete toInsert;
			return NULL;
		}
		else if (*current->data < *toInsert->data){
			containerNode * duplicate = insertHelper(current->right, toInsert);
			if (duplicate != NULL){
				current->right = duplicate;
			}
			else {
				return NULL;
			}
		}
		else {
			containerNode * duplicate = insertHelper(current->left, toInsert);
			if (duplicate != NULL){
				current->left = duplicate;
			}
			else {
				return NULL;
			}
		}
	}
	return current;
}

ObjectContainer::~ObjectContainer(){
	/*destructorHelper(root);
	root = NULL;*/
}

void ObjectContainer::destructorHelper(containerNode * current){
	//if (current != NULL){
	//	destructorHelper(current->left);
	//	destructorHelper(current->right);
	//	delete current->data;
	//	current->data = NULL;
	//	delete current;
	//	current = NULL;
	//}
}

bool ObjectContainer::isEmpty()const{
	return (root == NULL);
}
