LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

esegui:
	./main 
compila:esercizio09.1.cpp EquazioniDifferenziali.h EquazioniDifferenziali.cpp VectorOperations.h print_buffer.h
	g++ -o main esercizio09.1.cpp EquazioniDifferenziali.h EquazioniDifferenziali.cpp VectorOperations.h print_buffer.h ${INCS} ${LIBS}

clean:
	rm main
        

