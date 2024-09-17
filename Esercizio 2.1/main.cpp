#include <iostream>
#include "funzioni.h"

int main(int argc , char** argv) {
    if ( argc < 2 ) {
    cout << "Uso del programma : " << argv[0] << " <n_data> <filename> " << endl;
    return -1 ;
  }
  
  int ndata = atoi(argv[1]);
  char * filename = argv[2];

  // carico i dati da file

	Vettore v = Read(ndata,filename);
    cout << "Dati caricati : " << endl;
 	Print(v);
    cout<<endl;
	cout<<"Media: "<<CalcolaMedia(v)<<endl;
	cout<<"Varianza: "<<CalcolaVarianza(v)<<endl;
	//vettore copiato per mediana
	Vettore vcopy = Read(ndata,"data.dat");
	selection_sort(vcopy);
	Print(vcopy);
	cout<<endl;
	cout<<"Mediana: "<<CalcolaMediana(vcopy)<<endl;
	Print("esterno.dat",vcopy);

return 0;
}