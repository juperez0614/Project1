//---------------------------------------------------------------------------
// MovieObject.H
// Base class for all movie genre types, contains movie objects
// Authors: Julio Perez, Jeffrey Asmus
//---------------------------------------------------------------------------
// MovieObject class:  
//		includes  features:
//   -- creates movie object
//   -- gets quantity
//   -- sets quantity 
//   -- all other methods are overwritten in derived classes
//
// Assumptions:
//   -- quantity defaults to a fixed size of 10 if quantity is not specified
//   -- all other attributes default to empty chars, strings, or to 0
//---------------------------------------------------------------------------
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
