LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

esegui:
	./main 10000 data.dat
compila: main.cpp funzioni.h
	g++ -o main main.cpp funzioni.h ${INCS} ${LIBS} 

clean:
	rm main
        
