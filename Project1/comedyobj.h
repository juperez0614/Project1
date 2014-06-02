//---------------------------------------------------------------------------
// ComedyObj.H
// Derived class from movieobject, contains comedy types
// Authors: Julio Perez, Jeffrey Asmus
//---------------------------------------------------------------------------
// ComedyObj class:  
//		includes  features:
//   -- creates comedy object
//   -- sets data in object
//   -- allows for partial data to be set
//   -- allows for comparsion of 2 classic objects
//   -- displays classic object contents
//   -- displays actions performed on classic objects
//
//---------------------------------------------------------------------------
#define COMEDY_H
#include "movieobject.h"


class ComedyObj : public MovieObject {
public:
	ComedyObj();
	virtual ~ComedyObj();
	virtual Object* create() const;
	virtual void setData(ifstream & intake);
	virtual void setPartialData(ifstream & intake);
	virtual bool operator<(const Object & rhs) const;
	virtual bool operator==(const Object & rhs) const;
	virtual void display()const;
	virtual void actionDisplay() const;
	virtual bool equals(Object* target)const;

protected:

};
#endif
