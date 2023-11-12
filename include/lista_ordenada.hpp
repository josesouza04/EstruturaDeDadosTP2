#ifndef LISTA_ORDENADA_HPP
#define LISTA_ORDENADA_HPP

#include "grafo.hpp"

class ListaOrdenada {
    public:
        // Construtores
        ListaOrdenada();
        ListaOrdenada(Grafo* grafo_);
        ~ListaOrdenada();

        // Chamadas de funções de ordenação
        void bubbleSort(); // Ordenação por bolha
        void selectionSort(); // Ordenação por seleção
        void insertionSort(); // Ordenação por inserção
        void quickSort(); // Ordenação rápida (falta por id)
        void mergeSort(); // Ordenação por intercalação
        void heapSort(); // Ordenação por heap (falta por id)
        void mySort(); // Ordenação própria

        // Funções auxiliares
        void particao(int esq_, int dir_, int* i_, int* j_); // Função auxiliar do quickSort
        void ordena(int esq_, int dir_); // Função auxiliar do quickSort
        Vertice* merge(Vertice* vetorEsq_, Vertice* vetorDir_, int tamanhoEsq_, int tamanhoDir_); // Função auxiliar do mergeSort
        Vertice* mergeSortDivide(Vertice* vetor_, int tamanho_); // Função auxiliar do mergeSort
        Vertice* heapSortAux(Vertice* vetor_, int tamanho_); // Função auxiliar do heapSort

        void imprime(); // Função para imprimir a lista de vértices ordenada por cor
        void troca(int i_, int j_); // Função para trocar dois vértices de posição
    private:
        // Atributos da lista ordenada
        Vertice* vertices; // Vetor de vértices do grafo
        int tamanho;

};

#endif // LISTA_ORDENADA_HPP
// Path: include/lista_ordenada.hpp