#include <iostream>
#include <cmath>
#include <iomanip>
#include<sstream>

#include "Seno.h"
#include "Integral.h"


using namespace std;

int main (int argc,char** argv){


		double a = 0;
		double b = M_PI;
		double precision = atof(argv[1]);
		int cf=-log10(precision);

		Seno* mysin = new Seno();
		Integral *integrator = new Integral(a,b,mysin);

		//qualche test
		cout << "Integrale calcolato con precisione di "<<precision<<": "<<std::fixed<<std::setprecision(cf)<< integrator->TrapeziOpti(precision) <<endl;
	


return 0;
}