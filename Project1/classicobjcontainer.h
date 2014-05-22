#ifndef CLASSICOBJCONTAINER_H
#define CLASSICOBJCONTAINER_H
#include "movieobjectcontainer.h"

class ClassicObjContainer : public MovieObjectContainer {
	friend ostream& operator<<(ostream& output, const ClassicObjContainer& toWrite);

public:
	ClassicObjContainer();
	//ClassicObjContainer(const ClassicObjContainer& current);
	virtual void print(ostream & output);

protected:
	ostream& outputHelper(ostream& output, containerNode* toWrite);
	ObjectContainer::containerNode* copyHelper(const containerNode* current);
};






#endif