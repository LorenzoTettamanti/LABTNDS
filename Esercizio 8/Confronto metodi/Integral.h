#ifndef __INTEGRAL_H__
#define __INTEGRAL_H__

#include "FunzioneBase.h"

class Integral{
public:

   Integral(double a, double b, const FunzioneBase *f);
   double Midpoint(unsigned nstep);
   double Simpson(unsigned nstep);
   double Trapezi(unsigned nstep);
   
private:
   double m_a, m_b;
   double m_sum;
   double m_h;
   int m_sign;
   double m_integral;
   const FunzioneBase *m_f;
};

#endif