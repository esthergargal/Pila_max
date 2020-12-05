# Esther García Gallego
# INGENIERÍA INFORMÁTICA 2ºB
# Práctica 3 ED - Pila max


# Carpeta donde se guardan los objetos
BIN = ./bin
# Compilador
CC = g++
DOC = ./doc
# Carpeta donde se guardan los .h
INCLUDE = ./include
# Carpeta donde se guardan los objetos
OBJ = ./obj
# Carpeta donde se guardan los .cpp
SRC = ./src
# Navegador
BROWSER = firefox



pila_max_vd: $(OBJ)/pila_max_vd.o
	$(CC) -D CUAL_COMPILA=1 -o $(BIN)/pila_max_vd -I$(INCLUDE) $(SRC)/usopilas_max.cpp $(OBJ)/pila_max_vd.o


pila_max_cola: $(OBJ)/pila_max_cola.o
	$(CC) -D CUAL_COMPILA=2 -o $(BIN)/pila_max_cola -I$(INCLUDE) $(SRC)/usopilas_max.cpp $(OBJ)/pila_max_cola.o


$(OBJ)/pila_max_vd.o:
	$(CC) -c $(SRC)/Pila_max_VD.cpp -I$(INCLUDE) -o $(OBJ)/pila_max_vd.o


$(OBJ)/pila_max_cola.o: 
	$(CC) -c $(SRC)/Pila_max_Cola.cpp -I$(INCLUDE) -o $(OBJ)/pila_max_cola.o

clean:
	echo "Limpiando..."
	rm -f $(OBJ)/* $(BIN)/*

doxy:
	echo "Creando documentación..."
	doxygen pila_max

display_doxy:
	echo "Mostrando documentación..."
	$(BROWSER) ./doc/html/index.html &
