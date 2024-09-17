#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <cmath>

using namespace std;

void Print(double *, int);
void Print(const char*,double*,int);

double CalcolaMedia( double * , int ) ;
double CalcolaVarianza( double * , int ) ;

double CalcolaMedia_improved( double * , int ) ;
double CalcolaVarianza_improved ( double * , int ) ;
double CalcolaMediana( double * , int ) ;

double * ReadDataFromFile ( const char*  , int ) ;

void scambiaByValue(double , double ) ;
void scambiaByRef(double &, double &) ;
void scambiaByPointer(double *, double *) ;

void selection_sort( double * , int );
