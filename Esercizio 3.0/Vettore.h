#ifndef __Vettore_h__
#define __Vettore_h__

#include <iostream>
#include <assert.h>

using namespace std;

template <typename T> class Vettore {
                          
 public:
  
// costruttore senza argomenti
Vettore()  {
  cout << "Calling default constructor" << endl;
  m_N = 0;
  m_v = NULL;
};

// costruttore con dimensione
Vettore(unsigned int N) {
  cout << "Calling constructor with arguments" << endl;
  m_N = N;
  m_v = new T[N];
  for ( int k = 0 ; k < N ; k++ ) m_v[k] = 0;
  
};

Vettore(const Vettore& V){
	cout << "Calling copy constructor" << endl;
	m_N = V.GetN();
	m_v = new T [m_N];
	for(int i=0; i < m_N ; i++)
		m_v[i] = V.GetComponent(i);

};
	
Vettore& operator=(const Vettore& V){
	 cout << "Calling assing operator" << endl;
	 if (m_v) delete [] m_v;
	 	m_v = new T [m_N];
	for(int i=0; i < m_N ; i++)
		m_v[i] = V.GetComponent(i);

	return *this;

};

~Vettore() {
	cout << "Calling destructor" << endl;
	delete [] m_v;

};

void SetComponent(unsigned int i, T a) {
  assert( ( m_N > i ) && "Errore : l'indice e' troppo grande");
  if ( i<m_N ) {
    m_v[i]=a;
  } else {
    cerr << "Errore: indice " << i << ", dimensione " << m_N << endl;
    exit (-1);
  }
};

unsigned int GetN () const {
	return m_N;
};

T GetComponent (unsigned int i) const{
	assert ( ( m_N > i ) && "Errore : l'ndice è troppo grande");
	
	if ( i < m_N){
		return m_v[i];
	}
	
	else {
		cerr << "Errore: indice " << i << " , dimensione " << m_N << endl;
		exit (-1);
	}
};



void SwapComponents (unsigned int a, unsigned int b){
	assert ( ( m_N > a or m_N > b ) && "Errore : l'ndice è troppo grande");
  
	T jolly = m_v[a];
	m_v[a] = m_v[b];
	m_v[b] = jolly;

};

T& operator[](unsigned int i){return *m_v[i]; };

 private:
  
   unsigned int m_N;                        
   T* m_v;     
  
};

#endif // __Vettore_h__
