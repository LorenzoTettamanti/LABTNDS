#include "Vettore.h"
#include "funzioni.h"
using namespace std;
int main ( int argc, char** argv ) {

  if ( argc < 3 ) {
    cout << "Uso del programma : " << argv[0] << " <n_data> <filename> " << endl;
    return -1 ;
  }

  int ndata = atoi(argv[1]);
  char * filename = argv[2];

  // usiamo il contenitore Vettore per immagazzinare double !

  Vettore<double> v = Read<double>( &ndata , filename );

  Print( v );
	
  cout << "media    = " << CalcolaMedia<double>( v  ) << endl;
  cout << "varianza = " << CalcolaVarianza<double>( v  ) << endl;
  cout << "mediana  = " << CalcolaMediana<double>( v ) << endl; 

	cout << "Dati riordinati nel file output.dat" << endl;
  
	Print ( v, "output.dat" );

  return 0;

}
