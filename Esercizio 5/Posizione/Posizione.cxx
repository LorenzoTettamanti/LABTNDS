#include <iostream>
#include <cmath>
#include "Posizione.h" 

//definizione dei costruttori
Posizione::Posizione(){
		m_x = 0 ;
		m_y = 0 ; 
		m_z = 0;
}
Posizione::Posizione(double x, double y, double z){
		m_x = x ;
		m_y = y ; 
		m_z = z;
}

 //parametri coordinate cartesiane
  double Posizione::getX() const{
	  return m_x;
  }
  double Posizione::getY() const{
	  return m_y;
  }
  double Posizione::getZ() const{
	  return m_z;
  }

//parametri coordinate sferiche
  double Posizione::getTheta() const{
	    return acos(m_z/getR());
  }
  double Posizione::getPhi() const{
	  return atan2(m_y,m_x);
  }
  double Posizione::getR() const{
	  return sqrt(pow(m_x,2)+pow(m_y,2)+pow(m_z,2));

  }

  //Parametri coordinate cilindriche
  double Posizione::getRho() const{
	 return sqrt(pow(m_x,2)+pow(m_y,2)+pow(m_z,2));
  }
  double Posizione::Distanza(const Posizione& b) const{
	  return sqrt(pow(getX()-b.getX(),2)
	  +pow(getY()-b.getY(),2)
	  +pow(getZ()-b.getZ(),2));
  }
