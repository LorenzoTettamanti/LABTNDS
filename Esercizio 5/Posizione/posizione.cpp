#include <cmath>
#include <iostream>
#include <cstdlib>


#include "Posizione.h"

using namespace std;

int main(int argc,char** argv){
	double x =1;
	double y =1;
	double z =1;
	
	Posizione P(x,y,z);
    //coordinate cartesiane
	cout<<"Posizione in coordinate cartesiane : "<<P.getX()<<" "<<P.getY()<<" "<<P.getZ()<<endl;
	//coordinate cilindriche 
	cout<<"Posizione in coordinate cilindriche : "<<P.getRho()<<" "<<P.getPhi()<<" "<<P.getZ()<<endl;
	//coordinate sferiche
	cout<<"Posizione in coordinate sferiche : "<<P.getR()<<" "<<P.getPhi()<<" "<<P.getTheta()<<endl;

	return 0;
}
