#include "userfactory.h"

UserFactory::UserFactory() :Factory(){
	objFactory[0] = new CustomerObj; 

}

UserFactory::~UserFactory(){
	for (int i = 0; i < SIZE; i++){
		delete objFactory[i];
		objFactory[i] = NULL;
	}
}

Object* UserFactory::createIt(char userCode){
	int subscript = hash(userCode);
	return objFactory[subscript]->create();

}

int UserFactory::hash(char userCode){
		return 0; 
}