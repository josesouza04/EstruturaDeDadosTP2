#ifndef VERTICE_HPP
#define VERTICE_HPP

#include <chrono>

class Vertice {
    public:
        // Construtores
        Vertice();
        Vertice(int id_);

        // Funções de manipulação do Vértice
        void setId(int id_);
        void setColor(int color_);
        void setProximo(Vertice* proximo_);
        void setProximoVizinho(Vertice* proximoVizinho_);
        int getId();
        int getColor();
        Vertice* getProximo();
        Vertice* getProximoVizinho();

    private:
        // Atributos do Vértice
        int id;
        int coloracao;
        Vertice* proximo; // Ponteiro para o próximo vértice da lista
        Vertice* proximoVizinho; // Ponteiro para o próximo vizinho do vértice
};

#endif // VERTICE_HPP
// Path: include/vertice.hpp