#include "movieobject.h"

MovieObject::MovieObject():Object(){
	
}

MovieObject::MovieObject(string movieTitle, int yr, string dir):Object(){
	title = movieTitle;
	year = yr;
	director = dir;
	quantity = 10;
}
