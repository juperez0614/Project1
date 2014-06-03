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
	virtual bool checkComplete() const;

protected:


};


#endif
