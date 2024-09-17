#include <iostream>

#ifndef __posizione_h__
#define __posizione_h__

class Posizione {

public:

//costruttori
  Posizione();
  Posizione(double x, double y, double z);
  
  ~Posizione(){;}; //distruttore
 
 //parametri coordinate cartesiane
  double getX() const;
  double getY() const;
  double getZ() const;



//parametri coordinate sferiche
  double getTheta() const;
  double getPhi() const;
  double getR() const;

  //Parametri coordinate cilindriche
  double getRho() const;
  double Distanza(const Posizione&)const;

//data privati
private:
  double m_x, m_y, m_z;
};

#endif