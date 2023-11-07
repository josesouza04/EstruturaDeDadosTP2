#include <iostream>
#include "grafo.hpp"

int main() {
    char tipoOrdena;
    int tamanhoGrafo = 0, idA = 0, idB = 0, numVizinhos = 0, color = 0;
    std::cin >> tipoOrdena >> tamanhoGrafo;
    Grafo* grafo = new Grafo(tamanhoGrafo);

    for (int i = 0; i < tamanhoGrafo; i++) {
        std::cin >> numVizinhos;
        idA = i;
        for (int j = 0; j < numVizinhos; j++) {
            std::cin >> idB;
            grafo->insereAresta(idA, idB);
        }
    }

    for (int k = 0; k < tamanhoGrafo; k++) {
        std::cin >> color;
        grafo->getVertice(k)->setColor(color);
    }

    std::cout << "-------------------" << std::endl;
    
    //imprimir grafo
    for (int i = 0; i < tamanhoGrafo; i++) {
        std::cout << i << ": cor: " << grafo->getVertice(i)->getColor();
        std::cout << " vizinhos: ";
        grafo->imprimeVizinhos(i);
    }

    std::cout << "-------------------" << std::endl;

    return 0;
}

// Path: src/main.cpp