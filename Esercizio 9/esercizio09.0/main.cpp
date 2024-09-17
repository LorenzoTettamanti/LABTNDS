#include "VectorOperations.h"
#include <cassert>
#include <vector>
#include <iostream>
using namespace std;

const vector<int> v1{6, 2, 4};
const vector<int> v2{4, -3, 0};

void test_sum() {
  vector<int> calculated{v1 + v2};
  const vector<int> expected{10, -1, 4};

  for (size_t i{}; i < calculated.size(); ++i) {
    assert(calculated[i] == expected[i]);
  }
}

void test_diff() {
  vector<int> calculated{v1 - v2};
  const vector<int> expected{2,5,4};

	for (size_t i{}; i < calculated.size(); ++i) {
    assert(calculated[i] == expected[i]);
  }
  // Implement all the checks
}

void test_vector_diff() {
  vector<int> calculated{v1 - v2};
  const vector<int> expected{2,5,4};

	for (size_t i{}; i < calculated.size(); ++i) {
    assert(calculated[i] == expected[i]);
  }
  // Implement all the checks
}

void test_scalar_mul() {
  vector<int> calculated1{3 * v1};
  const vector<int> expected{18,6,12};
  
	for (size_t i{}; i < calculated1.size(); ++i) {
    assert(calculated1[i] == expected[i]);
	}
  // Implement all the checks

  vector<int> calculated2{v1 * 3};
  // Implement again the same checks
  const vector<int> expected2{18,6,12};
  
	for (size_t i{}; i < calculated2.size(); ++i) {
    assert(calculated2[i] == expected2[i]);
}
}



void test_scalar_div(){
  // Note that all the members of v2 are even numbers
  vector<int> calculated{v1 / 2};
  const vector<int> expected{3,1,2};
  
	for (size_t i{}; i < calculated.size(); ++i) {
    assert(calculated[i] == expected[i]);
	}

  // Implement all the checks
}


void test_inplace_sum() {
  vector<int> v{1, 7, 5};

  v += v1;

  vector<int> expected{7, 9, 9};
  // Implement all the checks
}

void test_inplace_diff() {
  vector<int> v{1, 7, 5};

  v -= v1;

  vector<int> expected{-5, 5, 1};
  // Implement all the checks
}

int main(void) {
	test_sum();
	test_diff();
	test_vector_diff();
	test_scalar_mul();
	test_scalar_div();
	test_inplace_sum();	
	test_inplace_diff();
	cout<<"test finito nessun errore"<<endl;
}
