#include <iostream>
#include <cstdlib>

#include "PuntoMateriale.h"
#include "CampoVettoriale.h"


#include "../Dipolo(Esercizio5.3)/root/include/TApplication.h"
#include "../Dipolo(Esercizio5.3)/root/include/TCanvas.h"
#include "../Dipolo(Esercizio5.3)/root/include/TGraph.h"
#include "../Dipolo(Esercizio5.3)/root/include/TAxis.h"
#include "../Dipolo(Esercizio5.3)/root/include/TF1.h"


using namespace std;



int main(int argc, char**argv){
	
	TApplication app("app",0,0);

	double x=atof(argv[1]);
	double y=atof(argv[2]);
	double z=atof(argv[3]);
	
	const double e = 1.60E-19;
	const double me = 9.10E-31;
	const double mp = 1.67E-27;
	const double d = 10E-10;


	Posizione r(x,y,z);
	Posizione r1(d*100,d*100,d*100);



	//creazione delle particelle
	PuntoMateriale elettrone(me,-e,0.0,0.0,d/2);
	PuntoMateriale protone(me,e,0.0,0.0,-d/2);

	//calcolo del campo generato dal Dipolo
	CampoVettoriale E1 = elettrone.CampoElettrico(r)+protone.CampoElettrico(r);
	CampoVettoriale E2 = elettrone.CampoElettrico(r1)+protone.CampoElettrico(r1);


	//print di check
	cout<<"E1 =("<<E1.getFx()<<","<<E1.getFy()<<","<<E1.getFz()<<" "<<")"<<endl;
	cout<<"E2 =("<<E2.getFx()<<","<<E2.getFy()<<","<<E2.getFz()<<" "<<")"<<endl;
	cout<<"Modulo di E1 = "<<E1.Modulo()<<endl;
	cout<<"Modulo di E2 = "<<E2.Modulo()<<endl;

	//calcolo alpha
	double alpha = log(E1.Modulo()/E2.Modulo())/log(d/1000*d);
	
	//check
	cout<<"valore di alpha = "<<alpha<<endl;
	
	const double k=9*10E+9;  

	TCanvas c("Dipolo","Dipolo");
	//grafico con relazione di potenza
	TF1 myfun( "function","[0]*pow(x,[1])");
	myfun.SetParameter(0,k);
	myfun.SetParameter(1, alpha);
	myfun.SetTitle("Dipolo");
	myfun.GetXaxis()->SetTitle("distanza [m] ");
	myfun.GetYaxis()->SetTitle("Intensita' ");
	myfun.Draw();




	app.Run();
	return 0;
}

