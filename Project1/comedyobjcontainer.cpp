#include "comedyobjcontainer.h"


ComedyObjContainer::ComedyObjContainer() : MovieObjectContainer(){
}

ComedyObjContainer::~ComedyObjContainer(){
	destructorHelper(root);
	root = NULL;
}

void ComedyObjContainer::destructorHelper(containerNode * current){
	if (current != NULL){
		destructorHelper(current->left);
		destructorHelper(current->right);
		const MovieObject* e = dynamic_cast<const MovieObject*>(current->data);
		const ComedyObj* p = dynamic_cast< const ComedyObj* >(e);
		current->data = NULL;
		delete current;
		current = NULL;
	}
}

bool ComedyObjContainer::isEmpty()const{
	return (root == NULL);
}

ostream& ComedyObjContainer::outputHelper(ostream& output, const containerNode * toWrite){
	if (toWrite->left != NULL){
		outputHelper(output, toWrite->left);
	}
	const MovieObject* e = dynamic_cast<const MovieObject*>(toWrite->data);
	const ComedyObj* p = dynamic_cast< const ComedyObj* >(e);
	p->display();
	if (toWrite->right != NULL){
		outputHelper(output, toWrite->right);
	}
	return output;

}



void ComedyObjContainer::print(ostream & output){
	output << "*IN*" << " " << "*OUT*" << endl;
	output << "DVD" << " " << "DVD" << "\t" << "TITLE" << "\t" << "DIRECTOR"
		<< "\t" << "YEAR" << endl;
	outputHelper(output, root);
}
