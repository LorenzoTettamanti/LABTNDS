#include <iostream>

#include "/home/runner/Lezione-11-1-Tettamanti164/root/include/TApplication.h"
#include "/home/runner/Lezione-11-1-Tettamanti164/root/include/TH1F.h"
#include "/home/runner/Lezione-11-1-Tettamanti164/root/include/TH2F.h"
#include "/home/runner/Lezione-11-1-Tettamanti164/root/include/TH2C.h"
#include "/home/runner/Lezione-11-1-Tettamanti164/root/include/TCanvas.h"
#include "/home/runner/Lezione-11-1-Tettamanti164/root/include/TLatex.h"
#include "/home/runner/Lezione-11-1-Tettamanti164/root/include/TAxis.h"

#include "EsperimentoPrisma.h"
#include "print_buffer.h"
#include "Variables.h"


int main(int argc,char** argv) {
TApplication app ("app",0,0);
	
	unsigned int nsimul = 10000;
	
	EsperimentoPrisma p;

	stringstream sout;


	//istogrammi
	
	TH1F thetha0 ("Risultati","thetha_0",100,1.5695,1.5718);
	TH1F thetha1 ("Risultati","thetha_1",100,2.6555,2.6578);
	TH1F thetha2 ("Risultati","thetha_2",100,2.6555,2.6578);
	TH1F dm1 ("Risultati","dm1",100, 0.97710, 0.97985);
	TH1F dm2 ("Risultati","dm2",100,1.0840,1.0875);
	TH1F n1 ("Risultati","N1",100,1.6955,1.6980);
	TH1F n2("Risultati","N2",100,1.7503,1.75180);
	TH1F A ("Risultati","A",100,2.6950,2.7050);
	TH1F B ("Risultati","B",100,58950,60950);
	

	//TH2F per indice di correlazione e residui
	TH2F residuo_dm ("Risultati","Correlazione deviazione minima ",10000,-0.002,0.002,10000,-0.002,0.002);
	TH2F i_c_indici("Risultati","Correlazione indici di rifrazione ",10000,-0.001,0.001,10000,-0.001,0.001);
	TH2F i_c_parametri ("Risultati","Correlazione parametri",10000,-0.005,0.005,10000,-1E-15,1E-15);

			double scale = 1.0E18;

			//inizio simulazione
			for (int i =0; i<nsimul;i++){
			p.Esegui();
			cout<<endl;
			//angoli
			thetha0.Fill(p.getth0mis());
			thetha1.Fill(p.getth1mis());
			thetha2.Fill(p.getth2mis());

			//deviazione minima
			dm1.Fill(p.getdm1());
			dm2.Fill(p.getdm2());
					//coefficiente di correlazione con deviazione minima tra x e y
					sumxy_m+=(p.getdm1()-dm1.GetMean())*(p.getdm2()-dm2.GetMean());

					sumx_m+=pow((p.getdm1()-dm1.GetMean()),2);
				
					sumy_m+=pow((p.getdm2()-dm2.GetMean()),2);
				
	
			//indici di rifrazione
		
			n1.Fill(p.getn1mis());
			n2.Fill(p.getn2mis());
			i_c_indici.Fill(p.getn1mis(),p.getn2mis());

			//correlazione tra n1 n2
					sumxy_m_n+=(p.getn1mis()-n1.GetMean())*(p.getn2mis()-n2.GetMean());

					sumx_m_n+=pow((p.getn1mis()-n1.GetMean()),2);
				
					sumy_m_n+=pow((p.getn2mis()-n2.GetMean()),2);
				

			//parametri finali
			A.Fill(p.getAmis());
			B.Fill(scale*p.getBmis());

					sumxy_AB+=(p.getAmis()-A.GetMean())*(scale*p.getBmis()-B.GetMean());

					sumx_m_AB+=pow((p.getAmis()-A.GetMean()),2);
				
					sumy_m_AB+=pow((scale*p.getBmis()-B.GetMean()),2);

			//coefficiente di correlazione tra parametri AB

			//residui
			p.Analizza();

			//grafici TH2F
			residuo_dm.Fill(p.getdmresiduo1(),p.getdmresiduo2());
			//sout<<p.getdm2()<<endl;
			i_c_indici.Fill(p.getn1residuo(),p.getn2residuo());
			i_c_parametri.Fill(p.getAresiduo(),p.getBresiduo());

		}
	
		//calcolo del coefficiente di correlazione tra deviazione minima
		rho=(sumxy_m)/(sqrt(sumx_m*sumy_m));
		rho_n=(sumxy_m_n)/(sqrt(sumx_m_n*sumy_m_n));
		rho_AB =(sumxy_AB)/(sqrt(sumx_m_AB*sumy_m_AB));


	//plotting 
	TCanvas can1 ("Risultati finali","Generazione angoli iniziali");
	TCanvas can2 ("Risultati finali2","Indici N +residuo");
	TCanvas can3 ("Risultati finali3","parametri A e B +residuo");
	TCanvas can4 ("Risultati finali4","controllo dm1 e dm2 + residuo");

	//divisione dei canvas
	can1.Divide(3,1);
	can2.Divide(3,1);
	can3.Divide(3,1); //divide in due colonne e due riga
	can4.Divide(3,1);


		//controllo generazione dm1 e dm2

		//controllo angoli iniziali
		
		sout<<"Risultati finali : "<<endl;
		sout<<endl;
		sout<<"Angoli"<<endl;
		//controllo angoli generati
		can1.cd(1);
		thetha0.StatOverflows( kTRUE );
		sout<<"\u03B80: "<<std::fixed<<setprecision(4)<<thetha0.GetMean()<<endl;
		sout<<"\u03C3: "<<std::fixed<<setprecision(4)<<thetha0.GetStdDev()<<endl;
		thetha0.GetXaxis()->SetTitle("thetha_0");
		thetha0.GetYaxis()->SetTitle("N[AU]");
		thetha0.Draw();
		sout<<endl;

		can1.cd(2);
		thetha1.StatOverflows( kTRUE );
		sout<<"\u03B81: "<<std::fixed<<setprecision(4)<<thetha1.GetMean()<<endl;
		sout<<"\u03C3: "<<std::fixed<<setprecision(4)<<thetha1.GetStdDev()<<endl;
		thetha1.GetXaxis()->SetTitle("thetha_1");
		thetha1.GetYaxis()->SetTitle("N[AU]");
		thetha1.Draw();
		sout<<endl;

		can1.cd(3);
		thetha2.StatOverflows( kTRUE );
		sout<<"\u03B82: "<<std::fixed<<setprecision(4)<<thetha2.GetMean()<<endl;
		sout<<"\u03C3: "<<std::fixed<<setprecision(4)<<thetha2.GetStdDev()<<endl;
		thetha2.GetXaxis()->SetTitle("\thetha_2");
		thetha2.GetYaxis()->SetTitle("N[AU]");
		thetha2.Draw();
		sout<<endl;
		sout<<endl;


		
		//controllo dm1 dm2 
		sout<<"Angoli di deviazione minima:"<<endl;
		can4.cd(1);
		dm1.StatOverflows( kTRUE );
		sout<<"dm1: "<<std::fixed<<setprecision(5)<<dm1.GetMean()<<endl;
		sout<<"\u03C3: "<<std::fixed<<setprecision(5)<<dm1.GetStdDev()<<endl;
		sout<<"Differenza dal valore reale: "<<std::fixed<<setprecision(5)<<p.getdmresiduo1()<<endl;
		dm1.GetXaxis()->SetTitle("dm1");
		dm1.GetYaxis()->SetTitle("N[AU]");
		dm1.Draw();
		sout<<endl;

		can4.cd(2);
		dm2.StatOverflows( kTRUE );
		sout<<"dm2: "<<std::fixed<<setprecision(5)<<dm2.GetMean()<<endl;
		sout<<"\u03C3: "<<std::fixed<<setprecision(5)<<dm2.GetStdDev()<<endl;
		sout<<"Differenza dal valore reale: "<<std::fixed<<setprecision(5)<<p.getdmresiduo2()<<endl;
		dm2.GetXaxis()->SetTitle("dm2");
		dm2.GetYaxis()->SetTitle("N[AU]");
		dm2.Draw();
	
		can4.cd(3);
		residuo_dm.StatOverflows( kTRUE );
		residuo_dm.GetXaxis()->SetTitle("errore dm1");
		residuo_dm.GetYaxis()->SetTitle("errore dm2");
		residuo_dm.Draw();
		sout<<"coefficiente di correlazione dm1 e dm2: "<<std::fixed<<setprecision(0)<<rho*100<<"%"<<endl;
		sout<<endl;
		sout<<endl;

		//controllo indici di rifrazione N1/N2
		sout<<"Indici di rifrazione:"<<endl;
		can2.cd(1);
		n1.StatOverflows( kTRUE );
		sout<<"N1: "<<std::fixed<<setprecision(5)<<n1.GetMean()<<endl;
		sout<<"\u03C3: "<<std::fixed<<setprecision(5)<<n1.GetStdDev()<<endl;
		sout<<"Differenza dal valore reale: "<<std::fixed<<setprecision(5)<<p.getn1residuo()<<endl;
		n1.GetXaxis()->SetTitle("n1");
		n1.GetYaxis()->SetTitle("N[AU]");
		n1.Draw();
		sout<<endl;

		can2.cd(2);
		n2.StatOverflows( kTRUE );
		sout<<"N2: "<<std::fixed<<setprecision(5)<<n2.GetMean()<<endl;
		sout<<"\u03C3: "<<std::fixed<<setprecision(5)<<n2.GetStdDev()<<endl;
		sout<<"Differenza dal valore reale: "<<std::fixed<<setprecision(5)<<p.getn2residuo()<<endl;
		n2.GetXaxis()->SetTitle("n2");
		n2.GetYaxis()->SetTitle("N[AU]");
		n2.Draw();

	
		sout<<std::fixed<<setprecision(0)<<"coefficiente di correlazione N1 e N2: "<<rho_n*100<<"%"<<endl;
		sout<<endl;
		sout<<endl;
		
		can2.cd(3);
		i_c_indici.StatOverflows( kTRUE );
		i_c_indici.GetXaxis()->SetTitle("errore n1");
		i_c_indici.GetYaxis()->SetTitle("errore n2");
		i_c_indici.Draw();
		


		//controllo parametri A/B
		sout<<"Parametri A/B:"<<endl;
		can3.cd(1);
		A.StatOverflows( kTRUE );
		sout<<"A: "<<std::fixed<<setprecision(5)<<A.GetMean()<<endl;
		sout<<"\u03C3: "<<std::fixed<<setprecision(5)<<A.GetStdDev()<<endl;
		A.GetXaxis()->SetTitle("A");
		B.GetYaxis()->SetTitle("N[AU]");
		A.Draw();
		sout<<endl;

		can3.cd(2);
		B.StatOverflows( kTRUE );
		sout<<"B: "<<std::fixed<<setprecision(0)<<B.GetMean()<<endl;
		sout<<"\u03C3: "<<std::fixed<<setprecision(0)<<B.GetStdDev()<<endl;
		B.GetXaxis()->SetTitle("B");
		B.GetYaxis()->SetTitle("N[AU]");
		B.Draw();


		sout<<"coefficiente di correlazione A e B: "<<std::fixed<<setprecision(0)<<rho_AB*100<<"%"<<endl;
		
		sout<<endl;
		sout<<endl;;


		can3.cd(3);
		i_c_parametri.StatOverflows( kTRUE );
		i_c_parametri.GetXaxis()->SetTitle("errore A");
		i_c_parametri.GetYaxis()->SetTitle("errore B");
		i_c_parametri.Draw();
		sout<<endl;

print_and_clear_buffer(sout);


app.Run();


}