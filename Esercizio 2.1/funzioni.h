#ifndef __funzioni__
#define __funzioni__

#include <iostream>
#include <fstream> 
#include "Vettore.h"

using namespace std;

Vettore Read(int,const char*) ;
void Print( const Vettore &) ;

double CalcolaMedia( const Vettore & ) ;
double CalcolaVarianza( const Vettore & ) ;
double CalcolaMediana ( Vettore & ) ; 
void selection_sort( Vettore & );

void Print(const char* , const Vettore &);


#endif
