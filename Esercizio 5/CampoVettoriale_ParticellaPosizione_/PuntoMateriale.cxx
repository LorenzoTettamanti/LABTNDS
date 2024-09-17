#include <iostream>
#include <cmath>
#include "PuntoMateriale.h"

//costanti
const double eps0= 8.854E-10;
const double GN= 6.67E-11;


PuntoMateriale::PuntoMateriale(double massa,double carica,const Posizione& r) : Particella(massa,carica),Posizione(r){

}

PuntoMateriale::PuntoMateriale(double massa,double carica,double x,double y ,double z):Particella(massa,carica),Posizione(x,y,z){

}
/*
CampoVettoriale PuntoMateriale::CampoElettrico(const Posizione& b )const{
	double r = Distanza(b);
	double k = m_carica/(4*M_PI*eps0*pow(r,3));
	double Ex = k*(b.getX()-getX());
	double Ey = k*(b.getY()-getY());
	double Ez = k*(b.getZ()-getZ());
	return CampoVettoriale(b.getX(),b.getY(),b.getZ(),Ex,Ey,Ez);
}

CampoVettoriale PuntoMateriale::CampoGravitazionale(const Posizione& b )const{
	double r = Distanza(b);
	double k = m_massa*GN/pow(r,3);
	double Ex = k*(b.getX()-getX());
	double Ey = k*(b.getY()-getY());
	double Ez = k*(b.getZ()-getZ());
	return CampoVettoriale(b.getX(),b.getY(),b.getZ(),Ex,Ey,Ez);
}
*/