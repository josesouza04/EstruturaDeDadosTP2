#include "grafo.hpp"

Grafo::Grafo(int tamanho_) {
    tamanho = tamanho_;
    primeiro = new Vertice(0);
    ultimo = primeiro;
    for (int i = 1; i < tamanho; i++) {
        Vertice* novoVertice = new Vertice(i);
        ultimo->setProximo(novoVertice);
        ultimo = novoVertice;
    }
}

Grafo::~Grafo() {
    Vertice* atual = primeiro;
    Vertice* proximo = nullptr;
    while (atual != nullptr) {
        proximo = atual->getProximo();
        delete atual;
        atual = proximo;
    }
}

void Grafo::imprime() {
    Vertice* atual = primeiro;
    while (atual != nullptr) {
        std::cout << atual->getId() << " ";
        atual = atual->getProximo();
    }
    std::cout << std::endl;
}

// Path: src/grafo.cpp