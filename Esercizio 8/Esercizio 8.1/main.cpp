#include <iostream>
#include <cmath>
#include <iomanip>
#include<sstream>

#include "Seno.h"
#include "Simpson.h"

#include "printbuffer.h"

#include "/home/runner/Lezione-8-Tettamanti164/root/include/TH1F.h"
#include "/home/runner/Lezione-8-Tettamanti164/root/include/TApplication.h"
#include "/home/runner/Lezione-8-Tettamanti164/root/include/TCanvas.h"
#include "/home/runner/Lezione-8-Tettamanti164/root/include/TGraph.h"
#include "/home/runner/Lezione-8-Tettamanti164/root/include/TF1.h"
#include "/home/runner/Lezione-8-Tettamanti164/root/include/TLegend.h"
#include "/home/runner/Lezione-8-Tettamanti164/root/include/TAxis.h"

using namespace std;

int main (int argc,char** argv){
	
	stringstream sout;
	
	TApplication app ("app",0,0);


		if (argc != 2) {
   	 		cout << "Usage: ./main nstep"<< endl;
   			 return -1;
 		 }


		double a = 0;
		double b = M_PI;

		int nstep = atoi(argv[1]);

		Seno* mysin = new Seno();
		Integral *integrator = new Integral(a,b,mysin);

		cout <<std::fixed <<setprecision(12) << integrator->Simpson(nstep) <<endl;

	TGraph *graph = new TGraph();
	 TCanvas *can = new TCanvas("Integrazione con metodo di Simpson","Integrazione con metodo di Simpson");
	double err;
		for (unsigned int i=1;i<nstep;i=i*2){
			double h = (b-a)/i;
			err=(4./3.)*fabs(integrator->Simpson(2*i)-integrator->Simpson(i));
			sout<<err<<endl;
			graph->SetPoint(i,h,err);
   }	

   	graph->Draw("AP");
 	graph->GetXaxis()->SetTitle("Passo h");
	graph->GetYaxis()->SetTitle("errore");
	graph->SetMinimum(1.E-16);
	graph->SetMaximum(1);
	graph->SetMarkerStyle(20);


	can->SetLogy();
	can->SetLogx();
	can->SetGridx();
	can->SetGridy();



print_and_clear_buffer(sout);
  app.Run();


  delete graph;
	return 0;
}