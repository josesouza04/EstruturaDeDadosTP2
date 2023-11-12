#include "grafo.hpp"

Grafo::Grafo() {
    // Inicializa os atributos do grafo como nulos
    tamanho = 0;
    primeiroVertice = nullptr;
    ultimoVertice = nullptr;
}

Grafo::Grafo(int tamanho_) { // O(n)
    // Cria um grafo ordenado numericamente
    tamanho = tamanho_;
    primeiroVertice = new Vertice(0);
    Vertice* verticeAtual = primeiroVertice;
    for (int i = 1; i < tamanho; i++) {
        Vertice* novoVertice = new Vertice(i);
        verticeAtual->setProximo(novoVertice);
        verticeAtual = novoVertice;
    }
}

Grafo::~Grafo() { // O(n)
    Vertice* verticeAtual = primeiroVertice;
    Vertice* verticeProximo = nullptr;
    while (verticeAtual != nullptr) { // Percorre a lista de vértices
        verticeProximo = verticeAtual->getProximo();
        delete verticeAtual; // Deleta vértice por vértice
        verticeAtual = verticeProximo;
    }

}

void Grafo::setTamanho(int tamanho_) {
    tamanho = tamanho_;
}

void Grafo::setPrimeiroVertice(Vertice* primeiroVertice_) {
    primeiroVertice = primeiroVertice_;
}

void Grafo::setUltimoVertice(Vertice* ultimoVertice_) {
    ultimoVertice = ultimoVertice_;
}

int Grafo::getTamanho() {
    return tamanho;
}

Vertice* Grafo::getPrimeiroVertice() {
    return primeiroVertice;
}

Vertice* Grafo::getUltimoVertice() {
    return ultimoVertice;
}

Vertice* Grafo::getVertice(int id_) { // O(n)
    Vertice* verticeAtual = primeiroVertice;
    while (verticeAtual != nullptr) { // Percorre a lista de vértices
        if (verticeAtual->getId() == id_) {
            return verticeAtual; // Ponteiro para o vértice encontrado
        }
        verticeAtual = verticeAtual->getProximo();
    }
    return nullptr; // Vértice não encontrado
}

bool Grafo::vazio() {
    return (tamanho == 0);
}

void Grafo::imprime() { // O(n)
    Vertice* verticeAtual = primeiroVertice;
    while (verticeAtual != nullptr) { // Percorre a lista de vértices
        std::cout << verticeAtual->getId() << "(" << verticeAtual->getColor() << ")" << " ";
        verticeAtual = verticeAtual->getProximo();
    }
    std::cout << std::endl;
}

void Grafo::insereAresta(int idA_, int idB_) { // O(n)
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

void Grafo::imprimeVizinhos(int id_) { // O(n)
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

void Grafo::coloreArestas() { // O(n^2)
    // Colore os vizinhos de cada vértice com a mesma cor do vértice referido
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

bool Grafo::guloso() { // O(n^2)
    // Checa se a coloração do grafo é gulosa
    // Coloração gulosa: cada vértice tem pelo menos um vizinho com cada cor menor que a dele
    Vertice* verticeAtual = primeiroVertice;
    for (int i = 0; i < tamanho; i++) { // Percorre a lista de vértices
        Vertice* vizinhoAtual = verticeAtual->getProximoVizinho();
        int corAtual = verticeAtual->getColor(), corEsperada = 1;
        while (corEsperada < corAtual) { // Percorre as cores menores que a do vértice atual
            int encontrouCor = 0;
            while (vizinhoAtual != nullptr) { // Percorre a lista de vizinhos
                if (vizinhoAtual->getColor() == corEsperada) {
                    encontrouCor = 1;
                    break;
                }
                vizinhoAtual = vizinhoAtual->getProximoVizinho();
            }
            if (encontrouCor == 0) { // Se não encontrou um vizinho com a cor esperada
                return false;
            }
            corEsperada++;
        }
        verticeAtual = verticeAtual->getProximo();
    }
    return true;
}

// Path: src/grafo.cpp