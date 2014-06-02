//---------------------------------------------------------------------------
// ComedyObj.cpp
// Derived class from movieobject, contains comedy types
// Authors: Julio Perez, Jeffrey Asmus
//---------------------------------------------------------------------------
// ComedyObj class:  
//		includes  features:
//   -- creates comedy object
//   -- sets data in object
//   -- allows for partial data to be set
//   -- allows for comparsion of 2 classic objects
//   -- displays classic object contents
//   -- displays actions performed on classic objects
//
//---------------------------------------------------------------------------
#include "comedyobj.h"

//---------------------------------------------------------------------------
//constructor
ComedyObj::ComedyObj() :MovieObject(){}

//---------------------------------------------------------------------------
//destructor
//sets attrubutes to empty or zero
ComedyObj::~ComedyObj(){
	title = "";
	year = 0;
	director = "";
	quantity = 0;
}

//---------------------------------------------------------------------------
//overloaded ==
//determines if a two comedy movie objects are equal
//using title, director, year as criteria
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

//---------------------------------------------------------------------------
//overloaded <
//determines if a comedy movie objects is less than another
//using title, director, year as criteria
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

//---------------------------------------------------------------------------
//create
//creates a new comedy object
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

//---------------------------------------------------------------------------
//display
//prints out inital quantity, new quantity, title, director, year to screen
void ComedyObj::display()const{
	cout << quantity << "\t" << 10 - quantity << "\t"
		<< title << "\t" << "\t" << director << "\t" << year
		<< endl;
}

//---------------------------------------------------------------------------
//actionDisplay
//prints out title, director, year, month to the screen 
//after an action has been performed
void ComedyObj::actionDisplay() const{
	cout << title << "  " << director << "  " << year << endl;
}

//---------------------------------------------------------------------------
//setPartialData
//sets title, year 
//used to find classic object when performing an action
void ComedyObj::setPartialData(ifstream & intake){

	intake.get();	//skip empty space

	getline(intake, title, ',');


	intake >> year;

	string s;

	getline(intake, s, '\n');

}

//---------------------------------------------------------------------------
//equals
// i dont think we need this???
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

