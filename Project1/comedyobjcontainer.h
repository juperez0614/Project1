#ifndef COMEDYOBJCONTAINER_H
#define COMEDYOBJCONTAINER_H

#include "movieobjectcontainer.h"

class ComedyObjContainer : public MovieObjectContainer{

	friend ostream& operator<<(ostream& output, const ComedyObjContainer& toWrite);

public:
	ComedyObjContainer();
	virtual ~ComedyObjContainer();
	virtual void print(ostream & output);
	//virtual bool search(Object* toFind);
	virtual bool isEmpty() const;


protected:
	virtual void destructorHelper(containerNode* current);
	virtual ostream& outputHelper(ostream& output, const containerNode* toWrite);

};

#endif