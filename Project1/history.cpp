#include "history.h"

class CustomerObj;

History::History() : CommandAction(){
}

History::~History(){
	id = 0;
	format = '\0';
	genre = '\0';
	delete movie;
	movie = NULL;
	delete customer;
	customer = NULL;
}

void History::performAct(){
	display(); 
}

CommandAction* History::createAction() {
	return new History();
}

void History::display() const{
	customer->displayHistory();
}

void History::setData(ifstream&  intake){
	intake >> actionCode >> id;
}

bool History::checkComplete()const{
	if (customer != NULL){
		return true;
	}
	else{
		return false;
	}
}