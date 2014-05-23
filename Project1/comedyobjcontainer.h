#ifndef COMEDYOBJCONTAINER_H
#define COMEDYOBJCONTAINER_H

#include "movieobjectcontainer.h"

class ComedyObjContainer : public MovieObjectContainer{

	friend ostream& operator<<(ostream& output, const ComedyObjContainer& toWrite);

public:
	ComedyObjContainer();
	virtual void print(ostream & output);

protected:
	ostream& outputHelper(ostream& output, const containerNode* toWrite);
};

#endif