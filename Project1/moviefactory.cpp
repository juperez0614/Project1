//---------------------------------------------------------------------------
// MovieFactory.cpp
// derived class for factorys, stores movie objects
// Authors: Julio Perez, Jeffrey Asmus
//---------------------------------------------------------------------------
// MovieObject class:  
//		includes  features:
//   -- creates new genre types
//   -- hash objects at apporiate location
//
// Assumptions:
//   -- Genre types will be stored in the apporiate location
//   -- invalid types are ignored
//---------------------------------------------------------------------------
#include "moviefactory.h"


//---------------------------------------------------------------------------
//constructor
//creates new movie obj containers at apporiate indexes
MovieFactory::MovieFactory() :Factory(){
	objFactory[0] = new ClassicObj(); 
	objFactory[1] = new DramaObj();
	objFactory[2] = NULL;
	objFactory[3] = new ComedyObj();
	objFactory[4] = NULL;
}

//---------------------------------------------------------------------------
//destructor
//deallocates memory created from objFactory
MovieFactory::~MovieFactory(){
	for (int i = 0; i < SIZE; i++){
		if (objFactory[i] != NULL){
			delete objFactory[i];
			objFactory[i] = NULL;
		}
	}
}

//---------------------------------------------------------------------------
//createit
//creates a new movie object and stores it at correct index
Object* MovieFactory::createIt(char movieCode){
	int subscript = hash(movieCode);
	if (subscript != 0 && subscript != 1 && subscript != 3) {
		return NULL;
	}
	return objFactory[subscript]->create();
}

//---------------------------------------------------------------------------
//hash
//uses moviecode to determine where to store object in objFactory
int MovieFactory::hash(char movieCode){
	return movieCode - 'C';
}
