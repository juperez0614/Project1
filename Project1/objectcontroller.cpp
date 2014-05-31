#include "objectcontroller.h"


const string ObjectController::NORMAL = "DVD\tDVD\tTITLE\t\tDIRECTOR\tYEAR";
const string ObjectController::CLASSIC = "DVD\tDVD\tTITLE\t\tDIRECTOR\tYEAR\tMONTH\tACTOR";
const string ObjectController::CUSTOMER = "ID\tLAST NAME\tFIRST NAME";

ObjectController::ObjectController(){
	
	objController[0] = new ObjectContainer(); //classic
	objController[0]->setOverhead(CLASSIC);
	objController[1] = new ObjectContainer(); // drama
	objController[1]->setOverhead(NORMAL);
	objController[2] = NULL;
	objController[3] = new ObjectContainer(); // comedy
	objController[3]->setOverhead(NORMAL);
	objController[4] = new ObjectContainer(); // customer
	objController[4]->setOverhead(CUSTOMER);
	objController[5] = NULL;
	objController[6] = NULL;
}

ObjectController::~ObjectController(){
	for (int i = 0; i < OBJCONTROLSIZE; i++){
		if (objController[i] != NULL){
			delete objController[i];
			objController[i] = NULL;
		}
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

void ObjectController::print(){

	for (int i = 0; i < OBJCONTROLSIZE; i++){
		if (objController[i] != NULL){
			objController[i]->print();
		}
	}
}


Object* ObjectController::find(char objCode, Object* target) {
	int subscript = hash(objCode);
	return objController[subscript]->find(target);
}