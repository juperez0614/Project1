/*
This is the base class for all movie genre types. Any additional, specific
information is found in the classes that inherit from this class.
*/
#ifndef MOVIEOBJECT_H
#define MOVIEOBJECT_H
#include <iostream>
#include <string>
#include "object.h"

using namespace std;


class MovieObject : public Object{

	//virtual friend ostream & operator<<(ostream& output, const MovieObject& toOutput);
	//virtual friend ifstream & operator>>(ifstream& input, MovieObject& toWrite);

public:
	MovieObject();
	MovieObject(string, int, string);
	//virtual void setData(ifstream & inputsGetLine);
	virtual Object* create() const = 0;
	virtual void setData(ifstream & intake) = 0;
	virtual bool operator<(const Object & rhs)const = 0;
	virtual bool operator==(const Object & rhs)const = 0;


protected:
	string title;
	int year;
	string director;
	int quantity;

};
#endif