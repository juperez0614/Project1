//---------------------------------------------------------------------------
// history.h
// Derive class for all command actions, performs history action
// Authors: Julio Perez, Jeffrey Asmus
//---------------------------------------------------------------------------
// history class:  
//		includes  features:
//   -- sets data
//   -- performs history action
//   -- displays action
//   --checks if complete
//
// Assumptions:
//   --movie, customer exist 
//---------------------------------------------------------------------------
#include "history.h"

class CustomerObj;

//---------------------------------------------------------------------------
//constructor
//initalizes command action
History::History() : CommandAction(){
}

//---------------------------------------------------------------------------
//destructor
//sets attributes to 0 or empty, deallocates memory
History::~History(){
	id = 0;
	format = '\0';
	genre = '\0';
	delete movie;
	movie = NULL;
	delete customer;
	customer = NULL;
}

//---------------------------------------------------------------------------
//performAct
//call display function
void History::performAct(){
	display(); 
}

//---------------------------------------------------------------------------
//createAction
//create new History action
CommandAction* History::createAction() {
	return new History();
}

//---------------------------------------------------------------------------
//display
//display a customer's history list
void History::display() const{
	customer->displayHistory();
}

//---------------------------------------------------------------------------
//setData
//set actionCode and customer id
void History::setData(ifstream&  intake){
	intake >> actionCode >> id;
}

//---------------------------------------------------------------------------
//determine if customer obj exists
bool History::checkComplete()const{
	if (customer != NULL){
		return true;
	}
	else{
		return false;
	}
}
