LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

esegui:
	./main
compila: main.cpp RandomGen.h EsperimentoPrisma.cpp EsperimentoPrisma.h print_buffer.h Variables.h
	g++ -o main main.cpp RandomGen.h EsperimentoPrisma.cpp EsperimentoPrisma.h print_buffer.h  Variables.h ${LIBS} ${INCS}

clean:
	rm main