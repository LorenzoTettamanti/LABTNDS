#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

#include "funzioni.h"

int main( int argc , char** argv ) {
  if ( argc < 3 ) {
    cout << "Uso del programma : " << argv[0] << " <n_data> <filename>" << endl;
    return -1 ;
  }
  
  int ndata = atoi(argv[1]);
  char * filename = argv[2];
  char *outputfile = argv[3];

  vector <double> v = Read<double>(ndata,filename);
  Print(v);
  
  cout<<"Media "<<CalcolaMedia(v)<<endl;
  cout<<"Varianza "<<CalcolaVarianza(v)<<endl; 
  cout<<"Mediana "<<CalcolaMediana(v)<<endl;
  Print(v,outputfile);
  
  return 0;
}
