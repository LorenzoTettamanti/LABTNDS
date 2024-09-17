LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

esegui:
	./main 500000
compila: main.cpp Simpson.h Simpson.cpp FunzioneBase.h Seno.h printbuffer.h
	g++ -o main main.cpp Simpson.h Simpson.cpp FunzioneBase.h Seno.h printbuffer.h ${LIBS} ${INCS}

clean:
	rm main