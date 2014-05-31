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
