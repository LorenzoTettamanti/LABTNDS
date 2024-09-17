#include <iostream>
#include <fstream> 

#include <vector>      // contenitore
#include <algorithm>  // sort di STL 
#include <numeric> 
#include <cmath>   

using namespace std;

template <typename T> void Print( const vector<T> & v ) {
  for (int i=0; i<v.size(); i++) cout << v[i] << endl;  
  return;
};

template <typename T> void Print( const vector<T> & v  , const char* filename ) {
	ofstream output(filename);
	 for (int i=0; i<v.size(); i++) output << v[i] << endl;  
	 output.close();
  return;
};


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
ifstream input(filename);
	if(!input){
		cerr<<"Impossibile aprire il file"<<filename;
		exit(1);
	} 
T value;
	while(input>>value)v.push_back(value);
	input.close();	
 return v;
};


template <typename T> double CalcolaMedia( const vector<T> & v){
	auto start=v.begin();
	auto end=v.end();
	T media = accumulate(start,end,0.0)/(T)(end-start);
	return media;
};

template <typename T> double CalcolaVarianza( const vector<T> & v) {
	T scarti = 0;
	for(T x:v){
		//cout<<x<<endl;
		scarti+=pow(x-CalcolaMedia(v),2);
	}

	return scarti/(T)(v.end()-v.begin());
};

template <typename T> double CalcolaMediana( vector<T> v ) {

	sort( v.begin(), v.end() ) ;  //sort della stl
	T mediana = 0;
		if(v.size()%2==0){
			mediana=(v[(v.size()/2) -1]+v[v.size()/2])/2;
		}
		else{
			mediana= v[v.size()/2];
		}
  return mediana;

};

