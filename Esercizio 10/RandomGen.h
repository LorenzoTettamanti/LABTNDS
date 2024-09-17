#ifndef __RANDOMGEN_H__
#define __RANDOMGEN_H__
#include <cmath>
#include <iostream>


using namespace std;
class RandomGen{
  public:
     RandomGen(unsigned int){
		m_a=1664525;
		m_c=1013904223;
		m_m=pow(2,31);
		m_seed=1;
	 };

     void SetA(unsigned int a) {m_a = a;}
     void SetC(unsigned int c) {m_c = c;}
     void SetM(unsigned int m) {m_m = m;}

     double Rand(){
		 m_seed = ((m_a*m_seed) + m_c)% m_m;
		 	return (double) m_seed/double (m_m);
	 };
	 //implementazione generazione randomica BoxMuller
     double BoxMuller(double mean, double sigma){
		 double s = Rand();
		 double t = Rand();
		 double x = sqrt(-2.0*log(s))*cos(2*M_PI*t);
		return mean+x*sigma;
	 }

  private:
     unsigned int m_a,m_c, m_m;
     unsigned int m_seed;
};
#endif