#include "classicobjcontainer.h"


ClassicObjContainer::ClassicObjContainer() : MovieObjectContainer(){}


ostream& ClassicObjContainer::outputHelper(ostream& output,const containerNode * toWrite){
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



void ClassicObjContainer::print(ostream & output){
	output << "*IN*" << " " << "*OUT*" << endl;
	output << "DVD" << " " << "DVD" << "\t" << "TITLE" << "\t" << "DIRECTOR"
		<< "\t" << "YEAR" << "\t" << "MO" << "\t" << "ACTOR" << endl;
	outputHelper(output, root);
}