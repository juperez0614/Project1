#include "customerobjcontainer.h"

CustomerObjContainer::CustomerObjContainer() : UserObjectContainer(){}



ostream& CustomerObjContainer::outputHelper(ostream& output, const containerNode * toWrite){
	if (toWrite->left != NULL){
		outputHelper(output, toWrite->left);
	}
	const CustomerObj* p = dynamic_cast< const CustomerObj* >(toWrite->data);
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