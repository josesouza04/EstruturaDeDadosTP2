#include <iostream>
#include "grafo.hpp"

int main() {
    int tamanhoGrafo = 0;
    std::cout << "Digite o tamanho do grafo: ";
    std::cin >> tamanhoGrafo;
    std::cout << std::endl;

    Grafo* grafo = new Grafo(tamanhoGrafo);
    if(grafo->getTamanho() == tamanhoGrafo) {
        std::cout << "Grafo criado com sucesso!" << std::endl;
        std::cout << "O tamanho do grafo é: " << grafo->getTamanho() << std::endl;
        grafo->imprime();
        std::cout << std::endl;
    } else {
        throw std::runtime_error("Erro ao criar grafo!");
    }

    return 0;
}

// Path: src/main.cpp