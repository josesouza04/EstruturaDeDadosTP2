#include "vertice.hpp"

Vertice::Vertice() {
    // Inicializa os atributos do vértice como nulos
    id = 0;
    coloracao = 0;
    proximo = nullptr;
    proximoVizinho = nullptr;
}

Vertice::Vertice(int id_) : Vertice() {
    // Inicializa o id do vértice com o valor passado como parâmetro
    if (id_ < 0) throw "Id do vértice não pode ser negativo!";
    id = id_;
}

void Vertice::setId(int id_) {
    id = id_;
}

void Vertice::setColor(int color_) {
    coloracao = color_;
}

void Vertice::setProximo(Vertice* proximo_) {
    proximo = proximo_;
}

void Vertice::setProximoVizinho(Vertice* proximoVizinho_) {
    proximoVizinho = proximoVizinho_;
}

int Vertice::getId() {
    return id;
}

int Vertice::getColor() {
    return coloracao;
}

Vertice* Vertice::getProximo() {
    return proximo;
}

Vertice* Vertice::getProximoVizinho() {
    return proximoVizinho;
}

// Path: src/vertice.cpp