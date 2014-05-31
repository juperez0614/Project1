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
