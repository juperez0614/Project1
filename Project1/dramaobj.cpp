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
	intake.get();
	getline(intake, director, ',');

	intake.get();
	getline(intake, title, ',');

	intake >> year;
}

ostream& operator<<(ostream& output, const DramaObj& toWrite){
	output << toWrite.quantity << "\t" << 10 - toWrite.quantity << "\t"
		<< toWrite.title << "\t" << "\t" << toWrite.director << "\t" << toWrite.year
		<< endl;
	return output;

}

