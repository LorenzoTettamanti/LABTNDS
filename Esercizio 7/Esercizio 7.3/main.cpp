#include<iostream>
#include<iomanip>

#include "Fun.h"
#include "Bisezione.h"


using namespace std;

int main(int argc,char**argv){
	
	double precision = 1.E-6;

	Fun *myfun = new Fun(1.,1.);
	
	Bisezione *bis = new Bisezione();
	
	//cifre significative
	int cf=-log10(precision);
	
	//cercare soluzioni su intervallo (npi,npi+pi/2) con precisione 1.E-6 e n da 1 a 20

	cout<<"Ricerca degli zeri della funzione"<<endl;
	for(int i=1;i<21;i++){
		double zero = bis->CercaZeri(i*M_PI,((i*M_PI)+(M_PI/2)),myfun,precision);
		cout<<"x"<<"_"<<i<<": "<<fixed<<zero<<endl;
	}
	


	
	delete bis;
	delete myfun;
	return 0;
}