#ifndef COMEDY_H
#define COMEDY_H
#include "movieobject.h"


class ComedyObj : public MovieObject {
public:
	ComedyObj();
	ComedyObj(string, int);
	virtual ~ComedyObj();
	virtual Object* create() const;
	virtual void setData(ifstream & intake);
	virtual bool operator<(const Object & rhs) const;
	virtual bool operator==(const Object & rhs) const;
	virtual void display()const;

protected:

};
#endif
