CFLAGS=-c

saludo:hola.o
	$(CXX) hola.o -o saludo

hola.o: main.cpp
	$(CXX) main.cpp tipos.cpp Clases/*.cpp -o FingMVD

clean:
	$(RM) *.o saludo core
