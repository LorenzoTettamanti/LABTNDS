#include <iostream>
#include <cmath>
#include <iomanip>

#include "Seno.h"
#include "Integral.h"
#include "print_buffer.h"

#include "/home/runner/Lezione-8-Tettamanti164/root/include/TH1F.h"
#include "/home/runner/Lezione-8-Tettamanti164/root/include/TApplication.h"
#include "/home/runner/Lezione-8-Tettamanti164/root/include/TCanvas.h"
#include "/home/runner/Lezione-8-Tettamanti164/root/include/TGraph.h"
#include "/home/runner/Lezione-8-Tettamanti164/root/include/TF1.h"
#include "/home/runner/Lezione-8-Tettamanti164/root/include/TLegend.h"
#include "/home/runner/Lezione-8-Tettamanti164/root/include/TAxis.h"

using namespace std;

int main(int argc, const char ** argv){

	stringstream sout;
	TApplication app ("app",0,0);
	/*
		if (argc != 2) {
			cout << "Usage: ./main nstep"<< endl;	
			return -1;
		}
		*/

	//estremi di integrazione
	double a = 0;
	double b = M_PI;

	 // int nstep = atoi(argv[1]);
	 //passi di integrazione
	 int nstep1 = 10; 
	 int nstep2 = 100; 
	 int nstep3 = 500; 
	 int nstep4 = 1000; 
	 int nstep5 = 10000; 
	

	//errori integrazione
	double errore1;
	double errore2;
	double errore3;
	double errore4;
	double errore5;

	//valore vero
	double ris=2;

	//funzione
	Seno *mysin = new Seno();

	//metodo
 	Integral *integrator = new Integral(a,b,mysin);
	
	
	//risultati
	sout<<"Risultato con precisione N = 10 "<<endl;
	sout << std::fixed<<setprecision(12) << integrator->Midpoint(nstep1) <<endl;
	errore1 = integrator->Midpoint(nstep1)-ris;
	sout<< "Differenza con valore noto: "<<errore1<<endl;
	sout<<endl;

	sout<<"Risultato con precisione N = 100 "<<endl;
	sout << std::fixed<<setprecision(12) << integrator->Midpoint(nstep2) <<endl;
	errore2 = integrator->Midpoint(nstep2)-ris;
	sout<< "Differenza con valore noto: "<<errore2<<endl;
	sout<<endl;

	sout<<"Risultato con precisione N = 500 "<<endl;
	sout << std::fixed <<setprecision(12) << integrator->Midpoint(nstep3) <<endl;
	errore3 = integrator->Midpoint(nstep3)-ris;
	sout<< "Differenza con valore noto: "<<errore3<<endl;
	sout<<endl;

	sout<<"Risultato con precisione N = 1000 "<<endl;
	sout << std::fixed<<setprecision(12) << integrator->Midpoint(nstep4) <<endl;
	errore4 = integrator->Midpoint(nstep4)-ris;
	sout<< "Differenza con valore noto: "<<errore4<<endl;
	sout<<endl;


	sout<<"Risultato con precisione N = 10000"<<endl;
	sout << setprecision(12) << integrator->Midpoint(nstep5) <<endl;
	errore5 = integrator->Midpoint(nstep5)-ris;
	sout<< "Differenza con valore noto: "<<errore5<<endl;
	sout<<endl;


  //plotting grafico
	double x[5] ={10,100,500,1000,10000};
	double y[5] ={errore1,errore2,errore3,errore4,errore5};

	TCanvas *can = new TCanvas("Distribuzioni","Distribuzioni");
	TGraph *graph = new TGraph();
	for(int i=0;i<5;i++){
		graph->SetPoint(i,x[i],y[i]);
	}
	graph->Draw();
	
	can->SetLogy();
	can->SetLogx();


	print_and_clear_buffer(sout);
  app.Run();
  
  
delete graph;
delete mysin;
delete integrator;  
return 0;
}
