LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

esegui:
	./main 1000000
compila: main.cpp Integral.h Integral.cpp FunzioneBase.h Seno.h
	g++ -o main main.cpp Integral.h Integral.cpp FunzioneBase.h Seno.h ${LIBS} ${INCS}

clean:
	rm main