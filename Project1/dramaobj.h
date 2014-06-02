//---------------------------------------------------------------------------
// DramaObj.H
// Derived class from movieobject, contains drama types
// Authors: Julio Perez, Jeffrey Asmus
//---------------------------------------------------------------------------
// DramaObj class:  
//		includes  features:
//   -- creates movie object
//   -- sets data in object
//   -- allows for partial data to be set
//   -- allows for comparsion of 2 classic objects
//   -- displays classic object contents
//   -- displays actions performed on classic objects
//
//---------------------------------------------------------------------------
#ifndef DRAMAOBJ_H
#define DRAMAOBJ_H
#include "movieobject.h"


class DramaObj : public MovieObject {
public:
	DramaObj();
	virtual ~DramaObj();
	virtual Object* create() const;
	virtual void setData(ifstream&);
	virtual void setPartialData(ifstream & intake);
	virtual bool operator<(const Object & rhs) const;
	virtual bool operator==(const Object & rhs) const;
	virtual void display() const;
	virtual void actionDisplay() const;
	virtual bool equals(Object* target)const;

protected:

};

#endif
