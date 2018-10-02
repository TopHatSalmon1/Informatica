
INCS=`root-config --cflags` 
LIBS=`root-config --libs`


compila: esame.o dlcgold.o
	g++ esame.o dlcgold.o -o esame.x ${INCS} ${LIBS}

esame.o: esame.C dlcgold.h
	g++ esame.C -c ${INCS} 
dlcgold.o: dlcgold.C dlcgold.h
	g++ dlcgold.C -c
esegui:	esame.x
	./esame.x>risultati.dat
