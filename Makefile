all: programa

programa: main.o fuerzaBruta.o programacionDinamica.o costos.o
	g++ -g -o programa main.o fuerzaBruta.o programacionDinamica.o costos.o

main.o: main.cpp headers/fuerzaBruta.h headers/programacionDinamica.h
	g++ -c main.cpp

costos.o: implementaciones/costos.cpp headers/costos.h
	g++ -c implementaciones/costos.cpp

fuerzaBruta.o: implementaciones/fuerzaBruta.cpp headers/fuerzaBruta.h headers/costos.h
	g++ -c implementaciones/fuerzaBruta.cpp

programacionDinamica.o: implementaciones/programacionDinamica.cpp headers/programacionDinamica.h headers/costos.h
	g++ -c implementaciones/programacionDinamica.cpp

run: programa
	./programa

clean:
	rm -f programa *.o