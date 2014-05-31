#include "comedyobj.h"

ComedyObj::ComedyObj() :MovieObject(){}


ComedyObj::~ComedyObj(){
	title = "";
	year = 0;
	director = "";
	quantity = 0;
}

bool ComedyObj::operator==(const Object & rhs)const{
	const MovieObject& e = dynamic_cast<const MovieObject&>(rhs);
	const ComedyObj& p = dynamic_cast< const ComedyObj& >(e);
	if (title == p.title && director == p.director && year == p.year){
		return true;
	}
	else {
		return false;
	}
}

bool ComedyObj::operator<(const Object & rhs)const {
	const MovieObject* e = dynamic_cast<const MovieObject*>(&rhs);
	const ComedyObj* p = dynamic_cast< const ComedyObj* >(e); 
	if (title < p->title){
		return true;
	}
	else if (title == p->title){
		if (year < p->year){
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

Object* ComedyObj::create()const {
	return new ComedyObj();
}

void ComedyObj::setData(ifstream& intake){
	char code;
	intake >> code;
	intake.get(); // get (and ignore) blank before director
	getline(intake, director, ',');// input director

	intake.get();                       // get (and ignore) blank before title
	getline(intake, title, ',');        // input title

	intake >> year;            // input month and year            // input month and year
	string s;
	getline(intake, s, '\n');                       // get eoln
}

void ComedyObj::display()const{
	cout << quantity << "\t" << 10 - quantity << "\t"
		<< title << "\t" << "\t" << director << "\t" << year
		<< endl;
}

void ComedyObj::actionDisplay() const{
	cout << title << "  " << director << "  " << year << endl;
}

void ComedyObj::setPartialData(ifstream & intake){

	intake.get();	//skip empty space

	getline(intake, title, ',');


	intake >> year;

	string s;

	getline(intake, s, '\n');

}


bool ComedyObj::equals(Object* target)const{
	MovieObject* e = dynamic_cast<MovieObject*>(target);
	ComedyObj* p = dynamic_cast<ComedyObj*>(e);
	if (p->title == title && p->year == year){
		return true;
	}
	else {
		return false;
	}
}

