#include <iostream>
#include <string>
#include <cmath>

#include "/home/runner/Lezione-9-Tettamanti164/root/include/TApplication.h"
#include "/home/runner/Lezione-9-Tettamanti164/root/include/TAxis.h"
#include "/home/runner/Lezione-9-Tettamanti164/root/include/TCanvas.h"
#include "/home/runner/Lezione-9-Tettamanti164/root/include/TGraph.h"


#include "EquazioniDifferenziali.h"


int main(int argc, const char *argv[]) {
	//test preliminari
 	//test_euler();
	//test_runge_kutta();

/*
	if (argc!=2){
		cerr<<"Usage: "<<argv[0]<<"<stepsize>"<<endl;
		return -1;
	}
*/

	TApplication app("app",0,0);
		RungeKutta rk;


		PendoloReale *osc =new PendoloReale(1.);
		
		//varibiali del Passo
		double h=1.E-3;
		int nsteps=30;
		
		//dichiarazione per plot
		TGraph *periodo = new TGraph();
		TGraph *differenza = new TGraph();

		//Risoluzione


		//cout<<"Periodo teorico: "<<setprecision(4)<<(2*M_PI)*sqrt(1/9.81)<<endl;

		for (int i=0;i<nsteps;i++){
		double T;
			double A=0.1*(i+1);
			double v = 0.;
			double t = 0.;
			vector <double> x {-A,v};
			
				while(v>=0.){
					v=x[1];
					x=rk.Passo(t,x,h,osc);
					t=t+h;
				}
			//cout<<"x " <<x[0]<<" " <<"v "<<v<<endl;	

			T = t-abs(v*h/(x[1]-v));
			//T= ((t)/(h)*v)+((-t+h)/(h)*x[1]);
			cout<<"periodo "<<2*T<<endl;
			//cout<<2*T<<endl;	//calcolo del semiperiodo
			periodo->SetPoint(i,A,2*T);
			
		}

		cout<<"test finito"<<endl;
	
		//Plotting
		TCanvas *c = new TCanvas();

		string title = "Periodo in funzione di A";
		periodo->SetTitle(title.c_str());
		periodo->GetXaxis()->SetTitle("Ampiezza [rad]");
		periodo->GetYaxis()->SetTitle("Periodo [s]");
		periodo->SetMarkerStyle(20);
		periodo->Draw("AP");

		c->SetGridx();
		c->SetGridy();


	
	app.Run();

delete c;
delete periodo;
delete differenza;
delete osc;
}
