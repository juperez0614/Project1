#ifndef CUSTOMEROBJ_H
#define CUSTOMEROBJ_H
#include "userobject.h"


using namespace std;

class CommandAction;

class CustomerObj : public UserObject{
public:
	CustomerObj();
	virtual ~CustomerObj();
	virtual Object* create() const;
	virtual void setData(ifstream & intake);
	virtual void setPartialData(ifstream& intake);
	virtual bool operator<(const Object & rhs) const;
	virtual bool operator==(const Object & rhs) const;
	virtual void display() const;
	virtual void displayHistory() const; 
	virtual void addToHistory(CommandAction* toInsert);
	virtual bool equals(Object* target)const;

protected:
	struct historyList {
		CommandAction* data;
		historyList* next;
		historyList* prev; 
	};
	historyList *historyRoot;
	historyList *historyTail; 

	void emptyHistoryList(historyList* tail);
	void addToHistoryHelper(historyList* current, CommandAction* toInsert);
};

#endif