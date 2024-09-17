#include<cmath>
#include <iostream>
#include <fstream>
#include <cstdlib>

#include "funzioni.h"

int main ( int argc , char** argv) {
  
  if ( argc < 2 ) {
    cout << "Uso del programma : " << argv[0] << " <n_data> <filename> " << endl;
    return -1 ;
  }
  
  int ndata = atoi(argv[1]);

  char * filename = argv[2];

  // carico i dati da file

  double * data = ReadDataFromFile ( filename, ndata ) ;

  // Visualizzo dati caricati 

  cout << "Dati caricati : " << endl;
  Print(data,ndata);
  cout<<endl;
  // Calcolo la media

  cout << "Media = " << CalcolaMedia( data , ndata ) << endl;
  cout << "Varianza = " << CalcolaVarianza( data , ndata ) << endl;
  
    

  // Calcola la mediana
  double *vcopy = new double[ndata];
    for(int i=0;i<ndata;i++){
        vcopy[i]=data[i];
     }
  selection_sort(vcopy,ndata);
  cout << "Mediana = " << CalcolaMediana( vcopy , ndata ) << endl;
  
  // Visualizzo dati caricati
  //Print(data,ndata);
  Print("output.dat", vcopy,ndata);
delete[] data;
return 0;
}






