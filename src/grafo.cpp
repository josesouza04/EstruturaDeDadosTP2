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

Vertice* Grafo::getVertice(int id_) {
    Vertice* verticeAtual = primeiroVertice;
    while (verticeAtual != nullptr) {
        if (verticeAtual->getId() == id_) {
            return verticeAtual;
        }
        verticeAtual = verticeAtual->getProximo();
    }
    return nullptr;

}

void Grafo::imprime() {
    Vertice* verticeAtual = primeiroVertice;
    while (verticeAtual != nullptr) {
        std::cout << verticeAtual->getId() << " ";
        verticeAtual = verticeAtual->getProximo();
    }
    std::cout << std::endl;
}

void Grafo::insereAresta(int idA_, int idB_) {
    Vertice* verticeAtual = primeiroVertice;
    while (verticeAtual != nullptr) {
        if (verticeAtual->getId() == idA_) {
            Vertice* novoVizinho = new Vertice(idB_);
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
        if (verticeAtual->getId() == idB_) {
            Vertice* novoVizinho = new Vertice(idA_);
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

void Grafo::imprimeVizinhos(int id_) {
    Vertice* verticeAtual = primeiroVertice;
    while (verticeAtual != nullptr) {
        if (verticeAtual->getId() == id_) {
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