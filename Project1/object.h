#ifndef OBJECT_H
#define OBJECT_H
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Object{

	//virtual friend ostream & operator<<(ostream& output, const Object& toOutput) = 0;
	//virtual friend ifstream & operator>>(ifstream& input, Object& toWrite) = 0;

public:
	Object();
	virtual ~Object();
	virtual Object* create() const = 0;
	virtual void setData(ifstream & intake) = 0;
	virtual bool operator<(const Object & rhs)const = 0;
	virtual bool operator==(const Object & rhs)const = 0;


protected:
	

};
#endif