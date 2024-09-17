#ifndef __solutore_h__
#define __solutore_h__

#include "FunzioneBase.h"
#include "Fun.h"

class Solutore{
	
public:
  virtual double CercaZeri(double xmin, double xmax, const FunzioneBase* f,double prec)=0;
  void SetPrecision(double epsilon) {m_prec = epsilon;}
  double GetPrecision() {return m_prec;}



protected:
  double m_a, m_b;
  double m_prec;
  const FunzioneBase* f;
  unsigned int m_interations;
  unsigned int m_nmax; 

 

};
#endif