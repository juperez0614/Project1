/*
This is a binary search tree that contains all the customers. the tree is 
sorted by the UserObject's definition of < and ==.
*/
#ifndef USEROBJECTCONTAINER_H
#define USEROBJECTCONTAINER_H
#include "objectcontainer.h"
#include "userobject.h"




class UserObjectContainer{
public:

	UserObject* search();
	bool insertUser(UserObject & toInsert);

	//TODO: ARE THESE NECESSARY
	bool removeUser(int idNumber); 
	bool removeUser(string lastName, string firstName);
	

protected:


};

#endif