#include <iostream>
#include <cmath>
#include "Particella.h"
#include "Posizione.h"
#include "CampoVettoriale.h"


#ifndef __puntomateriale_h__
#define __puntomateriale_h__



class PuntoMateriale : public Particella, Posizione {

public:
	const double eps0= 8.854E-10;
	const double GN= 6.67E-11;
	PuntoMateriale(double massa,double carica,const Posizione&);
	PuntoMateriale(double massa,double carica,double x,double y,double z);
	~PuntoMateriale(){;}; 

	CampoVettoriale CampoElettrico(const Posizione& b)const{	
	double r = Distanza(b);
	double k = m_carica/(4*M_PI*eps0*pow(r,3));
	double Ex = k*(b.getX()-getX());
	double Ey = k*(b.getY()-getY());
	double Ez = k*(b.getZ()-getZ());
	return CampoVettoriale(b.getX(),b.getY(),b.getZ(),Ex,Ey,Ez);

	};
	CampoVettoriale CampoGravitazionale(const Posizione& b)const{
	double r = Distanza(b);
	double k = m_massa*GN/pow(r,3);
	double Ex = k*(b.getX()-getX());
	double Ey = k*(b.getY()-getY());
	double Ez = k*(b.getZ()-getZ());
	return CampoVettoriale(b.getX(),b.getY(),b.getZ(),Ex,Ey,Ez);
	};	

};

#endif