#include <iostream>
#include <fstream> 

#include "root/include/TH1F.h"
#include <vector>
#include <numeric>

using namespace std;

// =====================================================================

template <typename T> void Print( const vector<T> & v ) {
  for (unsigned int i=0; i<v.size(); i++) cout << v[i] << endl;
};

template <typename T> void Print( const vector<T> & v  , char* filename ) {
 	ofstream output(filename);
	 for (int i=0; i<v.size(); i++) output << v[i] << endl;  
	 output.close();
  return;

};

// =====================================================================

template <typename T> vector<T> Read( unsigned int N , const char* filename ) {
vector<T> v;
ifstream input(filename);
	if(!input){
		cerr<<"Impossibile aprire il file"<<filename;
		exit(1);
	}
	else{
		for(int i=0;i<N;i++){
			T val=0;
			input>>val;
			v.push_back(val);		
			}
		}
	input.close();	
  return v;  
};

template <typename T> vector<T> ReadAll( const char* filename ) {
vector<T> v;
T value;
ifstream input(filename);
	if(!input){
		cerr<<"Impossibile aprire il file"<<filename;
		exit(1);
	}
	else{
		while(input>>value) v.push_back(value);
	}
	input.close();	
  return v;  
 
};
 

// =====================================================================

template <typename T> double CalcolaMedia( const vector<T> & v) {

 auto start=v.begin();
	auto end=v.end();
	T media = accumulate(start,end,0.0)/(T)(end-start);
	return media;

};


template <typename T> double CalcolaMediana( vector<T> v ) {

  	sort( v.begin(), v.end() ) ;  //sort della stl
	T mediana = 0;
		if(v.size()%2==0){
			mediana=(v[v.size()/2 -1]+v[v.size()/2])/2;
		}
		else{
			mediana= v[v.size()/2];
		}
  return mediana;

};

// =====================================================================
// in caso si puo' usare anche questa nel main

template <typename T> TH1F FillHisto( const vector<T> & v){
 
  TH1F h ("histo","histo", 100, -10, 100) ;
  h.StatOverflows( kTRUE );
  for ( int k = 0 ; k < v.size() ; k++ ) h.Fill( v[k] );
  return h;

}

