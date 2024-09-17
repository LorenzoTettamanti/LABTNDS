#ifndef __RANDOMGEN_H__
#define __RANDOMGEN_H__
#include <cmath>
#include <iostream>
#include "FunzioneBase.h"

using namespace std;
class RandomGen{
  public:
     RandomGen(unsigned int){
		m_a=1664525;
		m_c=1013904223;
		m_m =pow(2,31);
		m_seed=1;
	 };

     void SetA(unsigned int a) {m_a = a;}
     void SetC(unsigned int c) {m_c = c;}
     void SetM(unsigned int m) {m_m = m;}

     double Rand(){
		 m_seed = ((m_a*m_seed) + m_c)% m_m;
		 	return (double) m_seed/(double) (m_m);
	 };

	//generazione uniforme
     double Unif(double xmin, double xmax){
		return (xmin+(Rand()*(xmax-xmin)));
	 };

	 //generazione esponenziale
     double Exp(double mean){
		 double lambda = Rand();
		 double x = (-1/lambda)*log(1-lambda);
	 };

	 //generazione Boxmuller
     double BoxMuller(double mean, double sigma){
		 	double s = Rand();
			double t = Rand();
		 	double x = sqrt(-2*log(s))*cos(2*M_PI*t);
		return mean+(x*sigma);
	 };


	
	 //generazione Accept-Reject 
	double AcceptReject(double a,double b,double max,const FunzioneBase* f){
			//m_f = f;
			double s=Rand();
			double t=Rand();
			double x=a+(b-a)*s;
			double y=max*t;
	//char id;	
		//test gaussiana 
		if(y<f->Eval(x)){
			cout<<"Accepted"<<" "<<" "<<x<<" " <<y<<" "<<"f(x) "<<f->Eval(x) <<endl;
	//		id = 'A';
			return y;
		}
		else if(y>f->Eval(x)){
		//cout<<"Rejected"<<" "<<" "<<x<<" " <<y<<endl;
	//	id = 'R';
			y=-1;
			return y;
		}
		
	};


  private:
     unsigned int m_a,m_c, m_m;
     unsigned int m_seed;
	// unsigned int m_f;
};
#endif