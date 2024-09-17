esegui:
	./main
compila: pe
pe: pe.o Particella.o Elettrone.o
	g++ -o main pe.o Elettrone.o Particella.o
pe.o: ParticellaElettrone.cpp Particella.h Elettrone.h
	g++ -c -o pe.o ParticellaElettrone.cpp
Elettrone.o: Elettrone.cxx Elettrone.h
	g++ -c -o Elettrone.o Elettrone.cxx
Particella.o: Particella.cxx Particella.h
	g++ -c -o Particella.o Particella.cxx

clean:
	rm *.o 

cleanall: 
	rm *.o main
