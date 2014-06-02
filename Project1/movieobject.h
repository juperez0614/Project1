//---------------------------------------------------------------------------
// MovieObject.H
// Base class for all movie genre types, contains movie objects
// Authors: Julio Perez, Jeffrey Asmus
//---------------------------------------------------------------------------
// MovieObject class:  
//		includes  features:
//   -- creates movie object
//   -- gets quantity
//   -- sets quantity 
//   -- all other methods are overwritten in derived classes
//
// Assumptions:
//   -- quantity defaults to a fixed size of 10 if quantity is not specified
//   -- all other attributes default to empty chars, strings, or to 0
//---------------------------------------------------------------------------
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
