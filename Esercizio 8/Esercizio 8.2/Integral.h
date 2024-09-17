#ifndef __SIMPSON_H__
#define __SIMPSON_H__

#include "FunzioneBase.h"

class Integral{
public:

   Integral(double a, double b, const FunzioneBase* f);
   double Trapezi(unsigned nstep);
   double TrapeziOpti(double prec);
   

private:
	
	double m_a, m_b;
	double m_sum;
	double m_h;
	int m_sign;
	double m_integral;
	const FunzioneBase* m_f;

	//aggiunte ottimizzazione
	double  next_subsum(double h,double delta);
	double last_precision;
	int m_step;
	
};

#endif