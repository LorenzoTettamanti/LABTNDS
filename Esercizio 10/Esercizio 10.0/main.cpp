#include <iostream>

#include "/home/runner/Lezione-11-Tettamanti164/root/include/TApplication.h"
#include "/home/runner/Lezione-11-Tettamanti164/root/include/TCanvas.h"
#include "/home/runner/Lezione-11-Tettamanti164/root/include/TH1F.h"
#include "/home/runner/Lezione-11-Tettamanti164/root/include/TAxis.h"



#include "RandomGen.h"
#include <algorithm>
#include <vector>
int main() {
  
   	TApplication app("app",0,0);

   		RandomGen mygen(1);

   		int nmax = 10000;

		//dichiarazione delle distrubuzioni 
		TH1F unif ("Distribuzione uniforme","Distribuzione uniforme",100,4,11);
		TH1F exp ("Distribuzione Esponenziale","Distribuzione Esponenziale",100,1,6);
		TH1F boxmuller ("Distribuzione BoxMuller","Distribuzione BoxMuller",100,-3,5);
		TH1F AR ("Distribuzione Accept-Reject","Distribuzione Accept-Reject",100,-3,5);

		//generazione delle distribuzioni

		//Distribuzioni
		for (int k=0;k<nmax;k++){
    		unif.Fill(mygen.Unif(5,10)); 
			 boxmuller.Fill(mygen.BoxMuller(1.0,1.0)); 
			 exp.Fill(mygen.Exp(1)); 
			 AR.Fill(mygen.AcceptReject(1.,1.)); 
  		 }

	

		//Plotting
		
 		TCanvas *can = new TCanvas("Distribuzioni","Distribuzioni");
		 
		 //primo plot (Uniforme)
		can->Divide(2,2); //divide in due colonne e due riga
		can->cd(1);
		unif.GetXaxis()->SetTitle("x [AU]");
  		unif.GetYaxis()->SetTitle("N");
  		unif.Draw();

		//secondo plot (Boxmuller)
		can->cd(2);
		boxmuller.GetXaxis()->SetTitle("x [AU]");
  		boxmuller.GetYaxis()->SetTitle("N");
  		boxmuller.Draw();
		
		//terzo plot (Esponenziale)
		can->cd(3);
		exp.GetXaxis()->SetTitle("x [AU]");
  		exp.GetYaxis()->SetTitle("N");
  		exp.Draw();
		
		// quarto plot (Accept-Reject)
		can->cd(4);
		AR.GetXaxis()->SetTitle("x [AU]");
  		AR.GetYaxis()->SetTitle("N");
  		AR.Draw();		


   	app.Run();
delete can;
	
return 0;
}