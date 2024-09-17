#include <iostream>
#include "CampoVettoriale.h"

//#include "Posizione.h"

//definizione dei metodi
CampoVettoriale::CampoVettoriale(const Posizione& r): Posizione(r.getX(),r.getY(),r.getZ()){
	m_Fx=0;
	m_Fy=0;
	m_Fz=0;	
}

CampoVettoriale::CampoVettoriale(const Posizione& r,double Fx,double Fy,double Fz): Posizione(r) {
	m_Fx=Fx;
	m_Fy=Fy;
	m_Fz=Fz;	
}

CampoVettoriale::CampoVettoriale(double x, double y, double z,double Fx,double Fy,double Fz): Posizione(x,y,z){
	m_Fx=Fx;
	m_Fy=Fy;
	m_Fz=Fz;	
}


//definizione degli operatori
//definizione operatore +


//definizione operatore+=
CampoVettoriale CampoVettoriale::operator+(const CampoVettoriale &v)const{
	CampoVettoriale sum(v);
	sum.m_Fx+=getFx();
	sum.m_Fy+=getFy();
	sum.m_Fz+=getFz();
	return sum;
}

CampoVettoriale & CampoVettoriale::operator+=(const CampoVettoriale &v){
	return (*this) = (*this) +v;
}

