#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void print_and_clear_buffer(std::stringstream &ss)
	{
    	std::cout << ss.str();
    	std::ofstream outfile("risultati.dat", std::ios::app);
    	outfile << ss.str();
    	ss.clear();
	}

