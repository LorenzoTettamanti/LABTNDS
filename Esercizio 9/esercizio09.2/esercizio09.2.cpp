#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

#include "/home/runner/Lezione-9-Tettamanti164/root/include/TApplication.h"
#include "/home/runner/Lezione-9-Tettamanti164/root/include/TAxis.h"
#include "/home/runner/Lezione-9-Tettamanti164/root/include/TCanvas.h"
#include "/home/runner/Lezione-9-Tettamanti164/root/include/TGraph.h"
#include "/home/runner/Lezione-9-Tettamanti164/root/include/TLegend.h"


#include "EquazioniDifferenziali.h"

int main(int argc, const char *argv[]) {
	//test preliminari
 	test_euler();
	test_runge_kutta();



	TApplication app("app",0,0);
		RungeKutta rk;
		Eulero myeuler;
	
		OscillatoreArmonico *osc =new OscillatoreArmonico(1.);
		
		double tmax=70.;
	
		
		//dichiarazione per plot
		TGraph *errore_RK = new TGraph();
		TGraph *errore_eulero = new TGraph();
		

		//errore metodo RK
			for(int i=0;i<10;i++){
				double h = 0.1*pow(0.5,i);
				vector <double> x {0.,1.};
				
				double t=0.;
				int nstep = int(tmax/h+0.5);

					for(int step=0;step<nstep;step++){
							x=rk.Passo( t,x,h,osc);
							t=t+h;
					}
					double eps = fabs(x[0]-sin(t));
					errore_RK->SetPoint(i,h,eps);
			}
			fstream input;
 			input.open("err_euler.dat",ios::in);
			if(!input){
				cerr<<"File non presente"<<endl;
			}
			double err_eulero;
			for(int i=0;i<10;i++){
				double h = 0.1*pow(0.5,i);
				input>>err_eulero;
				errore_eulero->SetPoint(i,h,err_eulero);
			}

		
		
		//Plotting
		TCanvas *c = new TCanvas();

		//h=0.1

		//errore metodo di RK
		string title1 = "Confronto Metodo Eulero e Runge-Kutta";
		errore_RK->SetTitle(title1.c_str());
		errore_RK->GetXaxis()->SetTitle("Passo h");
		errore_RK->GetYaxis()->SetTitle("Errore ");
		errore_RK->SetMarkerStyle(21);
		errore_RK->SetMinimum(1E-12);
		errore_RK->SetMaximum(200);
		errore_RK->Draw("ALP");

		
		errore_eulero->SetMarkerStyle(20);
		
		errore_eulero->Draw("sameLP");

		c->SetLogx();
		c->SetLogy();
		c->SetGridx();
		c->SetGridy();

		TLegend *leg= new TLegend(0.1,0.7,0.3,0.9);
		leg->AddEntry(errore_RK,"Runge-Kutta","lp");
		leg->AddEntry(errore_eulero,"Eulero","lp");
		leg->Draw("same");


		
	app.Run();

delete c;
delete errore_RK;
delete osc;
}
