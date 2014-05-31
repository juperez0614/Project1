#include "moviefactory.h"



MovieFactory::MovieFactory() :Factory(){
	objFactory[0] = new ClassicObj(); 
	objFactory[1] = new DramaObj();
	objFactory[2] = NULL;
	objFactory[3] = new ComedyObj();
	objFactory[4] = NULL;
}

MovieFactory::~MovieFactory(){
	for (int i = 0; i < SIZE; i++){
		if (objFactory[i] != NULL){
			delete objFactory[i];
			objFactory[i] = NULL;
		}
	}
}

Object* MovieFactory::createIt(char movieCode){
	int subscript = hash(movieCode);
	return objFactory[subscript]->create();
}

int MovieFactory::hash(char movieCode){
	return movieCode - 'C';
}