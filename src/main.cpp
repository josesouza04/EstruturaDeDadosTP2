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
    
    int confirma = 1;
    int idA, idB;
    while(confirma) {
        std::cout << "Deseja adicionar uma aresta? (1/0) ";
        std::cin >> confirma;
        std::cout << std::endl;
        if(confirma) {
            std::cout << "Digite o id do primeiro vértice: ";
            std::cin >> idA;
            std::cout << std::endl;
            std::cout << "Digite o id do segundo vértice: ";
            std::cin >> idB;
            std::cout << std::endl;
            grafo->insereAresta(idA, idB);
            std::cout << "Aresta adicionada com sucesso!" << std::endl;
        }
    }
    std::cout << "_________________________" << std::endl;
    std::cout << "Grafo final:" << std::endl;
    grafo->imprime();

    confirma = 1;
    int id;
    while(confirma) {
        std::cout << "Deseja imprimir os vizinhos de algum vértice? (1/0) ";
        std::cin >> confirma;
        std::cout << std::endl;
        if(confirma) {
            std::cout << "Digite o id do vértice: ";
            std::cin >> id;
            std::cout << std::endl;
            grafo->imprimeVizinhos(id);
        }
    }
    std::cout << "_________________________" << std::endl;
    
    return 0;
}

// Path: src/main.cpp