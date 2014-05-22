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

	friend ostream & operator<<(ostream& output, const UserObject& toOutput);
	friend ifstream & operator>>(ifstream& input, UserObject& toWrite);

public:
	virtual void setData(ifstream & inputsGetLine);
	bool operator<(const UserObject & rhs)const;
	bool operator==(const UserObject & rhs)const;


protected:
	string firstName;
	string lastName;
	int id;

};

#endif