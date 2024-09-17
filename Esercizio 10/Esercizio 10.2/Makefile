LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

esegui:
	./main

compila: main.cpp IntegralMC.h FunzioneBase.h Seno.h print_buffer.h
	g++ -o main main.cpp IntegralMC.h FunzioneBase.h Seno.h print_buffer.h ${LIBS} ${INCS}

clean:
	rm main