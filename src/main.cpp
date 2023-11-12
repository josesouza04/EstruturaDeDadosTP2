// Ultima edição: 11/11/2023
// Autor: José Gabriel Vieira de Souza
// Título: Coloração de grafos e ordenação
// TRABALHO PRÁTICO 2 DE ESTRUTURA DE DADOS - 2023/2

#include <iostream>
#include "lista_ordenada.hpp"

int main() {
    // Declaração de variáveis
    char tipoOrdena;
    int tamanhoGrafo = 0, idA = 0, idB = 0, numVizinhos = 0, color = 0;

    // Leitura de dados
    std::cin >> tipoOrdena >> tamanhoGrafo;
    Grafo* grafo = new Grafo(tamanhoGrafo); // Criação do grafo com o tamanho lido 
    //O(n)

    for (int i = 0; i < tamanhoGrafo; i++) { // Leitura de arestas
        // O(n^2)
        std::cin >> numVizinhos;
        idA = i;
        for (int j = 0; j < numVizinhos; j++) {
            std::cin >> idB;
            grafo->insereAresta(idA, idB); // O(n)
        }
    }
    // O(n^3)

    for (int k = 0; k < tamanhoGrafo; k++) {
        std::cin >> color;
        grafo->getVertice(k)->setColor(color);
    }
    // O(n^2)

    grafo->coloreArestas();
    // O(n^2)


    // Ordenação por cor
    ListaOrdenada* lista = new ListaOrdenada(grafo);

    switch (tipoOrdena) { // Tipo de ordenação
        // O(n^2) no pior caso
        case 'b':
            lista->bubbleSort();
            break;
        case 's':
            lista->selectionSort();
            break;
        case 'i':
            lista->insertionSort();
            break;
        case 'q':
            lista->quickSort();
            break;
        case 'm':
            lista->mergeSort();
            break;
        case 'p':
            lista->heapSort();
            break;
        case 'y':
            lista->mySort();
            break;
        default:
            break;
    }

    // Impressão de dados de saída
    if (grafo->guloso()) {
        std::cout << "1 "; // Grafo é guloso
        lista->imprime(); // Imprime os id's da lista ordenada por cor
    } else {
        std::cout << "0" << std::endl; // Grafo não é guloso
    }
    // O(n^2)

    // Desalocação de memória
    lista->~ListaOrdenada();
    grafo->~Grafo();

    return 0;
} 

// Path: src/main.cpp