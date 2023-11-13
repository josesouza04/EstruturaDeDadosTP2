#include "lista_ordenada.hpp"

ListaOrdenada::ListaOrdenada() {
    // Inicializa os atributos da lista ordenada como nulos
    tamanho = 0;
    vertices = nullptr;
}

ListaOrdenada::ListaOrdenada(Grafo* grafo_) { // O(n)
    // Cria a lista ordenada a partir do grafo passado como parâmetro
    // Os itens da lista são os vértices do grafo
    if (grafo_ == nullptr) throw "Grafo não pode ser nulo!";
    tamanho = grafo_->getTamanho();
    vertices = new Vertice[tamanho];
    for (int i = 0; i < tamanho; i++) {
        vertices[i] = *grafo_->getVertice(i);
    }
}

ListaOrdenada::~ListaOrdenada() {
    delete[] vertices;
}

void ListaOrdenada::bubbleSort() { // O(n^2)
    if (tamanho <= 1) return;
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho - 1; j++) {
            if (vertices[j].getColor() > vertices[j + 1].getColor()) { 
                // Se a cor do vértice atual for maior que a cor do próximo vértice
                // troca os vértices de posição
                troca(j, j + 1);
            }
        }
    }
}

void ListaOrdenada::selectionSort() { // O(n^2)
    if (tamanho <= 1) return;
    int menor = 0;
    for (int i = 0; i < tamanho - 1; i++) { // O(n^2)
        menor = i;
        for (int j = i + 1; j < tamanho; j++) {
            // Encontra o vértice com a menor cor
            if (vertices[j].getColor() < vertices[menor].getColor()) {
                menor = j;
            }
        }
        if (menor != i) {
            // Se o vértice com a menor cor não for o vértice atual
            // troca os vértices de posição
            troca(i, menor);
        }
    }
}

void ListaOrdenada::insertionSort() { // O(n^2)
    if (tamanho <= 1) return;
    int j = 0;
    Vertice aux;
    for (int i = 1; i < tamanho; i++) { // O(n^2) no pior caso
        aux = vertices[i];
        j = i - 1;
        while ((j >= 0) && (aux.getColor() < vertices[j].getColor())) {
            // Itera os vértices, e trás o vértice atual para o início 
            // até achar um vértice com cor menor
            vertices[j + 1] = vertices[j];
            j--;
        }
        // Insere o vértice atual na posição correta
        vertices[j + 1] = aux;
    }
}

void ListaOrdenada::quickSort() { // O(n^2)
    if (tamanho <= 1) return;
    ordena(0, tamanho - 1);

    // Garante que os vértices com a mesma cor fiquem ordenados por id
    // Proporciona estabilidade ao algoritmo
    for (int j = 0; j < tamanho - 1; j++) {
        if (vertices[j].getColor() == vertices[j + 1].getColor()) {
            if (vertices[j].getId() > vertices[j + 1].getId()) {
                troca(j, j + 1);
            }
        }
    }
}

void ListaOrdenada::mergeSort() { // O(n log n)
    if (tamanho <= 1) return;
    vertices = mergeSortDivide(vertices, tamanho); // Chama a função auxiliar do mergeSort
}

void ListaOrdenada::heapSort() { // O(n log n)
    if (tamanho <= 1) return;
    for (int i = tamanho / 2 - 1; i >= 0; i--) {
        heapify(tamanho, i);
    }

    for (int i = tamanho - 1; i >= 0; i--) {
        troca(0, i);
        heapify(i, 0);
    }
}

void ListaOrdenada::mySort() { // O(n^2)
    if (tamanho <= 1) return;
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = i + 1; j < tamanho; j++) {
            if (vertices[i].getColor() > vertices[j].getColor()) {
                troca(i, j);
            }
        }
    }
}

void ListaOrdenada::particao(int esq, int dir, int* i, int* j) {
    Vertice pivo, aux;
    *i = esq;
    *j = dir;
    pivo = vertices[(*i + *j) / 2];

    do {
        while (vertices[*i].getColor() < pivo.getColor())
            (*i)++;

        while (vertices[*j].getColor() > pivo.getColor())
            (*j)--;

        if (*i <= *j) {
            troca(*i, *j);
            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}

void ListaOrdenada::ordena(int esq, int dir) {
    int i, j;
    particao(esq, dir, &i, &j);

    if (esq < j)
        ordena(esq, j);

    if (i < dir)
        ordena(i, dir);
}

Vertice* ListaOrdenada::merge(Vertice* vetorEsq, Vertice* vetorDir, int tamanhoEsq, int tamanhoDir) { // O(n)
    int tamanho = tamanhoEsq + tamanhoDir;
    Vertice* vetor = new Vertice[tamanho];
    int i = 0, j = 0, k = 0;
    while ((i < tamanhoEsq) && (j < tamanhoDir)) {
        // Intercala os vértices dos dois vetores em um vetor ordenado
        if (vetorEsq[i].getColor() <= vetorDir[j].getColor()) {
            vetor[k] = vetorEsq[i];
            i++;
        } else {
            vetor[k] = vetorDir[j];
            j++;
        }
        k++;
    }
    while (i < tamanhoEsq) {
        vetor[k] = vetorEsq[i];
        i++;
        k++;
    }
    while (j < tamanhoDir) {
        vetor[k] = vetorDir[j];
        j++;
        k++;
    }
    delete[] vetorEsq;
    delete[] vetorDir;

    return vetor;
}

Vertice* ListaOrdenada::mergeSortDivide(Vertice* vetor, int tamanho) { // O(n log n)
    // Divide o vetor em dois até que o tamanho seja 1
    // Chama a função merge para intercalar os vértices
    Vertice* vetorEsq = new Vertice[tamanho / 2];
    Vertice* vetorDir = new Vertice[tamanho - (tamanho / 2)];
    int tamanhoEsq = tamanho / 2;
    int tamanhoDir = tamanho - (tamanho / 2);
    for (int i = 0; i < tamanhoEsq; i++) {
        vetorEsq[i] = vetor[i];
    }
    for (int j = 0; j < tamanhoDir; j++) {
        vetorDir[j] = vetor[tamanhoEsq + j];
    }
    if (tamanho > 1) {
        vetorEsq = mergeSortDivide(vetorEsq, tamanhoEsq);
        vetorDir = mergeSortDivide(vetorDir, tamanhoDir);
    }
    delete[] vetor;

    return merge(vetorEsq, vetorDir, tamanhoEsq, tamanhoDir);
}

void ListaOrdenada::heapify(int n, int i) {
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    if (esquerda < n && vertices[esquerda].getColor() > vertices[maior].getColor())
        maior = esquerda;

    if (direita < n && vertices[direita].getColor() > vertices[maior].getColor())
        maior = direita;

    if (maior != i) {
        troca(i, maior);
        heapify(n, maior);
    }
}

void ListaOrdenada::imprime() { // O(n)
    for (int i = 0; i < tamanho; i++) {
        std::cout << vertices[i].getId() << " ";
    }
    std::cout << std::endl;
}

void ListaOrdenada::troca(int i_, int j_) { // O(1)
    if ((i_ < 0) || (j_ < 0)) throw "Índice não pode ser negativo!";
    // Troca os vértices de posição
    Vertice aux = vertices[i_];
    vertices[i_] = vertices[j_];
    vertices[j_] = aux;
}