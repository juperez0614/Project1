#include "customerFactory.h"

CustomerFactory::CustomerFactory() :Factory(){
	objFactory[0] = new CustomerObj;
}

CustomerFactory::~CustomerFactory(){
	for (int i = 0; i < SIZE; i++){
		delete objFactory[i];
		objFactory[i] = NULL;
	}
}

Object* CustomerFactory::createIt(char userCode){
	int subscript = hash(userCode);
	return objFactory[subscript]->create();
}

int CustomerFactory::hash(char userCode){
	return 0;	//this will need to be reconsidered
}