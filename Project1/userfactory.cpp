//---------------------------------------------------------------------------
// userFactory.h
// derived class for factorys, stores user objects
// Authors: Julio Perez, Jeffrey Asmus
//---------------------------------------------------------------------------
// userObject class:  
//		includes  features:
//   -- creates new user types
//   -- hash objects at apporiate location
//
// Assumptions:
//   -- Genre types will be stored in the apporiate location
//   -- invalid types are ignored
//---------------------------------------------------------------------------
#include "userfactory.h"

//---------------------------------------------------------------------------
//constructor
//create new customer obj 
UserFactory::UserFactory() :Factory(){
	objFactory[0] = new CustomerObj();
}

//---------------------------------------------------------------------------
//destructor
//deallocate memory from objfactory
UserFactory::~UserFactory(){
	for (int i = 0; i < SIZE; i++){
		if (objFactory[i] != NULL){
			delete objFactory[i];
			objFactory[i] = NULL;
		}
	}
}

//---------------------------------------------------------------------------
//createIt
//create new user obj at subscipt index
Object* UserFactory::createIt(char userCode){
	int subscript = hash(userCode);
	return objFactory[subscript]->create();
}

//---------------------------------------------------------------------------
//hash
//determine the index to store user obj
int UserFactory::hash(char userCode){
		return 0; 
}
