#include<iostream>
#include<iomanip>

#include "Parabola.h"
#include "Bisezione.h"


using namespace std;

int main(int argc,char**argv){
	double a=atof(argv[1]);
	double b=atof(argv[2]);
	double c=atof(argv[3]);
	double precision = atof(argv[4]);

	Parabola *p = new Parabola(a,b,c);
	
	Bisezione *bis = new Bisezione();
	
	//cifre significative
	int cf=-log10(precision);
	
	double zero = bis->CercaZeri(0.,0.5,p,0.001);
	double zero1 = bis->CercaZeri(-3,-1,p,0.001);

	cout<<"Ricerca degli zeri della funzione"<<endl;
	cout<<"x_1: "<<fixed<<setprecision(cf)<<zero<<endl;
	cout<<"x_2: "<<fixed<<setprecision(cf)<<zero1<<endl;


	
	delete bis;
	delete p;
	return 0;
}