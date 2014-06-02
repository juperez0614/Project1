//---------------------------------------------------------------------------
// DramaObj.H
// Derived class from movieobject, contains drama types
// Authors: Julio Perez, Jeffrey Asmus
//---------------------------------------------------------------------------
// DramaObj class:  
//		includes  features:
//   -- creates movie object
//   -- sets data in object
//   -- allows for partial data to be set
//   -- allows for comparsion of 2 classic objects
//   -- displays classic object contents
//   -- displays actions performed on classic objects
//
//---------------------------------------------------------------------------
#include "dramaobj.h"

DramaObj::DramaObj() : MovieObject(){}

DramaObj::~DramaObj(){
	title = "";
	director = "";
	year = 0;
	quantity = 0;
}

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


Object* DramaObj::create()const {
	return new DramaObj();
}

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


void DramaObj::display()const{
	cout << quantity << "\t" << 10 - quantity << "\t"
		<< title << "\t" << "\t" << director << "\t" << year
		<< endl;
}

void DramaObj::actionDisplay() const{
	cout << title << "  " << director << "  " << year << endl;
}

void DramaObj::setPartialData(ifstream & intake){

	intake.get();	//skip empty space

	getline(intake, director, ',');

	intake.get(); //skip empty space

	getline(intake, title, ',');

	string s;

	getline(intake, s, '\n');

}


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


