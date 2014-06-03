//---------------------------------------------------------------------------
// customerFactory.h
// derived class for factorys, stores customer objects
// Authors: Julio Perez, Jeffrey Asmus
//---------------------------------------------------------------------------
// customerfactor class:  
//		includes  features:
//   -- creates new customer types
//   -- hash objects at apporiate location
//
// Assumptions:
//   -- customer types will be stored in the apporiate location
//   -- invalid types are ignored
//---------------------------------------------------------------------------
#include "customerFactory.h"

//---------------------------------------------------------------------------
//constructor
//creates new customerobj
CustomerFactory::CustomerFactory() :Factory(){
	objFactory[0] = new CustomerObj;
}

//---------------------------------------------------------------------------
//destructor
//deallocates memory from objFactory
CustomerFactory::~CustomerFactory(){
	for (int i = 0; i < SIZE; i++){
		delete objFactory[i];
		objFactory[i] = NULL;
	}
}

//---------------------------------------------------------------------------
//createIt
//create customerobj stored at index subscript
Object* CustomerFactory::createIt(char userCode){
	int subscript = hash(userCode);
	return objFactory[subscript]->create();
}

//---------------------------------------------------------------------------
//determines the location to store customer objects
int CustomerFactory::hash(char userCode){
	return 0;	//this will need to be reconsidered
}
