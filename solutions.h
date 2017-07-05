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
int guloso();
int forca_bruta();
int verifyConflict(Edge a, Edge b);