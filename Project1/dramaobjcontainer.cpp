#include "dramaobjcontainer.h"


DramaObjContainer::DramaObjContainer() : MovieObjectContainer(){
}


DramaObjContainer::~DramaObjContainer(){
	destructorHelper(root);
	root = NULL;
}

void DramaObjContainer::destructorHelper(containerNode * current){
	if (current != NULL){
		destructorHelper(current->left);
		destructorHelper(current->right);
		const MovieObject* e = dynamic_cast<const MovieObject*>(current->data);
		const DramaObj* p = dynamic_cast<const DramaObj*>(e);
		current->data = NULL;
		delete current;
		current = NULL;
	}
}

bool DramaObjContainer::isEmpty()const{
	return (root == NULL);
}

ostream& DramaObjContainer::outputHelper(ostream& output, const containerNode * toWrite){
	if (toWrite == NULL){
		return output;
	}
	if (toWrite->left != NULL){
		outputHelper(output, toWrite->left);
	}
	const MovieObject* e = dynamic_cast<const MovieObject*>(toWrite->data);
	const DramaObj* p = dynamic_cast<const DramaObj*>(e);
	p->display();
	if (toWrite->right != NULL){
		outputHelper(output, toWrite->right);
	}
	return output;

}



void DramaObjContainer::print(ostream & output){
	output << "*IN*" << " " << "*OUT*" << endl;
	output << "DVD" << " " << "DVD" << "\t" << "TITLE" << "\t" << "DIRECTOR"
		<< "\t" << "YEAR" << endl;
	outputHelper(output, root);
}