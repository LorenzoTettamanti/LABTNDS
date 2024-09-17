#include "funzioni.h"
#include <cmath>
void Print(double * data, int size){
  for(int i=0;i<size;i++){
    cout<<data[i]<<" "<<endl;
  }

}
void Print(const char* Filename,double* data,int size){
  ofstream output(Filename);
    for(int i=0;i<size;i++){
      output<<data[i]<<" "<<endl;
    }
  output.close(); 
}

double CalcolaMedia( double * data , int size ) {
  
  double sum=0;
  for(int i=0;i<size;i++){
    sum=sum+data[i];
  }
  double media=sum/size; 
  return media ;
}

double CalcolaVarianza( double * data , int size )
{
  double sum=0;
    for(int i=0;i<size;i++){
      sum=sum+data[i];
    }
    double media=sum/size;
    double scarti=0;
    for(int i =0;i<size;i++){
      scarti=pow(data[i]-media,2);
    }
  double varianza = scarti/size; 
  
  return varianza ;
}
                                 
double * ReadDataFromFile ( const char* Filename , int size  ) {
   ifstream input;
    input.open(Filename);
      if(!input)
        throw runtime_error ("impossibile aprire il file");

  double * data = new double[size];
    for(int i =0;i<size;i++){
        input>>data[i];
    }  
    
 
  return data;

}

void scambiaByValue(double a, double b) {
 double temp=b;
  b=a;
  a=temp;

}

void scambiaByRef(double &a, double &b) {
double temp=b; ;
  b=a;
  a=temp;

}

void scambiaByPointer(double *a, double *b) {
  double temp=*b;
  *b=*a;
  *a=temp;  

}


void selection_sort( double * vcopy , int size) {
    
  //sel sort
    for(int i=0;i<size-1;i++){
      for(int j=i+1;j<size;j++){
            if(vcopy[i]>vcopy[j]){
                scambiaByPointer(&vcopy[j],&vcopy[i]);
            }
      }
    }

}

// Calcolo della mediana di un array <vec> di dimensione <size>. Prima si crea
// una copia dell'array, lo riordina e calcola la mediana

double CalcolaMediana ( double vcopy[] , int size ) {

  int index;
    if(size % 2==1){
      index=(size+1)/2;
      double mediana = vcopy[index-1];
      return mediana;
    }
    else{
      index=(size)/2;
       double mediana =(vcopy[index-1]+vcopy[index])/2;
       return mediana;
    }

  return 0;

} 

