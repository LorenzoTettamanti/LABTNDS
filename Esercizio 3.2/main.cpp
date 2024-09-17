#include <iostream>
#include <fstream>
#include "root/include/TH1F.h"
#include "root/include/TApplication.h"
#include "root/include/TCanvas.h"

#include "funzioni.h"

int main( int argc , char** argv ) {

 if ( argc < 3 ) {
    cout << "Uso del programma : " << argv[0] << " <n_data> <filename> " << endl;
    return -1 ;
  }
  
  int ndata = atoi(argv[1]);

  char * filename = argv[2];


  // creo un processo "app" che lascia il programma attivo ( app.Run() ) in modo
  // da permettermi di vedere gli outputs grafici

  TApplication app("app",0,0);
  
  // leggo dati da file
  vector <double> v = Read<double>(ndata,filename);

  // creo e riempio il vettore. L'opzione StatOvergflows permetter di calcolalare
  // le informazioni statistiche anche se il dato sta fuori dal range di definizione
  // dell'istogramma
  
  TH1F histo ("histo","histo", 100, -10, 100) ;
  histo.StatOverflows( kTRUE );
  for ( int k = 0 ; k < v.size() ; k++ ) histo.Fill( v[k] );
  
  // accedo a informazioni statistiche 

  cout << "Media dei valori caricati = " << histo.GetMean() << endl;

  // disegno

  TCanvas mycanvas ("Histo","Histo");
  histo.Draw();
  histo.GetXaxis()->SetTitle("measurement");
  histo.GetYaxis()->SetTitle("N");

 app.Run();
  
}
