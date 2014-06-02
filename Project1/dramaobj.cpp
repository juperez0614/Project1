//---------------------------------------------------------------------------
// DramaObj.cpp
// Derived class from movieobject, contains drama types
// Authors: Julio Perez, Jeffrey Asmus
//---------------------------------------------------------------------------
// DramaObj class:  
//		includes  features:
//   -- creates drama object
//   -- sets data in object
//   -- allows for partial data to be set
//   -- allows for comparsion of 2 drama objects
//   -- displays classic object contents
//   -- displays actions performed on drama objects
//
//---------------------------------------------------------------------------
#include "dramaobj.h"

//---------------------------------------------------------------------------
//constructor
DramaObj::DramaObj() : MovieObject(){}

//---------------------------------------------------------------------------
//destructor
//sets attrubutes to empty or zero
DramaObj::~DramaObj(){
	title = "";
	director = "";
	year = 0;
	quantity = 0;
}

//---------------------------------------------------------------------------
//overloaded ==
//determines if a two drama movie objects are equal
//using title, director, year as criteria
bool DramaObj::operator==(const Object & rhs) const{
	const MovieObject& e = dynamic_cast<const MovieObject&>(rhs);
	const DramaObj& p = dynamic_cast<const DramaObj&>(e);
	if (title == p.title && director == p.director && year == p.year){
		return true;
	}
	else {
		return false;
	}
}

//---------------------------------------------------------------------------
//overloaded <
//determines if a drama movie objects is less than another
//using title, director, year as criteria
bool DramaObj::operator<(const Object & rhs) const{
	const MovieObject& e = dynamic_cast<const MovieObject&>(rhs);
	const DramaObj& p = dynamic_cast<const DramaObj&>(e);
	if (director < p.director){
		return true;
	}
	else if (director == p.director){
		if (title < p.title){
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
//creates a new drama object
Object* DramaObj::create()const {
	return new DramaObj();
}

//---------------------------------------------------------------------------
//setData
//sets the director, title, and year attruibutes
//from an input file
void DramaObj::setData(ifstream& intake){
	char code;
	intake >> code;
	intake.get(); // get (and ignore) blank before director
	getline(intake, director, ',');// input director

	intake.get();                       // get (and ignore) blank before title
	getline(intake, title, ',');        // input title

	intake >> year;           // input year
	string s;
	getline(intake, s, '\n'); // get eoln
}

//---------------------------------------------------------------------------
//display
//prints out inital quantity, new quantity, title, director, year to screen
void DramaObj::display()const{
	cout << quantity << "\t" << 10 - quantity << "\t"
		<< title << "\t" << "\t" << director << "\t" << year
		<< endl;
}

//---------------------------------------------------------------------------
//actionDisplay
//prints out title, director, year, month to the screen 
//after an action has been performed
void DramaObj::actionDisplay() const{
	cout << title << "  " << director << "  " << year << endl;
}

//---------------------------------------------------------------------------
//setPartialData
//sets title, year 
//used to find classic object when performing an action
void DramaObj::setPartialData(ifstream & intake){

	intake.get();	//skip empty space

	getline(intake, director, ',');

	intake.get(); //skip empty space

	getline(intake, title, ',');

	string s;

	getline(intake, s, '\n');

}

//---------------------------------------------------------------------------
//equals
// i dont think we need this???
bool DramaObj::equals(Object* target)const{
	MovieObject* e = dynamic_cast<MovieObject*>(target);
	DramaObj* p = dynamic_cast<DramaObj*>(e);
	if (p->director == director && p->title == title){
		return true;
	}
	else {
		return false;
	}
}


