#include "movieobject.h"

MovieObject::MovieObject():Object(){
	format = 'D';
	title = "";
	year = 0;
	director = "";
	quantity = 10;
}

MovieObject::MovieObject(string movieTitle, int yr, string dir):Object(){
	title = movieTitle;
	year = yr;
	director = dir;
	quantity = 10;
}

MovieObject::~MovieObject(){
	title = "";
	year = 0;
	director = "";
	quantity = 0;
}

int MovieObject::getQuantity() const{
	return quantity;
}

bool MovieObject::setQuantity(int change){
	quantity = quantity + change; 
	return true;
}
