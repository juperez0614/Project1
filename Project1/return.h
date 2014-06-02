#ifndef RETURN_H
#define RETURN_H

#include "commandaction.h"

using namespace std;

class Return : public CommandAction{
public:
	Return();
	virtual ~Return();
	virtual void performAct();
	virtual CommandAction* createAction();
	virtual void setData(ifstream& intake);
	virtual void display() const;


protected:


};


#endif