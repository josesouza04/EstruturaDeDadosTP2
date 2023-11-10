#ifndef VERTICE_HPP
#define VERTICE_HPP


class Vertice {
    public:
        // Construtores
        Vertice() {id = 0; coloracao = 0; proximo = nullptr; proximoVizinho = nullptr;}; 
        Vertice(int id_) {id = id_; coloracao = 0; proximo = nullptr; proximoVizinho = nullptr;};

        // Funções de manipulação do Vértice
        void setId(int id_) {id = id_;};
        void setColor(int color_) {coloracao = color_;};
        void setProximo(Vertice* proximo_) {proximo = proximo_;};
        void setProximoVizinho(Vertice* proximoVizinho_) {proximoVizinho = proximoVizinho_;};
        int getId() {return id;};
        int getColor() {return coloracao;};
        Vertice* getProximo() {return proximo;};
        Vertice* getProximoVizinho() {return proximoVizinho;};

    private:
        int id;
        int coloracao;
        Vertice* proximo;
        Vertice* proximoVizinho;
};

/*

#include <iostream>

class Vertice {
    public:
        Vertice() {id = 0; coloracao = 0; vizinhos = NULL; numVizinhos = 0;};
        Vertice(int id_) : Vertice() {id = id_;};
        void setId(int id_) {id = id_;};
        void setColor(int color_) {coloracao = color_;};
        int getId() {return id;};
        int getColor() {return coloracao;};
        int getVizinho(int i) {return vizinhos[i];};
        int getNumVizinhos() {return numVizinhos;};
        void insereVizinho(int id_) {vizinhos[numVizinhos] = id_; numVizinhos++;};
        void imprimeVizinhos();
    private:
        int id;
        int coloracao;
        int* vizinhos;
        int numVizinhos;
};
*/
#endif // VERTICE_HPP
// Path: include/vertice.hpp