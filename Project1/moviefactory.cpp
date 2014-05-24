#include "moviefactory.h"



MovieFactory::MovieFactory() :Factory(){
	objFactory[0] = new ClassicObj; 
	objFactory[1] = new DramaObj;
	objFactory[3] = new ComedyObj;
}

MovieFactory::~MovieFactory(){
	for (int i = 0; i < SIZE; i++){
		delete objFactory[i];
		objFactory[i] = NULL;
	}
}

Object* MovieFactory::createIt(char movieCode){
	int subscript = hash(movieCode);
	return objFactory[subscript]->create();
}

int MovieFactory::hash(char movieCode){
	return movieCode - 'C';
}