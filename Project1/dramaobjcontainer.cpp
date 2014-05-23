#include "dramaobjcontainer.h"


DramaObjContainer::DramaObjContainer() : MovieObjectContainer(){}


ostream& DramaObjContainer::outputHelper(ostream& output, const containerNode * toWrite){
	if (toWrite->left != NULL){
		outputHelper(output, toWrite->left);
	}
	const DramaObj* p = dynamic_cast< const DramaObj* >(toWrite->data);
	output << *p << endl;
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