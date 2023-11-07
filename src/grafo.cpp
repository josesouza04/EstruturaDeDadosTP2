#include "grafo.hpp"

Grafo::Grafo(int tamanho_) {
    tamanho = tamanho_;
    primeiroVertice = new Vertice(0);
    Vertice* verticeAtual = primeiroVertice;
    for (int i = 1; i < tamanho; i++) {
        Vertice* novoVertice = new Vertice(i);
        verticeAtual->setProximo(novoVertice);
        verticeAtual = novoVertice;
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

void Grafo::insereAresta(int idA, int idB) {
    Vertice* verticeAtual = primeiroVertice;
    while (verticeAtual != nullptr) {
        if (verticeAtual->getId() == idA) {
            Vertice* novoVizinho = new Vertice(idB);
            Vertice* vizinhoAtual = verticeAtual->getProximoVizinho();
            if (vizinhoAtual == nullptr) {
                verticeAtual->setProximoVizinho(novoVizinho);
            } else {
                while (vizinhoAtual->getProximoVizinho() != nullptr) {
                    vizinhoAtual = vizinhoAtual->getProximoVizinho();
                }
                vizinhoAtual->setProximoVizinho(novoVizinho);
            }
        }
        if (verticeAtual->getId() == idB) {
            Vertice* novoVizinho = new Vertice(idA);
            Vertice* vizinhoAtual = verticeAtual->getProximoVizinho();
            if (vizinhoAtual == nullptr) {
                verticeAtual->setProximoVizinho(novoVizinho);
            } else {
                while (vizinhoAtual->getProximoVizinho() != nullptr) {
                    vizinhoAtual = vizinhoAtual->getProximoVizinho();
                }
                vizinhoAtual->setProximoVizinho(novoVizinho);
            }
        }
        verticeAtual = verticeAtual->getProximo();
    }
}

void Grafo::imprimeVizinhos(int id) {
    Vertice* verticeAtual = primeiroVertice;
    while (verticeAtual != nullptr) {
        if (verticeAtual->getId() == id) {
            Vertice* vizinhoAtual = verticeAtual->getProximoVizinho();
            while (vizinhoAtual != nullptr) {
                std::cout << vizinhoAtual->getId() << " ";
                vizinhoAtual = vizinhoAtual->getProximoVizinho();
            }
            std::cout << std::endl;
        }
        verticeAtual = verticeAtual->getProximo();
    }
}

// Path: src/grafo.cpp