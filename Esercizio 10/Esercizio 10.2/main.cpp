#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

#include "Seno.h"
#include "IntegralMC.h"
#include "print_buffer.h"

#include "/home/runner/Lezione-11-Tettamanti164/root/include/TH1F.h"
#include "/home/runner/Lezione-11-Tettamanti164/root/include/TApplication.h"
#include "/home/runner/Lezione-11-Tettamanti164/root/include/TCanvas.h"
#include "/home/runner/Lezione-11-Tettamanti164/root/include/TGraphErrors.h"
#include "/home/runner/Lezione-11-Tettamanti164/root/include/TF1.h"
#include "/home/runner/Lezione-11-Tettamanti164/root/include/TLegend.h"
#include "/home/runner/Lezione-11-Tettamanti164/root/include/TAxis.h"
#include "/home/runner/Lezione-11-Tettamanti164/root/include/TGraph.h"

using namespace std;

int main(int argc, const char ** argv){
	//inizializzazione printer personalizzato
	stringstream sout;

	TApplication app ("app",0,0);

		//numero di integrali calcolati
		int nmax = 10000;

		//nuemro di sample generati tra [a,b]
		int N_sample=100;
		int N_sample2=500;
		int N_sample3=1000;
		int N_sample4=5000;
		int N_sample5=10000;

		//intervallo di generazione



		//estremi di integrazione
		double a = 0;
		double b = M_PI;

		//generazione della distribuzione (Metodo Media)
		TH1F Integrale("Risultati","100 sample",100,1.6,2.4);
		TH1F Integrale2("Risultati","500 sample",100,1.8,2.2);
		TH1F Integrale3("Risultati","1000 sample",100,1.85,2.15);
		TH1F Integrale4("Risultati","5000 sample",100,1.90,2.1);
		TH1F Integrale5("Risultati","10000 sample",100,1.96,2.04);

		//generazione della distribuzione (Metodo HoM)
		TH1F IntegraleHoM ("Risultati","100 sample",100,1.2,2.8);
		TH1F Integrale2HoM("Risultati","500 sample",100,1.7,2.3);
		TH1F Integrale3HoM("Risultati","1000 sample",100,1.8,2.2);
		TH1F Integrale4HoM("Risultati","5000 sample",100,1.9,2.1);
		TH1F Integrale5HoM ("Risultati","10000 sample",100,1.93,2.06);

		TGraph gr_error;
		TGraph gr_error_HoM;
		
		//setting dell'integrale
		Seno *mysin = new Seno();
		Integral *integrator = new Integral(a,b,mysin);

		//variabili per metodo media
		
		double y;
		double y2;
		double y3;
		double y4;
		double y5;
		
		//variabili per metodo HoM
		double y1_1;
		double y2_2;
		double y3_3;
		double y4_4;
		double y5_5;
		double fmax=1.1;
		vector <double> errore;
		vector <double> erroreHoM;



		//calcolo degli integrali
		for (int i=0 ; i<nmax;i++){
			y=integrator->media(N_sample,a,b);
			y1_1= integrator->HoM(N_sample,a,b,fmax);
		//	sout << setprecision(12) << y <<endl;
		//	sout << setprecision(12) << y1_1 <<endl;
			Integrale.Fill(y);
			IntegraleHoM.Fill(y1_1);
		}
		sout<<endl;
		sout<<"risultati con N = 100 (Metodo Media) "<<endl;
		sout<< "valore: "<< Integrale.GetMean()<<endl;
		sout<< "deviazione standard: "<< Integrale.GetStdDev()<<endl;

		//sout<<endl;
		sout<<"risultati con N = 100 (Metodo HoM) "<<endl;
		sout<< "valore: "<< IntegraleHoM.GetMean()<<endl;
		sout<< "deviazione standard: "<< IntegraleHoM.GetStdDev()<<endl;
		erroreHoM.push_back(Integrale.GetStdDev());

//////////////////////////////////////////////////////////////////////////

			for (int i=0 ; i<nmax;i++){
			y2=integrator->media(N_sample2,a,b);
			y2_2=integrator->HoM(N_sample2,a,b,fmax);
		//	sout << setprecision(12) << y2 <<endl;
		//	sout << setprecision(12) << y2_2 <<endl;
			Integrale2.Fill(y2);
			Integrale2HoM.Fill(y2_2);
		}
		sout<<endl;
		sout<<endl;
		sout<<"risultati con N = 500 (Metodo Media)"<<endl;
		sout<< "valore: "<< Integrale2.GetMean()<<endl;
		sout<< "deviazione standard: "<< Integrale2.GetStdDev()<<endl;
		errore.push_back(Integrale2.GetStdDev());

		//sout<<endl;
		sout<<"risultati con N = 500 (Metodo HoM)"<<endl;
		sout<< "valore: "<< Integrale2HoM.GetMean()<<endl;
		sout<< "deviazione standard: "<< Integrale2HoM.GetStdDev()<<endl;
		erroreHoM.push_back(Integrale2HoM.GetStdDev());

///////////////////////////////////////////////////////////////////////////////


			for (int i=0 ; i<nmax;i++){
			y3=integrator->media(N_sample3,a,b);
			y3_3=integrator->HoM(N_sample3,a,b,fmax);
		//	sout << setprecision(12) << y3 <<endl;
		//	sout << setprecision(12) << y3_3 <<endl;
			Integrale3.Fill(y3);
			Integrale3HoM.Fill(y3_3);
		}
		sout<<endl;
		sout<<endl;
		sout<<"risultati con N = 1000 (Metodo Media) "<<endl;
		sout<< "valore: "<< Integrale3.GetMean()<<endl;
		sout<< "deviazione standard: "<< Integrale3.GetStdDev()<<endl;
		errore.push_back(Integrale3.GetStdDev());

		//sout<<endl;
		sout<<"risultati con N = 1000 (Metodo HoM) "<<endl;
		sout<< "valore: "<< Integrale3HoM.GetMean()<<endl;
		sout<< "deviazione standard: "<< Integrale3HoM.GetStdDev()<<endl;
		erroreHoM.push_back(Integrale3.GetStdDev());

////////////////////////////////////////////////////////////////////////////////


			for (int i=0 ; i<nmax;i++){
			y4=integrator->media(N_sample4,a,b);
			y4_4=integrator->HoM(N_sample4,a,b,fmax);
		//	sout << setprecision(12) << y4 <<endl;
		//	sout << setprecision(12) << y4_4 <<endl;
			Integrale4.Fill(y4);
			Integrale4HoM.Fill(y4_4);
		}
		sout<<endl;
		sout<<endl;
		sout<<"risultati con N = 5000 (Metodo Media) "<<endl;
		sout<< "valore: "<< Integrale4.GetMean()<<endl;
		sout<< "deviazione standard: "<< Integrale4.GetStdDev()<<endl;
		errore.push_back(Integrale4.GetStdDev());

		//sout<<endl;
		sout<<"risultati con N = 5000 (Metodo HoM) "<<endl;
		sout<< "valore: "<< Integrale4HoM.GetMean()<<endl;
		sout<< "deviazione standard: "<< Integrale4HoM.GetStdDev()<<endl;
		erroreHoM.push_back(Integrale4HoM.GetStdDev());

////////////////////////////////////////////////////////////////////////////////

			for (int i=0 ; i<nmax;i++){
			y5=integrator->media(N_sample5,a,b);
			y5_5=integrator->HoM(N_sample5,a,b,fmax);
		//	sout << setprecision(12) << y4 <<endl;
		//	sout << setprecision(12) << y5_5 <<endl;
			Integrale5.Fill(y5);
			Integrale5HoM.Fill(y5_5);
		}
		sout<<endl;
		sout<<endl;
		sout<<"risultati con N = 10000 (Metodo Media) "<<endl;
		sout<< "valore: "<< Integrale5.GetMean()<<endl;
		sout<< "deviazione standard: "<< Integrale5.GetStdDev()<<endl;
		errore.push_back(Integrale5.GetStdDev());

		//sout<<endl;
		sout<<"risultati con N = 10000 (Metodo HoM) "<<endl;
		sout<< "valore: "<< Integrale5HoM.GetMean()<<endl;
		sout<< "deviazione standard: "<< Integrale5HoM.GetStdDev()<<endl;
		erroreHoM.push_back(Integrale5HoM.GetStdDev());
//////////////////////////////////////////////////////////////////////////////

		//calcolo precisione (errore) considerando l'andamento k/sqrt(N) 
		//N = devstandard*Nsample/precisione^2
		double prec=0.001;
		int Ntest=10000;
		int M=10000;
		double standard_dev,standard_devHoM;

		TH1F *IntegraleTest = new TH1F("","10000 sample",101,0,4);
		TH1F *IntegraleTestHoM = new TH1F("","10000 sample",101,0,4);


		double ytest,ytestHoM;
		/*
		for(int i=0;i<M;i++){
				ytest=integrator->media(Ntest,a,b);
				ytestHoM=integrator->HoM(Ntest,a,b,fmax);
				IntegraleTest->Fill(ytest);
				IntegraleTestHoM->Fill(ytestHoM);
		}
		*/
		//standard_dev = IntegraleTest->GetStdDev();
		//standard_devHoM = IntegraleTestHoM->GetStdDev();
		standard_dev=Integrale5.GetStdDev();
		standard_devHoM=Integrale5HoM.GetStdDev();
		int N=(standard_dev*standard_dev*Ntest)/(pow(prec, 2));
		int NHoM=(standard_devHoM*standard_devHoM*Ntest)/(pow(prec, 2));


		sout<<endl;
		sout<<"Punti che sarebbero necessari per avere sigma = "<<prec<<"(Metodo AVE) :"<<N<<endl;
		sout<<"Punti che sarebbero necessari per avere sigma = "<<prec<<"(Metodo HoM): "<<NHoM<<endl;





//////////////////////////////////////////////////////////////////////////////		

		//plot dei risultati	(Metodo Media)
		TCanvas can2("Distribuzioni AVE","Distribuzioni AVE");
		 
		 //primo plot (100)
		can2.Divide(3,2); //divide in due colonne e due riga
		can2.cd(1);
		Integrale.GetXaxis()->SetTitle("x [AU]");
  		Integrale.GetYaxis()->SetTitle("N");
  		Integrale.Draw();

		//secondo plot (500)
		can2.cd(2);
		Integrale2.GetXaxis()->SetTitle("x [AU]");
  		Integrale2.GetYaxis()->SetTitle("N");
  		Integrale2.Draw();
		
		//terzo plot (1000)
		can2.cd(3);
		Integrale3.GetXaxis()->SetTitle("x [AU]");
  		Integrale3.GetYaxis()->SetTitle("N");
  		Integrale3.Draw();
		
		// quarto plot (5000)
		can2.cd(4);
		Integrale4.GetXaxis()->SetTitle("x [AU]");
  		Integrale4.GetYaxis()->SetTitle("N");
  		Integrale4.Draw();		

		//quinto plot (10000)
		can2.cd(5);
		Integrale5.GetXaxis()->SetTitle("x [AU]");
  		Integrale5.GetYaxis()->SetTitle("N");
  		Integrale5.Draw();		
		
		//plot dell'errore AVE

		int punti[5] ={100,500,1000,5000,10000};
		can2.cd(6);
		int k=0;
		for (auto & element : errore) {
			gr_error.SetPoint(k,punti[k],element);
  			//cout<<element<<endl;
			//sout<<"coppie di punti "<< punti[k]<<" " << element<<endl;
			k++;
		}
		gr_error.SetTitle("Valutazione dell'errore");
		gr_error.GetXaxis()->SetTitle("N");
		gr_error.GetYaxis()->SetTitle("Errore");
		gr_error.SetMarkerStyle(20);
		gr_error.Draw("ALP");




		//plot dei risultati	(Metodo HoM)
		TCanvas can3("Distribuzioni HoM","Distribuzioni Hom");
		 
		 //primo plot (100)
		can3.Divide(3,2); //divide in due colonne e due riga
		can3.cd(1);
		IntegraleHoM.GetXaxis()->SetTitle("x");
  		IntegraleHoM.GetYaxis()->SetTitle("N");
  		IntegraleHoM.Draw();

		//secondo plot (500)
		can3.cd(2);
		Integrale2HoM.GetXaxis()->SetTitle("x [AU]");
  		Integrale2HoM.GetYaxis()->SetTitle("N");
  		Integrale2HoM.Draw();
		
		//terzo plot (1000)
		can3.cd(3);
		Integrale3HoM.GetXaxis()->SetTitle("x [AU]");
  		Integrale3HoM.GetYaxis()->SetTitle("N");
  		Integrale3HoM.Draw();
		
		// quarto plot (5000)
		can3.cd(4);
		Integrale4HoM.GetXaxis()->SetTitle("x [AU]");
  		Integrale4HoM.GetYaxis()->SetTitle("N");
  		Integrale4HoM.Draw();		

		//quinto plot (10000)
		can3.cd(5);
		Integrale5HoM.GetXaxis()->SetTitle("x [AU]");
  		Integrale5HoM.GetYaxis()->SetTitle("N");
  		Integrale5HoM.Draw();		
		
		//plot dell'errore HoM

		int punti2[5] ={100,500,1000,5000,10000};
		can3.cd(6);
		int q=0;
		for (auto & element : erroreHoM) {
			gr_error_HoM.SetPoint(q,punti2[q],element);
  			//cout<<element<<endl;
			//sout<<"coppie di punti "<< punti[k]<<" " << element<<endl;
			q++;
		}
		gr_error_HoM.SetTitle("Valutazione dell'errore");
		gr_error_HoM.GetXaxis()->SetTitle("N");
		gr_error_HoM.GetYaxis()->SetTitle("Errore");
		gr_error_HoM.SetMarkerStyle(20);
		gr_error_HoM.Draw("ALP");






	//can->SetLogy();
	//can->SetLogx();



	//salvo i dati 
	print_and_clear_buffer(sout);
	
	
	app.Run();
  
delete mysin;
delete integrator;
delete IntegraleTest;
delete IntegraleTestHoM;
return 0;
}
