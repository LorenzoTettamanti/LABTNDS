esegui: 
	./posizione
compila: posizione
posizione: main.o Posizione.o 
	g++ -o posizione main.o Posizione.o
main.o: posizione.cpp Posizione.h 
	g++ -c -o main.o posizione.cpp
Posizione.o: Posizione.cxx Posizione.h
	g++ -c -o Posizione.o Posizione.cxx

cleanall:
	rm *.o posizione