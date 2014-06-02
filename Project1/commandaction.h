#ifndef COMMANDACTION_H
#define COMMANDACTION_H

#include <string>
#include "movieobject.h"
#include "customerobj.h"

using namespace std;

class CommandAction{
public:
	CommandAction();
	virtual ~CommandAction();
	virtual void performAct() = 0;
	virtual CommandAction* createAction() = 0;
	virtual void setData(ifstream& intake) = 0;
	virtual void display() const = 0;
	virtual void customerSet(Object* toCreate);
	virtual void movieSet(Object* toCreate);
	virtual char getCode()const;
	virtual bool checkComplete() const;
	virtual char getFormat() const;

protected:
	int  id;
	char format;
	char genre;
	char actionCode;
	MovieObject* movie;
	CustomerObj* customer;

	virtual bool checkQuantity();
	virtual void increaseQuantity();
	virtual void decreaseQuantity();

};
#endif