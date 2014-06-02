//---------------------------------------------------------------------------
// Borrow.h
// Derive class for all command actions, performs borrow action
// Authors: Julio Perez, Jeffrey Asmus
//---------------------------------------------------------------------------
// Borrow class:  
//		includes  features:
//   -- sets data
//   -- performs borrow action
//   -- displays action
//
// Assumptions:
//   --movie, customer exist and has a quantity > 0
//---------------------------------------------------------------------------
#ifndef BORROW_H
#define BORROW_H

#include "commandaction.h"

using namespace std;

class Borrow : public CommandAction {
public:
	Borrow();
	virtual ~Borrow();
	virtual void performAct();
	virtual CommandAction* createAction();
	virtual void display() const; 
	virtual void setData(ifstream& intake);


protected:


};


#endif
