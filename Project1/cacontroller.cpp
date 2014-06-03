//---------------------------------------------------------------------------
// cacontoller.h
// Derive class for all command actions, controls actions
// Authors: Julio Perez, Jeffrey Asmus
//---------------------------------------------------------------------------
// Borrow class:  
//		includes  features:
//   -- selects action
//   -- hashs it to apporiate location
//
//---------------------------------------------------------------------------
#include "cacontroller.h"

//---------------------------------------------------------------------------
//constructor
//creates actions at location in action array
CAController::CAController(){
	actionArray[0] = new Borrow();
	actionArray[1] = new Return();
	actionArray[2] = new History();
}

//---------------------------------------------------------------------------
//destructor
//deallocates memory from actionarray
CAController::~CAController(){
	for (int i = 0; i < CASIZE; i++){
		if (actionArray[i] != NULL){
			delete actionArray[i];
			actionArray[i] = NULL;
		}
	}
}

//---------------------------------------------------------------------------
//hash
//determines where to put action in actionarray
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
		return -1; //mitigates bad input give outside limits value
	}

}

//---------------------------------------------------------------------------
//selectAction
//creations action to store at index supscript
CommandAction* CAController::selectAction(char code){
	int subscript = hash(code);
	//if (subscript < 0 || subscript > 2){
	// error mitigation attempt!!!!
	//}
	return actionArray[subscript]->createAction();
}


