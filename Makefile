CC = g++
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/vertice.o $(OBJ)/grafo.o
HDRS = $(INC)/vertice.hpp $(INC)/grafo.hpp 
CFLAGS = -Wall -g -c -I $(INC) -std=c++11

EXE = $(BIN)/tp2.out

.PHONY: all clean

run: all
	$(EXE)

all: $(EXE)

$(BIN)/tp2.out: $(OBJS)
	$(CC) -std=c++11 -g -o $(BIN)/tp2.out $(OBJS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/vertice.o: $(HDRS) $(SRC)/vertice.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/vertice.o $(SRC)/vertice.cpp

$(OBJ)/grafo.o: $(HDRS) $(SRC)/grafo.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/grafo.o $(SRC)/grafo.cpp

clean:
	rm -f $(EXE) $(OBJS) gmon.out