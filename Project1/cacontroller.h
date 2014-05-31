#ifndef CACONTROLLER_H
#define CACONTROLLER_H

#include "commandaction.h"
#include "borrow.h"
#include "return.h"
#include "history.h"

using namespace std;


class CAController{
	static const int CASIZE = 3;
public:
	CAController();
	~CAController();
	CommandAction* selectAction(char ch);

protected:
	CommandAction * actionArray[CASIZE];
	int hash(char ch);

};


#endif