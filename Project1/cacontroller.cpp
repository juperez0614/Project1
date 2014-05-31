#include "cacontroller.h"

CAController::CAController(){
	actionArray[0] = new Borrow();
	actionArray[1] = new Return();
	actionArray[2] = new History();
}

CAController::~CAController(){
	for (int i = 0; i < CASIZE; i++){
		if (actionArray[i] != NULL){
			delete actionArray[i];
			actionArray[i] = NULL;
		}
	}
}

int CAController::hash(char code){
	if (code == 'B'){
		return 0;
	}
	else if (code == 'R'){
		return 1;
	}
	else if (code == 'H'){
		return 2;
	}
	else {
		return -1;
	}
//use to mitigate bad input give outside limits value
}

CommandAction* CAController::selectAction(char code){
	int subscript = hash(code);
	//if (subscript < 0 || subscript > 2){
	// error mitigation attempt!!!!
	//}
	return actionArray[subscript]->createAction();
}


