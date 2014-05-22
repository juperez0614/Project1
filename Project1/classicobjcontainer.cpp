#include "classicobjcontainer.h"


ClassicObjContainer::ClassicObjContainer() : MovieObjectContainer(){}

//ClassicObjContainer::ClassicObjContainer(const ClassicObjContainer& current){
//	if (current.isEmpty()){
//		root = NULL;
//		return;
//	}
//	root = copyHelper(current.root);
//}
//
//ObjectContainer::containerNode* MovieObjectContainer::copyHelper(const containerNode* current){
//	containerNode* copy = NULL;
//	if (current != NULL){
//		copy = new containerNode;
//		copy->data = new ClassicObj();	//not sure if this will work
//		*copy->data = *current->data;
//		copy->left = copyHelper(current->left);
//		copy->right = copyHelper(current->right);
//	}
//	return copy;
//
//}

ostream& ClassicObjContainer::outputHelper(ostream& output, containerNode * toWrite){
	if (toWrite->left != NULL){
		outputHelper(output, toWrite->left);
	}
	const ClassicObj* p = dynamic_cast< const ClassicObj* >(toWrite->data);
	output << *p << endl; 
	if (toWrite->right != NULL){
		outputHelper(output, toWrite->right);
	}
	return output; 

}


ostream& operator<<(ostream& output, const ClassicObjContainer& toWrite){
	output << "*IN*" << "\t" << "*OUT*" << endl;
	output << "DVD" << "\t" << "DVD" << "\t" << "TITLE" << "\t" << "DIRECTOR" 
			<< "\t" << "YEAR" << "\t" << "MO" << "\t" << "ACTOR" << endl;
	ObjectContainer::containerNode *p = toWrite.root;
	ClassicObjContainer temp(toWrite);
	temp.outputHelper(output, temp.root);
	return output;
}


void ClassicObjContainer::print(ostream & output){
	outputHelper(output, root);
}