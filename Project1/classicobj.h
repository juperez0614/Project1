//---------------------------------------------------------------------------
// ClassicObj.H
// Derived class from movieobject, contains classic types
// Authors: Julio Perez, Jeffrey Asmus
//---------------------------------------------------------------------------
// ClassicObj class:  
//		includes  features:
//   -- creates movie object
//   -- sets data in object
//   -- allows for partial data to be set
//   -- allows for comparsion of 2 classic objects
//   -- displays classic object contents
//   -- displays actions performed on classic objects
//
// Assumptions:
//   -- all attributes default to empty strings, or to 0
//---------------------------------------------------------------------------
#ifndef CLASSICOBJ_H
#define CLASSICOBJ_H
#include "movieobject.h"


class ClassicObj : public MovieObject {
public:
	ClassicObj();
	virtual ~ClassicObj();
	virtual Object* create() const;
	virtual void setData(ifstream & intake);
	virtual void setPartialData(ifstream & intake);
	virtual bool operator<(const Object & rhs)const;
	virtual bool operator==(const Object & rhs)const;
	virtual void display()const;
	virtual void actionDisplay() const;
	virtual bool equals(Object* target)const;

protected:
	string actorFirst;
	string actorLast;
	int month;

};
#endif
