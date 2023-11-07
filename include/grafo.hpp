#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <iostream>
#include "vertice.hpp"

class Grafo {
    public:
        Grafo() {tamanho = 0; primeiro = nullptr; ultimo = nullptr;};
        Grafo(int tamanho_);
        ~Grafo();
        void setTamanho(int tamanho_) {tamanho = tamanho_;};
        int getTamanho() {return tamanho;};
        Vertice* getPrimeiro() {return primeiro;};
        Vertice* getUltimo() {return ultimo;};
        bool vazio() {return (tamanho == 0);};
        void imprime();

    private:
        int tamanho;
        Vertice* primeiro;
        Vertice* ultimo;
};

#endif // GRAFO_HPP
// Path: include/vertice.hpp