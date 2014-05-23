#include "comedyobjcontainer.h"


ComedyObjContainer::ComedyObjContainer() : MovieObjectContainer(){}


ostream& ComedyObjContainer::outputHelper(ostream& output, const containerNode * toWrite){
	if (toWrite->left != NULL){
		outputHelper(output, toWrite->left);
	}
	const ComedyObj* p = dynamic_cast<const ComedyObj*>(toWrite->data);
	output << *p << endl;
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
