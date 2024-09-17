#include <iostream>
#include "Particella.h"
#include "Elettrone.h"

using namespace std;


int main(int argc,char** argv){

	Particella *a = new Particella(1,1);
	Elettrone *e = new Elettrone();
	
	cout<< "Particella"<<a->GetMassa()<<a->GetCarica()<<endl;
	a->Print();

	cout<< "Elettrone"<<e->GetMassa()<<e->GetCarica()<<endl;
	e->Print();

	return 0;
}
