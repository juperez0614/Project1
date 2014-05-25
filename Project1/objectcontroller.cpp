#include "objectcontroller.h"




ObjectController::ObjectController(){

	objController[0] = new ClassicObjContainer();
	objController[1] = new DramaObjContainer();
	objController[3] = new ComedyObjContainer();
	objController[4] = new CustomerObjContainer();
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
	if (ch < 'C'){		//TODO: Fix this SWITCH
		return 4;
	}
	else {
		return ch - 'C';
	}
}

void ObjectController::print(ostream & output){
	for (int i = 0; i < FACTSIZE; i++){
		if (objController[i] != NULL){
			objController[i]->print(output);
		}
	}
}