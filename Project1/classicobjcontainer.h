#ifndef CLASSICOBJCONTAINER_H
#define CLASSICOBJCONTAINER_H
#include "movieobjectcontainer.h"

class ClassicObjContainer : public MovieObjectContainer {
	friend ostream& operator<<(ostream& output, const ClassicObjContainer& toWrite);

public:
	ClassicObjContainer();
	virtual void print(ostream & output);

protected:
	ostream& outputHelper(ostream& output,const containerNode* toWrite);
	ObjectContainer::containerNode* copyHelper(const containerNode* current);
};






#endif