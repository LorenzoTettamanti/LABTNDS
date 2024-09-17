esegui:
	./main 10000 data.dat
compila: main.o Vettore.o funzioni.o
	g++ -o main main.o Vettore.o funzioni.o
main.o: main.cpp funzioni.h
	g++ -c -o main.o main.cpp
funzioni.o: funzioni.cxx funzioni.h
	g++ -c -o funzioni.o funzioni.cxx
Vettore.o: Vettore.cxx Vettore.h
	g++ -c -o Vettore.o Vettore.cxx

clean:
	rm *.o
cleanall:
	rm main *.o