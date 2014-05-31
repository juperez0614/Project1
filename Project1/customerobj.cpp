#include "customerobj.h"
#include "commandaction.h"

CustomerObj::CustomerObj() : UserObject(){
	historyRoot = NULL;
	historyTail = NULL;
}

CustomerObj::~CustomerObj(){
	emptyHistoryList(historyTail);
	historyRoot = NULL;
	id = 0;
	firstName = "";
	lastName = "";


}

void CustomerObj::emptyHistoryList(historyList* tail){



	while (tail != historyRoot && tail != NULL){
		
		if (tail->next != NULL){
			delete tail->next->data;
			tail->next->next = NULL;
			tail->next->prev = NULL;
		}
		tail = tail->prev;
	}

	//fence post problem
	delete tail;
	tail = NULL;

}

void CustomerObj::setData(ifstream& intake){
	intake >> id >> firstName >> lastName;
	string s;
	getline(intake, s, '\n');
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
	else {
		return false;
	}
}

Object* CustomerObj::create() const{
	return new CustomerObj();
}


void CustomerObj::display() const{
	cout << id << "\t" << lastName << "\t" << firstName << endl;
}

void CustomerObj::displayHistory() const{
	cout << "*** Customer ID= ";
	display();
	cout << endl;
	historyList* current = historyRoot;
	while (current != NULL){
		current->data->display();
		current = current->next;
	}// need to test for overflow
}

void CustomerObj::addToHistory(CommandAction* toInsert){
	if (historyRoot == NULL){
		historyList* temp = new historyList;
		temp->data = toInsert;
		temp->next = NULL;
		temp->prev = NULL;
		historyRoot = temp;
		historyTail = temp; // locked in
	}
	else {
		addToHistoryHelper(historyRoot, toInsert);
	}
}

void CustomerObj::addToHistoryHelper(historyList* current, CommandAction* toInsert){
	while (current != NULL){
		current = current->prev;
	}
	if (current == NULL){ //double check current == NULL
		historyList* temp = new historyList;
		temp->data = toInsert;
		temp->next = historyRoot;
		temp->prev = NULL;
		historyRoot = temp;
	}
}

void CustomerObj::setPartialData(ifstream& intake){
	intake >> id;
}



bool CustomerObj::equals(Object* target)const{
	UserObject* e = dynamic_cast<UserObject*>(target);
	CustomerObj* p = dynamic_cast<CustomerObj*>(e);
	if (p->id == id){
		return true;
	}
	else {
		return false;
	}
}
//*** Customer ID = 1000  Mouse Minnie
//DVD Borrow  Good Morning Vietnam  Barry Levinson    1988
//DVD Borrow  The Philadelphia Stor George Cukor      1940 5  Katherine Hepburn
//DVD Borrow  Good Will Hunting     Gus Van Sant      2000
//DVD Borrow  The Philadelphia Stor George Cukor      1940 5  Cary Grant
//DVD Borrow  Harold and Maude      Hal Ashby         1971 3  Ruth Gordon
