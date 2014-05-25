#ifndef CLASSICOBJCONTAINER_H
#define CLASSICOBJCONTAINER_H
#include "objectcontainer.h"
#include "movieobjectcontainer.h"

class ClassicObjContainer : public MovieObjectContainer{
	friend ostream& operator<<(ostream& output, const ClassicObjContainer& toWrite);

public:
	ClassicObjContainer();
	virtual ~ClassicObjContainer();
	virtual void print(ostream & output);
	//virtual bool search(Object* toFind);
	virtual bool isEmpty() const;


protected:
	virtual void destructorHelper(containerNode* current);
	virtual ostream& outputHelper(ostream& output, const containerNode* toWrite);
};


#endif