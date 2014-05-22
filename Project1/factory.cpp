#include "factory.h";

Factory::Factory(){
	objFactory[0] = new ClassicObj();
	objFactory[1] = new DramaObj();
	objFactory[3] = new ComedyObj();
}

Factory::~Factory(){
	for (int i = 0; i < FACTSIZE; i++){
		delete objFactory[i];
	}
	delete objFactory;
}

int Factory::hash(char ch){
	return ch - 'C'; 
}

Object* Factory::createIt(char ch){
	int subscript = hash(ch);
	return objFactory[subscript]->create();
}