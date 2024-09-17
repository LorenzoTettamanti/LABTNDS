#include<sstream>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
void print_and_clear_buffer(std::stringstream &ss)
	{
    	cout << ss.str();
    	ofstream outfile("Errore.dat", ios::app);
    	outfile << ss.str();
    	ss.clear();
	}
