//#pragma once

#include "VectorOperations.h"
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

// Classe astratta, Restituisce la derivata nel punto (t, x)

#ifndef __funzionevettorialebase_h__
#define __funzionevettorialebase_h__
class FunzioneVettorialeBase {
public:
  virtual vector<double> Eval(double t , const vector <double> &x )const=0;
};
#endif
// Classe concreta, usata nei test
 //derivate
 
class OscillatoreArmonico : public FunzioneVettorialeBase {
public:

  OscillatoreArmonico(double omega0){m_omega0 = omega0; };

	virtual vector<double> Eval(double t,const vector<double> &x)const{
		vector<double> dxdt {x[1],-(m_omega0*m_omega0*x[0]) };
	return dxdt;

  }

private:
  double m_omega0;
};




// Classe astratta per un integratore di equazioni differenziali

#ifndef __eqdiffbase_h__
#define __eqdiffbase_h__
class EquazioneDifferenzialeBase {
public:
  virtual vector<double> Passo(double t, const vector<double> &x,double h,FunzioneVettorialeBase *f)const=0;
};
#endif

// Classe concreta, metodo di Eulero //metodo risolutivo
class Eulero : public EquazioneDifferenzialeBase {
public:

  virtual vector <double> Passo(double t , const  vector <double> &x, double h, FunzioneVettorialeBase *f)const{
	  return x+((f->Eval(t,x))*h);
  }

};

void test_euler();
