#include "comedyobj.h"

ComedyObj::ComedyObj() :MovieObject(){}

ComedyObj::ComedyObj(string titleName, int yr) : MovieObject(titleName, yr, ""){}

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
	intake.get();
	getline(intake, director, ',');

	intake.get();
	getline(intake, title, ',');

	intake >> year;
}

ostream& operator<<(ostream& output, const ComedyObj& toWrite){
	output << toWrite.quantity << "\t" << 10 - toWrite.quantity << "\t"
		<< toWrite.title << "\t" << "\t" << toWrite.director << "\t" << toWrite.year
			 << endl;
	return output;

}