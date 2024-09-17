#ifndef __Seno_h__
#define __Seno_h__

#include "FunzioneBase.h"
#include <cmath>

class Seno: public FunzioneBase{
public:
  Seno(){;};
  Seno(double a){
	  m_x=a;
  };
  ~Seno(){;};
  virtual double Eval(double x) const {return sin(x);}
  double GetX() const {return m_x;}
  

private:
  double m_x;
};
#endif