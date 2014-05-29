#ifndef CLASSICOBJ_H
#define CLASSICOBJ_H
#include "movieobject.h"


class ClassicObj : public MovieObject {
public:
	ClassicObj();
	ClassicObj(string, string, int, int);
	virtual ~ClassicObj();
	virtual Object* create() const;
	virtual void setData(ifstream & intake);
	virtual bool operator<(const Object & rhs)const;
	virtual bool operator==(const Object & rhs)const;
	virtual void display()const;

protected:
	string actorFirst;
	string actorLast;
	int month;

};
#endif
