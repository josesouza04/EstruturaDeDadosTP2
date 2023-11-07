#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <iostream>
#include "vertice.hpp"

class Grafo {
    public:
        Grafo() {tamanho = 0; primeiroVertice = nullptr; ultimoVertice = nullptr;};
        Grafo(int tamanho_);
        ~Grafo();
        void setTamanho(int tamanho_) {tamanho = tamanho_;};
        void setPrimeiroVertice(Vertice* primeiroVertice_) {primeiroVertice = primeiroVertice_;};
        void setUltimoVertice(Vertice* ultimoVertice_) {ultimoVertice = ultimoVertice_;};
        int getTamanho() {return tamanho;};
        Vertice* getPrimeiroVertice() {return primeiroVertice;};
        Vertice* getUltimoVertice() {return ultimoVertice;};
        bool vazio() {return (tamanho == 0);};
        void imprime();

    private:
        int tamanho;
        Vertice* primeiroVertice;
        Vertice* ultimoVertice;
};

#endif // GRAFO_HPP
// Path: include/vertice.hpp