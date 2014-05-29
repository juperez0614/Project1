/*
This is the base class for all movie genre types. Any additional, specific
information is found in the classes that inherit from this class.
*/
#ifndef USEROBJECT_H
#define USEROBJECT_H

#include <iostream>
#include <string>
#include "object.h"
using namespace std;


class UserObject : public Object{


public:
	UserObject();
	virtual ~UserObject();
	virtual Object* create() const = 0;
	virtual void setData(ifstream & inputsGetLine) = 0;
	bool operator<(const Object & rhs)const = 0;
	bool operator==(const Object & rhs)const = 0;
	virtual void display() const = 0;

protected:
	string firstName;
	string lastName;
	string id;

};

#endif