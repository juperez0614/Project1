#ifndef DRAMAOBJCONTAINER_H
#define DRAMAOBJCONTAINER_H

#include "movieobjectcontainer.h"

class DramaObjContainer : public MovieObjectContainer{

	friend ostream& operator<<(ostream& output, const DramaObjContainer& toWrite);

public:
	DramaObjContainer();
	virtual void print(ostream & output);

protected:
	ostream& outputHelper(ostream& output, const containerNode* toWrite);
};

#endif