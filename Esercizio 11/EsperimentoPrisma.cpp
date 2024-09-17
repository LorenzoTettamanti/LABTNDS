#include "EsperimentoPrisma.h"
#include <cmath>

EsperimentoPrisma::~EsperimentoPrisma(){}

//metodi Get
double dm_misurato_1, dm_misurato_2;
double dm_residuo1,dm_residuo2;
double dm1,dm2;
double n1_residuo,n2_residuo;
double A_residuo,B_residuo;

double EsperimentoPrisma::getAmis()const{
	return m_A_misurato;
}
double EsperimentoPrisma::getBmis()const{
	return m_B_misurato;
}
double EsperimentoPrisma::getn1mis()const{
	return m_n1_misurato;
};
double EsperimentoPrisma::getn2mis()const{
	return m_n2_misurato;
};
double EsperimentoPrisma:: getth0mis()const{
	return m_th0_misurato;
};
double EsperimentoPrisma:: getth1mis()const{
	return m_th2_misurato;
};
double EsperimentoPrisma:: getth2mis()const{
	return m_th2_misurato;
};
double EsperimentoPrisma:: getdm1()const{
	return dm_misurato_1;
};
double EsperimentoPrisma:: getdm2()const{
	return dm_misurato_2;
};
double EsperimentoPrisma::getdmresiduo1() const{
	return dm_residuo1;
};
double EsperimentoPrisma::getdmresiduo2() const{
	return dm_residuo2;
};
double EsperimentoPrisma::getn1residuo() const{
	return n1_residuo;
};
double EsperimentoPrisma::getn2residuo() const{
	return n2_residuo;
};
double EsperimentoPrisma::getAresiduo() const{
	return A_residuo;
};
double EsperimentoPrisma::getBresiduo() const{
	return B_residuo;
};



EsperimentoPrisma::EsperimentoPrisma() :
  m_rgen(1),
  m_lambda1(579.1E-9),
  m_lambda2(404.7E-9),
  m_alpha(60.*M_PI/180.),
  m_sigmat(0.3E-3),
  m_A_input(2.7),
  m_B_input(60000E-18)

  //esegui ---> esegue la misura sperimentale di ogni angolo  θ0, θm(λ1), θm(λ2) che si ottiene generado un numero distribuito in maniera gaussiana intorno al suo valore di ingresso nella simulazione e deviazione standard σθ.
{
  // calcolo degli indici di rifrazione
  m_n1_input = sqrt(m_A_input + (m_B_input / (m_lambda1*m_lambda1)) );
  m_n2_input = sqrt(m_A_input + (m_B_input / (m_lambda2*m_lambda2)) );

  // theta0 e' arbitrario, scelgo M_PI/2.

  m_th0_input = M_PI/2.;

  // determino deviazione minima 
  //double dm1,dm2;
  dm1 = 2.*asin( m_n1_input * sin(0.5 * m_alpha) ) - m_alpha;
  m_th1_input = m_th0_input + dm1;
  dm2 = 2.*asin( m_n2_input * sin(0.5 * m_alpha) ) - m_alpha;
  m_th2_input = m_th0_input + dm2;


} 


void EsperimentoPrisma::Esegui(){
 	//calcolo delle quantità misurate
  	m_th0_misurato = m_rgen.BoxMuller(m_th0_input,m_sigmat);
  	m_th1_misurato = m_rgen.BoxMuller(m_th1_input,m_sigmat);
  	m_th2_misurato= m_rgen.BoxMuller(m_th2_input,m_sigmat);


	dm_misurato_1 = m_th1_misurato- m_th0_misurato;
	
	dm_misurato_2= m_th2_misurato - m_th0_misurato;

	//lunghezze d'onda λ1=579.1 nm, ed il viola, λ2=404.7 nm
	
	//calcolo indice di rifrazione
	m_n1_misurato = (sin((dm_misurato_1+m_alpha)/(2)))/(sin(m_alpha/2));

	m_n2_misurato =  (sin((dm_misurato_2+m_alpha)/(2)))/(sin(m_alpha/2));

	//calcolo A E B 
	m_A_misurato=((pow(m_lambda2,2)*pow(m_n2_misurato,2))-(pow(m_lambda1,2)*pow(m_n1_misurato,2)))/(pow(m_lambda2,2)-pow(m_lambda1,2));

	m_B_misurato = ((pow(m_n2_misurato,2))-(pow(m_n1_misurato,2)))/((1/(pow(m_lambda2,2))-(1/(pow(m_lambda1,2)))));


}	

//differenza tra i valori misurati e i valori attesi
void EsperimentoPrisma::Analizza(){

	dm_residuo1 = dm_misurato_1-dm1;
	dm_residuo2 = dm_misurato_2-dm2;

	n1_residuo = m_n1_input -m_n1_misurato;
	n2_residuo = m_n2_input -m_n2_misurato;

	A_residuo = m_A_input -m_A_misurato;
	B_residuo = m_B_input -m_B_misurato;

	
	
}