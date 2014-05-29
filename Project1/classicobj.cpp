#include "classicobj.h"

ClassicObj::ClassicObj():MovieObject(){
	month = 0;
	actorFirst = "";
	actorLast = "";
}

ClassicObj::ClassicObj(string actorName, string actorLastName, int mon, int yr):MovieObject("", yr, ""){
	month = mon;
	actorFirst = actorName;
	actorLast = actorLastName;
}

ClassicObj::~ClassicObj(){
	title = "";
	month = 0;
	year = 0;
	director = "";
	actorFirst = "";
	actorLast = "";
}


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

Object* ClassicObj::create() const{
	return new ClassicObj();
}

void ClassicObj::setData(ifstream & intake){
    char code;
 	intake >> code;
	intake.get(); // get (and ignore) blank before director
	getline(intake, director, ',');// input director
	    
	intake.get();                       // get (and ignore) blank before title
	getline(intake, title, ',');        // input title

	intake >> actorFirst >> actorLast;  // input star's name
	intake >> month >> year;            // input month and year            // input month and year
	string s;
	getline(intake, s, '\n');                       // get eoln
}



void ClassicObj::display() const {
	cout << quantity << "\t" << (10 - quantity) << "\t" 
		<< title << "\t" << director << "\t" << year 
		<< "\t" << month << "\t" << actorFirst 
		<< " " << actorLast << endl;
}

