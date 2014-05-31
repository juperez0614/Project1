#include "commandaction.h"

CommandAction::CommandAction(){
	 id = 0;
	 format ='\0';
	 genre = '\0';
	 movie = NULL;
	 customer = NULL;
}

CommandAction::~CommandAction(){
	id = 0;
	format = '\0';
	genre = '\0';
	delete movie;
	movie = NULL;
	delete customer;
	customer = NULL;

}

bool CommandAction::checkQuantity(){
	if (movie->getQuantity() > 0){
		return true;
	}
	else{
		return false;
	}
}

void CommandAction::increaseQuantity(){
		movie->setQuantity(1); 
}

void CommandAction::decreaseQuantity(){
	if (checkQuantity() == true){
		movie->setQuantity(-1);
	}
}


void CommandAction::customerSet(Object* toAdd){
	UserObject* e = dynamic_cast< UserObject*> (toAdd);
	CustomerObj* p = dynamic_cast< CustomerObj* >(e);
	customer = p;
}


void CommandAction::movieSet(Object* toAdd){
	MovieObject* e = dynamic_cast< MovieObject*> (toAdd);
	movie = e;
}


char CommandAction::getCode() const{
	return genre;
}
