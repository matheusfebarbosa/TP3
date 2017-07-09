#include <stdio.h>

typedef struct Edge{
	int va;
	int vb;
	int conflicts;
} Edge;

int verifyConflict(Edge a, Edge b);
void readGraph(Edge *edges, int n);