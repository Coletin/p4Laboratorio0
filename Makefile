CFLAGS=-c
CC = g++ # gcc -x c 

all: main.cpp
	$(CC) -Wall -Werror -I$Clases main.cpp tipos.cpp Clases/*.cpp -std=gnu++0x -o FingVMB -g # -DNDEBUG 

# clean:
# 	$(RM) *.o saludo core

EJECUTABLE=FingVMB
TESTDIR = test





# casos de prueba
CASOS = 00 01
# cadena de archivos, con directorio y extensión
INS=$(CASOS:%=$(TESTDIR)/%.in)
OUTS=$(CASOS:%=$(TESTDIR)/%.out)
SALS=$(CASOS:%=$(TESTDIR)/%.sal)
DIFFS=$(CASOS:%=$(TESTDIR)/%.diff)

$(SALS):$(EJECUTABLE)
# el guión antes del comando es para que si hay error no se detenga la
# ejecución de los otros casos
$(TESTDIR)/%.sal:$(TESTDIR)/%.in
	-timeout 4  ./$(EJECUTABLE) < $< > $@ 2>&1
	@if [ $$(stat -L -c %s $@) -ge 200000000 ]; then \
		echo "tamaño excedido" > $@;\
	fi

# test de tiempo
# para estos test puede ser conveniente agregar -DNDEBUG en la variable CCFLAGS
#$(TESTDIR)/t-ultimos.sal:$(TESTDIR)/t-ultimos.in
#	-timeout 5 ./$(EJECUTABLE) < $< > $@ 2>&1
#$(TESTDIR)/t-avl.sal:$(TESTDIR)/t-avl.in
#	-timeout 10 ./$(EJECUTABLE) < $< > $@ 2>&1
#$(TESTDIR)/t-map.sal:$(TESTDIR)/t-map.in
#	-timeout 5 ./$(EJECUTABLE) < $< > $@ 2>&1
#$(TESTDIR)/t-cp.sal:$(TESTDIR)/t-cp.in
#	-timeout 5 ./$(EJECUTABLE) < $< > $@ 2>&1
#$(TESTDIR)/t-grafo.sal:$(TESTDIR)/t-grafo.in
#	-timeout 10 ./$(EJECUTABLE) < $< > $@ 2>&1


%.diff:Makefile
# cada .diff depende de su .out y de su .sal
%.diff: %.out %.sal
	@diff $^ > $@;                                            \
	if [ $$? -ne 0 ];                                         \
	then                                                      \
		echo ---- ERROR en caso $@ ----;                  \
	fi
# Con $$? se obtiene el estado de salida del comando anterior.
# En el caso de `diff', si los dos archivos comparados no son iguales,
# el estado de la salida no es 0 y en ese caso se imprime el mensaje.




# Test general. Las dependencias son los .diff.
# Con `find` se encuentran los .diff de tamaño > 0 que están en el directorio
# $(TESTDIR) y lo asigna a $(LST_ERR).
# Si el tamaño de $(LST_ERR) no es cero imprime los casos con error.
# Con `sed` se elimina el nombre de directorio y la extensión.
testing:all $(DIFFS)
	@LST_ERR=$$(find $(TESTDIR) -name *.diff* -size +0c -print);             \
	if [ -n "$${LST_ERR}" ];                                                \
	then                                                                    \
		echo -- CASOS CON ERRORES --;                                   \
		echo "$${LST_ERR}" | sed -e 's/$(TESTDIR)\///g' -e 's/.diff//g';\
	fi

# Genera el entregable.
ENTREGA=Entrega5.tar.gz
CPPS_ENTREGA =  colaDePrioridad.cpp mapping.cpp grafo.cpp
entrega:
	@rm -f $(ENTREGA)
	tar zcvf $(ENTREGA) -C src $(CPPS_ENTREGA)
	@echo --        El directorio y archivo a entregar es:
	@echo $$(pwd)/$(ENTREGA)


# borra binarios
clean_bin:
	@rm -f $(EJECUTABLE) $(ODIR)/$(PRINCIPAL).o $(OS)

# borra resultados de ejecución y comparación
clean_test:
	@rm -f $(TESTDIR)/*.sal $(TESTDIR)/*.diff

# borra binarios, resultados de ejecución y comparación, y copias de respaldo
clean:clean_test clean_bin
	@rm -f *~ $(HDIR)/*~ $(CPPDIR)/*~ $(TESTDIR)/*~



check-syntax:
	gcc -o nul -S ${CHK_SOURCES}
