#include "dramaobj.h"

DramaObj::DramaObj() : MovieObject(){}

DramaObj::DramaObj(string dirName, string titleName) : MovieObject(titleName, 2000, dirName){}

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

