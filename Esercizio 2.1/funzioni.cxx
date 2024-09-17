#include <assert.h>
#include <cmath>
#include "funzioni.h"
#include "Vettore.h"

Vettore Read(int size,const char* Filename) {
	Vettore v(size);
	ifstream input(Filename);
		if(!input){
			cerr<<"Impossibile aprire il file"<<endl;
			exit(1);
		}
		else{
			for(int i=0;i<size;i++){
				double val=0;
				input>>val;				
				v.SetComponent(i,val);
		}
	}
	return v;
}
void Print(const Vettore & v){
  for(int i=0;i<v.GetN();i++){
    cout<<v.GetComponent(i)<<" ";
  }

}

double CalcolaMedia( const Vettore & v ) {
  
  double accumulo = 0;
  for ( int k = 0 ; k < v.GetN() ; k++ ) { 
    accumulo += v.GetComponent(k) ;
  }
  
  return accumulo / double ( v.GetN() ) ;
  
}
double CalcolaVarianza(const Vettore &v )
{
  double sum=0;
    for(int i=0;i<v.GetN();i++){
      sum=sum+v.GetComponent(i);
    }
    double media=sum/v.GetN();
    double scarti=0;
    for(int i =0;i<v.GetN();i++){
      scarti=pow(v.GetComponent(i)-media,2);
    }
  double varianza = scarti/v.GetN(); 
  
  return varianza ;
}

void selection_sort( Vettore &v) {
    int i ,j;
  //sel sort
    for( i=0;i<v.GetN()-1;i++){
      for(j=i+1;j<v.GetN();j++){
            if(v.GetComponent(i)>v.GetComponent(j)){
                v.Scambia(i,j);
            }
      }
    }

}


double CalcolaMediana (Vettore &v ) {
	selection_sort(v);	
    int index;
    if(v.GetN() % 2==1){
      index=(v.GetN()+1)/2;
      double mediana = v.GetComponent(index-1);
      return mediana;
    }
    else{
      index=(v.GetN())/2;
       double mediana =(v.GetComponent(index-1)+v.GetComponent(index/2));
       return mediana;
    }

  return 0;

} 

void Print(const char* Filename, const Vettore &v){
  ofstream output(Filename);
    for(int i=0;i<v.GetN();i++){
      output<<v.GetComponent(i)<<" ";
    }
  output.close(); 
}
                        
