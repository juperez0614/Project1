#include "return.h"

Return::Return() : CommandAction(){
}

Return::~Return(){
	id = 0;
	format = '\0';
	genre = '\0';
	delete movie;
	movie = NULL;
	delete customer;
	customer = NULL;
}

void Return::performAct(){
	increaseQuantity();
	customer->addToHistory(this);
}

CommandAction* Return::createAction() {
	return new Return();
}

void Return::setData(ifstream&  intake){
	intake >> format >> genre;
}

void Return::display() const{
	cout << "DVD  Return  ";
	movie->actionDisplay();
}