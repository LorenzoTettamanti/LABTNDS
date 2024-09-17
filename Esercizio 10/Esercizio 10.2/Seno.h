#ifndef __seno_h__
#define __seno_h__

#include "FunzioneBase.h"
#include <cmath>
class Seno: public FunzioneBase{
public:
  Seno(){;
  };
  ~Seno(){;};
  virtual double Eval(double x) const {return sin(x);}
  void SetA(double a) {m_x = a;}
  double GetA() const {return m_x;}

private:
  double m_x;
};
#endif