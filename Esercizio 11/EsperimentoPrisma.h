#ifndef _Esperimento_Prisma_h_
#define _Esperimento_Prisma_h_
#include "RandomGen.h"



class EsperimentoPrisma {
	//data membri pubblici 
 public:
   EsperimentoPrisma();
   ~EsperimentoPrisma();

//metodi di tipo Get per accedere ai data membri 

double getAmis()const;
double getBmis()const;
double getn1mis()const;
double getn2mis()const;
double getth0mis()const;
double getth1mis()const;
double getth2mis()const;
double getdm1()const;
double getdm2()const;
double getdmresiduo1() const;
double getdmresiduo2() const;
double getn1residuo() const;
double getn2residuo() const;
double getAresiduo() const;
double getBresiduo() const;
double getcorrdm() const;
double getcorrN() const;
double getcorrAB() const;




//analisi ed esecuzione della simulazione
	void Esegui();
	void Analizza();

//data membri privati 
 private:
//generatore di numeri casuali---> consigliato BoxMuller
   RandomGen m_rgen;

   double m_lambda1, m_lambda2, m_alpha, m_sigmat;

   double m_A_input, m_A_misurato;
   double m_B_input, m_B_misurato;
   double m_n1_input, m_n1_misurato;
   double m_n2_input, m_n2_misurato;
   double m_th0_input, m_th0_misurato;
   double m_th1_input, m_th1_misurato;
   double m_th2_input, m_th2_misurato;

};
#endif