#include "graph.h"

//Funções para ordenação interna
void maxHeapify(Edge *edges, int n, int father);
void buildHeap(Edge *edges, int n);
void heapSort(Edge *edges, int n);