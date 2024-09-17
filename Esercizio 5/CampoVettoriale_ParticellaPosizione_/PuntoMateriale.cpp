#include<iostream>
#include<cstdlib>

#include "PuntoMateriale.h"
#include "CampoVettoriale.h"


using namespace std;

int main(int argc, char**argv){
	
	double x=1;
	double y=1;
	double z=1;
	
	Posizione r(x,y,z);
	const double e = 1.60E-19;
	const double me = 9.10E-31;
	const double mp = 1.67E-27;
	const double d = 1.E-10;


	//creazione delle particelle
	PuntoMateriale elettrone(me,-e,0.0,0.0,d/2);
	PuntoMateriale protone(me,e,0.0,0.0,-d/2);

	
	CampoVettoriale E = elettrone.CampoElettrico(r)+protone.CampoElettrico(r);
	
	cout<<"E =("<<E.getFx()<<","<<E.getFy()<<","<<E.getFz()<<" "<<")"<<endl;
	return 0;
}