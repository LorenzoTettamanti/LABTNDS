#include <iostream>
#include <string>

#include "/home/runner/Lezione-9-Tettamanti164/root/include/TApplication.h"
#include "/home/runner/Lezione-9-Tettamanti164/root/include/TAxis.h"
#include "/home/runner/Lezione-9-Tettamanti164/root/include/TCanvas.h"
#include "/home/runner/Lezione-9-Tettamanti164/root/include/TGraph.h"


#include "EquazioniDifferenziali.h"
#include "print_buffer.h"

using namespace std;
int main(int argc, char** argv) {
	
/*
	if (argc!=2){
		cerr<<"Usage: "<<argv[0]<<"<stepsize>"<<endl;
		return -1;
	}
*/
	TApplication app("app",0,0);
	
		Eulero myeuler;
		OscillatoreArmonico *osc =new OscillatoreArmonico(1.);
		stringstream sout;
	/*	
		//varibiali del Passo
		double h=0.1;
		double h2=0.01;
		double h3=0.001;
		double h4=0.0001;
	
		double tmax = 70.;
		double tmax2 = 70.;
		double tmax3 = 70.;
		double tmax4 = 70.;

		vector <double> x {0.0,1.0};
		
		
		double t=0.0;
		double t2=0.0;
		double t3=0.0;
		double t4=0.0;
		
		//dichiarazione per plot
		TGraph *graph = new TGraph();
		TGraph *graph2 = new TGraph();
		TGraph *graph3 = new TGraph();
		TGraph *graph4 = new TGraph();


		int nstep = int (tmax/h+0.5);
		int nstep2 = int (tmax2/h2+0.5);
		int nstep3 = int (tmax3/h3+0.5);
		int nstep4 = int (tmax4/h4+0.5);

		int step=0;

		//Risoluzione
		//h=0.1
		for (int step=0;step<nstep;step++){
			graph->SetPoint(step,t,x[0]);
			x=myeuler.Passo(t,x,h,osc);
			t=t+h;
		}

		//h=0.01
		for (int step=0;step<nstep2;step++){
			graph2->SetPoint(step,t2,x[0]);
			x=myeuler.Passo(t2,x,h2,osc);
			t2=t2+h2;
		}

		//h=0.001
		for (int step=0;step<nstep3;step++){
			graph3->SetPoint(step,t3,x[0]);
			x=myeuler.Passo(t3,x,h3,osc);
			t3=t3+h3;
		}

		//h=0.0001
		for (int step=0;step<nstep4;step++){
			graph4->SetPoint(step,t4,x[0]);
			x=myeuler.Passo(t4,x,h4,osc);
			t4=t4+h4;
		}



		//Plotting
		TCanvas *c = new TCanvas();
		c->Divide(2,2);


		//h=0.1
		c->cd(1);
		string title = "Oscillatore armonico h=0.1";
		graph->SetTitle(title.c_str());
		graph->GetXaxis()->SetTitle("Tempo [s]");
		graph->GetYaxis()->SetTitle("Posizione x [m]");
		graph->Draw("AL");


		//h=0.01
		c->cd(2);
		string title2 = "Oscillatore armonico h=0.01";
		graph2->SetTitle(title2.c_str());
		graph2->GetXaxis()->SetTitle("Tempo [s]");
		graph2->GetYaxis()->SetTitle("Posizione x [m]");
		graph2->Draw("AL");


		//h=0.001
		c->cd(3);
		string title3 = "Oscillatore armonico h=0.001";
		graph3->SetTitle(title3.c_str());
		graph3->GetXaxis()->SetTitle("Tempo [s]");
		graph3->GetYaxis()->SetTitle("Posizione x [m]");
		graph3->Draw("AL");


		c->cd(4);
		string title4 = "Oscillatore armonico h=0.0001";
		graph4->SetTitle(title4.c_str());
		graph4->GetXaxis()->SetTitle("Tempo [s]");
		graph4->GetYaxis()->SetTitle("Posizione x [m]");
		graph4->Draw("AL");

*/
TGraph *errore_eulero = new TGraph();
double tmax=70.;
for(int i=0;i<10;i++){
				double h = 0.1*pow(0.5,i);
				vector <double> x {0.,1.};
				
				double t=0.;
				int nstep = int(tmax/h+0.5);

					for(int step=0;step<nstep;step++){
							x=myeuler.Passo( t,x,h,osc);
							t=t+h;
					}
					double eps = fabs(x[0]-sin(t));
					sout<<eps<<endl;
					errore_eulero->SetPoint(i,h,eps);
			}
		print_and_clear_buffer(sout);

TCanvas *c = new TCanvas();
	string title1 = "Errore metodo di eulero";
		errore_eulero->SetTitle(title1.c_str());
		errore_eulero->GetXaxis()->SetTitle("Passo");
		errore_eulero->GetYaxis()->SetTitle("Errore");
		
		errore_eulero->SetMinimum(1.E-12);
		errore_eulero->SetMaximum(20);
		errore_eulero->SetMarkerStyle(20);

		errore_eulero->Draw("ALP");
		c->SetLogx();
		c->SetLogy();
		c->SetGridx();
		c->SetGridy();

	app.Run();

delete c;
//delete graph;
//delete graph2;
//delete graph3;
//delete graph4;
//delete osc;

}
