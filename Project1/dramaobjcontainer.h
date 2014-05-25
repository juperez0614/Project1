#ifndef DRAMAOBJCONTAINER_H
#define DRAMAOBJCONTAINER_H

#include "movieobjectcontainer.h"

class DramaObjContainer : public MovieObjectContainer{

	friend ostream& operator<<(ostream& output, const DramaObjContainer& toWrite);

public:
	DramaObjContainer();
	virtual ~DramaObjContainer();
	virtual void print(ostream & output);
	//virtual bool search(Object* toFind);
	virtual bool isEmpty() const;


protected:
	virtual void destructorHelper(containerNode* current);
	virtual ostream& outputHelper(ostream& output, const containerNode* toWrite);
};

#endif