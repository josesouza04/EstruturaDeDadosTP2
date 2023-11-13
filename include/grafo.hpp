#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <iostream>
#include "vertice.hpp"

class Grafo {
    public:
        // Construtores e destrutor
        Grafo();
        Grafo(int tamanho_); // Construtor que recebe o tamanho do grafo e cria um grafo ordenado numericamente
        // O(n)
        ~Grafo();

        // Funções de manipulação do Grafo
        void setTamanho(int tamanho_);
        void setPrimeiroVertice(Vertice* primeiroVertice_);
        void setUltimoVertice(Vertice* ultimoVertice_);
        int getTamanho();
        Vertice* getPrimeiroVertice();
        Vertice* getUltimoVertice();
        Vertice* getVertice(int id_);
        bool vazio();
        void imprime();

        // Tratamento dos vértices e seus vizinhos
        void insereAresta(int idA_, int idB_); // O(n)
        void imprimeVizinhos(int id_); // O(n)
        void coloreArestas(); // O(n^2)

        bool guloso();

    private:
        // Atributos do Grafo
        int tamanho;
        Vertice* primeiroVertice; // Ponteiro para o primeiro vértice do grafo
        Vertice* ultimoVertice; // Ponteiro para o último vértice do grafo
};

#endif // GRAFO_HPP
// Path: include/vertice.hpp