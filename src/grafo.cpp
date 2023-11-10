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
    while (verticeAtual != nullptr) { // Percorre a lista de vértices
        verticeProximo = verticeAtual->getProximo();
        delete verticeAtual;
        verticeAtual = verticeProximo;
    }
}

Vertice* Grafo::getVertice(int id_) { 
    Vertice* verticeAtual = primeiroVertice;
    while (verticeAtual != nullptr) { // Percorre a lista de vértices
        if (verticeAtual->getId() == id_) {
            return verticeAtual; // Ponteiro para o vértice encontrado
        }
        verticeAtual = verticeAtual->getProximo();
    }
    return nullptr; // Vértice não encontrado
}

void Grafo::imprime() {
    Vertice* verticeAtual = primeiroVertice;
    while (verticeAtual != nullptr) {
        std::cout << verticeAtual->getId() << "(" << verticeAtual->getColor() << ")" << " ";
        verticeAtual = verticeAtual->getProximo();
    }
    std::cout << std::endl;
}

void Grafo::insereAresta(int idA_, int idB_) {
    Vertice* verticeAtual = primeiroVertice;
    while (verticeAtual != nullptr) { // Percorre a lista de vértices
        if (verticeAtual->getId() == idA_) {
            Vertice* novoVizinho = new Vertice(idB_);
            Vertice* corV = getVertice(idB_);
            if (corV != nullptr) {
                int cor = corV->getColor();
                novoVizinho->setColor(cor);
            }
            novoVizinho->setProximoVizinho(nullptr); // O novo vizinho não tem vizinho posterior a ele
            Vertice* vizinhoAtual = verticeAtual->getProximoVizinho();
            if (vizinhoAtual == nullptr) { // Se o vértice não tem vizinhos
                verticeAtual->setProximoVizinho(novoVizinho);
            } else {
                if (vizinhoAtual->getId() == idB_) return; // Se o vértice já é vizinho
                while (vizinhoAtual->getProximoVizinho() != nullptr) {
                    if (vizinhoAtual->getProximoVizinho()->getId() == idB_) return; // Se o vértice já é vizinho
                    vizinhoAtual = vizinhoAtual->getProximoVizinho();
                }
                vizinhoAtual->setProximoVizinho(novoVizinho);
            }
        }
        if (verticeAtual->getId() == idB_) {
            Vertice* novoVizinho = new Vertice(idA_);
            Vertice* corV = getVertice(idA_);
            if (corV != nullptr) {
                int cor = corV->getColor();
                novoVizinho->setColor(cor);
            }
            novoVizinho->setProximoVizinho(nullptr); // O novo vizinho não tem vizinho posterior a ele
            Vertice* vizinhoAtual = verticeAtual->getProximoVizinho();
            if (vizinhoAtual == nullptr) { // Se o vértice não tem vizinhos
                verticeAtual->setProximoVizinho(novoVizinho);
            } else {
                if (vizinhoAtual->getId() == idA_) return; // Se o vértice já é vizinho
                while (vizinhoAtual->getProximoVizinho() != nullptr) {
                    if (vizinhoAtual->getProximoVizinho()->getId() == idA_) return; // Se o vértice já é vizinho
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
            while (vizinhoAtual != nullptr) { // Percorre a lista de vizinhos
                std::cout << vizinhoAtual->getId() << "(" << vizinhoAtual->getColor() << ")" << " ";
                vizinhoAtual = vizinhoAtual->getProximoVizinho();
            }
            std::cout << std::endl;
        }
        verticeAtual = verticeAtual->getProximo();
    }
}

bool Grafo::guloso() {
    Vertice* verticeAtual = primeiroVertice;
    for (int i = 0; i < tamanho; i++) { // Percorre a lista de vértices
        Vertice* vizinhoAtual = verticeAtual->getProximoVizinho();
        int corAtual = verticeAtual->getColor(), corEsperada = 1;
        while (corEsperada < corAtual) {
            int encontrouCor = 0;
            while (vizinhoAtual != nullptr) { // Percorre a lista de vizinhos
                if (vizinhoAtual->getColor() == corEsperada) {
                    encontrouCor = 1;
                    break;
                }
                vizinhoAtual = vizinhoAtual->getProximoVizinho();
            }
            if (encontrouCor == 0) {
                return false;
            }
            corEsperada++;
        }
        verticeAtual = verticeAtual->getProximo();
    }
    return true;
}

void Grafo::coloreArestas() {
    for (int i = 0; i < tamanho; i++) {
        Vertice* verticeAtual = getVertice(i);
        for (int j = 0; j < tamanho; j++) {
            Vertice* verticeIterado = getVertice(j);
            Vertice* verticeVizinho = verticeIterado->getProximoVizinho();
            while (verticeVizinho != nullptr) {
                if (verticeAtual->getId() == verticeVizinho->getId()) {
                    verticeVizinho->setColor(verticeAtual->getColor());
                }
                verticeVizinho = verticeVizinho->getProximoVizinho();
            }
        }
    }
}

/*
void Grafo::imprime() {
    for (int i = 0; i < tamanho; i++) {
        std::cout << vertices[i].getId() << std::endl;
    }
}

bool Grafo::guloso() {
    int achouCor = 0, corEsperada = 0;
    for (int i = 0; i < tamanho; i++) {
        Vertice verticeAtual = vertices[i];
        corEsperada = verticeAtual.getColor() - 1;
        for (int j = verticeAtual.getColor() - 1; j > 0; j--) {
            for (int k = 0; k < verticeAtual.getNumVizinhos(); k++) {
                if (getVertice(verticeAtual.getVizinho(k)).getColor() == corEsperada) {
                    achouCor = 1;
                    break;
                }
            }
            if (achouCor == 0) return false;
            corEsperada--;
        }
    }
    return true;
}
*/

// Path: src/grafo.cpp