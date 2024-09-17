#include<iostream>
#include<cstdlib>
#include "FunzioneBase.h"
#include "Parabola.h"

using namespace std;

int main(int argc,char** argv){
	
	double a=atof(argv[1]);
	double b=atof(argv[2]);
	double c=atof(argv[3]);

	cout<<"test della classe parabola"<<endl;
	//Parabola p(a,b,c);
	Parabola *p = new Parabola(a,b,c);
	cout<<"vertice = "<<p->GetVertex()<<endl;
	

		


	return 0;
}