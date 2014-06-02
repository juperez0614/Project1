//---------------------------------------------------------------------------
// ClassicObj.cpp
// Derived class from movieobject, contains classic types
// Authors: Julio Perez, Jeffrey Asmus
//---------------------------------------------------------------------------
// ClassicObj class:  
//		includes  features:
//   -- creates movie object
//   -- sets data in object
//   -- allows for partial data to be set
//   -- allows for comparsion of 2 classic objects
//   -- displays classic object contents
//   -- displays actions performed on classic objects
//
// Assumptions:
//   -- all attributes default to empty strings, or to 0
//---------------------------------------------------------------------------
#include "classicobj.h"

//---------------------------------------------------------------------------
//constructor
//initalizes attributes to empty or zero
ClassicObj::ClassicObj():MovieObject(){
	month = 0;
	actorFirst = "";
	actorLast = "";
}

//---------------------------------------------------------------------------
//destructor
//sets attrubutes to empty or zero
ClassicObj::~ClassicObj(){
	title = "";
	month = 0;
	year = 0;
	director = "";
	actorFirst = "";
	actorLast = "";
}

//---------------------------------------------------------------------------
//overloaded ==
//determines if a two classic movie objects are equal
//using year, month, title, direction, actor name as criteria
bool ClassicObj::operator==(const Object &rhs)const {
	const MovieObject& e = dynamic_cast<const MovieObject&> (rhs);
	const ClassicObj& p = dynamic_cast< const ClassicObj& >(e);
	if (year == p.year && month == p.month && title == p.title &&
			director == p.director && actorFirst == p.actorFirst &&
			actorLast == p.actorLast){
		return true;
	}
	else {
		return false;
	}
}

//---------------------------------------------------------------------------
//overloaded <
//determines if a classic movie objects is less than another
//using year, month, title, direction, actor name as criteria
bool ClassicObj::operator<(const Object &rhs) const{
	const MovieObject& e = dynamic_cast<const MovieObject&> (rhs);
	const ClassicObj& p = dynamic_cast< const ClassicObj& >(e);
	if (year < p.year){
		return true;
	}
	else if (year == p.year){
		if (month < p.month){
			return true;
		}
		else if (month == p.month){
			if (actorLast < p.actorLast){
				return true;
			}
			else if (actorLast == p.actorLast){
				if (actorFirst < p.actorFirst){
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
	} else {
		return false;
	}
}

//---------------------------------------------------------------------------
//create
//creates a new classic object
Object* ClassicObj::create() const{
	return new ClassicObj();
}

//---------------------------------------------------------------------------
//setData
//sets the director, title, actor name, month, and year attruibutes
//from an input file
void ClassicObj::setData(ifstream & intake){
    char code;
 	intake >> code;
	intake.get(); // get (and ignore) blank before director
	getline(intake, director, ',');// input director
	    
	intake.get();                // get (and ignore) blank before title
	getline(intake, title, ',');        // input title

	intake >> actorFirst >> actorLast;  // input star's name
	intake >> month >> year;            // input month and year          
	string s;
	getline(intake, s, '\n');           // get eoln
}


//---------------------------------------------------------------------------
//display
//prints out inital quantity, new quantity, title, director, year, month
//actor name to the screen
void ClassicObj::display() const {
	cout << quantity << "\t" << (10 - quantity) << "\t" 
		<< title << "\t" << director << "\t" << year 
		<< "\t" << month << "\t" << actorFirst 
		<< " " << actorLast << endl;
}

//---------------------------------------------------------------------------
//actionDisplay
//prints out title, director, year, month, actor name to the screen 
//after an action has been performed
void ClassicObj::actionDisplay() const{
	cout << title << "  " << director << "  " << year << "  " << month 
	<< "  " << actorFirst << " " << actorLast << endl;
}

//---------------------------------------------------------------------------
//setPartialData
//sets month, year, and actor name
//used to find classic object when performing an action
void ClassicObj::setPartialData(ifstream & intake){

	intake >> month;	//get month

	intake >> year;		//get year

	intake >> actorFirst;	//get actor first

	intake >> actorLast;	//get last name

	string s;

	getline(intake, s, '\n');	//move to the next line

}

//---------------------------------------------------------------------------
//equals
// i dont think we need this???
bool ClassicObj::equals(Object* target)const{
	MovieObject* e = dynamic_cast<MovieObject*>(target);
	ClassicObj* p = dynamic_cast<ClassicObj*>(e);
	if (p->month == month && p->year == year && 
		p->actorFirst == actorFirst && p->actorLast == actorLast){
		return true;
	}
	else {
		return false;
	}
}
