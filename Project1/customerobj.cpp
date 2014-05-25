#include "customerobj.h"

CustomerObj::CustomerObj() : UserObject(){
	historyRoot = NULL;
	historyTail = NULL;
}

CustomerObj::~CustomerObj(){
	id = "";
	firstName = "";
	lastName = "";
	emptyHistoryList(historyTail);
	delete historyRoot;

}

void CustomerObj::emptyHistoryList(historyList* tail){
	
	
	while (tail != historyRoot){
		tail = tail->prev;
		tail->next->prev = NULL;
		tail->next->next = NULL;
		delete tail->next;
	}
	//fence post problem
	delete tail;
	tail = NULL;

}

void CustomerObj::setData(ifstream& intake){
	intake >> id >> firstName >> lastName;
}


bool CustomerObj::operator==(const Object &rhs)const {
	const UserObject* e = dynamic_cast<const UserObject*>(&rhs);
	const CustomerObj* p = dynamic_cast<const CustomerObj*>(e);
	if (id == p->id && firstName == p->firstName && lastName == p->lastName){
		return true;
	}
	else {
		return false;
	}
}

bool CustomerObj::operator<(const Object &rhs) const{
	const UserObject* e = dynamic_cast<const UserObject*>(&rhs);
	const CustomerObj* p = dynamic_cast<const CustomerObj*>(e);
	if (id < p->id){
		return true;
	}
	else if (id == p->id){
		if (lastName < p->lastName){
			return true;
		}
		else if (lastName == p->lastName){
			if (firstName < p->firstName){
				return true;
			}
			else{
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

Object* CustomerObj::create() const{
	return new CustomerObj();
}


ostream& operator<<(ostream& output, const CustomerObj& toWrite){
	output << toWrite.id << toWrite.lastName << toWrite.firstName << endl;
	return output;
}