#include "factorycontroller.h"

FactoryController::FactoryController(){
	factArray[0] = new MovieFactory();
	factArray[1] = new UserFactory();
}

FactoryController::~FactoryController(){
	for (int i = 0; i < FACTORIES; i++){
		delete factArray[i];
		factArray[i] = NULL;
	}
 }

Object* FactoryController::selectFactory(char objCode){
	if (objCode >= 65 && objCode <= 90){	//can't include z 
		 return factArray[0]->createIt(objCode);
	}
	else{
		return factArray[1]->createIt(objCode);
	}
	//here is where we should check for invalid codes 

}