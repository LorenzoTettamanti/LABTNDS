#ifndef __INTEGRAL_H__
#define __INTEGRAL_H__

#include "FunzioneBase.h"
#include "RandomGen.h"
#include <iostream>
#include <random>

class Integral{
public:
	
	Integral(double a, double b, const FunzioneBase *f){
	   
   m_f = f;
   m_a = min(a,b);
   m_b = max(a,b);
   
   if ( a > b){
	   m_sign = -1;
   }
   else{ 
	   m_sign = 1;
   }
   
   };

   double media(int N,double a,double b){
	//generare npunti uniformemente distribuiti tra a e b 
	double x_i;
	m_sum=0;

//std::default_random_engine generator;

	for (int k=0;k<N;k++){
	//	cout<<"Generazione numero: "<<k<<endl;
		x_i = myrand->Unif(a,b);
		//std::uniform_int_distribution<int> distribution(a,b);
		//x_i=distribution(generator);
		//cout<<"controllo della generazione "<< x_i <<endl;
		m_sum += m_f->Eval(x_i);
		//cout<<"somma delle f "<<m_sum<<endl;
		//m_integral = (m_sum/N)*(m_b-m_a);
		//cout<<"controllo integrale "<< m_integral<<endl;
	//	cout<<endl;
	}
	//calcolare il valore stimato dell'integrale
	m_integral = ((m_sum/N)*(m_b-m_a))*m_sign;
//	cout<<"controllo integrale "<< m_integral<<endl;
	return m_integral;
   };
   
   double HoM(int N, double a , double b, double f_max){
	
	   int ntot=0;
	   int nhit=0;
	   double rapporto;
		//generazioni
		
		for(int k=0;k<N;k++){
		//algoritmo hit or miss
			double x_i = myrand->Unif(a,b);
			double y_i = myrand->Unif(0,f_max);
			//cout<<"controllo sulla generazione dei punti " <<endl;
			//cout<<"x: "<<x_i<<endl;
			//cout<<"y: "<<y_i<<endl;
			if(y_i < m_f->Eval(x_i)){
				nhit++;
				ntot++;
			}
			else{
				ntot++;
			}
		}
		//cout<<"numero di hit: "<<nhit<<endl;
		//cout<<"totale: "<<ntot<<endl;
		rapporto = (double )nhit/ntot;
		m_integral = (m_b-m_a)*f_max*rapporto*m_sign;
		
		return (double) m_integral;
   };

private:
   double m_a, m_b;
   double m_sum;
   double m_h;
   int m_sign;
   double m_integral;
   const FunzioneBase *m_f;
   RandomGen *myrand = new RandomGen(1.);
};

#endif


/* 
std::default_random_engine generator;
std::uniform_int_distribution<int> distribution(1,6);
int dice_roll = distribution(generator);  // generates number in the range 1..6
*/ 