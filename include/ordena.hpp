#ifndef ORDENA_HPP
#define ORDENA_HPP

#include "grafo.hpp"

class Ordena {
    public:
        void Troca(Vertice* a, Vertice* b);
        void bubbleSort(Grafo* grafo_, int tamanho_);
};

#endif // ORDENA_HPP
// Path: include/ordena.hpp