#ifndef __bisezione_h__
#define __bisezione_h__

#include "Solutore.h"
#include "funzioni.h"
#include <cmath>
class Bisezione:public Solutore{

  public:
  Bisezione(){;};
  ~Bisezione(){;};
  virtual double CercaZeri(double xmin, double xmax, const FunzioneBase* f,double prec){
	  m_nmax=100;

	  m_interations=0;
	  double a = 0;
	  double b = 0;

	  if(xmin < xmax){
		  a = xmin;
		  b = xmax;
	  }else{
		a = xmax;
		b = xmin;
	  }
	  double fa = f->Eval(a);
	  double fb = f->Eval(b);
	  	while(fabs(b+a)>prec){

			  double c = 0.5*(b+a);
			  double fc = f->Eval(c);

			  	if(m_interations>m_nmax) break;
				  m_interations++;
				if(sign(fa)*sign(fc)<=0){
					b = c;
					fb = fc;
					}
				else if(sign(fb)*sign(fc)<=0){
					a = c; 
					fa = fc;
					}
				else{
					return 0;
				}

		  }
	return 0.5*(b+a);
	}
};

#endif