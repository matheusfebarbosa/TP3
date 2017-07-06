#include <stdlib.h>
#include <stdio.h>
#include "internal_sorting.h"
//#include "graph.h"

typedef struct Edge{
	int va;
	int vb;
	int conflicts;
} Edge;


int dinamico();
int guloso(Edge *flagLines, int n);
int forca_bruta(Edge *flagLines, int n);
int verifyConflict(Edge a, Edge b);
void readInput(Edge *flagLines, int n);