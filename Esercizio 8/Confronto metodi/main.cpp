#include <iostream>
#include <cmath>
#include <iomanip>

#include "Seno.h"
#include "Integral.h"

#include "/home/runner/Lezione-8-Tettamanti164/root/include/TH1F.h"
#include "/home/runner/Lezione-8-Tettamanti164/root/include/TApplication.h"
#include "/home/runner/Lezione-8-Tettamanti164/root/include/TCanvas.h"
#include "/home/runner/Lezione-8-Tettamanti164/root/include/TGraphErrors.h"
#include "/home/runner/Lezione-8-Tettamanti164/root/include/TF1.h"
#include "/home/runner/Lezione-8-Tettamanti164/root/include/TLegend.h"
#include "/home/runner/Lezione-8-Tettamanti164/root/include/TAxis.h"

using namespace std;

int main(int argc, const char ** argv){
TApplication app ("app",0,0);

//messaggio di errore se non si immette nstep
  /*
  if (argc != 2) {
    cout << "Usage: ./main nstep"<< endl;
    return -1;
  }
  */
  double a = 0;
  double b = M_PI;

	int nstep = atoi(argv[1]);
	Seno *mysin = new Seno();
  
	Integral *integrator = new Integral(a,b,mysin);

	//metodo Midpoint
	cout<<"Risultato dell'Integrale con metodo Midpoint = " ;
	cout << setprecision(15) << integrator->Midpoint(nstep)<<endl;
	
	//Metodo Simpson
	cout<<"Risultato dell'Integrale con metodo di Simpson = " ;
	cout << setprecision(15) << integrator->Simpson(nstep)<<endl;
	
	//Metodo Trapezi
	cout<<"Risultato dell'Integrale con metodo dei Trapezi = " ;
	cout << setprecision(15) << integrator->Trapezi(nstep)<<endl;
  
	cout<<endl;

  //stima dell'errore
	double err_trapezi;
	double err_Simpson;
	double err_Midpoint;
	
	//errori
	TGraph *err_Mid = new TGraph();
	TGraph *err_Simp = new TGraph();
	TGraph *err_Trap = new TGraph();
	TCanvas *can = new TCanvas("Confronto metodi di Integrazione","Confronto metodi di Integrazione");
	double err;
		for (unsigned int i=1;i<nstep;i=i*2){
			double h = (b-a)/i;

			err_Midpoint=integrator->Midpoint(i)-2;
			err_Simpson=(4./3.)*fabs(integrator->Simpson(2*i)-integrator->Simpson(i));
			err_trapezi=(4./3.)*fabs(integrator->Trapezi(2*i)-integrator->Trapezi(i));
			
			err_Mid->SetPoint(i,h,err_Midpoint);
			err_Simp->SetPoint(i,h,err_Simpson);
			err_Trap->SetPoint(i,h,err_trapezi);
   }	

  //plotting grafico

   	err_Simp->Draw("ap1");
 	err_Simp->GetXaxis()->SetTitle("Passo h");
	err_Simp->GetYaxis()->SetTitle("errore");
	err_Simp->SetMinimum(1.E-16);
	err_Simp->SetMaximum(1);
	err_Simp->SetMarkerStyle(20);
	err_Simp->SetMarkerColor(2);
	
	can->SetLogy();
	can->SetLogx();
	can->SetGridx();
	can->SetGridy();
	
	err_Trap->Draw("p1 same");
 	err_Trap->GetXaxis()->SetTitle("Passo h");
	err_Trap->GetYaxis()->SetTitle("errore");
	err_Trap->SetMinimum(1.E-16);
	err_Trap->SetMaximum(1);
	err_Trap->SetMarkerStyle(21);
	err_Trap->SetMarkerColor(3);


	err_Mid->Draw("p1 same");
 	err_Mid->GetXaxis()->SetTitle("Passo h");
	err_Mid->GetYaxis()->SetTitle("errore");
	err_Mid->SetMinimum(1.E-16);
	err_Mid->SetMaximum(1);
	err_Mid->SetMarkerStyle(22);
	err_Mid->SetMarkerColor(1);

	TLegend *leg= new TLegend(0.1,0.7,0.3,0.9);
	leg->AddEntry(err_Mid,"Midpoint","lp");
	leg->AddEntry(err_Simp,"Simpson","lp");
	leg->AddEntry(err_Trap,"Trapezi","lp");
	leg->Draw("same");

 app.Run();
  

  delete err_Mid;
  delete err_Simp;
  delete err_Trap;
  return 0;
}
