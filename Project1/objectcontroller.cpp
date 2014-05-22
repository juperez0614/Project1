#include "objectcontroller.h"
#include "objectcontainer.h"
#include "movieobjectcontainer.h"


ObjectController::ObjectController(){

	objController[0] = new MovieObjectContainer;
	objController[1] = new MovieObjectContainer;
	objController[3] = new MovieObjectContainer;
}

ObjectController::~ObjectController(){
	delete[] objController;
}

bool ObjectController::insertIt(char ch, Object* toInsert){
	int subscript = hash(ch);
	return	objController[subscript]->insert(toInsert);
}

int ObjectController::hash(char ch){
	return ch - 'C';
}