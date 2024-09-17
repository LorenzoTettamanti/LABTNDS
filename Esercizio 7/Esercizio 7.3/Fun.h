#ifndef __parabola_h__
#define __parabola_h__

#include "FunzioneBase.h"
#include <cmath>

class Fun: public FunzioneBase{
public:
  Fun();
  Fun(double a, double b){
	  m_a=a;
	  m_b=b;
  };
  ~Fun(){;};
  virtual double Eval(double x) const {return (m_a*sin(x))-x*(m_b*cos(x));}
  void SetA(double a) {m_a = a;}
  void SetB(double b) {m_b = b;}

  double GetA() const {return m_a;}
  double GetB() const {return m_b;}
 


private:
  double m_a, m_b;
};
#endif