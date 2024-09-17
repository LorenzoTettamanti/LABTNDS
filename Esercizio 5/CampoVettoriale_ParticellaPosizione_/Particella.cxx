#include <iostream>
#include "Particella.h"

Particella::Particella(double massa,double carica){
	m_massa=massa;
	m_carica=carica;
}
void Particella::Print()const{
		cout<<"Particella"<<endl;
		cout<<"massa m = "<<m_massa<<endl;
		cout<<"carica q = " <<m_carica<<endl;
}