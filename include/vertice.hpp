#ifndef VERTICE_HPP
#define VERTICE_HPP

class Vertice {
    public:
        Vertice() {id = 0; coloracao = 0;};
        Vertice(int id_) {id = id_; coloracao = 0;};
        void setId(int id_) {id = id_;};
        void setColor(int color_) {coloracao = color_;};
        void setProximo(Vertice* proximo_) {proximo = proximo_;};
        int getId() {return id;};
        int getColor() {return coloracao;};
        Vertice* getProximo() {return proximo;};

    private:
        int id;
        int coloracao;
        Vertice* proximo;
};

#endif // VERTICE_HPP
// Path: include/vertice.hpp