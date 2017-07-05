#include <stdlib.h>

typedef struct Edge{
	 int vertexA;
	 int vextexB;
	 int conflicts;
} Edge;

typedef struct EdgeCell{
	Edge edge;
	struct EdgeCell *next;
} EdgeCell;

typedef struct Graph{
	EdgeCell *first;
	EdgeCell *last;
} Graph;

void insertEdge(Graph *g, int i, int y);
void makeEmptyGraph(Graph **g);
int verifyConflict(Edge *a, Edge *b);