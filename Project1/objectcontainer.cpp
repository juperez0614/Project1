#include "objectcontainer.h"


ObjectContainer::ObjectContainer(){
	root = NULL; 
	inOutHeading = "*IN* *OUT*";
	heading = "";
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
	destructorHelper(root);
}

void ObjectContainer::destructorHelper(containerNode * current){
	if (current == NULL){
		return;
	}
	else{
		if (current->left != NULL){
			destructorHelper(current->left);
		}
		if (current->right != NULL){
			destructorHelper(current->right);
		}
	}
	delete current -> data;
	delete current;
	current = NULL;
}

bool ObjectContainer::isEmpty()const{
	return (root == NULL);
}

void ObjectContainer::print(){
	cout << inOutHeading << endl;
	cout << heading << endl;
	print(root);
}

void ObjectContainer::print(const containerNode* toWrite){
	if (toWrite == NULL){
		cout << "";
	}
	if (toWrite->left != NULL){
		print( toWrite->left);
	}
	toWrite->data->display();
	if (toWrite->right != NULL){
		print(toWrite->right);
	}
}

void ObjectContainer::setOverhead(string setTo){
	heading = setTo;
}



Object* ObjectContainer::find(Object * target){
	return find(root, target);
}

Object* ObjectContainer::find(containerNode* current, Object* target){
	if (current == NULL){
		return NULL;
	}
	while (current != NULL){
		if (current->data->equals(target) == true){
			delete target;			// mem management getting ready to return current to same place
			return current->data;
		}
		else if (*current->data < *target){
			current = current->right;
		}
		else {
			current = current->left;
		}
	}
	return NULL; // account for all possibilities
}