//#include "classicobj.h"
//#include "dramaobj.h"
//#include "comedyobj.h"
#include "manager.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	bool test = true;
	ClassicObj* A = new ClassicObj("Katherine", "Hepburn", 9, 1942);
	ClassicObj* B = new ClassicObj("Cary", "Grant", 9, 1942);
	ClassicObj* C = new ClassicObj("Cary", "Grant", 3, 1942);
	ClassicObj* D = new ClassicObj("Cary", "Grant", 9, 1941);
	ClassicObj* E = new ClassicObj("Cary", "Grant", 9, 1941);


	cout << "*A < *B: " << (*A < *B) << endl;
	cout << "*A < *C: " << (*A < *C) << endl;
	cout << "*D < *A: " << (*D < *A) << endl;
	cout << "*B == *D: " << (*B == *D) << endl;
	cout << "*D == *E: " << (*D == *E) << endl;

	cout << "True = " << test << endl;
	//-----------------------------------------------------------------------------
	DramaObj* AA = new DramaObj("Jeffrey Asmus", "The gayest movie on earth");
	DramaObj* BB = new DramaObj("Jeffrey Asmus", "The greatest movie on earth");
	DramaObj* CC = new DramaObj("Julio Perez", "The greatest movie on earth");
	DramaObj* DD = new DramaObj("Jeffrey Asmus", "The gayest movie on earth");

	cout << endl;
	cout << "*AA < *BB: " << (*AA < *BB) << endl; //true
	cout << "*AA < *CC: " << (*AA < *CC) << endl; //true
	cout << "*DD < *AA: " << (*DD < *AA) << endl; //false
	cout << "*BB == *DD: " << (*AA == *DD) << endl; //true
	cout << "*DD == *EE: " << (*DD == *CC) << endl; //false

	//-----------------------------------------------------------------------------
	ComedyObj* EE = new ComedyObj("greatest movie", 2005);
	ComedyObj* F = new ComedyObj("greatest movie", 2006);
	ComedyObj* G = new ComedyObj("gayest movie", 2005);
	ComedyObj* H = new ComedyObj("greatest movie", 2005);

	cout << endl;
	cout << "*EE < *F: " << (*EE < *F) << endl; //true
	cout << "*EE < *G: " << (*EE < *G) << endl; //false
	cout << "*EE < *H  " << (*EE < *H) << endl; //false
	cout << "*EE == *H: " << (*EE == *H) << endl; //true
	cout << "*EE == *G: " << (*EE == *G) << endl; //false


	delete A;
	delete B;
	delete C;
	delete D;
	delete E;
	delete AA;
	delete BB;
	delete CC;
	delete DD;
	delete EE;
	delete F;
	delete G;
	delete H;
	
//-----------------------------------------------------------------------------

	ifstream intakeFile("data4movies.txt");
	if (!intakeFile) {
		cout << "File could not be opened." << endl;
		return 1;
	}
	//file reads

	Manager mystuff;
	mystuff.intakeDataFromFile(intakeFile);


	return 0;
}