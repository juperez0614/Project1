/*
This is the base class for all movie genre types. Any additional, specific
information is found in the classes that inherit from this class.
*/
#ifndef MOVIEOBJECT_H
#define MOVIEOBJECT_H
#include <iostream>
#include <string>
#include "object.h"

using namespace std;


class MovieObject : public Object{


public:
	MovieObject();
	MovieObject(string, int, string);
	virtual ~MovieObject();
	virtual Object* create() const = 0;
	virtual void setData(ifstream & intake) = 0;
	virtual void setPartialData(ifstream & intake) = 0;
	virtual bool operator<(const Object & rhs)const = 0;
	virtual bool operator==(const Object & rhs)const = 0;
	virtual void display()const = 0;
	virtual bool equals(Object* target)const = 0;

	virtual int getQuantity() const; 
	virtual bool setQuantity(int change);
	virtual void actionDisplay() const = 0;

protected:
	char format;
	string title;
	int year;
	string director;
	int quantity;


};
#endif