#include <iostream>
#include "grafo.hpp"

Vertice* bubbleSort(Grafo* grafo_) {
    int tamanho = grafo_->getTamanho();
    Vertice* vetor = new Vertice[tamanho];
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = *grafo_->getVertice(i);
    }
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho - 1; j++) {
            if (vetor[j].getColor() > vetor[j + 1].getColor()) {
                Vertice aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
    return vetor;
}

Vertice* selectionSort(Grafo* grafo_) {
    int tamanho = grafo_->getTamanho(), menor = 0;
    Vertice* vetor = new Vertice[tamanho];
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = *grafo_->getVertice(i);
    }
    for (int i = 0; i < tamanho - 1; i++) {
        menor = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[j].getColor() < vetor[menor].getColor()) {
                menor = j;
            }
        }
        if (menor != i) {
            Vertice aux = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = aux;
        }
    }
    return vetor;
}

Vertice* insertionSort(Grafo* grafo_) {
    int tamanho = grafo_->getTamanho(), j = 0;
    Vertice* vetor = new Vertice[grafo_->getTamanho()];
    Vertice aux;
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = *grafo_->getVertice(i);
    }
    for (int i = 1; i < tamanho; i++) {
        aux = vetor[i];
        j = i - 1;
        while ((j >= 0) && (aux.getColor() < vetor[j].getColor())) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = aux;
    }
    return vetor;
}

void particao(int esq, int dir, int* i, int* j, Vertice* vetor) {
    Vertice x, w;
    *i = esq, *j = dir;
    x = vetor[(*i + *j) / 2]; /* obtem o pivo x */
    do {
        while (x.getColor() > vetor[*i].getColor()) (*i)++;
        while (x.getColor() < vetor[*j].getColor()) (*j)--;
        if (*i <= *j) {
            w = vetor[*i];
            vetor[*i] = vetor[*j];
            vetor[*j] = w;
            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}

void ordena(int esq, int dir, Vertice* vetor) {
    int i, j;
    particao(esq, dir, &i, &j, vetor);
    if (esq < j) ordena(esq, j, vetor);
    if (i < dir) ordena(i, dir, vetor);
}

Vertice* quickSort(Vertice* vetor, int tamanho) {
    ordena(0, tamanho - 1, vetor);
    return vetor;
}

Vertice* quickSortCall(Grafo* grafo_) {
    int tamanho = grafo_->getTamanho();
    Vertice* vetor = new Vertice[tamanho];
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = *grafo_->getVertice(i);
    }
    vetor = quickSort(vetor, tamanho);
    return vetor;
}  

Vertice* merge(Vertice* vetorEsq, Vertice* vetorDir, int tamanhoEsq, int tamanhoDir) {
    int tamanho = tamanhoEsq + tamanhoDir;
    Vertice* vetor = new Vertice[tamanho];
    int i = 0, j = 0, k = 0;
    while ((i < tamanhoEsq) && (j < tamanhoDir)) {
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
    return vetor;
}

Vertice* mergeSort(Vertice* vetor, int tamanho) {
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
        vetorEsq = mergeSort(vetorEsq, tamanhoEsq);
        vetorDir = mergeSort(vetorDir, tamanhoDir);
    }

    vetor = merge(vetorEsq, vetorDir, tamanhoEsq, tamanhoDir);
    return vetor;
}

Vertice* mergeSortCall(Grafo* grafo_) {
    int tamanho = grafo_->getTamanho();
    Vertice* vetor = new Vertice[tamanho];
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = *grafo_->getVertice(i);
    }
    vetor = mergeSort(vetor, tamanho);

    return vetor;
}

Vertice* heapSort(Vertice* vetor, int tamanho) {
    int maior = 0;
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i].getColor() > vetor[maior].getColor()) {
            maior = i;
        }
    }
    Vertice aux = vetor[tamanho - 1];
    vetor[tamanho - 1] = vetor[maior];
    vetor[maior] = aux;
    if (tamanho > 1) {
        vetor = heapSort(vetor, tamanho - 1);
    }

    return vetor;
}

Vertice* heapSortCall(Grafo* grafo_) {
    int tamanho = grafo_->getTamanho();
    Vertice* vetor = new Vertice[tamanho];
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = *grafo_->getVertice(i);
    }
    vetor = heapSort(vetor, tamanho);

    return vetor;
}

Vertice* mySort(Grafo* grafo_) {
    Vertice* vetor = new Vertice[grafo_->getTamanho()];
    for (int i = 0; i < grafo_->getTamanho(); i++) {
        vetor[i] = *grafo_->getVertice(i);
    }
    int tamanho = grafo_->getTamanho();
    vetor = bubbleSort(grafo_);
    return vetor;
}

int main() {
    char tipoOrdena;
    int tamanhoGrafo = 0, idA = 0, idB = 0, numVizinhos = 0, color = 0;
    std::cin >> tipoOrdena >> tamanhoGrafo;
    Grafo* grafo = new Grafo(tamanhoGrafo);

    for (int i = 0; i < tamanhoGrafo; i++) {
        std::cin >> numVizinhos;
        idA = i;
        for (int j = 0; j < numVizinhos; j++) {
            std::cin >> idB;
            grafo->insereAresta(idA, idB);
        }
    }

    for (int k = 0; k < tamanhoGrafo; k++) {
        std::cin >> color;
        grafo->getVertice(k)->setColor(color);
    }

    grafo->coloreArestas();

    Vertice* vetor = new Vertice[tamanhoGrafo];


    switch (tipoOrdena) {
        case 'b':
            vetor = bubbleSort(grafo); // funciona
            break;
        case 'i':
            vetor = insertionSort(grafo); // funciona
            break;
        case 's':
            vetor = selectionSort(grafo); // funciona
            break;
        case 'q':
            vetor = quickSortCall(grafo); // funciona
            break;
        case 'm':
            vetor = mergeSortCall(grafo); // funciona
            break;
        case 'p':
            vetor = heapSortCall(grafo); // funciona
            break;
        case 'y':
            vetor = mySort(grafo); // funciona
            break;
    }

    if (grafo->guloso()) {
        std::cout << "1 ";
        for (int i = 0; i < tamanhoGrafo; i++) {
            std::cout << vetor[i].getId() << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "0" << std::endl;
    }
  
    return 0;
} 

// Path: src/main.cpp