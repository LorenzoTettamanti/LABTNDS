/* ========================================

This file contains some template functions 
to be used on the Vetteore class

======================================== */
#include <cstdlib>
#include <iostream>
#include <fstream> 
#include <string>
#include "Vettore.h"

using namespace std;

template <typename T> Vettore<T> Read ( int* N , const char* filename ) {

 Vettore<T> v(*N);
  
  ifstream infile (filename);
  if (!infile){
    cout << endl << "Error finding file" << endl;
    exit(0);
  }
  int n = 0;
	T val=0;

	do{
		infile >> val;
		v.SetComponent(n, val);
  	if(infile.eof()) *N = n;
		n++;
	}while(n < *N);
    
  infile.close();
  
  return v;
}

template <typename T> void Print(const Vettore<T> &v){
	for (int i=0 ; i<v.GetN(); i++) cout << v.GetComponent(i) <<endl;
	return;
}
template <typename T> void Print (const Vettore<T> &v, const char* filename){

	ofstream out (filename);
	if (!out)cout << "Cannot create file" << filename << endl;
	for (int i=0 ; i<v.GetN(); i++) out << v.GetComponent(i) << endl;
	return;
}

template <typename T> T CalcolaMedia ( const Vettore<T> & v  ) {

T accumulo = 0;
  for ( int k = 0 ; k < v.GetN() ; k++ ) { 
    accumulo += v.GetComponent(k) ;
  }
  
  return accumulo / T ( v.GetN() ) ;
  
}

template <typename T> T CalcolaVarianza( const Vettore<T> & v )
{
 
 T sum = 0, sum2 = 0, varianza = 0;
  for(int k = 0; k < v.GetN(); k++){
    sum += v.GetComponent(k);
    sum2 += v.GetComponent(k)*v.GetComponent(k);
  }
  varianza = sum2/T ( v.GetN() ) - sum*sum/T ( v.GetN()*v.GetN() );
  
  return varianza ;

}

template <typename T> void selection_sort( Vettore<T> &v) {

T min = 0;
int imin = 0;
  for (int k = 0; k < v.GetN()-1; k++){
    min = v.GetComponent(k);
		imin = k;
    for (int i = k+1; i < v.GetN(); i++){
      if (v.GetComponent(i) < min){
        min = v.GetComponent(i);
				imin = i;
      }
    }

    v.SwapComponents( k, imin);
   
  }
}


template <typename T>T CalcolaMediana ( Vettore<T> &v ) {

	selection_sort( v );
  
  T mediana = 0;
  if(v.GetN() % 2 == 0) mediana = T ( (v.GetComponent(v.GetN()/2 -1) + v.GetComponent(v.GetN()/2))/2);
  else mediana = T (v.GetComponent(v.GetN()/2)); 
	
	return mediana;

}