//#pragma once

#include <algorithm> // se se vogliono usare algoritmi STL
#include <cassert>
#include <iostream>
#include <vector>


using namespace std;
//////////////////////////////////////////////////////////////
// Nel namespace myVectAlgebra potremmo ridefinire gli operatori
// matematici che coinvolgono vettori e scalari

// somma di due vettori : somma componente per componente

template <typename T>
vector<T> operator+(const vector<T> &a, const vector<T> &b) {

  assert(a.size() == b.size());
  vector<T> result(a.size());

  for (size_t i{}; i < a.size(); i++)
    result[i] = a[i] + b[i];

  // Alternativamente si puo' usare l'algoritmo transform della STL
  //
  //    std::transform(a.begin(), a.end(), b.begin(), result.begin() ,
  //    std::plus<T>());

  return result;
}

// differenza di due vettori componente per componente
// [ preferisco re-implementarlo perche' si fanno meno operazioni rispetto
// result = a + (-1.*b) ]

template <typename T>
vector<T> operator-(const vector<T> &a, const vector<T> &b) {

  assert(a.size() == b.size());
  vector<T> result(a.size());

  for (size_t i{}; i < a.size(); i++)
    result[i] = a[i] - b[i];

  // Alternativamente si puo' usare l'algoritmo transform della STL
  //
  //    std::transform(a.begin(), a.end(), b.begin(), result.begin() ,
  //    std::minus<T>());

  return result;
}

//////////////////////////////////////////////////////////////
// prodotto scalare tra due vettori

template <typename T>
T operator*(const vector<T> &a, const vector<T> &b) {

  assert(a.size() == b.size());
  T sum{};
  for (size_t i{}; i < a.size(); i++)
    sum += a[i] * b[i];

  // Alternativamente si puo' usare l'algoritmo inner_product della STL
  //
  // sum = std::inner_product(std::begin(a), std::end(a), std::begin(b), 0.);

  return sum;
}

//////////////////////////////////////////////////////////////
// prodotto tra uno scalare e un vettore

template <typename T> vector<T> operator*(T c, const vector<T> &a) {

  vector<T> result(a.size());

  for (size_t i{}; i < a.size(); i++)
    result[i] = c * a[i];

  // Alternativamente si puo' usare l'algoritmo inner product
  //
  //     std::transform(std::begin(a), std::end(a), std::begin(result), [&c](T
  //     x){ return x * c; } );

  return result;
}

//////////////////////////////////////////////////////////////
// prodotto tra un vettore e uno scalare

template <typename T> vector<T> operator*(const vector<T> &a, T c) {

  vector<T> result(a.size());
  for (size_t i{}; i < a.size(); i++)
	result[i] = c * a[i];

  // oppure il ciclo for puo' essere sostituito da ( ~ stesso numero di
  // operazioni con il move constructor del vector altrimenti sarebbe meno
  // efficiente )
  //
  // result = c * a ;

  // Alternativamente si puo' usare l'algoritmo transform della STL con una
  // lambda function
  //
  //    std::transform(std::begin(a), std::end(a), std::begin(result), [&c](T
  //    x){ return x * c; } );

  return result;
}

//////////////////////////////////////////////////////////////
// divisione tra un vettore e uno scalare

template <typename T> vector<T> operator/(const vector<T> &a, T c) {

  vector<T> result(a.size());
  for (size_t i{}; i < a.size(); i++)
    result[i] = a[i] / c;

  // oppure il ciclo for puo' essere sostituito da

  // double fact = 1./c
  // result = a * fact ;

  // Alternativamente si puo' usare l'algoritmo transform della STL con una
  // lambda function
  //
  //    std::transform(std::begin(a), std::end(a), std::begin(result), [&c](T
  //    x){ return x / c; } );

  return result;
}

//////////////////////////////////////////////////////////////
// somma ad a un vettore b e il risultato viene messo in a

template <typename T>
vector<T> &operator+=(std::vector<T> &a, const vector<T> &b) {

  assert(a.size() == b.size());

  for (size_t i{}; i < a.size(); i++)
    a[i] += b[i];

  // Alternativamente si puo' usare l'algoritmo transform della STL
  //
  //    std::transform(a.begin(), a.end(), b.begin(), a.begin() ,
  //    std::plus<T>());

  return a;
}

//////////////////////////////////////////////////////////////
// sottrai ad a un vettore b e il risultato viene messo in a

template <typename T>
vector<T> &operator-=(vector<T> &a, const vector<T> &b) {

  assert(a.size() == b.size());

  for (size_t i{}; i < a.size(); i++)
    a[i] -= b[i];

  // Alternativamente si puo' usare l'algoritmo transform della STL
  //
  //    std::transform(a.begin(), a.end(), b.begin(), a.begin() ,
  //    std::minus<T>());

  return a;
}

//////////////////////////////////////////////////////////////
// Possiamo usare il namespace myVectUtils per funzioni generiche che
// agiscono sui vettori

namespace myVectUtils {

// metodo comodo per stampare il vettore

template <typename T> void Print(const vector<T> &v) {
  cout << "Printing vector\n";
  for (auto elem : v)
    cout << v << " ";
	cout << "\n";
  cout << "End of printing vector\n";
}

} // namespace myVectUtils
