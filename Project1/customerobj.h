#ifndef CUSTOMEROBJ_H
#define CUSTOMEROBJ_H
#include "userobject.h"

class CustomerObj : public UserObject{
	friend ostream& operator<<(ostream& output, const CustomerObj & toWrite);
public:
	CustomerObj();
	virtual ~CustomerObj();
	virtual Object* create() const;
	virtual void setData(ifstream & intake);
	virtual bool operator<(const Object & rhs) const;
	virtual bool operator==(const Object & rhs) const;

protected:

	struct historyList {
		string action;
		string date;
		string movie;
		historyList* next;
		historyList* prev; 
	};
	historyList *historyRoot;
	historyList *historyTail; 

	void emptyHistoryList(historyList* tail);
};

#endif