#include "objectcontroller.h"
#include "objectcontainer.h"
#include "movieobjectcontainer.h"
#include "classicobjcontainer.h"


ObjectController::ObjectController(){

	objController[0] = new ClassicObjContainer;
	//objController[1] = new MovieObjectContainer;
	//objController[3] = new MovieObjectContainer;
}

ObjectController::~ObjectController(){
	for (int i = 0; i < FACTSIZE; i++){
		delete objController[i];
		objController[i] = NULL;
	}
}

bool ObjectController::insertIt(char ch, Object* toInsert){
	int subscript = hash(ch);
	return	objController[subscript]->insert(toInsert);
}

int ObjectController::hash(char ch){
	return ch - 'C';
}

void ObjectController::print(ostream & output){
	objController[0]->print(output);
}