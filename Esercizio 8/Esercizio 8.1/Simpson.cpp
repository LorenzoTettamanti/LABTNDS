#include "Simpson.h"
#include <algorithm>


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
}



//giusto
double Integral::Simpson(unsigned int nstep){
   
   m_h = (m_b - m_a)/nstep;
   m_sum = 0.0;
   m_integral=0.0;

//somma per elementi pari
   for (unsigned int i=1;i<nstep;i=i+2){
     m_sum += 4.0* m_f->Eval(m_a+(i*m_h));
	// cout<< "somma parziale pari numero  " << i << " " <<m_sum1<<endl;
   }
//somma per elementi dispari	
    for (unsigned int i=2;i<nstep-1;i=i+2){
     m_sum += 2.0*m_f->Eval(m_a + (i*m_h));
	  //cout<< "somma parziale dispari numero " << i << " " <<m_sum2<<endl;
   }	

   m_integral = m_sign*(m_h/3.0)*(m_f->Eval(m_a) + m_sum + m_f->Eval(m_b));

   return m_integral;
}


