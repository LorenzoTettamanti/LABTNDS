LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

esegui:
	./main
compila: main.cpp RandomGen.h 
	g++ -o main main.cpp RandomGen.h ${LIBS} ${INCS}

clean:
	rm main