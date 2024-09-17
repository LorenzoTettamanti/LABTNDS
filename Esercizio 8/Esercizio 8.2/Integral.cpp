#include "Integral.h"
#include <algorithm>
#include <iostream>
#include <cmath>


using namespace std;

Integral::Integral(double a, double b, const FunzioneBase* f)
{
   m_f = f;
   m_a = min(a,b);
   m_b = max(a,b);
   
   if ( a > b){
	   m_sign = -1;
   }
   else{ 
	   m_sign = 1;
   }
   //aggiunte per ottimizzazione
   m_sum = (m_f->Eval(m_b)*m_f->Eval(m_a))/2;
   m_integral = m_sign*m_sum*(m_b-m_a);
   last_precision = -1,
   m_h=(m_b-m_a)/2;
   m_step=1;
}

//giusto

double Integral::Trapezi(unsigned int nstep){
   m_h = (m_b - m_a)/nstep;
   m_sum = 0.0;
   m_integral=0.0;

	
	for (unsigned int i=0;i<nstep-1;i++){
		m_sum +=  2*m_f->Eval(m_a+((i+1)*m_h));
	}	

	m_integral = m_sign*(m_h/2.0)*(m_f->Eval(m_a)+ m_sum + m_f->Eval(m_b));

   return m_integral;
}


double Integral::next_subsum(double h,double delta){
	double x = h+m_a;
	double sum=0;
	while(x<m_b){
		sum += m_f->Eval(x);
		x += delta;
	}
	return sum;
}

double Integral::TrapeziOpti(double precision){
	//if((precision>last_precision) && last_precision !=1){
	//	return m_integral;
	//}	
	//else{
		double delta = m_h*2;
		do{
			m_sum += next_subsum(m_h,delta);
			double prev_integral=m_integral;
			m_integral = m_sign*m_sum*m_h;
			
			
			//controllo step massimi
				if(m_step>10000){
					cerr<<"Numero massimo di step raggiunto"<<endl;
					break;
				}
			
			
			last_precision = fabs(m_integral-prev_integral);								
			delta=m_h;
			m_h/=2;
			m_step++;
		}while(last_precision>precision);
	//}
	return m_integral;
}
