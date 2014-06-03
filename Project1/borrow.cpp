//---------------------------------------------------------------------------
// Borrow.cpp
// Derive class for all command actions, performs borrow action
// Authors: Julio Perez, Jeffrey Asmus
//---------------------------------------------------------------------------
// Borrow class:  
//		includes  features:
//   -- sets data
//   -- creates borrow object
//   -- performs borrow action
//   -- displays action
//
// Assumptions:
//   --movie, customer exist and has a quantity > 0
//---------------------------------------------------------------------------
#include "borrow.h"

//---------------------------------------------------------------------------
//constructor
//initalizes command action
Borrow::Borrow() : CommandAction(){
}

//---------------------------------------------------------------------------
//destructor
//sets all attributes to 0, empty, or null
Borrow::~Borrow(){
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
//performs borrow; decreases quantity and adds it to customer's history 
void Borrow::performAct(){
	decreaseQuantity();
	customer->addToHistory(this);
}

//---------------------------------------------------------------------------
//createAction
//creates new borrow object
CommandAction* Borrow::createAction() {
	return new Borrow(); 
}

//---------------------------------------------------------------------------
//displays borrow action to screen
void Borrow::display() const {
	cout << "DVD  Borrow  ";
	movie->actionDisplay();
}

//---------------------------------------------------------------------------
//setData
//sets format and genre from an input file
void Borrow::setData(ifstream&  intake){
	intake >> format >> genre;

}
