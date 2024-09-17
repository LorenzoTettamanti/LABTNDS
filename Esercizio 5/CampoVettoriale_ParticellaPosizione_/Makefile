compila: PuntoMateriale
esegui: 
	./puntomateriale

PuntoMateriale: pm.o Particella.o PuntoMateriale.o CampoVettoriale.o Posizione.o
	g++ -o puntomateriale pm.o Particella.o PuntoMateriale.o Posizione.o CampoVettoriale.o

pm.o: PuntoMateriale.cpp Particella.h PuntoMateriale.h CampoVettoriale.h Posizione.h
	g++ -c -o pm.o PuntoMateriale.cpp 
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
	rm *.o puntomateriale
