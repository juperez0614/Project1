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