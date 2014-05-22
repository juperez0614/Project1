#include "dramaobj.h"

DramaObj::DramaObj() : MovieObject(){}

DramaObj::DramaObj(string dirName, string titleName) : MovieObject(dirName, 2000, titleName){}

DramaObj::~DramaObj(){
	title = "";
	director = "";
	year = 0;
	quantity = 0;
}

bool DramaObj::operator==(const Object & rhs) const{
	const DramaObj* p = dynamic_cast< const DramaObj* >(&rhs);
	if (title == p->title && director == p->director && year == p->year){
		return true;
	}
	else {
		return false;
	}
}

bool DramaObj::operator<(const Object & rhs) const{
	const DramaObj* p = dynamic_cast< const DramaObj* >(&rhs);
	if (director < p->director){
		return true;
	}
	else if (director == p->director){
		if (title < p->title){
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



