LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

compila: Dipolo
esegui: 
	./Dipolo 0 0 0

Dipolo: pm.o Particella.o PuntoMateriale.o CampoVettoriale.o Posizione.o
	g++ -o Dipolo pm.o Particella.o PuntoMateriale.o Posizione.o CampoVettoriale.o ${INCS} ${LIBS} 

pm.o: Dipolo.cpp Particella.h PuntoMateriale.h CampoVettoriale.h Posizione.h
	g++ -c -o pm.o Dipolo.cpp ${INCS} ${LIBS} 
Particella.o: Particella.cxx Particella.h
	g++ -c -o Particella.o Particella.cxx  
PuntoMateriale.o: PuntoMateriale.cxx PuntoMateriale.h
	g++ -c -o PuntoMateriale.o PuntoMateriale.cxx  
CampoVettoriale.o: CampoVettoriale.cxx CampoVettoriale.h
	g++ -c -o CampoVettoriale.o CampoVettoriale.cxx  
Posizione.o: Posizione.cxx Posizione.h
	g++ -c -o Posizione.o Posizione.cxx 
	
clean:
	rm *.o 

cleanall: 
	rm *.o Dipolo
