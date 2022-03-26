CFLAGS=-c


principal: main.cpp
	$(CXX) main.cpp tipos.cpp Clases/*.cpp -std=gnu++0x -o FingVMB

clean:
	$(RM) *.o saludo core
