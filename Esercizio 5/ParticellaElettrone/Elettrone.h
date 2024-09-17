#include <iostream>
#include "Particella.h"


using namespace std;

#ifndef __elettrone_h__
#define __elettrone_h__

//classe figlia di Particella
class Elettrone: public Particella {

public:

	Elettrone();
	~Elettrone(){;};

  void Print() const{
		cout<<"Elettrone"<<endl;
		cout<<"massa m = "<<m_massa<<endl;
		cout<<"carica q = " <<m_carica<<endl;
  };
};
#endif