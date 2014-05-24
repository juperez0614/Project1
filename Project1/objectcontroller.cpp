#include "objectcontroller.h"
#include "classicobjcontainer.h"
#include "dramaobjcontainer.h"
#include "comedyobjcontainer.h"
#include "customerobjcontainer.h"



ObjectController::ObjectController(){

	objController[0] = new ClassicObjContainer;
	objController[1] = new DramaObjContainer;
	objController[3] = new ComedyObjContainer;
	objController[4] = new CustomerObjContainer;
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
	objController[0]->print(output);
	objController[1]->print(output);
	objController[3]->print(output);
	objController[4]->print(output);
}