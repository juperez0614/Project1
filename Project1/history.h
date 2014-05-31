#ifndef HISTORY_H
#define HISTORY_H

#include "commandaction.h"

using namespace std;

class History : public CommandAction {
public:
	History();
	virtual ~History();
	virtual void performAct();
	virtual CommandAction* createAction();
	virtual void display() const; 
	virtual void setData(ifstream& intake);

protected:


};


#endif