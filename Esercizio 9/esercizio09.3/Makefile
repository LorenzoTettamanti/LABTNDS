LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

esegui:
	./main 
compila:esercizio09.3.cpp EquazioniDifferenziali.h EquazioniDifferenziali.cpp VectorOperations.h
	g++ -o main esercizio09.3.cpp EquazioniDifferenziali.h EquazioniDifferenziali.cpp VectorOperations.h ${INCS} ${LIBS}

clean:
	rm main