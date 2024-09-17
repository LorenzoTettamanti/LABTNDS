#include <iostream>
using namespace std;

#ifndef __particella_h__
#define __particella_h__

class Particella{

public:
	
	Particella();  //costruttore
	Particella(double massa,double carica);
	~Particella(){;}; //distruttore
	


	//metodi
	void Print()const;
	double GetMassa()const{
		return m_massa;
	};
	double GetCarica()const{
		return m_carica;
	};
	
protected:
	double m_massa;
	double m_carica;
};

#endif
