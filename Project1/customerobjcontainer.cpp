#include "customerobjcontainer.h"

CustomerObjContainer::CustomerObjContainer() : UserObjectContainer(){
	root = NULL;
}

CustomerObjContainer::~CustomerObjContainer(){
	destructorHelper(root);
	root = NULL;
}

void CustomerObjContainer::destructorHelper(containerNode * current){
	if (current != NULL){
		destructorHelper(current->left);
		destructorHelper(current->right);
		const UserObject* e = dynamic_cast<const UserObject*>(current->data);
		const CustomerObj* p = dynamic_cast<const CustomerObj*>(e);
		current->data = NULL;
		delete current;
		current = NULL;
	}
}

bool CustomerObjContainer::isEmpty()const{
	return (root == NULL);
}

ostream& CustomerObjContainer::outputHelper(ostream& output, const containerNode * toWrite){
	if (toWrite->left != NULL){
		outputHelper(output, toWrite->left);
	}
	const UserObject* e = dynamic_cast<const UserObject*>(toWrite->data);
	const CustomerObj* p = dynamic_cast<const CustomerObj*>(e);
	output << *p << endl;
	if (toWrite->right != NULL){
		outputHelper(output, toWrite->right);
	}
	return output;

}



void CustomerObjContainer::print(ostream & output){
	output << "ID" << "\t" << "Last Name" << "\t" << "First Name" << endl;
	outputHelper(output, root);
}