#ifndef LISTA_HPP
#define LISTA_HPP

#include <iostream>

template <class Elemento>
class Lista {
    public:
        Lista() {tamanho = 0; primeiro = nullptr; ultimo = nullptr;};
        Lista(int tamanho_);
        ~Lista();
        void setTamanho(int tamanho_) {tamanho = tamanho_;};
        int getTamanho() {return tamanho;};
        Elemento* getPrimeiro() {return primeiro;};
        Elemento* getUltimo() {return ultimo;};
        bool vazio() {return (tamanho == 0);};
        void imprime();
    private:
        int tamanho;
        Elemento* primeiro;
        Elemento* ultimo;
};

#endif // LISTA_HPP
// Path: include/lista.hpp