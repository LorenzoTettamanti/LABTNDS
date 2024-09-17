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
/*
	TApplication app("app",0,0);
		RungeKutta rk;
		double omega0=10;
		double alpha=1./30.;
		double A=1.;
		double omega=10;
		double dumptime=10./alpha;
		OscillatoreArmonicoForzante *osc =new OscillatoreArmonicoForzante(omega0,alpha,A,omega);
		//varibiali del Passo
		double h=1.E-2;	
		double tmax = 10;
		vector <double> x {0.0,0.0};
		double t=0.0;
		//dichiarazione per plot
		TGraph *graph = new TGraph();
		int nstep = int (tmax/h+0.5);
		int step=0;
		//Risoluzione
		//h=0.1
		for (int step=0;step<nstep;step++){
			graph->SetPoint(step,t,x[0]);
			x=rk.Passo(t,x,h,osc);
			t=t+h;
		}
		//Plotting
		TCanvas *c = new TCanvas();
		//c->Divide(2,2);
		//h=0.1
		c->cd(1);
		string title = "Oscillatore armonico con forzante ";
		graph->SetTitle(title.c_str());
		graph->GetXaxis()->SetTitle("Tempo [s]");
		graph->GetYaxis()->SetTitle("Posizione x [m]");
		graph->Draw("AL");
	app.Run();
delete c;
delete graph;
delete osc;
*/

	TApplication app("app",0,0);
		RungeKutta rk;
		
		//varibiali del Passo
		double omega0=10.0;
		double alpha=1./30.;
		double A=1.;
		double dumptime =10./alpha;
		double h=1.E-2;
		int steps=60;

		//dichiarazione per plot
		TGraph *ampiezza = new TGraph();


		//Risoluzione


		//h=0.01
		for (int i=0;i<steps;i++){
			double omega = 0.9*omega0+(0.2*omega0/steps)*(i+1);
			OscillatoreArmonicoForzante *osc =new OscillatoreArmonicoForzante(omega0,alpha,A,omega);
			double t=0;
			vector <double> x {0.,0.};

			double v=0;
			unsigned int index=0;
		
		//evoluzione del sistema fino ad esaurire il transiente
			do{
					x=rk.Passo(t,x,h,osc);
					t=t+h;
			}while(t<=dumptime);
		
		//ricerca della risonanza
			while(v>=0.){
					v=x[1];
					x=rk.Passo(t,x,h,osc);
					t=t+h;
					//cout<<"tempo: "<<t<<"   "<<"v: "<< v<<endl;
			}
			//cout<<"finito"<<endl;
			ampiezza->SetPoint(i,omega,fabs(x[0]));
			delete osc;
		}

		//Plotting
		TCanvas *c = new TCanvas();
	
		//h=0.1
		c->cd(1);
		string title = "Ampiezza in funzione della forzante ";
		ampiezza->SetTitle(title.c_str());
		ampiezza->GetXaxis()->SetTitle("Pulsazione [rad/s]");
		ampiezza->GetYaxis()->SetTitle("Ampiezza [u.a.]");
		ampiezza->SetMarkerStyle(20);
		ampiezza->Draw("ALP");
	
	
	app.Run();

delete c;
delete ampiezza;

}
