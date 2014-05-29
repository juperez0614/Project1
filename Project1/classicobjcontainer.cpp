#include "classicobjcontainer.h"


ClassicObjContainer::ClassicObjContainer() : MovieObjectContainer(){
}

ClassicObjContainer::~ClassicObjContainer(){
	destructorHelper(root);
	root = NULL;
}

void ClassicObjContainer::destructorHelper(containerNode * current){
	if (current != NULL){
		destructorHelper(current->left);
		destructorHelper(current->right);
		const MovieObject* e = dynamic_cast<const MovieObject*> (current->data);
		const ClassicObj* p = dynamic_cast< const ClassicObj* >(e);
		current->data = NULL;
		delete current;
		current = NULL;
	}
}

bool ClassicObjContainer::isEmpty()const{
	return (root == NULL);
}

ostream& ClassicObjContainer::outputHelper(ostream& output,const containerNode * toWrite){
	if (toWrite == NULL){
		return output;
	}
	if (toWrite->left != NULL){
		outputHelper(output, toWrite->left);
	}
	const MovieObject* e = dynamic_cast<const MovieObject*> (toWrite->data);
	const ClassicObj* p = dynamic_cast< const ClassicObj* >(e);
	p->display();
	if (toWrite->right != NULL){
		outputHelper(output, toWrite->right);
	}
	return output; 

}



void ClassicObjContainer::print(ostream & output){
	output << "*IN*" << " " << "*OUT*" << endl;
	output << "DVD" << " " << "DVD" << "\t" << "TITLE" << "\t" << "DIRECTOR"
		<< "\t" << "YEAR" << "\t" << "MO" << "\t" << "ACTOR" << endl;
	outputHelper(output, root);
}