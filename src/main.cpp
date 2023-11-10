#include <iostream>
#include "grafo.hpp"

void bubbleSort(Grafo* grafo_) {
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
    for (int i = 0; i < tamanho; i++) {
        std::cout << vetor[i].getId() << " ";
    }
    std::cout << std::endl;
}

void selectionSort(Grafo* grafo_) {
    int tamanho = grafo_->getTamanho(), menor = 0;
    Vertice* vetor = new Vertice[tamanho];
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
    for (int i = 0; i < tamanho; i++) {
        std::cout << vetor[i].getId() << " ";
    }
}

void insertionSort(Grafo* grafo_) {
    int tamanho = grafo_->getTamanho(), j = 0;
    Vertice* vetor = new Vertice[grafo_->getTamanho()];
    Vertice aux;
    for (int i = 1; i < tamanho; i++) {
        aux = vetor[i];
        j = i - 1;
        while ((j >= 0) && (aux.getColor() < vetor[j].getColor())) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = aux;
    }
    for (int i = 0; i < tamanho; i++) {
        std::cout << vetor[i].getId() << " ";
    }
}

void particao(int esq, int dir, int* i, int* j, Vertice* vetor) {
    Vertice pivo, aux;
    *i = esq;
    *j = dir;
    pivo = vetor[(*i + *j) / 2];
    do {
        while (pivo.getColor() > vetor[*i].getColor()) {
            (*i)++;
        }
        while (pivo.getColor() < vetor[*j].getColor()) {
            (*j)--;
        }
        if (*i <= *j) {
            aux = vetor[*i];
            vetor[*i] = vetor[*j];
            vetor[*j] = aux;
            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}

Vertice* quickSort(Vertice* vetor, int tamanho) {
    int i, j;
    particao(0, tamanho - 1, &i, &j, vetor);
    if (j > 0) {
        quickSort(vetor, j + 1);
    }
    if (i < tamanho) {
        quickSort(&vetor[i], tamanho - i);
    }
    return vetor;

}

void quickSortCall(Grafo* grafo_) {
    int tamanho = grafo_->getTamanho();
    Vertice* vetor = new Vertice[tamanho];
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = *grafo_->getVertice(i);
    }
    vetor = quickSort(vetor, tamanho);

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

void mergeSortCall(Grafo* grafo_) {
    int tamanho = grafo_->getTamanho();
    Vertice* vetor = new Vertice[tamanho];
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = *grafo_->getVertice(i);
    }
    vetor = mergeSort(vetor, tamanho);

    for (int i = 0; i < tamanho; i++) {
        std::cout << vetor[i].getId() << " ";
    }
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

void heapSortCall(Grafo* grafo_) {
    int tamanho = grafo_->getTamanho();
    Vertice* vetor = new Vertice[tamanho];
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = *grafo_->getVertice(i);
    }
    vetor = heapSort(vetor, tamanho);

    for (int i = 0; i < tamanho; i++) {
        std::cout << vetor[i].getId() << " ";
    }
}

void mySort(Grafo* grafo_) {
    return;
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

    std::cout << "-------------------" << std::endl;

    //imprimir grafo
    for (int i = 0; i < tamanhoGrafo; i++) {
        std::cout << i << ": cor: " << grafo->getVertice(i)->getColor();
        std::cout << " vizinhos: ";
        grafo->imprimeVizinhos(i);
    }

    std::cout << "-------------------" << std::endl;

    grafo->imprime();

    std::cout << "-------------------" << std::endl;

    std::cout << "Guloso: " << grafo->guloso() << std::endl;

    std::cout << "-------------------" << std::endl;

    std::cin >> tipoOrdena;

    switch (tipoOrdena) {
        case 'b':
            bubbleSort(grafo); // funciona
            break;
        case 's':
            selectionSort(grafo); // nao funciona
            break;
        case 'i':
            insertionSort(grafo); // nao funciona
            break;
        case 'q':
            quickSortCall(grafo); // nao funciona
            break;
        case 'm':
            mergeSortCall(grafo); // funciona
            break;
        case 'p':
            heapSortCall(grafo); // nao funciona
            break;
        case 'y':
            mySort(grafo); // nao funciona
            break;
        default:
            break;
    }
  
    return 0;
} 


/*
int main() {
    char tipoOrdena;
    int tamanho = 0, id = 0, numVizinhos = 0, color = 0;

    std::cin >> tipoOrdena >> tamanho;
    Grafo grafo = Grafo(tamanho);

    for (int i = 0; i < tamanho; i++) {
        std::cin >> numVizinhos;
        for (int j = 0; j < numVizinhos; j++) {
            std::cin >> id;
            grafo.insereVizinho(i, id);
        }
    }

    for (int k = 0; k < tamanho; k++) {
        std::cin >> color;
        grafo.coloreVertice(k, color);
    }

    std::cout << "--------------------" << std::endl;
    
    if (grafo.guloso()) {
        std::cout << "GULOSO" << std::endl;
    } else {
        std::cout << "NAO" << std::endl;
    }

    std::cout << "--------------------------" << std::endl;
}

*/
// Path: src/main.cpp