#include "movieobject.h"

MovieObject::MovieObject():Object(){
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
