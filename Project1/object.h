#ifndef OBJECT_H
#define OBJECT_H
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Object{


public:
	Object();
	virtual ~Object();
	virtual Object* create() const = 0;
	virtual void setData(ifstream & intake) = 0;
	virtual bool operator<(const Object & rhs)const = 0;
	virtual bool operator==(const Object & rhs)const = 0;
	virtual void display() const = 0;

protected:
	

};
#endif
