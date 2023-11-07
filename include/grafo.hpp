#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <iostream>
#include "vertice.hpp"

class Grafo {
    public:
        // Construtores e destrutor
        Grafo() {tamanho = 0; primeiroVertice = nullptr; ultimoVertice = nullptr;};
        Grafo(int tamanho_); // Construtor que recebe o tamanho do grafo e cria um grafo ordenado numericamente
        ~Grafo();

        // Funções de manipulação do Grafo
        void setTamanho(int tamanho_) {tamanho = tamanho_;};
        void setPrimeiroVertice(Vertice* primeiroVertice_) {primeiroVertice = primeiroVertice_;};
        void setUltimoVertice(Vertice* ultimoVertice_) {ultimoVertice = ultimoVertice_;};
        int getTamanho() {return tamanho;};
        Vertice* getPrimeiroVertice() {return primeiroVertice;};
        Vertice* getUltimoVertice() {return ultimoVertice;};
        Vertice* getVertice(int id_);
        bool vazio() {return (tamanho == 0);};
        void imprime();

        // Tratamento dos vértices e seus vizinhos
        void insereAresta(int idA_, int idB_);
        void imprimeVizinhos(int id_);

    private:
        int tamanho;
        Vertice* primeiroVertice; // Ponteiro para o primeiro vértice do grafo
        Vertice* ultimoVertice; // Ponteiro para o último vértice do grafo
};

#endif // GRAFO_HPP
// Path: include/vertice.hpp