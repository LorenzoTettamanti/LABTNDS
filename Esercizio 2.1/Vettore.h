
#ifndef __Vettore_h__
#define __Vettore_h__

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


class Vettore {

 public:
	Vettore();
	Vettore(unsigned int N);
    ~Vettore(); //distruttore
    
    unsigned int GetN() const {return m_N;} //accede alla dimensione 
    void SetComponent(unsigned int, double); //modifica la componente
    double GetComponent(unsigned int) const;    //accede alla componente

    void Scambia(unsigned int ,unsigned int ); 
    double& operator[](unsigned int i );


private:
    unsigned int m_N;
    double* m_v;
};

#endif //__Vettore_h__
