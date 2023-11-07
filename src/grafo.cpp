#include "grafo.hpp"

Grafo::Grafo(int tamanho_) {
    tamanho = tamanho_;
    primeiroVertice = new Vertice(0);
    ultimoVertice = primeiroVertice;
    for (int i = 1; i < tamanho; i++) {
        Vertice* novoVertice = new Vertice(i);
        ultimoVertice->setProximo(novoVertice);
        ultimoVertice = novoVertice;
    }
}

Grafo::~Grafo() {
    Vertice* verticeAtual = primeiroVertice;
    Vertice* verticeProximo = nullptr;
    while (verticeAtual != nullptr) {
        verticeProximo = verticeAtual->getProximo();
        delete verticeAtual;
        verticeAtual = verticeProximo;
    }
}

void Grafo::imprime() {
    Vertice* verticeAtual = primeiroVertice;
    while (verticeAtual != nullptr) {
        std::cout << verticeAtual->getId() << " ";
        verticeAtual = verticeAtual->getProximo();
    }
    std::cout << std::endl;
}
 
// Path: src/grafo.cpp