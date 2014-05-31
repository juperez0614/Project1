#include "borrow.h"

Borrow::Borrow() : CommandAction(){
}

Borrow::~Borrow(){
	id = 0;
	format = '\0';
	genre = '\0';
	delete movie;
	movie = NULL;
	delete customer;
	customer = NULL;
}

void Borrow::performAct(){
	decreaseQuantity();
	customer->addToHistory(this);
}

CommandAction* Borrow::createAction() {
	return new Borrow(); 
}

void Borrow::display() const {
	cout << "DVD  Borrow  ";
	movie->actionDisplay();
}

void Borrow::setData(ifstream&  intake){
	intake >> format >> genre;

}