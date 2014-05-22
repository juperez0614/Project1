#ifndef CUSTOMEROBJ_H
#define CUSTOMEROBJ_H
#include "userobject.h"

class CustomerObj : public UserObject{
public:
	CustomerObj();
	~CustomerObj();
	virtual void setData(ifstream & intake);
	virtual bool operator<(const UserObject & rhs) const;
	virtual bool operator==(const UserObject & rhs) const;


protected:

	struct historyList {
		string action;
		string date;
		string movie;
	};

};

#endif