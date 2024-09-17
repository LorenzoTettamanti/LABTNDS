#ifndef __parabola_h__
#define __parabola_h__

#include "FunzioneBase.h"

class Parabola: public FunzioneBase{
public:
  Parabola();
  Parabola(double a, double b, double c){
	  m_a=a;
	  m_b=b;
	  m_c=c;
  };
  ~Parabola(){;};
  virtual double Eval(double x) const {return m_a*x*x + m_b*x + m_c;}
  void SetA(double a) {m_a = a;}
  void SetB(double b) {m_b = b;}
  void SetC(double c) {m_c = c;}
  double GetA() const {return m_a;}
  double GetB() const {return m_b;}
  double GetC() const {return m_c;}
  double GetVertex(){
	  return -(m_b)/(2*m_a);
  }

private:
  double m_a, m_b, m_c;
};
#endif